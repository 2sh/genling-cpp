#include <stdexcept>
#include <string>

#include "stem.hpp"

using namespace genling;

Stem::Stem(const std::vector<Syllable>& syllables,
	const std::vector<int>& balance,
	const std::vector<std::shared_ptr<Filter>>& filters,
	const std::u32string& prefix,
	const std::u32string& suffix,
	const std::u32string& infix) :
		syllables(syllables), filters(filters),
		prefix(prefix), suffix(suffix), infix(infix),
		rng((std::random_device())())
{
	set_balance(balance);
}

Stem::Stem(const Stem& o) :
	syllables(o.syllables), balance(o.balance), filters(o.filters),
	prefix(o.prefix), suffix(o.suffix), infix(o.infix),
	rng((std::random_device())()),
	balance_distribution(o.balance_distribution) {}


std::u32string Stem::generate_unfiltered()
{
	int syllable_amount = balance_distribution(rng) + 1;
	std::u32string output = prefix;
	
	for(int i=0; i<syllable_amount; i++)
	{
		std::vector<Syllable> possible_syllables;
		std::vector<int> weights;
		Syllable * pt_syllable;
		
		for(Syllable syllable : syllables)
		{
			if(!syllable.is_permitted_position(i, syllable_amount))
				continue;
			possible_syllables.push_back(syllable);
			weights.push_back(syllable.get_weight());
		}
		
		if(i>0) output += infix;
		if(possible_syllables.size() > 1)
		{
			std::discrete_distribution<int> distribution(
				weights.begin(), weights.end());
			
			pt_syllable = &possible_syllables[distribution(rng)];
		}
		else if(possible_syllables.size() == 1)
		{
			pt_syllable = &possible_syllables[0];
		}
		else
		{
			throw std::invalid_argument("No possible syllable for position " + std::to_string(i+1));
		}
		output += pt_syllable->generate();
	}
	return output + suffix;
}

std::u32string Stem::generate()
{
	std::u32string stem;
	bool is_rejected = false;
	for(int i=0; i<1000; i++)
	{
		stem = generate_unfiltered();
		for(auto filter : filters)
		{
			is_rejected = filter->is_rejected(stem);
			if(is_rejected) break;
		}
		if(!is_rejected)
			return stem;
	}
	throw std::out_of_range("Too many filter rejected stems");
}

// Getters

const std::vector<Syllable>& Stem::get_syllables() const
{
	return syllables;
}

const std::vector<int>& Stem::get_balance() const
{
	return balance;
}

const std::vector<std::shared_ptr<Filter>>& Stem::get_filters() const
{
	return filters;
}

const std::u32string& Stem::get_prefix() const
{
	return prefix;
}

const std::u32string& Stem::get_suffix() const
{
	return suffix;
}

const std::u32string& Stem::get_infix() const
{
	return infix;
}

// Setters

void Stem::set_syllables(const std::vector<Syllable>& syllables)
{
	this->syllables = syllables;
}

void Stem::set_balance(const std::vector<int>& balance)
{
	this->balance = balance;
	balance_distribution = std::discrete_distribution<int>(
		this->balance.begin(), this->balance.end());
}

void Stem::set_filters(
	const std::vector<std::shared_ptr<Filter>>& filters)
{
	this->filters = filters;
}

void Stem::set_prefix(const std::u32string& prefix)
{
	this->prefix = prefix;
}

void Stem::set_suffix(const std::u32string& suffix)
{
	this->suffix = suffix;
}

void Stem::set_infix(const std::u32string& infix)
{
	this->infix = infix;
}
