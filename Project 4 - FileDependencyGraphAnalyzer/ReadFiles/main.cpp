#include <iostream>
#include <string>
#include <vector>

#include "ReadFiles.h"

using namespace std;

#ifdef TEST_READ_FILES

// Driver
int main()
{	
	ReadFiles rf;

	cout << "    Testing ReadFiles" << endl;

	cout << "\n\n" << endl;
	cout << "    Processing all Files please wait ..." << endl;

	const char* filepath = "../TestFilesWithCycle/";
	vector<string> filenames = rf.getallfilenames(filepath);

	for (string str : filenames)
	{
		cout << "    " << str << endl;
	}

	return 0;
}

#endif