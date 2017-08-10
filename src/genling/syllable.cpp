#include "syllable.hpp"

using namespace genling;


Syllable::Syllable(std::vector<Segment> segments,
	int position, int weight,
	std::string prefix, std::string suffix, std::string infix) :
		segments(segments), position(position), weight(weight),
		prefix(prefix), suffix(suffix), infix(infix) {}

bool Syllable::is_permitted_position(int i, int length)
{
	return (position == 0 ||
		(position > 0 ? position : length+position+1) == (i+1));
}

std::string Syllable::generate()
{
	std::string output = prefix;
	for(int i=0; i<segments.size(); i++)
	{
		if(i>0) output += infix;
		output += segments[i].generate();
	}
	return output + suffix;
}

// Getters

std::vector<Segment> Syllable::get_segments()
{
	return segments;
}

int Syllable::get_position()
{
	return position;
}

int Syllable::get_weight()
{
	return weight;
}

std::string Syllable::get_prefix()
{
	return prefix;
}

std::string Syllable::get_suffix()
{
	return suffix;
}

std::string Syllable::get_infix()
{
	return infix;
}

// Setters

void Syllable::set_segments(std::vector<Segment> segments)
{
	this->segments = segments;
}

void Syllable::set_position(int position)
{
	this->position = position;
}

void Syllable::set_weight(int weight)
{
	this->weight = weight;
}

void Syllable::set_prefix(std::string prefix)
{
	this->prefix = prefix;
}

void Syllable::set_suffix(std::string suffix)
{
	this->suffix = suffix;
}

void Syllable::set_infix(std::string infix)
{
	this->infix = infix;
}