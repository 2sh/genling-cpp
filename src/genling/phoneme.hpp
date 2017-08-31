#ifndef GENLING_PHONEME_HPP_INCLUDED
#define GENLING_PHONEME_HPP_INCLUDED

#include <string>

namespace genling
{
	class Phoneme
	{
		private:
			std::wstring grapheme;
			int weight;
		
		public:
			Phoneme(std::wstring grapheme, int weight = 1);
			
			std::wstring get_grapheme();
			int get_weight();
			
			void set_grapheme(std::wstring grapheme);
			void set_weight(int weight);
	};
}

#endif // GENLING_PHONEME_HPP_INCLUDED
