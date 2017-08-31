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
			std::wstring prefix;
			std::wstring suffix;
			std::wstring infix;
			
			std::mt19937 rng;
			std::discrete_distribution<int> balance_distribution;
			
			std::wstring generate_unfiltered();
			
		public:
			Stem(std::vector<Syllable> syllables, std::vector<int> balance,
				std::vector<std::shared_ptr<genling::Filter>> filters,
				std::wstring prefix = L"", std::wstring suffix = L"",
				std::wstring infix = L"");
			
			std::wstring generate();
			
			std::vector<Syllable> get_syllables();
			std::vector<int> get_balance();
			std::vector<std::shared_ptr<genling::Filter>> get_filters();
			std::wstring get_prefix();
			std::wstring get_suffix();
			std::wstring get_infix();
			
			void set_syllables(std::vector<Syllable> syllables);
			void set_balance(std::vector<int> balance);
			void set_filters(std::vector<std::shared_ptr<genling::Filter>> filters);
			void set_prefix(std::wstring prefix);
			void set_suffix(std::wstring suffix);
			void set_infix(std::wstring infix);
	};
}
#endif // GENLING_STEM_HPP_INCLUDED
