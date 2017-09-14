#include "phoneme.hpp"

using namespace genling;

Phoneme::Phoneme(const std::u32string& grapheme, const int weight) :
	grapheme(grapheme), weight(weight) {}

// Getters

const std::u32string& Phoneme::get_grapheme() const
{
	return grapheme;
}

int Phoneme::get_weight() const
{
	return weight;
}

// Setters

void Phoneme::set_grapheme(const std::u32string& grapheme)
{
	this->grapheme = grapheme;
}

void Phoneme::set_weight(const int weight)
{
	this->weight = weight;
}
