#ifndef GENLING_FILTER_HPP_INCLUDED
#define GENLING_FILTER_HPP_INCLUDED

#include <string>
#include <random>
#include <boost/regex/icu.hpp>
#include <codecvt>
#include <locale>

namespace genling
{
	/**
		A filter to permit or reject strings containing a string.
	*/
	class Filter
	{
		private:
			std::u32string pattern;
			float probability;
			bool permit;
			
			std::mt19937 rng;
			std::uniform_real_distribution<float> distribution;
		
		protected:
			/**
				Overloadable match method.
				
				This method can be overloaded to define an alternative
				implementation of matching the pattern within an input string.
				
				@param string
					The string to check.
			*/
			virtual bool match(std::u32string string);
		
		public:
			/**
				Constructor for Filter.
			
				@param pattern
					The pattern to match.
				@param probability
					The probability that this filter takes effect.
				@param permit
					If this filter should permit instead of reject.
			*/
			Filter(std::u32string pattern,
				float probability = 1.0, bool permit = false);
			
			/**
				Copy constructor for Filter.
				
				@param o
					The Filter to copy.
			*/
			Filter(const Filter& o);
			
			/**
				Check if the string is permitted.
				
				@param string
					The string to check.
				
				@return If the string is permitted.
			*/
			bool is_permitted(std::u32string string);
			
			/**
				Check if the string is rejected.
				
				@param string
					The string to check.
				
				@return If the string is rejected.
			*/
			bool is_rejected(std::u32string string);
			
			
			/**
				Get the pattern.
				
				@return The pattern.
			*/
			std::u32string get_pattern();
			
			/**
				Get the probability.
				
				@return The probability.
			*/
			float get_probability();
			
			/**
				Does the filter permit or reject.
				
				@return If is permit.
			*/
			bool is_permit();
	};
	
	/**
		A filter to permit or reject strings matching a regex pattern.
	*/
	class RegexFilter: public Filter
	{
		private:
			boost::u32regex rgx;
			std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> u32cvt;
			
		protected:
			bool match(std::u32string string);
		
		public:
			RegexFilter(std::u32string pattern,
				float probability = 1.0, bool permit = false);
	};
}
#endif // GENLING_FILTER_HPP_INCLUDED
