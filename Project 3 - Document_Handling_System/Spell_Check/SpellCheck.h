#ifndef SPELLCHECK_H
#define SPELLCHECK_H

#include <string>
#include <vector>
#include <set>
#include "../Trie/Trie.h"
#include "../Queue/Queue.h"

using namespace std;

class SpellCheck
{
private:
	TrieNode tn;
	set<string> misspelled_words;
	
public:
	TrieNode& getTrieNode();
	set<string> getIncorrectWords();
	TrieNode* readDictInTrie(vector<string>& elems1);
	void checkSpell(vector<string>& elems2, TrieNode* root);
	void displayMisspelledWords();
	void split(const string &s, char delim, vector<string> &elems);
	void toLowerCase(vector<string>& elem);
	void removePunct(string& str);
};

#endif