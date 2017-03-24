
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

#ifdef TEST_DOC_RET

// Driver
int main()
{
	DocRet dt;

	cout << "\n\n" << endl;
	cout << "    Processing all Files please wait ..." << endl;

	const char* filepath = "../TestFiles/";
	vector<string> filenames = dt.getallfilenames(filepath);;
	vector<string> elems;

	for (string str : filenames)
	{
		elems.clear();
		dt.processFiles(elems, filepath + str);
		dt.insert(elems, str);
	}

	cout << "\n\n" << endl;
	cout << "    Processed all files !!! " << endl;
	cout << "\n\n" << endl;
	cout << "    Query Mechanism started ... " << endl;
	cout << "\n\n" << endl;

	int queries;
	cout << "    Enter number of queries:" << endl;
	cout << "    ";
	cin >> (int)queries;
	string word;
	for (int i = 1; i <= queries; i++)
	{
		cout << "    Enter word #" << i << " : " << endl;
		cout << "    ";
		cin >> word;
		dt.search(word);
	}

	cout << "\n    " << "Set of all Filenames queried:" << endl;
	for(string str: dt.get_set_filenames())
		cout << "    " << str << " ";


	cout << "\n\n";
	return 0;
}


#endif