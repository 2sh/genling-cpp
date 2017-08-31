#ifndef GENLING_REPLACE_HPP_INCLUDED
#define GENLING_REPLACE_HPP_INCLUDED

#include <string>
#include <random>
#include <boost/regex/icu.hpp>
#include <codecvt>
#include <locale>

namespace genling
{
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
			Replace(std::u32string pattern, std::u32string repl,
				float probability = 1.0);
			
			std::u32string apply(std::u32string string);
			
			std::u32string get_pattern();
			std::u32string get_repl();
			float get_probability();
	};
	
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
