#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator> 
#include <cctype>
#include <ctype.h>

#include "../Spell_Check/SpellCheck.h"
#include "WordSuggest.h"

using namespace std;

#ifdef TEST_WORD_SUGGEST

// Driver
int main()
{
	WordSuggest ws;

	// Read dictionary into the Trie of Spell Checker
	TrieNode* root = ws.readDictInTrie();

	/* --------------------------------------------------------------------------*/

	ifstream file2("../TobeSpellChecked.txt");

	string str2;

	vector<string> elems2;

	while (getline(file2, str2))
	{	
		ws.removePunct(str2);
		ws.split(str2, ' ', elems2);
	}

	ws.toLowerCase(elems2);

	ws.checkSpell(elems2, root);

	ws.displayMisspelledWords();

	set<string> misspelled_word = ws.getIncorrectWords();

	set<string> suggestions;

	cout << "    Suggestions:" << endl;
	cout << "    ------------" << endl;

	for (string str6 : misspelled_word)
	{	
		cout << "    " << str6 << endl;
		suggestions = ws.getSuggestions(str6, root);

		if (suggestions.size() == 0)
			cout << "         " << " No Suggestions Found !!!!"  << endl;
		for (string str : suggestions)
		{	
			cout << "      -> " << str << endl;
		}
	}
	return 0;
}

#endif