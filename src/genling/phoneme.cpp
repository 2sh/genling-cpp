#include "phoneme.hpp"

using namespace genling;


Phoneme::Phoneme(std::wstring grapheme, int weight) :
	grapheme(grapheme), weight(weight) {}

// Getters

std::wstring Phoneme::get_grapheme()
{
	return grapheme;
}

int Phoneme::get_weight()
{
	return weight;
}

// Setters

void Phoneme::set_grapheme(std::wstring grapheme)
{
	this->grapheme = grapheme;
}

void Phoneme::set_weight(int weight)
{
	this->weight = weight;
}