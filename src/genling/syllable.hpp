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
			std::string prefix;
			std::string suffix;
			std::string infix;
		
		public:
			Syllable(std::vector<Segment> segments,
				int position = 0, int weight = 1,
				std::string prefix = "", std::string suffix = "",
				std::string infix = "");
			
			bool is_permitted_position(int i, int length);
			std::string generate();
			
			std::vector<Segment> get_segments();
			int get_position();
			int get_weight();
			std::string get_prefix();
			std::string get_suffix();
			std::string get_infix();
			
			void set_segments(std::vector<Segment> segments);
			void set_position(int position);
			void set_weight(int weight);
			void set_prefix(std::string prefix);
			void set_suffix(std::string suffix);
			void set_infix(std::string infix);
	};
}

#endif // GENLING_SYLLABLE_HPP_INCLUDED
