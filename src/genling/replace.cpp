#include "replace.hpp"

using namespace genling;

Replace::Replace(std::u32string pattern, std::u32string repl, float probability) :
	pattern(pattern), repl(repl), probability(probability),
	rng((std::random_device())())
{
	distribution = std::uniform_real_distribution<float>(0.0,1.0);
}

Replace::Replace(const Replace& o) :
	pattern(o.pattern), repl(o.repl), probability(o.probability),
	rng((std::random_device())()), distribution(o.distribution) {}

std::u32string Replace::apply(std::u32string string)
{
	if(distribution(rng) > probability)
		return string;
	return replace(string);
}

// Getters

std::u32string Replace::get_pattern()
{
	return pattern;
}

std::u32string Replace::get_repl()
{
	return repl;
}

float Replace::get_probability()
{
	return probability;
}

// (Simple) Replace

std::u32string Replace::replace(std::u32string string)
{
	std::u32string::size_type position = 0;
	while((position = string.find(pattern, position)) != std::u32string::npos)
	{
		string = string.replace(position, pattern.size(), get_repl());
		position += get_repl().size();
	}
	return string;
}

// Regex Replace

RegexReplace::RegexReplace(
	std::u32string pattern, std::u32string repl, float probability) :
	Replace(pattern, repl, probability), u8repl(u32cvt.to_bytes(repl)),
	rgx(boost::make_u32regex(pattern)) {}

std::u32string RegexReplace::replace(std::u32string string)
{
	return u32cvt.from_bytes(
		boost::u32regex_replace(u32cvt.to_bytes(string), rgx, u8repl)
	);
}
