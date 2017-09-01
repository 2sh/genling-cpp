#ifndef GENLING_STEM_HPP_INCLUDED
#define GENLING_STEM_HPP_INCLUDED

#include <string>
#include <vector>
#include <random>

#include "syllable.hpp"
#include "filter.hpp"

namespace genling
{
	class Stem
	{
		private:
			std::vector<Syllable> syllables;
			std::vector<int> balance;
			std::vector<std::shared_ptr<genling::Filter>> filters;
			std::u32string prefix;
			std::u32string suffix;
			std::u32string infix;
			
			std::mt19937 rng;
			std::discrete_distribution<int> balance_distribution;
			
			std::u32string generate_unfiltered();
			
		public:
			Stem(std::vector<Syllable> syllables, std::vector<int> balance,
				std::vector<std::shared_ptr<genling::Filter>> filters,
				std::u32string prefix = U"", std::u32string suffix = U"",
				std::u32string infix = U"");
			Stem(const Stem& o);
			
			std::u32string generate();
			
			std::vector<Syllable> get_syllables();
			std::vector<int> get_balance();
			std::vector<std::shared_ptr<genling::Filter>> get_filters();
			std::u32string get_prefix();
			std::u32string get_suffix();
			std::u32string get_infix();
			
			void set_syllables(std::vector<Syllable> syllables);
			void set_balance(std::vector<int> balance);
			void set_filters(std::vector<std::shared_ptr<genling::Filter>> filters);
			void set_prefix(std::u32string prefix);
			void set_suffix(std::u32string suffix);
			void set_infix(std::u32string infix);
	};
}
#endif // GENLING_STEM_HPP_INCLUDED
