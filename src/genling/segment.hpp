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
			std::u32string prefix;
			std::u32string suffix;
			
			std::mt19937 rng;
			std::discrete_distribution<int> weight_distribution;
		public:
			Segment(std::vector<Phoneme> phonemes,
				std::u32string prefix = U"", std::u32string suffix = U"");
			Segment(const Segment& o);
			
			std::u32string generate();
			
			std::vector<Phoneme> get_phonemes();
			std::u32string get_prefix();
			std::u32string get_suffix();
			
			void set_phonemes(std::vector<Phoneme> phonemes);
			void set_prefix(std::u32string prefix);
			void set_suffix(std::u32string suffix);
	};
}

#endif // GENLING_SEGMENT_HPP_INCLUDED
