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
			std::string pattern;
			float probability;
			bool permit;
			
			std::mt19937 rng;
			std::uniform_real_distribution<float> distribution;
		
		protected:
			virtual bool match(std::string string);
		
		public:
			Filter(std::string pattern,
				float probability = 1.0, bool permit = false);
		
			bool is_permitted(std::string string);
			bool is_rejected(std::string string);
			
			std::string get_pattern();
			float get_probability();
			bool get_permit();
	};
	
	class RegexFilter: public Filter
	{
		private:
			std::regex rgx;
		
		protected:
			bool match(std::string string);
		
		public:
			RegexFilter(std::string pattern,
				float probability = 1.0, bool permit = false);
	};
}
#endif // GENLING_FILTER_HPP_INCLUDED
