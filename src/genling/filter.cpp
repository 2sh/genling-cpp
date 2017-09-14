#include "filter.hpp"

using namespace genling;

Filter::Filter(const std::u32string& pattern,
	const float probability, const bool permit) :
	pattern(pattern), probability(probability), permit(permit),
	rng((std::random_device())())
{
	distribution = std::uniform_real_distribution<float>(0.0,1.0);
}

Filter::Filter(const Filter& o) :
	pattern(o.pattern), probability(o.probability), permit(o.permit),
	rng((std::random_device())()), distribution(o.distribution) {}

bool Filter::is_permitted(const std::u32string& string)
{
	if(distribution(rng) > probability)
		return !permit;
	if(match(string))
		return permit;
	return !permit;
}

bool Filter::is_rejected(const std::u32string& string)
{
	return !is_permitted(string);
}

// Getters

const std::u32string& Filter::get_pattern() const
{
	return pattern;
}

float Filter::get_probability() const
{
	return probability;
}

bool Filter::is_permit() const
{
	return permit;
}

// (Simple) Filter

bool Filter::match(const std::u32string& string)
{
	return string.find(get_pattern()) != std::u32string::npos;
}

// Regex Filter

RegexFilter::RegexFilter(const std::u32string& pattern,
	const float probability, const bool permit) :
	Filter(pattern, probability, permit)
{
	rgx = boost::make_u32regex(pattern);
}

bool RegexFilter::match(const std::u32string& string)
{
	boost::smatch m;
	return boost::u32regex_search(u32cvt.to_bytes(string), m, rgx);
}
