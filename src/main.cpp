#include <iostream>
#include <vector>
#include <cstdlib>

#include "genling/lib.hpp"

struct GenLang
{
	genling::Stem stem;
	std::vector<genling::Replace> script_rules;
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
		{"_", 10},
		{"j", 1},
		{"h", 1},
		{"c", 1} // C
	};
	segments.push_back({phonemes});
	
	// Medial
	phonemes =
	{
		{"_", 20},

		{"t", 5},  // t
		{"tc", 2}, // t_hC
		{"th", 5}, // t_h
		{"tj", 2}, // t_h_j

		{"d", 6},  // d
		{"dj", 2}, // d_j

		{"k", 5},
		{"kc", 2},
		{"kh", 4},
		{"kj", 2},
		{"kT", 4}, // k_hT

		{"g", 6},
		{"gc", 2},
		{"gj", 3},

		{"f", 5},
		{"fc", 2},
		{"fh", 3},
		{"fj", 3},

		{"v", 3},
		{"vj", 1},

		{"p", 4},
		{"pc", 2}, // p_hC
		{"ph", 2}, // p_h
		{"pj", 1}, // p\j
		{"pf", 1}, // p\f

		{"b", 6},
		{"bj", 2},

		{"h", 5},

		{"s", 5},  // S
		{"sh", 4}, // S_h
		{"sj", 1}, // S_h_j
		{"st", 2},
		{"sk", 2},
		{"sf", 2},
		{"sp", 1},
		{"sn", 3},
		{"sm", 4},

		{"T", 4},  // T
		{"Tj", 2}, // T_j

		{"D", 5},  // D
		{"Dj", 2}, // D_j

		{"l", 7},
		{"lc", 6}, // K
		{"lh", 4},
		{"lj", 4},

		{"n", 6},
		{"nh", 5},
		{"nj", 3},

		{"m", 4},
		{"my", 2},

		{"j", 5},  // j

		{"r", 2},  // 4
		{"rh", 3},
		{"rj", 3}
	};
	segments.push_back({phonemes});
	
	// Nucleus
	phonemes =
	{
		{"a", 5},  // a
		{"A", 3},  // @
		{"i", 4},  // I
		{"ie", 2}, // i
		{"u", 4},  // U
		{"e", 3},  // E
		{"o", 3},  // O
		{"ea", 2}, // Ea
		{"oe", 2}, // 9
		{"y", 2}  // Y
	};
	segments.push_back({phonemes});

	// Coda
	phonemes =
	{
		{"_", 22},

		{"n", 6},
		{"l", 4},
		{"x", 6}, // repeater
		{"c", 1},
		{"h", 2},
		{"r", 3}
	};
	segments.push_back({phonemes});
	
	syllables.push_back({segments, 1});
	
	segments = {};
	// Second syllable of stem

	// Initial
	phonemes =
	{
		{"t", 4},
		{"tj", 2},

		{"d", 5},
		{"dj", 1},

		{"k", 4},
		{"kj", 3},

		{"g", 6},
		{"gj", 1},

		{"f", 4},
		{"fj", 2},

		{"p", 4},
		{"pj", 1},

		{"b", 4},
		{"bj", 1},

		{"s", 5},
		{"sj", 2},

		{"T", 4},
		{"Tj", 1},

		{"D", 3},
		{"Dj", 1},

		{"l", 7},
		{"lc", 2},
		{"lj", 3},

		{"n", 8},
		{"nj", 3},

		{"m", 6},
		{"mj", 3},

		{"j", 3},

		{"r", 2},
		{"rj", 1}
	};
	segments.push_back({phonemes});

	// Nucleus
	phonemes =
	{
		{"a", 5},
		{"A", 5},
		{"e", 3},
		{"o", 3}
	};
	segments.push_back({phonemes});
	
	syllables.push_back({segments, 2});
	
	std::vector<genling::Filter> filters =
	{
		{"x>"},
		{"h>"},
		{"c>"},

		{"n#m"},

		{"cs"},

		{"l#l"},
		{"r#r"},
		{"l#r"},
		{"x#r"},

		genling::RegexFilter("<._") // Stem starting with an initial
	};
	
	std::vector<int> syllable_balance = {5, 2};
	
	std::vector<genling::Replace> script_rules =
	{
		{"_", ""},

		{"A", "ı"},
		{"oe", "ø"},

		{"T", "þ"},
		{"D", "ð"},

		genling::RegexReplace("x#(.)", "\\1\\1"),

		{"<", ""},
		{"#", ""},
		{">", ""}
	};
	
	return {
		{syllables, syllable_balance, filters, "<", ">", "#"},
		script_rules
	};
}

int main(int argc, char* argv[])
{
	int word_count = 100;
	if(argc > 1)
		word_count = strtoul(argv[1], nullptr, 10);
	
	GenLang lang = conlang();
	
	std::string output;
	std::cout << "start" << std::endl;
	for(int i=0; i<word_count; i++)
	{
		if(i>0) std::cout << " ";
		
		output = lang.stem.generate();
		for(genling::Replace rule : lang.script_rules)
		{
			output = rule.apply(output);
		}
		std::cout << output;
	}
	std::cout << std::endl << "done" << std::endl;
	return 0;
}
