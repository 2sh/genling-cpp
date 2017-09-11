#ifndef GENLING_SEGMENT_HPP_INCLUDED
#define GENLING_SEGMENT_HPP_INCLUDED

#include <string>
#include <vector>
#include <random>

#include "phoneme.hpp"

namespace genling
{
	/**
		The segment within a syllable.
	*/
	class Segment
	{
		private:
			std::vector<Phoneme> phonemes;
			std::u32string prefix;
			std::u32string suffix;
			
			std::mt19937 rng;
			std::discrete_distribution<int> weight_distribution;
		public:
			/**
				Constructor for Segment.
				
				@param phonemes
					The phonemes of the segment.
				@param prefix
					The preceding string.
				@param suffix
					The following string.
			*/
			Segment(std::vector<Phoneme> phonemes,
				std::u32string prefix = U"", std::u32string suffix = U"");
			
			/**
				Copy constructor for Segment.
				
				@param o
					The Segment to copy.
			*/
			Segment(const Segment& o);
			
			/**
				Generate a segment by choosing one of its phonemes.
		
				@return The generated segment.
			*/
			std::u32string generate();
			
			
			/**
				Get the phonemes.
				
				@return The phonemes.
			*/
			std::vector<Phoneme> get_phonemes();
			
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
				Set the phonemes.
				
				@param phonemes
			*/
			void set_phonemes(std::vector<Phoneme> phonemes);
			
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
	};
}

#endif // GENLING_SEGMENT_HPP_INCLUDED
