#include "filter.hpp"

using namespace genling;

Filter::Filter(std::string pattern, float probability, bool permit) :
	probability(probability), permit(permit)
{
	set_pattern(pattern);
	std::random_device rd;
	generator = std::default_random_engine(rd());
	distribution = std::uniform_real_distribution<float>(0.0,1.0);
}

bool Filter::is_permitted(std::string string)
{
	if(distribution(generator) > probability)
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

// Setters

void Filter::set_pattern(std::string pattern)
{
	this->pattern = pattern;
	prepare();
}

void Filter::set_probability(float probability)
{
	this->probability = probability;
}

void Filter::set_permit(bool permit)
{
	this->permit = permit;
}

// (Simple) Filter

bool Filter::match(std::string string)
{
	return string.find(get_pattern()) != std::string::npos;
}

void Filter::prepare(){}

// Regex Filter

bool RegexFilter::match(std::string string)
{
	std::smatch m;
	return std::regex_search(string, m, rgx);
}

void RegexFilter::prepare()
{
	rgx = std::regex(get_pattern());
}
