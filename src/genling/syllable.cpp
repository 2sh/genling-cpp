#include "syllable.hpp"

using namespace genling;


Syllable::Syllable(std::vector<Segment> segments,
	int position, int weight,
	std::wstring prefix, std::wstring suffix, std::wstring infix) :
		segments(segments), position(position), weight(weight),
		prefix(prefix), suffix(suffix), infix(infix) {}

bool Syllable::is_permitted_position(int i, int length)
{
	return (position == 0 ||
		(position > 0 ? position : length+position+1) == (i+1));
}

std::wstring Syllable::generate()
{
	std::wstring output = prefix;
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

std::wstring Syllable::get_prefix()
{
	return prefix;
}

std::wstring Syllable::get_suffix()
{
	return suffix;
}

std::wstring Syllable::get_infix()
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

void Syllable::set_prefix(std::wstring prefix)
{
	this->prefix = prefix;
}

void Syllable::set_suffix(std::wstring suffix)
{
	this->suffix = suffix;
}

void Syllable::set_infix(std::wstring infix)
{
	this->infix = infix;
}