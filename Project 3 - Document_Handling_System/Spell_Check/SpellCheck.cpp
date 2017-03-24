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

set<string> SpellCheck::getIncorrectWords()
{
	return misspelled_words;
}

TrieNode& SpellCheck::getTrieNode()
{
	return tn;
}

TrieNode* SpellCheck::readDictInTrie(vector<string>& elems1)
{
	TrieNode *root = tn.getNode();

	// Construct trie
	int i;
	int vec_size = elems1.size();
	for (i = 0; i < vec_size; i++)
		tn.insert(root, elems1[i]);

	return root;
}

void SpellCheck::checkSpell(vector<string>& elems2 , TrieNode* root)
{
	for (string str : elems2)
	{
		if (!tn.search(root, str))
		{
			misspelled_words.insert(str);
		}
	}	
}

void SpellCheck::displayMisspelledWords()
{
	cout << "\n";

	cout << "   Incorrect Spelled words:" << endl;
	cout << "   ------------------------" << endl;

	for (string str : misspelled_words)
	{
		cout << "    -> " << str << endl;
	}

}


void SpellCheck::split(const string &s, char delim, vector<string> &elems)
{
	string temp;
	for (size_t i = 0; i <s.size(); i++)
	{
		if (s.at(i) != delim)
		{
			temp.append(s, i, 1);

			if (i == s.size() - 1)
				elems.push_back(temp);
		}
		else if (temp != "")
		{
			elems.push_back(temp);
			temp = "";
		}
	}
}

void SpellCheck::toLowerCase(vector<string>& elem)
{
	for (string& s : elem) {
		std::transform(s.begin(), s.end(), s.begin(),
			[](char c) { return std::tolower(c); });
	}
}

void SpellCheck::removePunct(string& str)
{
	for (auto& ch : str)
	{
		if (ch == '`' || ch == '~' || ch == '!' || ch == '@' || ch == '#' || ch == '$' ||
			ch == '%' || ch == '^' || ch == '&' || ch == '*' || ch == '(' || ch == ')' ||
			ch == '_' || ch == '-' || ch == '+' || ch == '=' || ch == '|' || ch == '\\' ||
			ch == '{' || ch == '[' || ch == '}' || ch == ']' || ch == ':' || ch == ';' ||
			ch == '\'' || ch == '\"' || ch == '<' || ch == ',' || ch == '>' || ch == '.' ||
			ch == '?' || ch == '/')
			ch = ' ';
	}
}
