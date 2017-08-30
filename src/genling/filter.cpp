#include "filter.hpp"

using namespace genling;

Filter::Filter(std::string pattern, float probability, bool permit) :
	pattern(pattern), probability(probability), permit(permit),
	rng((std::random_device())())
{
	distribution = std::uniform_real_distribution<float>(0.0,1.0);
}

bool Filter::is_permitted(std::string string)
{
	if(distribution(rng) > probability)
		return !permit;
	if(match(string))
		return permit;
	return !permit;
}

bool Filter::is_rejected(std::string string)
{
	return !is_permitted(string);
}

// Getters

std::string Filter::get_pattern()
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

bool Filter::match(std::string string)
{
	return string.find(get_pattern()) != std::string::npos;
}

// Regex Filter

RegexFilter::RegexFilter(std::string pattern, float probability, bool permit) :
	Filter(pattern, probability, permit), rgx(std::regex(pattern)) {}

bool RegexFilter::match(std::string string)
{
	std::smatch m;
	return std::regex_search(string, m, rgx);
}