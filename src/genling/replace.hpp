#ifndef GENLING_REPLACE_HPP_INCLUDED
#define GENLING_REPLACE_HPP_INCLUDED

#include <string>
#include <random>
#include <boost/regex/icu.hpp>
#include <codecvt>
#include <locale>

namespace genling
{
	/**
		A checker for replacing a matching string within strings.
	*/
	class Replace
	{
		private:
			std::u32string pattern;
			std::u32string repl;
			float probability;
			
			std::mt19937 rng;
			std::uniform_real_distribution<float> distribution;
		
		protected:
			virtual std::u32string replace(std::u32string string);
			
		public:
			/**
				Constructor for Replace.
				
				@param pattern
					The pattern to match.
				@param repl
					The replacement string.
				@param probability
					The probability that the matched string is replaced.
			*/
			Replace(std::u32string pattern, std::u32string repl,
				float probability = 1.0);
			
			/**
				Copy constructor for Replace.
				
				@param o
					The Replace to copy.
			*/
			Replace(const Replace& o);
			
			/**
				Replace the matching parts of the string.
				
				@param string
					The string to check.
				
				@return The replaced string.
			*/
			std::u32string apply(std::u32string string);
			
			
			/**
				Get the pattern.
				
				@return The pattern.
			*/
			std::u32string get_pattern();
			
			/**
				Get the replacement string.
				
				@return The replacement string.
			*/
			std::u32string get_repl();
			
			/**
				Get the probability.
				
				@return The probability.
			*/
			float get_probability();
	};
	
	/**
		A checker for replacing a matching regex pattern within strings.
	*/
	class RegexReplace: public Replace
	{
		private:
			std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> u32cvt;
			std::string u8repl;
			boost::u32regex rgx;

		protected:
			std::u32string replace(std::u32string string);
		
		public:
			RegexReplace(std::u32string pattern, std::u32string repl,
				float probability = 1.0);
	};
}
#endif // GENLING_REPLACE_HPP_INCLUDED
