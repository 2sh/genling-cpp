#include <iostream>
#include <vector>
#include <cstdlib>

#include "genling/lib.hpp"

struct GenLang
{
	genling::Stem stem;
	std::vector<std::shared_ptr<genling::Replace>> script_rules;
};

GenLang conlang()
{
	std::vector<genling::Syllable> syllables;
	std::vector<genling::Segment> segments;
	std::vector<genling::Phoneme> phonemes;
	
	// First syllable of stem
	
	// Initial
	phonemes =
	{
		{U"_", 10},
		{U"j", 1},
		{U"h", 1},
		{U"c", 1} // C
	};
	segments.push_back({phonemes});
	
	// Medial
	phonemes =
	{
		{U"_", 20},

		{U"t", 5},  // t
		{U"tc", 2}, // t_hC
		{U"th", 5}, // t_h
		{U"tj", 2}, // t_h_j

		{U"d", 6},  // d
		{U"dj", 2}, // d_j

		{U"k", 5},
		{U"kc", 2},
		{U"kh", 4},
		{U"kj", 2},
		{U"kT", 4}, // k_hT

		{U"g", 6},
		{U"gc", 2},
		{U"gj", 3},

		{U"f", 5},
		{U"fc", 2},
		{U"fh", 3},
		{U"fj", 3},

		{U"v", 3},
		{U"vj", 1},

		{U"p", 4},
		{U"pc", 2}, // p_hC
		{U"ph", 2}, // p_h
		{U"pj", 1}, // p\j
		{U"pf", 1}, // p\f

		{U"b", 6},
		{U"bj", 2},

		{U"h", 5},

		{U"s", 5},  // S
		{U"sh", 4}, // S_h
		{U"sj", 1}, // S_h_j
		{U"st", 2},
		{U"sk", 2},
		{U"sf", 2},
		{U"sp", 1},
		{U"sn", 3},
		{U"sm", 4},

		{U"T", 4},  // T
		{U"Tj", 2}, // T_j

		{U"D", 5},  // D
		{U"Dj", 2}, // D_j

		{U"l", 7},
		{U"lc", 6}, // K
		{U"lh", 4},
		{U"lj", 4},

		{U"n", 6},
		{U"nh", 5},
		{U"nj", 3},

		{U"m", 4},
		{U"my", 2},

		{U"j", 5},  // j

		{U"r", 2},  // 4
		{U"rh", 3},
		{U"rj", 3}
	};
	segments.push_back({phonemes});
	
	// Nucleus
	phonemes =
	{
		{U"a", 5},  // a
		{U"A", 3},  // @
		{U"i", 4},  // I
		{U"ie", 2}, // i
		{U"u", 4},  // U
		{U"e", 3},  // E
		{U"o", 3},  // O
		{U"ea", 2}, // Ea
		{U"oe", 2}, // 9
		{U"y", 2}  // Y
	};
	segments.push_back({phonemes});

	// Coda
	phonemes =
	{
		{U"_", 22},

		{U"n", 6},
		{U"l", 4},
		{U"x", 6}, // repeater
		{U"c", 1},
		{U"h", 2},
		{U"r", 3}
	};
	segments.push_back({phonemes});
	
	syllables.push_back({segments, 1});
	
	segments = {};
	// Second syllable of stem

	// Initial
	phonemes =
	{
		{U"t", 4},
		{U"tj", 2},

		{U"d", 5},
		{U"dj", 1},

		{U"k", 4},
		{U"kj", 3},

		{U"g", 6},
		{U"gj", 1},

		{U"f", 4},
		{U"fj", 2},

		{U"p", 4},
		{U"pj", 1},

		{U"b", 4},
		{U"bj", 1},

		{U"s", 5},
		{U"sj", 2},

		{U"T", 4},
		{U"Tj", 1},

		{U"D", 3},
		{U"Dj", 1},

		{U"l", 7},
		{U"lc", 2},
		{U"lj", 3},

		{U"n", 8},
		{U"nj", 3},

		{U"m", 6},
		{U"mj", 3},

		{U"j", 3},

		{U"r", 2},
		{U"rj", 1}
	};
	segments.push_back({phonemes});

	// Nucleus
	phonemes =
	{
		{U"a", 5},
		{U"A", 5},
		{U"e", 3},
		{U"o", 3}
	};
	segments.push_back({phonemes});
	
	syllables.push_back({segments, 2});
	
	std::vector<std::shared_ptr<genling::Filter>> filters =
	{
		std::make_shared<genling::Filter>(U"x>"),
		std::make_shared<genling::Filter>(U"h>"),
		std::make_shared<genling::Filter>(U"c>"),

		std::make_shared<genling::Filter>(U"n#m"),

		std::make_shared<genling::Filter>(U"cs"),

		std::make_shared<genling::Filter>(U"l#l"),
		std::make_shared<genling::Filter>(U"r#r"),
		std::make_shared<genling::Filter>(U"l#r"),
		std::make_shared<genling::Filter>(U"x#r"),

		std::make_shared<genling::RegexFilter>(U"<._")
		// Stem starting with an initial
	};
	
	std::vector<int> syllable_balance = {5, 2};
	
	std::vector<std::shared_ptr<genling::Replace>> script_rules =
	{
		std::make_shared<genling::Replace>(U"_", U""),

		std::make_shared<genling::Replace>(U"A", U"ı"),
		std::make_shared<genling::Replace>(U"oe", U"ø"),

		std::make_shared<genling::Replace>(U"T", U"þ"),
		std::make_shared<genling::Replace>(U"D", U"ð"),

		std::make_shared<genling::RegexReplace>(U"x#(.)", U"$1$1"),

		std::make_shared<genling::Replace>(U"<", U""),
		std::make_shared<genling::Replace>(U"#", U""),
		std::make_shared<genling::Replace>(U">", U"")
	};
	
	return {
		{syllables, syllable_balance, filters, U"<", U">", U"#"},
		script_rules
	};
}

int main(int argc, char* argv[])
{
	int word_count = 100;
	if(argc > 1)
		word_count = strtoul(argv[1], nullptr, 10);
	
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> u32cvt;
	
	GenLang lang = conlang();
	
	std::u32string output;
	for(int i=0; i<word_count; i++)
	{
		if(i>0) std::cout << std::endl;
		
		output = lang.stem.generate();
		std::cout << u32cvt.to_bytes(output) << " ";
		for(auto rule : lang.script_rules)
		{
			output = rule->apply(output);
		}
		std::cout << u32cvt.to_bytes(output);
	}
	std::cout << std::endl;
	return 0;
}
