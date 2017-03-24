#include <iostream>
#include <fstream>
#include "WordSuggest.h"

using namespace std;

#define THRESHOLD 1000	// Threshold for Insertion , Deletion , Substitution

TrieNode& WordSuggest::getTrieNode()
{
	return tn;
}


TrieNode* WordSuggest::readDictInTrie()
{	
	ifstream file1("../dictionary.txt");

	string str1;

	vector<string> elems1;

	while (getline(file1, str1))
	{
		split(str1, ' ', elems1);
	}

	TrieNode *root = tn.getNode();

	// Construct trie
	int i;
	int vec_size = elems1.size();
	for (i = 0; i < vec_size; i++)
		tn.insert(root, elems1[i]);

	return root;
}


set<string> WordSuggest::getSuggestions(string word, TrieNode* root)
{	
	set<string> suggestions;

	Queue queue;
	
	queue.enqueue(word);

	bool aflag = true;

	while (!queue.isEmpty() && suggestions.size() < 10 && aflag )
	{
		string s = queue.dequeue();

		vector<string> neighbors = distanceOne(s);		
		
		int neigh_size = neighbors.size();
		
		if (neigh_size < 10)
			aflag = false;

		for (string curr : neighbors)
		{
			queue.enqueue(curr);
			if (tn.search(root, curr))	// If s is in dictionary
			{
				suggestions.insert(curr);
			}
		}
	}
	return suggestions;
}

vector<string> WordSuggest::distanceOne(string s)
{	
	vector<string> currlist;

	insertion(s, currlist);
	substitution(s, currlist);
	deletion(s, currlist);

	return currlist;
}

void WordSuggest::substitution(string s, vector<string>& currlist)
{
	string is;
	int str_length = s.length();

	for (int index = 0; index < str_length; index++)
	{
		for (int charCode = (int)'a'; charCode <= (int)'z'; charCode++)
		{
			is = s;
			is[index] = charCode;

			vector<string>::iterator it;
			it = find(currlist.begin(), currlist.end(), is);

			if (it == currlist.end() && (is != s))  // (sc.getTrieNode().search(root, is)) &&
			{
				currlist.push_back(is);
				if (currlist.size() >= THRESHOLD)
				{
					return;
				}
			}
		}
	}
}

void WordSuggest::insertion(string s, vector<string>& currlist)
{
	string is;

	int str_length = s.length();

	for (int index = 0; index < str_length; index++)
	{
		for (int charCode = (int)'a'; charCode <= (int)'z'; charCode++)
		{
			is = s;

			is.insert(index, 1, (char)charCode);

			vector<string>::iterator it;
			it = find(currlist.begin(), currlist.end(), is);

			if (it == currlist.end() && (is != s))  // (sc.getTrieNode().search(root, is)) &&
			{
				currlist.push_back(is);
				if (currlist.size() >= THRESHOLD)
				{
					return;
				}
			}
		}
	}
}

void WordSuggest::deletion(string s, vector<string>& currlist)
{
	string is;

	int str_length = s.length();

	for (int index = 0; index < str_length; index++)
	{
		is = s;

		is.erase(index, 1);

		vector<string>::iterator it;
		it = find(currlist.begin(), currlist.end(), is);

		if (it == currlist.end() && (is != s))  // (sc.getTrieNode().search(root, is)) &
		{
			currlist.push_back(is);
			if (currlist.size() >= THRESHOLD)
			{
				return;
			}
		}

	}

}