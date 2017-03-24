#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <set>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

using namespace std;

// trie node
class TrieNode
{

public:
	TrieNode* children[ALPHABET_SIZE];
	// isLeaf is true if the node represents
	// end of a word
	bool isLeaf;
	TrieNode* getNode(void);
	void insert(TrieNode *root, string key);
	bool search(TrieNode *root, string key);

};
#endif

