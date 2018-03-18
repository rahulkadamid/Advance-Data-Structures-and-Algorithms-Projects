#include <iostream>
#include <string>
#include <vector>

#include "../ReadFiles/ReadFiles.h"
#include "DepAnal.h"

using namespace std;

#ifdef TEST_DEPENDENCY_ANALYSIS

// Driver
int main()
{
	ReadFiles rf;

	cout << "\n\n" << endl;
	cout << "    Processing all Files please wait ..." << endl;
	cout << "\n\n" << endl;

	const char* filepath = "../TestFilesWithCycle/";
	vector<string> filenames = rf.getallfilenames(filepath);

	map<string,set<string>> depmap;

	DepAnal da;

	for (string str : filenames)
	{
		da.processDependency(filepath + str);
	}

	da.displayDependency();
	
	da.storeToGraph(filenames);

	return 0;
}

#endif