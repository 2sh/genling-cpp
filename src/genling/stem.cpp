#include <stdexcept>
#include <string>

#include "stem.hpp"

using namespace genling;

Stem::Stem(std::vector<Syllable> syllables, std::vector<int> balance,
	std::vector<std::shared_ptr<genling::Filter>> filters,
	std::u32string prefix, std::u32string suffix,  std::u32string infix) :
		syllables(syllables), filters(filters),
		prefix(prefix), suffix(suffix), infix(infix),
		rng((std::random_device())())
{
	set_balance(balance);
}

Stem::Stem(const Stem& o) :
	syllables(o.syllables), balance(balance), filters(o.filters),
	prefix(o.prefix), suffix(o.suffix), infix(o.infix),
	balance_distribution(o.balance_distribution),
	rng((std::random_device())()) {}


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

std::vector<Syllable> Stem::get_syllables()
{
	return syllables;
}

std::vector<int> Stem::get_balance()
{
	return balance;
}

std::vector<std::shared_ptr<genling::Filter>> Stem::get_filters()
{
	return filters;
}

std::u32string Stem::get_prefix()
{
	return prefix;
}

std::u32string Stem::get_suffix()
{
	return suffix;
}

std::u32string Stem::get_infix()
{
	return infix;
}

// Setters

void Stem::set_syllables(std::vector<Syllable> syllables)
{
	this->syllables = syllables;
}

void Stem::set_balance(std::vector<int> balance)
{
	this->balance = balance;
	balance_distribution = std::discrete_distribution<int>(
		balance.begin(), balance.end());
}

void Stem::set_filters(std::vector<std::shared_ptr<genling::Filter>> filters)
{
	this->filters = filters;
}

void Stem::set_prefix(std::u32string prefix)
{
	this->prefix = prefix;
}

void Stem::set_suffix(std::u32string suffix)
{
	this->suffix = suffix;
}

void Stem::set_infix(std::u32string infix)
{
	this->infix = infix;
}
