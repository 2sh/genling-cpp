#include "replace.hpp"

using namespace genling;

Replace::Replace(std::string pattern, std::string repl, float probability) :
	pattern(pattern), repl(repl), probability(probability),
	rng((std::random_device())())
{
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

// Regex Replace

RegexReplace::RegexReplace(
	std::string pattern, std::string repl, float probability) :
	Replace(pattern, repl, probability), rgx(std::regex(pattern)) {}

std::string RegexReplace::replace(std::string string)
{
	return std::regex_replace(string, rgx, get_repl());
}