// C++ implementation of search and insert operations
// on Trie

#include <iostream>
#include <string>
#include "Trie.h"

using namespace std;

// Returns new trie node (initialized to NULLs)
TrieNode* TrieNode::getNode(void)
{
	 TrieNode *pNode = NULL;

	pNode = new TrieNode();

	if (pNode)
	{
		int i;

		pNode->isLeaf = false;

		for (i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;
	}

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void TrieNode::insert( TrieNode *root, std::string key)
{
	int level;
	int slength = key.length();
	int index;

	 TrieNode *pCrawl = root;

	for (level = 0; level < slength; level++)
	{
		index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isLeaf = true;
}

// Returns true if key presents in trie, else false
bool TrieNode::search( TrieNode *root, string key)
{
	int level;
	int slength = key.length();
	int index;
	 TrieNode *pCrawl = root;

	for (level = 0; level < slength; level++)
	{
		index = CHAR_TO_INDEX(key[level]);

		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isLeaf);
}
