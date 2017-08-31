#ifndef GENLING_SEGMENT_HPP_INCLUDED
#define GENLING_SEGMENT_HPP_INCLUDED

#include <string>
#include <vector>
#include <random>

#include "phoneme.hpp"

namespace genling
{
	class Segment
	{
		private:
			std::vector<Phoneme> phonemes;
			std::wstring prefix;
			std::wstring suffix;
			
			std::mt19937 rng;
			std::discrete_distribution<int> weight_distribution;
		public:
			Segment(std::vector<Phoneme> phonemes,
				std::wstring prefix = L"", std::wstring suffix = L"");
			
			std::wstring generate();
			
			std::vector<Phoneme> get_phonemes();
			std::wstring get_prefix();
			std::wstring get_suffix();
			
			void set_phonemes(std::vector<Phoneme> phonemes);
			void set_prefix(std::wstring prefix);
			void set_suffix(std::wstring suffix);
	};
}

#endif // GENLING_SEGMENT_HPP_INCLUDED
