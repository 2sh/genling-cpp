#ifndef GENLING_WORD_HPP_INCLUDED
#define GENLING_WORD_HPP_INCLUDED

#include <string>
#include <vector>
#include <memory>

#include "replace.hpp"

namespace genling
{
	/**
		A word formed from a stem.
	
		A Word object may represent an inflection such as a noun declension, verb
		conjugation, derivation, etc. Finally, the replacements may also remove
		the helper characters (prefixes, infixes and suffixes) and transliterate
		the raw graphemes to the correct writing system.
	*/
	class Word
	{
	public:
		/**
			Constructor for Word.
			
			@param replacements
				The replace objects for creating a word from a stem.
		*/
		Word(const std::vector<std::shared_ptr<Replace>>& replacements);
		
		/**
			Create a word from a stem.
			
			@param stem_string
				The stem string from which to create a word.
			
			@return The created word.
		*/
		std::u32string create(const std::u32string& stem_string);
		
		
		/**
			Get the replacements.
			
			@return The replacements.
		*/
		const std::vector<std::shared_ptr<Replace>>& get_replacements() const;
		
		
		/**
			Set the replacements.
			
			@param replacements
		*/
		void set_replacements(const std::vector<std::shared_ptr<Replace>>&);
		
	private:
		std::vector<std::shared_ptr<Replace>> replacements;
	};
}

#endif // GENLING_WORD_HPP_INCLUDED
