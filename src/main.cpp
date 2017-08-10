#include <iostream>
#include <vector>
#include <cstdlib>

#include "genling/lib.hpp"

int main(int argc, char* argv[])
{
	int word_count = 100;
	if(argc > 1)
		word_count = strtoul(argv[1], nullptr, 10);
	
	std::vector<genling::Phoneme> phonemes;
	std::vector<genling::Segment> segments;
	
	phonemes.push_back(genling::Phoneme("k", 3));
	phonemes.push_back(genling::Phoneme("b"));
	phonemes.push_back(genling::Phoneme("n", 2));
	
	segments.push_back(genling::Segment(phonemes));
	phonemes.clear();
	
	phonemes.push_back(genling::Phoneme("a", 3));
	phonemes.push_back(genling::Phoneme("e"));
	phonemes.push_back(genling::Phoneme("u"));
	
	segments.push_back(genling::Segment(phonemes));
	phonemes.clear();
	
	genling::Syllable syllable(segments, 0, 1, "<", ">");
	
	std::cout << "start" << std::endl;
	for(int i=0; i<word_count; i++)
	{
		if(i>0) std::cout << " ";
		std::cout << syllable.generate();
	}
	std::cout << std::endl << "done" << std::endl;
	return 0;
}
