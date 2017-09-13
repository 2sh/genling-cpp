#ifndef GENLING_SYLLABLE_HPP_INCLUDED
#define GENLING_SYLLABLE_HPP_INCLUDED

#include <string>
#include <vector>

#include "segment.hpp"

namespace genling
{
	/**
		The syllable within a stem.
	*/
	class Syllable
	{
	public:
		/**
			Constructor for Syllable.
			
			@param segments
				The segments of the syllable.
			@param position
				The position of the syllable with a stem.
			@param weight
				The likelihood of being chosen as a syllable in a stem.
			@param prefix
				The preceding string.
			@param suffix
				The following string.
			@param infix
				The string between the segments.
		*/
		Syllable(std::vector<Segment> segments,
			int position = 0, int weight = 1,
			std::u32string prefix = U"", std::u32string suffix = U"",
			std::u32string infix = U"");
		
		/**
			Check if this syllable is permitted in the stem's position.
			
			@param i
				The position within the stem.
			@param length
				The number of syllables with the stem.
			
			@return If this syllable is permitted.
		*/
		bool is_permitted_position(int i, int length);
		
		/**
			Generate a syllable by its segments.
			
			@return The generated syllable.
		*/
		std::u32string generate();
		
		
		/**
			Get the segments.
			
			@return The segments.
		*/
		std::vector<Segment> get_segments();
		
		/**
			Get the position.
			
			@return The position.
		*/
		int get_position();
		
		/**
			Get the weight.
			
			@return The weight.
		*/
		int get_weight();
		
		/**
			Get the prefix.
			
			@return The prefix.
		*/
		std::u32string get_prefix();
		
		/**
			Get the suffix.
			
			@return The suffix.
		*/
		std::u32string get_suffix();
		
		/**
			Get the infix.
			
			@return The infix.
		*/
		std::u32string get_infix();
		
		
		/**
			Set the segments.
			
			@param segments
		*/
		void set_segments(std::vector<Segment> segments);
		
		/**
			Set the position.
			
			@param position
		*/
		void set_position(int position);
		
		/**
			Set the weight.
			
			@param weight
		*/
		void set_weight(int weight);
		
		/**
			Set the prefix.
			
			@param prefix
		*/
		void set_prefix(std::u32string prefix);
		
		/**
			Set the suffix.
			
			@param suffix
		*/
		void set_suffix(std::u32string suffix);
		
		/**
			Set the infix.
			
			@param infix
		*/
		void set_infix(std::u32string infix);
	
	private:
		std::vector<Segment> segments;
		int position;
		int weight;
		std::u32string prefix;
		std::u32string suffix;
		std::u32string infix;
	};
}

#endif // GENLING_SYLLABLE_HPP_INCLUDED
