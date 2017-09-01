#ifndef GENLING_FILTER_HPP_INCLUDED
#define GENLING_FILTER_HPP_INCLUDED

#include <string>
#include <random>
#include <boost/regex/icu.hpp>
#include <codecvt>
#include <locale>

namespace genling
{
	class Filter
	{
		private:
			std::u32string pattern;
			float probability;
			bool permit;
			
			std::mt19937 rng;
			std::uniform_real_distribution<float> distribution;
		
		protected:
			virtual bool match(std::u32string string);
		
		public:
			Filter(std::u32string pattern,
				float probability = 1.0, bool permit = false);
			Filter(const Filter& o);
		
			bool is_permitted(std::u32string string);
			bool is_rejected(std::u32string string);
			
			std::u32string get_pattern();
			float get_probability();
			bool is_permit();
	};
	
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
