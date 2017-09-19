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
		Replace(const std::u32string& pattern,
			const std::u32string& repl, float probability = 1.0);
		
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
		std::u32string apply(const std::u32string& string);
		
		
		/**
			Get the pattern.
			
			@return The pattern.
		*/
		const std::u32string& get_pattern() const;
		
		/**
			Get the replacement string.
			
			@return The replacement string.
		*/
		const std::u32string& get_repl() const;
		
		/**
			Get the probability.
			
			@return The probability.
		*/
		float get_probability() const;
	
	protected:
		/**
			Overloadable replace method.
			
			This method can be overloaded to define an alternative
			implementation of replacing the pattern within an input string.
			
			@param string
				The string to replace.
		*/
		virtual std::u32string replace(std::u32string string);
	
	private:
		std::u32string pattern;
		std::u32string repl;
		float probability;
		
		std::mt19937 rng;
		std::uniform_real_distribution<float> distribution;
	};
	
	/**
		A checker for replacing a matching regex pattern within strings.
	*/
	class RegexReplace: public Replace
	{
	public:
		RegexReplace(const std::u32string& pattern,
			const std::u32string& repl, float probability = 1.0);
		
	protected:
		std::u32string replace(std::u32string string);
		
	private:
		std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> u32cvt;
		std::string u8repl;
		boost::u32regex rgx;
	};
}
#endif // GENLING_REPLACE_HPP_INCLUDED
