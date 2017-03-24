#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator> 
#include <cctype>
#include <ctype.h>
#include <map>
#include <set>

#include "DocRet.h"
#include "dirent.h"

using namespace std;

void DocRet::search(string word)
{
	static int sugg_count = 0;

	string filenames;

	string data = word;
	transform(data.begin(), data.end(), data.begin(), tolower);

	if (inv.find(data) != "" )			// Present in files
		filenames = inv.find(data);
	else
	{	
		sugg_count++;
		TrieNode* root = readDictInTrie();
		set<string> suggestions = getSuggestions(data, root);
		if (suggestions.size() == 0)
		{
			cout << "    " << "\tNo Suggestions Found..."<< endl;
			return;
		}			
		else
		{	
			if (sugg_count < 10)
			{
				string str = *(suggestions.begin());
				if (inv.find(str) != "")	// Present in files
					cout << "    " << "\tDid you mean " << "\"" << str << "\"" << " ? " << endl;

				search(str);
				return;
			}
			else
			{
				cout << "    " << "\tNo valid Suggestions found  " << endl;
				return;
			}
		}
	}

	size_t n = std::count(filenames.begin(), filenames.end(), '.');

	if (n < 10)
	{
		cout << "    " << "\tFound in " << n << " files:" << endl;
		cout << "    " << filenames << endl;
	}
	else
	{
		cout << "    " << "\tFound in " << n << " files:" << endl;
		cout << "    " << "\tNot Displaying Due to Large Volume ...." << endl;
	}

	split(filenames, ' ', set_filenames);

}

set<string> DocRet::get_set_filenames()
{
	return set_filenames;
}

void DocRet::split(const string &s, char delim, set<string> &elems)
{
	string temp;
	for (size_t i = 0; i <s.size(); i++)
	{
		if (s.at(i) != delim)
		{
			temp.append(s, i, 1);

			if (i == s.size() - 1)
				elems.insert(temp);
		}
		else if (temp != "")
		{
			elems.insert(temp);
			temp = "";
		}
	}
}

void DocRet::insert(vector<string>& elems, string word)
{
	for (string str : elems)
	{
		inv.insert(str,word);
	}
}

void DocRet::processFiles(vector<string>& elems, string inpfilenames)
{

	ifstream file1(inpfilenames);

	string str;

	while (getline(file1, str))
	{
		removePunct(str);
		split(str, ' ', elems);
	}
	toLowerCase(elems);
}

void DocRet::split(const string &s, char delim, vector<string> &elems)
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

void DocRet::removePunct(string& str)
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

void DocRet::toLowerCase(vector<string>& elem)
{
	for (string& s : elem) {
		std::transform(s.begin(), s.end(), s.begin(),
			[](char c) { return std::tolower(c); });
	}
}

vector<string>  DocRet::getallfilenames(const char* filepath)
{
	vector<string> vec;
	DIR *dir;
	struct dirent *ent;
	int count = 0;
	if ((dir = opendir(filepath)) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL)
		{
			count++;
			if (count > 2)
				vec.push_back(ent->d_name);
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		perror("");
	}
	return vec;
}