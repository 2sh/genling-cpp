#include "phoneme.hpp"

using namespace genling;


Phoneme::Phoneme(std::string grapheme, int weight) :
	grapheme(grapheme), weight(weight) {}

// Getters

std::string Phoneme::get_grapheme()
{
	return grapheme;
}

int Phoneme::get_weight()
{
	return weight;
}

// Setters

void Phoneme::set_grapheme(std::string grapheme)
{
	this->grapheme = grapheme;
}

void Phoneme::set_weight(int weight)
{
	this->weight = weight;
}