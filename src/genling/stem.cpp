#include <stdexcept>

#include "stem.hpp"

using namespace genling;

Stem::Stem(std::vector<Syllable> syllables, std::vector<int> balance,
	std::vector<Filter> filters,
	std::string prefix, std::string suffix,  std::string infix) :
		syllables(syllables), filters(filters),
		prefix(prefix), suffix(suffix), infix(infix)
{
	set_balance(balance);
	std::random_device rd;
	generator = std::default_random_engine(rd());
}

std::string Stem::generate_unfiltered()
{
	int syllable_amount = balance_distribution(generator) + 1;
	std::string output = prefix;
	Syllable * pt_syllable;
	
	for(int i=0; i<syllable_amount; i++)
	{
		std::vector<Syllable> syllables;
		std::vector<int> weights;
		for(Syllable syllable : syllables)
		{
			if(!syllable.is_permitted_position(i, syllable_amount))
				continue;
			syllables.push_back(syllable);
			weights.push_back(syllable.get_weight());
		}
		
		if(i>0) output += " ";
		if(syllables.size() > 1)
		{
			std::discrete_distribution<int> distribution(
				weights.begin(), weights.end());
			
			pt_syllable = &syllables[distribution(generator)];
		}
		else
		{
			pt_syllable = &syllables[0];
		}
		output += pt_syllable->generate();
	}
	return output + suffix;
}

std::string Stem::generate()
{
	std::string stem;
	bool is_rejected = false;
	for(int i=0; i<1000; i++)
	{
		stem = generate_unfiltered();
		for(Filter filter : filters)
		{
			is_rejected = filter.is_rejected(stem);
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

std::vector<Filter> Stem::get_filters()
{
	return filters;
}

std::string Stem::get_prefix()
{
	return prefix;
}

std::string Stem::get_suffix()
{
	return suffix;
}

std::string Stem::get_infix()
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

void Stem::set_filters(std::vector<Filter> filters)
{
	this->filters = filters;
}

void Stem::set_prefix(std::string prefix)
{
	this->prefix = prefix;
}

void Stem::set_suffix(std::string suffix)
{
	this->suffix = suffix;
}

void Stem::set_infix(std::string infix)
{
	this->infix = infix;
}
