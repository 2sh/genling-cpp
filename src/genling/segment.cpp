#include "segment.hpp"

using namespace genling;


Segment::Segment(std::vector<Phoneme> phonemes,
	std::string prefix, std::string suffix) :
		prefix(prefix), suffix(suffix)
{
	set_phonemes(phonemes);
	std::random_device rd;
	generator = std::default_random_engine(rd());
}

std::string Segment::generate()
{
	return prefix + phonemes[weight_distribution(generator)].get_grapheme() + suffix;
}

// Getters

std::vector<Phoneme> Segment::get_phonemes()
{
	return phonemes;
}

std::string Segment::get_prefix()
{
	return prefix;
}

std::string Segment::get_suffix()
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

void Segment::set_prefix(std::string prefix)
{
	this->prefix = prefix;
}

void Segment::set_suffix(std::string suffix)
{
	this->suffix = suffix;
}