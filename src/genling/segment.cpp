#include "segment.hpp"

using namespace genling;

Segment::Segment(const std::vector<Phoneme>& phonemes,
	const std::u32string& prefix, const std::u32string& suffix) :
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

const std::vector<Phoneme>& Segment::get_phonemes() const
{
	return phonemes;
}

const std::u32string& Segment::get_prefix() const
{
	return prefix;
}

const std::u32string& Segment::get_suffix() const
{
	return suffix;
}

// Setters

void Segment::set_phonemes(const std::vector<Phoneme>& phonemes)
{
	this->phonemes = phonemes;
	
	std::vector<int> weights;
	for(const Phoneme& phoneme : this->phonemes)
	{
		weights.push_back(phoneme.get_weight());
	}
	weight_distribution = std::discrete_distribution<int>(
		weights.begin(), weights.end());
}

void Segment::set_prefix(const std::u32string& prefix)
{
	this->prefix = prefix;
}

void Segment::set_suffix(const std::u32string& suffix)
{
	this->suffix = suffix;
}
