#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator> 
#include <cctype>
#include <ctype.h>

#include "SpellCheck.h"

using namespace std;

#ifdef TEST_SPELL_CHECK

// Driver
int main()
{	
	SpellCheck sc;

	/* --------------------------------------------------------------------------*/
	ifstream file1("../dictionary.txt");

	string str1;

	vector<string> elems1;

	while (getline(file1, str1))
	{
		sc.split(str1, ' ', elems1);
	}

	// Read dictionary into the Trie of Spell Checker
	TrieNode* root = sc.readDictInTrie(elems1);

	/* --------------------------------------------------------------------------*/

	ifstream file2("../TobeSpellChecked.txt");

	string str2;

	vector<string> elems2;

	while (getline(file2, str2))
	{	
		sc.removePunct(str2);
		sc.split(str2, ' ', elems2);
	}

	cout << "\n\n";

	sc.toLowerCase(elems2);

	for (string str4 : elems2)
		cout << str4 << "  ";    
	
	sc.checkSpell(elems2 , root);

	sc.displayMisspelledWords();

	cout << "\n\n";

	return 0;
}



#endif