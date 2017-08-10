#ifndef GENLING_PHONEME_HPP_INCLUDED
#define GENLING_PHONEME_HPP_INCLUDED

#include <string>

namespace genling
{
	class Phoneme
	{
		private:
			std::string grapheme;
			int weight;
		
		public:
			Phoneme(std::string grapheme, int weight = 1);
			
			std::string get_grapheme();
			int get_weight();
			
			void set_grapheme(std::string grapheme);
			void set_weight(int weight);
	};
}

#endif // GENLING_PHONEME_HPP_INCLUDED
