#ifndef GENLING_REPLACE_HPP_INCLUDED
#define GENLING_REPLACE_HPP_INCLUDED

#include <string>
#include <regex>
#include <random>

namespace genling
{
	class Replace
	{
		private:
			std::wstring pattern;
			std::wstring repl;
			float probability;
			
			std::mt19937 rng;
			std::uniform_real_distribution<float> distribution;
		
		protected:
			virtual std::wstring replace(std::wstring string);
			
		public:
			Replace(std::wstring pattern, std::wstring repl,
				float probability = 1.0);
			
			std::wstring apply(std::wstring string);
			
			std::wstring get_pattern();
			std::wstring get_repl();
			float get_probability();
	};
	
	class RegexReplace: public Replace
	{
		private:
			std::wregex rgx;
		
		protected:
			std::wstring replace(std::wstring string);
		
		public:
			RegexReplace(std::wstring pattern, std::wstring repl,
				float probability = 1.0);
	};
}
#endif // GENLING_REPLACE_HPP_INCLUDED
