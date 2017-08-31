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
			std::wstring prefix;
			std::wstring suffix;
			std::wstring infix;
		
		public:
			Syllable(std::vector<Segment> segments,
				int position = 0, int weight = 1,
				std::wstring prefix = L"", std::wstring suffix = L"",
				std::wstring infix = L"");
			
			bool is_permitted_position(int i, int length);
			std::wstring generate();
			
			std::vector<Segment> get_segments();
			int get_position();
			int get_weight();
			std::wstring get_prefix();
			std::wstring get_suffix();
			std::wstring get_infix();
			
			void set_segments(std::vector<Segment> segments);
			void set_position(int position);
			void set_weight(int weight);
			void set_prefix(std::wstring prefix);
			void set_suffix(std::wstring suffix);
			void set_infix(std::wstring infix);
	};
}

#endif // GENLING_SYLLABLE_HPP_INCLUDED
