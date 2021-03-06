#ifndef GENLING_STEM_HPP_INCLUDED
#define GENLING_STEM_HPP_INCLUDED

#include <string>
#include <vector>
#include <random>
#include <memory>

#include "syllable.hpp"
#include "filter.hpp"

namespace genling
{
	/**
		The stem of a word.
	*/
	class Stem
	{
	public:
		/**
			Constructor for Stem.
			
			@param syllables
				The possible syllables from which to generate a word stem.
			@param balance
				The balance of the amount of syllables in the generated stem.
			@param filters
				The filters for permitting or rejecting stems. The stem string
				to be filtered includes the Stem object prefix, suffix and
				infixes.
			@param prefix
				The string added to the front of a generated stem.
			@param suffix
				The string added at the end of a generated stem.
			@param infix
				The string inserted between generated syllables.
		*/
		Stem(const std::vector<Syllable>& syllables,
			const std::vector<unsigned int>& balance,
			const std::vector<std::shared_ptr<Filter>>& filters,
			const std::u32string& prefix = U"",
			const std::u32string& suffix = U"",
			const std::u32string& infix = U"");
		
		/**
			Copy constructor for Stem.
			
			@param o
				The Stem to copy.
		*/
		Stem(const Stem& o);
		
		/**
			Generate a stem by its syllables.
			
			@return The generated stem.
		*/
		std::u32string generate();
		
		
		/**
			Get the syllables.
			
			@return The syllables.
		*/
		const std::vector<Syllable>& get_syllables() const;
		
		/**
			Get the balance.
			
			@return The balance.
		*/
		const std::vector<unsigned int>& get_balance() const;
		
		/**
			Get the filters.
			
			@return The filters.
		*/
		const std::vector<std::shared_ptr<Filter>>& get_filters() const;
		
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
			Set the syllables.
			
			@param syllables
		*/
		void set_syllables(const std::vector<Syllable>& syllables);
		
		/**
			Set the balance.
			
			@param balance
		*/
		void set_balance(const std::vector<unsigned int>& balance);
		
		/**
			Set the filters.
			
			@param filters
		*/
		void set_filters(
			const std::vector<std::shared_ptr<Filter>>& filters);
		
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
		std::vector<Syllable> syllables;
		std::vector<unsigned int> balance;
		std::vector<std::shared_ptr<Filter>> filters;
		std::u32string prefix;
		std::u32string suffix;
		std::u32string infix;
		
		std::mt19937 rng;
		std::discrete_distribution<unsigned int> balance_distribution;
		
		/**
			Generate an unfiltered stem by its syllables.
			
			@return The generated unfiltered stem.
		*/
		std::u32string generate_unfiltered();
	};
}
#endif // GENLING_STEM_HPP_INCLUDED
