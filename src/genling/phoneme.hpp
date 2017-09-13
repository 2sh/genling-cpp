#ifndef GENLING_PHONEME_HPP_INCLUDED
#define GENLING_PHONEME_HPP_INCLUDED

#include <string>

namespace genling
{
	/**
		The phoneme of a segment.
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
		Phoneme(std::u32string grapheme, int weight = 1);
		
		
		/**
			Get the grapheme.
			
			@return The grapheme.
		*/
		std::u32string get_grapheme();
		
		/**
			Get the weight.
			
			@return The weight.
		*/
		int get_weight();
		
		
		/**
			Set the grapheme.
			
			@param grapheme
		*/
		void set_grapheme(std::u32string grapheme);
		
		/**
			Set the weight.
			
			@param weight
		*/
		void set_weight(int weight);
		
	private:
		std::u32string grapheme;
		int weight;
	};
}

#endif // GENLING_PHONEME_HPP_INCLUDED
