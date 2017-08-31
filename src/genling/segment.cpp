#include "segment.hpp"

using namespace genling;



Segment::Segment(std::vector<Phoneme> phonemes,
	std::wstring prefix, std::wstring suffix) :
		prefix(prefix), suffix(suffix),
		rng((std::random_device())())
{
	set_phonemes(phonemes);
}

std::wstring Segment::generate()
{
	return prefix + phonemes[weight_distribution(rng)].get_grapheme() + suffix;
}

// Getters

std::vector<Phoneme> Segment::get_phonemes()
{
	return phonemes;
}

std::wstring Segment::get_prefix()
{
	return prefix;
}

std::wstring Segment::get_suffix()
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

void Segment::set_prefix(std::wstring prefix)
{
	this->prefix = prefix;
}

void Segment::set_suffix(std::wstring suffix)
{
	this->suffix = suffix;
}