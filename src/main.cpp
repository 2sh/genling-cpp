#include <iostream>
#include <vector>
#include <cstdlib>
#include <codecvt>
#include <locale>

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
		{L"_", 10},
		{L"j", 1},
		{L"h", 1},
		{L"c", 1} // C
	};
	segments.push_back({phonemes});
	
	// Medial
	phonemes =
	{
		{L"_", 20},

		{L"t", 5},  // t
		{L"tc", 2}, // t_hC
		{L"th", 5}, // t_h
		{L"tj", 2}, // t_h_j

		{L"d", 6},  // d
		{L"dj", 2}, // d_j

		{L"k", 5},
		{L"kc", 2},
		{L"kh", 4},
		{L"kj", 2},
		{L"kT", 4}, // k_hT

		{L"g", 6},
		{L"gc", 2},
		{L"gj", 3},

		{L"f", 5},
		{L"fc", 2},
		{L"fh", 3},
		{L"fj", 3},

		{L"v", 3},
		{L"vj", 1},

		{L"p", 4},
		{L"pc", 2}, // p_hC
		{L"ph", 2}, // p_h
		{L"pj", 1}, // p\j
		{L"pf", 1}, // p\f

		{L"b", 6},
		{L"bj", 2},

		{L"h", 5},

		{L"s", 5},  // S
		{L"sh", 4}, // S_h
		{L"sj", 1}, // S_h_j
		{L"st", 2},
		{L"sk", 2},
		{L"sf", 2},
		{L"sp", 1},
		{L"sn", 3},
		{L"sm", 4},

		{L"T", 4},  // T
		{L"Tj", 2}, // T_j

		{L"D", 5},  // D
		{L"Dj", 2}, // D_j

		{L"l", 7},
		{L"lc", 6}, // K
		{L"lh", 4},
		{L"lj", 4},

		{L"n", 6},
		{L"nh", 5},
		{L"nj", 3},

		{L"m", 4},
		{L"my", 2},

		{L"j", 5},  // j

		{L"r", 2},  // 4
		{L"rh", 3},
		{L"rj", 3}
	};
	segments.push_back({phonemes});
	
	// Nucleus
	phonemes =
	{
		{L"a", 5},  // a
		{L"A", 3},  // @
		{L"i", 4},  // I
		{L"ie", 2}, // i
		{L"u", 4},  // U
		{L"e", 3},  // E
		{L"o", 3},  // O
		{L"ea", 2}, // Ea
		{L"oe", 2}, // 9
		{L"y", 2}  // Y
	};
	segments.push_back({phonemes});

	// Coda
	phonemes =
	{
		{L"_", 22},

		{L"n", 6},
		{L"l", 4},
		{L"x", 6}, // repeater
		{L"c", 1},
		{L"h", 2},
		{L"r", 3}
	};
	segments.push_back({phonemes});
	
	syllables.push_back({segments, 1});
	
	segments = {};
	// Second syllable of stem

	// Initial
	phonemes =
	{
		{L"t", 4},
		{L"tj", 2},

		{L"d", 5},
		{L"dj", 1},

		{L"k", 4},
		{L"kj", 3},

		{L"g", 6},
		{L"gj", 1},

		{L"f", 4},
		{L"fj", 2},

		{L"p", 4},
		{L"pj", 1},

		{L"b", 4},
		{L"bj", 1},

		{L"s", 5},
		{L"sj", 2},

		{L"T", 4},
		{L"Tj", 1},

		{L"D", 3},
		{L"Dj", 1},

		{L"l", 7},
		{L"lc", 2},
		{L"lj", 3},

		{L"n", 8},
		{L"nj", 3},

		{L"m", 6},
		{L"mj", 3},

		{L"j", 3},

		{L"r", 2},
		{L"rj", 1}
	};
	segments.push_back({phonemes});

	// Nucleus
	phonemes =
	{
		{L"a", 5},
		{L"A", 5},
		{L"e", 3},
		{L"o", 3}
	};
	segments.push_back({phonemes});
	
	syllables.push_back({segments, 2});
	
	std::vector<std::shared_ptr<genling::Filter>> filters =
	{
		std::make_shared<genling::Filter>(L"x>"),
		std::make_shared<genling::Filter>(L"h>"),
		std::make_shared<genling::Filter>(L"c>"),

		std::make_shared<genling::Filter>(L"n#m"),

		std::make_shared<genling::Filter>(L"cs"),

		std::make_shared<genling::Filter>(L"l#l"),
		std::make_shared<genling::Filter>(L"r#r"),
		std::make_shared<genling::Filter>(L"l#r"),
		std::make_shared<genling::Filter>(L"x#r"),

		std::make_shared<genling::RegexFilter>(L"<._") // Stem starting with an initial
	};
	
	std::vector<int> syllable_balance = {5, 2};
	
	std::vector<std::shared_ptr<genling::Replace>> script_rules =
	{
		std::make_shared<genling::Replace>(L"_", L""),

		std::make_shared<genling::Replace>(L"A", L"ı"),
		std::make_shared<genling::Replace>(L"oe", L"ø"),

		std::make_shared<genling::Replace>(L"T", L"þ"),
		std::make_shared<genling::Replace>(L"D", L"ð"),

		std::make_shared<genling::RegexReplace>(L"x#(.)", L"$1$1"),

		std::make_shared<genling::Replace>(L"<", L""),
		std::make_shared<genling::Replace>(L"#", L""),
		std::make_shared<genling::Replace>(L">", L"")
	};
	
	return {
		{syllables, syllable_balance, filters, L"<", L">", L"#"},
		script_rules
	};
}

int main(int argc, char* argv[])
{
	int word_count = 100;
	if(argc > 1)
		word_count = strtoul(argv[1], nullptr, 10);
	
	GenLang lang = conlang();
	
	std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
	
	std::wstring output;
	for(int i=0; i<word_count; i++)
	{
		if(i>0) std::cout << std::endl;
		
		output = lang.stem.generate();
		std::cout << utf8_conv.to_bytes(output) << " ";
		for(auto rule : lang.script_rules)
		{
			output = rule->apply(output);
		}
		std::cout << utf8_conv.to_bytes(output);
	}
	std::cout << std::endl;
	return 0;
}
