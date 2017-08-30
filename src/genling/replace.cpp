#include "replace.hpp"

using namespace genling;

Replace::Replace(std::string pattern, std::string repl, float probability) :
	repl(repl), probability(probability),
	rng((std::random_device())())
{
	set_pattern(pattern);
	distribution = std::uniform_real_distribution<float>(0.0,1.0);
}

std::string Replace::apply(std::string string)
{
	if(distribution(rng) > probability)
		return string;
	
	return replace(string);
}

// Getters

std::string Replace::get_pattern()
{
	return pattern;
}

std::string Replace::get_repl()
{
	return repl;
}

float Replace::get_probability()
{
	return probability;
}

// Setters

void Replace::set_pattern(std::string pattern)
{
	this->pattern = pattern;
	prepare();
}

void Replace::set_repl(std::string repl)
{
	this->repl = repl;
}

void Replace::set_probability(float probability)
{
	this->probability = probability;
}

// (Simple) Replace

std::string Replace::replace(std::string string)
{
	std::string::size_type position = 0;
	while((position = string.find(pattern, position)) != std::string::npos)
	{
		string = string.replace(position, pattern.size(), get_repl());
		position += get_repl().size();
	}
	return string;
}

void Replace::prepare(){}

// Regex Replace

std::string RegexReplace::replace(std::string string)
{
	return std::regex_replace(string, rgx, get_repl());
}

void RegexReplace::prepare()
{
	rgx = std::regex(get_pattern());
}