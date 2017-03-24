#include <iostream>
#include <string>
#include "Trie.h"

using namespace std;

#ifdef TEST_MAIN_TRIE

// Driver
int main()
{
	// Input keys (use only 'a' through 'z' and lower case)
	char keys[][9] = { "the", "a", "there", "answer", "any", "thaw",
		"by", "bye", "their" };

	char output[][32] = { "Not present in trie", "Present in trie" };

	TrieNode tn;

	TrieNode *root = tn.getNode();

	// Con trie
	int i;
	for (i = 0; i < ARRAY_SIZE(keys); i++)
		tn.insert(root, keys[i]);

	// Search for different keys
	cout << "the	->" << output[tn.search(root, "the")] << endl;
	cout << "these	->" << output[tn.search(root, "these")] << endl;
	cout << "their	->" << output[tn.search(root, "their")] << endl;
	cout << "thaw	->" << output[tn.search(root, "thaw")] << endl;
	cout << "rah	->" << output[tn.search(root, "rah")] << endl;
	cout << "answer ->" << output[tn.search(root, "answer")] << endl;
	

	return 0;
}

#endif