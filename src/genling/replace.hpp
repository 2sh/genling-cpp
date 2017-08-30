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
			std::string pattern;
			std::string repl;
			float probability;
			
			std::mt19937 rng;
			std::uniform_real_distribution<float> distribution;
		
		protected:
			virtual std::string replace(std::string string);
			
		public:
			Replace(std::string pattern, std::string repl,
				float probability = 1.0);
			
			std::string apply(std::string string);
			
			std::string get_pattern();
			std::string get_repl();
			float get_probability();
	};
	
	class RegexReplace: public Replace
	{
		private:
			std::regex rgx;
		
		protected:
			std::string replace(std::string string);
		
		public:
			RegexReplace(std::string pattern, std::string repl,
				float probability = 1.0);
	};
}
#endif // GENLING_REPLACE_HPP_INCLUDED
