#ifndef WORDSUGGEST_H
#define WORDSUGGEST_H

#include <string>
#include <vector>
#include <set>
#include "../Queue/Queue.h"
#include "../Trie/Trie.h"
#include "../Spell_Check/SpellCheck.h"

using namespace std;

class WordSuggest:public SpellCheck
{
private:
	TrieNode tn;

public:
	TrieNode& getTrieNode();
	TrieNode* readDictInTrie();
	set<string> getSuggestions(string word, TrieNode* root);
	vector<string> distanceOne(string s);
	void substitution(string s, vector<string>& currlist);
	void insertion(string s, vector<string>& currlist);
	void deletion(string s, vector<string>& currlist);
};

#endif