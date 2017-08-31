#include "filter.hpp"

using namespace genling;

Filter::Filter(std::wstring pattern, float probability, bool permit) :
	pattern(pattern), probability(probability), permit(permit),
	rng((std::random_device())())
{
	distribution = std::uniform_real_distribution<float>(0.0,1.0);
}

bool Filter::is_permitted(std::wstring string)
{
	if(distribution(rng) > probability)
		return !permit;
	if(match(string))
		return permit;
	return !permit;
}

bool Filter::is_rejected(std::wstring string)
{
	return !is_permitted(string);
}

// Getters

std::wstring Filter::get_pattern()
{
	return pattern;
}

float Filter::get_probability()
{
	return probability;
}

bool Filter::get_permit()
{
	return permit;
}

// (Simple) Filter

bool Filter::match(std::wstring string)
{
	return string.find(get_pattern()) != std::wstring::npos;
}

// Regex Filter

RegexFilter::RegexFilter(std::wstring pattern, float probability, bool permit) :
	Filter(pattern, probability, permit), rgx(std::wregex(pattern)) {}

bool RegexFilter::match(std::wstring string)
{
	std::wsmatch m;
	return std::regex_search(string, m, rgx);
}