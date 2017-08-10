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
			std::string prefix;
			std::string suffix;
			
			std::default_random_engine generator;
			std::discrete_distribution<int> weight_distribution;
		public:
			Segment(std::vector<Phoneme> phonemes,
				std::string prefix = "", std::string suffix = "");
			
			std::string generate();
			
			std::vector<Phoneme> get_phonemes();
			std::string get_prefix();
			std::string get_suffix();
			
			void set_phonemes(std::vector<Phoneme> phonemes);
			void set_prefix(std::string prefix);
			void set_suffix(std::string suffix);
	};
}

#endif // GENLING_SEGMENT_HPP_INCLUDED
