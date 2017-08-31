#include "filter.hpp"

using namespace genling;

Filter::Filter(std::u32string pattern, float probability, bool permit) :
	pattern(pattern), probability(probability), permit(permit),
	rng((std::random_device())())
{
	distribution = std::uniform_real_distribution<float>(0.0,1.0);
}

bool Filter::is_permitted(std::u32string string)
{
	if(distribution(rng) > probability)
		return !permit;
	if(match(string))
		return permit;
	return !permit;
}

bool Filter::is_rejected(std::u32string string)
{
	return !is_permitted(string);
}

// Getters

std::u32string Filter::get_pattern()
{
	return pattern;
}

float Filter::get_probability()
{
	return probability;
}

bool Filter::is_permit()
{
	return permit;
}

// (Simple) Filter

bool Filter::match(std::u32string string)
{
	return string.find(get_pattern()) != std::u32string::npos;
}

// Regex Filter

RegexFilter::RegexFilter(std::u32string pattern, float probability, bool permit) :
	Filter(pattern, probability, permit)
{
	rgx = boost::make_u32regex(pattern);
}

bool RegexFilter::match(std::u32string string)
{
	boost::smatch m;
	return boost::u32regex_search(u32cvt.to_bytes(string), m, rgx);
}
