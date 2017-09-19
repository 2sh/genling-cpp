#include "word.hpp"

using namespace genling;

Word::Word(const std::vector<std::shared_ptr<Replace>>& replacements) :
	replacements(replacements) {}

std::u32string Word::create(const std::u32string& stem_string)
{
	std::u32string string = stem_string;
	for(auto replace : replacements)
	{
		string = replace->apply(string);
	}
	return string;
}

// Getters

const std::vector<std::shared_ptr<Replace>>& Word::get_replacements() const
{
	return replacements;
}

// Setters

void Word::set_replacements(const std::vector<std::shared_ptr<Replace>>&)
{
	this->replacements = replacements;
}
