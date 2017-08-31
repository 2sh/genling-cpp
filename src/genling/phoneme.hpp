#ifndef GENLING_PHONEME_HPP_INCLUDED
#define GENLING_PHONEME_HPP_INCLUDED

#include <string>

namespace genling
{
	class Phoneme
	{
		private:
			std::u32string grapheme;
			int weight;
		
		public:
			Phoneme(std::u32string grapheme, int weight = 1);
			
			std::u32string get_grapheme();
			int get_weight();
			
			void set_grapheme(std::u32string grapheme);
			void set_weight(int weight);
	};
}

#endif // GENLING_PHONEME_HPP_INCLUDED
