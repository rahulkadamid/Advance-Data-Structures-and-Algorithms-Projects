
#include <iostream>
#include <algorithm>
#include "AutoComplete.h"

using namespace std;

int main(int argc, const char * argv[])
{
    Trie* myTrie = new Trie();
    
    string input, options;
	input = "dictionary.txt";

	cout << "\n";
	cout << "Reading dictionary.txt Please wait ...." << endl;

    if (myTrie->populate(input))
    {
        cout << "Trie was populated. Total notes created were " << myTrie->getTotalNodes() << "\n";
    }
    else
    {
        cout << "Sorry, Trie was not populated. \n";
        goto cleanup;
    }
    cout << "Enter a prefix for Auto-Completion. Enter quit to exit.\n";
    getline(cin, input);
    while (input != "quit")
    {
        options = myTrie->retrieve(input);
        cout << options;
        cout << "Next prefix: ";
        getline(cin, input);
    }
cleanup:
    deletePtr<Trie>(myTrie);
    return 0;
}

