#include "syllable.hpp"

using namespace genling;

Syllable::Syllable(const std::vector<Segment>& segments,
	int position, unsigned int weight,
	const std::u32string& prefix,
	const std::u32string& suffix,
	const std::u32string& infix) :
		segments(segments), position(position), weight(weight),
		prefix(prefix), suffix(suffix), infix(infix) {}

bool Syllable::is_permitted_position(unsigned int i, unsigned int length) const
{
	return (position == 0 ||
		((unsigned int)(position > 0 ? position : length+position+1)) == (i+1));
}

std::u32string Syllable::generate()
{
	std::u32string output = prefix;
	for(std::vector<Segment>::size_type i=0; i<segments.size(); i++)
	{
		if(i>0) output += infix;
		output += segments[i].generate();
	}
	return output + suffix;
}

// Getters

const std::vector<Segment>& Syllable::get_segments() const
{
	return segments;
}

int Syllable::get_position() const
{
	return position;
}

unsigned int Syllable::get_weight() const
{
	return weight;
}

const std::u32string& Syllable::get_prefix() const
{
	return prefix;
}

const std::u32string& Syllable::get_suffix() const
{
	return suffix;
}

const std::u32string& Syllable::get_infix() const
{
	return infix;
}

// Setters

void Syllable::set_segments(const std::vector<Segment>& segments)
{
	this->segments = segments;
}

void Syllable::set_position(int position)
{
	this->position = position;
}

void Syllable::set_weight(unsigned int weight)
{
	this->weight = weight;
}

void Syllable::set_prefix(const std::u32string& prefix)
{
	this->prefix = prefix;
}

void Syllable::set_suffix(const std::u32string& suffix)
{
	this->suffix = suffix;
}

void Syllable::set_infix(const std::u32string& infix)
{
	this->infix = infix;
}
