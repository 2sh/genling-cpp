#ifndef GENLING_FILTER_HPP_INCLUDED
#define GENLING_FILTER_HPP_INCLUDED

#include <string>
#include <regex>
#include <random>

namespace genling
{
	class Filter
	{
		private:
			std::wstring pattern;
			float probability;
			bool permit;
			
			std::mt19937 rng;
			std::uniform_real_distribution<float> distribution;
		
		protected:
			virtual bool match(std::wstring string);
		
		public:
			Filter(std::wstring pattern,
				float probability = 1.0, bool permit = false);
		
			bool is_permitted(std::wstring string);
			bool is_rejected(std::wstring string);
			
			std::wstring get_pattern();
			float get_probability();
			bool get_permit();
	};
	
	class RegexFilter: public Filter
	{
		private:
			std::wregex rgx;
		
		protected:
			bool match(std::wstring string);
		
		public:
			RegexFilter(std::wstring pattern,
				float probability = 1.0, bool permit = false);
	};
}
#endif // GENLING_FILTER_HPP_INCLUDED
