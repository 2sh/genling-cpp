#ifndef GENLING_PHONEME_HPP_INCLUDED
#define GENLING_PHONEME_HPP_INCLUDED

#include <string>

namespace genling
{
	/**
		A phoneme of a segment.
	*/
	class Phoneme
	{
	public:
		/**
			Constructor for Phoneme.
			
			@param grapheme
				The graphical representation.
			@param weight
				The likelihood of being chosen as a segment of a syllable.
		*/
		Phoneme(const std::u32string& grapheme, unsigned int weight = 1);
		
		
		/**
			Get the grapheme.
			
			@return The grapheme.
		*/
		const std::u32string& get_grapheme() const;
		
		/**
			Get the weight.
			
			@return The weight.
		*/
		unsigned int get_weight() const;
		
		
		/**
			Set the grapheme.
			
			@param grapheme
		*/
		void set_grapheme(const std::u32string& grapheme);
		
		/**
			Set the weight.
			
			@param weight
		*/
		void set_weight(unsigned int weight);
		
	private:
		std::u32string grapheme;
		unsigned int weight;
	};
}

#endif // GENLING_PHONEME_HPP_INCLUDED
