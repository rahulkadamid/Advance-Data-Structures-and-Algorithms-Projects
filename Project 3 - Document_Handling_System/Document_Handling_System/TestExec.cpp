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
#include "../Word_Suggest/WordSuggest.h"
#include "../Document_Retrieval/DocRet.h"
#include "../Auto_Complete/AutoComplete.h"

using namespace std;

#ifdef TEST_EXEC

void spell_check();
void word_suggest();
void auto_correct();
void doc_retrieval();

// Driver
int main()
{	
	cout << "\n";
	cout << "\n";
	cout << "\t\t\t\t Welcome to my Document Handling System" << endl;
	cout << "\t\t\t\t ======================================" << endl;
	
	spell_check();

	word_suggest();

	auto_correct();

	doc_retrieval();

	return 0;
}

void spell_check()
{	
	cout << "\n";
	cout << "    " << "Spell Check Feature" << endl;
	cout << "    " << "-------------------" << endl;

	SpellCheck sc;

	/* --------------------------------------------------------------------------*/
	
	cout << "    " << "Reading dictionary.txt into the Trie ...." << endl;

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
	cout << "\n";
	cout << "    " << "Reading TobeSpellChecked.txt ...." << endl;

	ifstream file2("../TobeSpellChecked.txt");

	string str2;

	vector<string> elems2;

	while (getline(file2, str2))
	{
		sc.removePunct(str2);
		sc.split(str2, ' ', elems2);
	}

	sc.toLowerCase(elems2);

	sc.checkSpell(elems2, root);

	sc.displayMisspelledWords();

}

void word_suggest()
{	
	cout << "\n";
	cout << "    " << "Word Suggest Feature" << endl;
	cout << "    " << "--------------------" << endl;

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

	set<string> misspelled_word = ws.getIncorrectWords();

	set<string> suggestions;

	cout << "    Suggestions:" << endl;
	cout << "    ------------" << endl;

	for (string str6 : misspelled_word)
	{
		cout << "    " << str6 << endl;
		suggestions = ws.getSuggestions(str6, root);

		if (suggestions.size() == 0)
			cout << "         " << " No Suggestions Found !!!!" << endl;
		for (string str : suggestions)
		{
			cout << "      -> " << str << endl;
		}
	}
}

void auto_correct()
{
	cout << "\n";
	cout << "    " << "Auto Correct Feature" << endl;
	cout << "    " << "--------------------" << endl;

	Trie* myTrie = new Trie();

	string input, options;
	input = "../dictionary.txt";

	cout << "\n";
	cout << "    Reading dictionary.txt Please wait ...." << endl;

	if (myTrie->populate(input))
	{
		cout << "    Trie was populated. Total notes created were " << myTrie->getTotalNodes() << "\n";
	}
	else
	{
		cout << "    Sorry, Trie was not populated. \n";
		goto cleanup;
	}
	cout << "    Enter a prefix for Auto-Completion. Enter quit to exit.\n";
	cout << "    ";
	getline(cin, input);
	while (input != "quit")
	{
		options = myTrie->retrieve(input);
		cout << options;
		cout << "    Next prefix: ";
		getline(cin, input);
	}
cleanup:
	deletePtr<Trie>(myTrie);
}

void doc_retrieval()
{
	cout << "\n";
	cout << "    " << "Document Retrieval Feature" << endl;
	cout << "    " << "--------------------------" << endl;

	DocRet dt;

	cout << "\n\n" << endl;
	cout << "    Processing all Files please wait ..." << endl;

	const char* filepath = "../TestFiles/";
	vector<string> filenames = dt.getallfilenames(filepath);;
	vector<string> elems;

	for (string str : filenames)
	{
		elems.clear();
		dt.processFiles(elems, filepath + str);
		dt.insert(elems, str);
	}

	cout << "\n\n" << endl;
	cout << "    Processed all files !!! " << endl;
	cout << "\n\n" << endl;
	cout << "    Query Mechanism started ... " << endl;
	cout << "\n\n" << endl;

	int queries;
	cout << "    Enter number of queries:" << endl;
	cout << "    ";
	cin >> (int)queries;
	string word;
	for (int i = 1; i <= queries; i++)
	{
		cout << "    Enter word #" << i << " : " << endl;
		cout << "    ";
		cin >> word;
		dt.search(word);
	}

	cout << "\n    " << "Set of all Filenames queried:" << endl;
	for (string str : dt.get_set_filenames())
		cout << "    " << str << " ";

	cout << "\n\n";
}


#endif