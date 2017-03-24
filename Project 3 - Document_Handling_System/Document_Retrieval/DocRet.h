#ifndef DOCRET_H
#define DOCRET_H

#include <map>
#include <set>
#include <string>
#include "../Trie/Trie.h"
#include "../Word_Suggest/WordSuggest.h"
#include "../HashMap/HashMap.h"

using namespace std;

class DocRet:public WordSuggest
{
private:
	HashMap inv;
	set<string> set_filenames;
public:
	void search(string word);
	void insert(vector<string>& elems, string word);
	void processFiles(vector<string>& elems, string inpfilenames);
	void split(const string &s, char delim, vector<string> &elems);
	void removePunct(string& str);
	void toLowerCase(vector<string>& elem);
	vector<string> getallfilenames(const char* filepath);
	set<string> get_set_filenames();
	void split(const string &s, char delim, set<string> &elems);
};

#endif