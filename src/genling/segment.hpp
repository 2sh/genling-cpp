#ifndef GENLING_SEGMENT_HPP_INCLUDED
#define GENLING_SEGMENT_HPP_INCLUDED

#include <string>
#include <vector>
#include <random>

#include "phoneme.hpp"

namespace genling
{
	/**
		A segment within a syllable.
	*/
	class Segment
	{
	public:
		/**
			Constructor for Segment.
			
			@param phonemes
				The possible phonemes from which to generate a syllable
				segment.
			@param prefix
				The string added to the front of a generated segment.
			@param suffix
				The string added at the end of a generated segment.
		*/
		Segment(const std::vector<Phoneme>& phonemes,
			const std::u32string& prefix = U"",
			const std::u32string& suffix = U"");
		
		/**
			Copy constructor for Segment.
			
			@param o
				The Segment to copy.
		*/
		Segment(const Segment& o);
		
		/**
			Generate a segment by choosing one of its phonemes.
			
			Usually only called by the Syllable object.
	
			@return The generated segment.
		*/
		std::u32string generate();
		
		
		/**
			Get the phonemes.
			
			@return The phonemes.
		*/
		const std::vector<Phoneme>& get_phonemes() const;
		
		/**
			Get the prefix.
			
			@return The prefix.
		*/
		const std::u32string& get_prefix() const;
		
		/**
			Get the suffix.
			
			@return The suffix.
		*/
		const std::u32string& get_suffix() const;
		
		
		/**
			Set the phonemes.
			
			@param phonemes
		*/
		void set_phonemes(const std::vector<Phoneme>& phonemes);
		
		/**
			Set the prefix.
			
			@param prefix
		*/
		void set_prefix(const std::u32string& prefix);
		
		/**
			Set the suffix.
			
			@param suffix
		*/
		void set_suffix(const std::u32string& suffix);
	
	private:
		std::vector<Phoneme> phonemes;
		std::u32string prefix;
		std::u32string suffix;
		
		std::mt19937 rng;
		std::discrete_distribution<unsigned int> weight_distribution;
	};
}

#endif // GENLING_SEGMENT_HPP_INCLUDED
