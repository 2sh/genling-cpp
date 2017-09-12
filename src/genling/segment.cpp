#include "segment.hpp"

using namespace genling;

Segment::Segment(std::vector<Phoneme> phonemes,
	std::u32string prefix, std::u32string suffix) :
		prefix(prefix), suffix(suffix),
		rng((std::random_device())())
{
	set_phonemes(phonemes);
}

Segment::Segment(const Segment& o) :
	phonemes(o.phonemes), prefix(o.prefix), suffix(o.suffix),
	rng((std::random_device())()),
	weight_distribution(o.weight_distribution) {}

std::u32string Segment::generate()
{
	return prefix + phonemes[weight_distribution(rng)].get_grapheme() + suffix;
}

// Getters

std::vector<Phoneme> Segment::get_phonemes()
{
	return phonemes;
}

std::u32string Segment::get_prefix()
{
	return prefix;
}

std::u32string Segment::get_suffix()
{
	return suffix;
}

// Setters

void Segment::set_phonemes(std::vector<Phoneme> phonemes)
{
	this->phonemes = phonemes;
	
	std::vector<int> weights;
	for(Phoneme phoneme : phonemes)
	{
		weights.push_back(phoneme.get_weight());
	}
	weight_distribution = std::discrete_distribution<int>(
		weights.begin(), weights.end());
}

void Segment::set_prefix(std::u32string prefix)
{
	this->prefix = prefix;
}

void Segment::set_suffix(std::u32string suffix)
{
	this->suffix = suffix;
}
