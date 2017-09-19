#ifndef GENLING_SYLLABLE_HPP_INCLUDED
#define GENLING_SYLLABLE_HPP_INCLUDED

#include <string>
#include <vector>

#include "segment.hpp"

namespace genling
{
	/**
		A syllable within a stem.
	*/
	class Syllable
	{
	public:
		/**
			Constructor for Syllable.
			
			@param segments
				The possible segments from which to generate a stem syllable.
			@param position
				The position of the syllable with a stem.
			@param weight
				The likelihood of being chosen as a syllable in a stem.
			@param prefix
				The string added to the front of a generated syllable.
			@param suffix
				The string added at the end of a generated syllable.
			@param infix
				The string inserted between generated segments.
		*/
		Syllable(const std::vector<Segment>& segments,
			int position = 0, unsigned int weight = 1,
			const std::u32string& prefix = U"",
			const std::u32string& suffix = U"",
			const std::u32string& infix = U"");
		
		/**
			Check if this syllable is permitted in the stem's position.
			
			Usually only called by the Stem object.
			
			@param i
				The position within the stem.
			@param length
				The number of syllables with the stem.
			
			@return If this syllable is permitted.
		*/
		bool is_permitted_position(unsigned int i, unsigned int length) const;
		
		/**
			Generate a syllable by its segments.
			
			Usually only called by the Stem object.
			
			@return The generated syllable.
		*/
		std::u32string generate();
		
		
		/**
			Get the segments.
			
			@return The segments.
		*/
		const std::vector<Segment>& get_segments() const;
		
		/**
			Get the position.
			
			@return The position.
		*/
		int get_position() const;
		
		/**
			Get the weight.
			
			@return The weight.
		*/
		unsigned int get_weight() const;
		
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
			Get the infix.
			
			@return The infix.
		*/
		const std::u32string& get_infix() const;
		
		
		/**
			Set the segments.
			
			@param segments
		*/
		void set_segments(const std::vector<Segment>& segments);
		
		/**
			Set the position.
			
			@param position
		*/
		void set_position(int position);
		
		/**
			Set the weight.
			
			@param weight
		*/
		void set_weight(unsigned int weight);
		
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
		
		/**
			Set the infix.
			
			@param infix
		*/
		void set_infix(const std::u32string& infix);
	
	private:
		std::vector<Segment> segments;
		int position;
		unsigned int weight;
		std::u32string prefix;
		std::u32string suffix;
		std::u32string infix;
	};
}

#endif // GENLING_SYLLABLE_HPP_INCLUDED
