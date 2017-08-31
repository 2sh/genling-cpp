#include "replace.hpp"

using namespace genling;

Replace::Replace(std::wstring pattern, std::wstring repl, float probability) :
	pattern(pattern), repl(repl), probability(probability),
	rng((std::random_device())())
{
	distribution = std::uniform_real_distribution<float>(0.0,1.0);
}

std::wstring Replace::apply(std::wstring string)
{
	if(distribution(rng) > probability)
		return string;
	
	
	
	return replace(string);
}

// Getters

std::wstring Replace::get_pattern()
{
	return pattern;
}

std::wstring Replace::get_repl()
{
	return repl;
}

float Replace::get_probability()
{
	return probability;
}

// (Simple) Replace

std::wstring Replace::replace(std::wstring string)
{
	std::wstring::size_type position = 0;
	while((position = string.find(pattern, position)) != std::wstring::npos)
	{
		string = string.replace(position, pattern.size(), get_repl());
		position += get_repl().size();
	}
	return string;
}

// Regex Replace

RegexReplace::RegexReplace(
	std::wstring pattern, std::wstring repl, float probability) :
	Replace(pattern, repl, probability), rgx(std::wregex(pattern)) {}

std::wstring RegexReplace::replace(std::wstring string)
{
	return std::regex_replace(string, rgx, get_repl());
}