#ifndef GENLING_STEM_HPP_INCLUDED
#define GENLING_STEM_HPP_INCLUDED

#include <string>
#include <vector>

#include "syllable.hpp"
#include "filter.hpp"

namespace genling
{
	class Stem
	{
		private:
			std::vector<Syllable> syllables;
			std::vector<int> balance;
			std::vector<Filter> filters;
			std::string prefix;
			std::string suffix;
			std::string infix;
			
			std::default_random_engine generator;
			std::discrete_distribution<int> balance_distribution;
			
			std::string generate_unfiltered();
			
		public:
			Stem(std::vector<Syllable> syllables, std::vector<int> balance,
				std::vector<Filter> filters,
				std::string prefix = "", std::string suffix = "",
				std::string infix = "");
			
			std::string generate();
			
			std::vector<Syllable> get_syllables();
			std::vector<int> get_balance();
			std::vector<Filter> get_filters();
			std::string get_prefix();
			std::string get_suffix();
			std::string get_infix();
			
			void set_syllables(std::vector<Syllable> syllables);
			void set_balance(std::vector<int> balance);
			void set_filters(std::vector<Filter> filters);
			void set_prefix(std::string prefix);
			void set_suffix(std::string suffix);
			void set_infix(std::string infix);
	};
}
#endif // GENLING_STEM_HPP_INCLUDED
