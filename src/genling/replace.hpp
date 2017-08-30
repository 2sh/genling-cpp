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
			std::string replace(std::string string);
			void prepare();
			
		public:
			Replace(std::string pattern, std::string repl,
				float probability = 1.0);
			
			std::string apply(std::string string);
			
			std::string get_pattern();
			std::string get_repl();
			float get_probability();
			
			void set_pattern(std::string pattern);
			void set_repl(std::string repl);
			void set_probability(float probability);
	};
	
	class RegexReplace: public Replace
	{
		private:
			std::regex rgx;
		
		protected:
			std::string replace(std::string string);
			void prepare();
	};
}
#endif // GENLING_REPLACE_HPP_INCLUDED
