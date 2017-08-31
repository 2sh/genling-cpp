#ifndef GENLING_SYLLABLE_HPP_INCLUDED
#define GENLING_SYLLABLE_HPP_INCLUDED

#include <string>
#include <vector>

#include "segment.hpp"

namespace genling
{
	class Syllable
	{
		private:
			std::vector<Segment> segments;
			int position;
			int weight;
			std::u32string prefix;
			std::u32string suffix;
			std::u32string infix;
		
		public:
			Syllable(std::vector<Segment> segments,
				int position = 0, int weight = 1,
				std::u32string prefix = U"", std::u32string suffix = U"",
				std::u32string infix = U"");
			
			bool is_permitted_position(int i, int length);
			std::u32string generate();
			
			std::vector<Segment> get_segments();
			int get_position();
			int get_weight();
			std::u32string get_prefix();
			std::u32string get_suffix();
			std::u32string get_infix();
			
			void set_segments(std::vector<Segment> segments);
			void set_position(int position);
			void set_weight(int weight);
			void set_prefix(std::u32string prefix);
			void set_suffix(std::u32string suffix);
			void set_infix(std::u32string infix);
	};
}

#endif // GENLING_SYLLABLE_HPP_INCLUDED
