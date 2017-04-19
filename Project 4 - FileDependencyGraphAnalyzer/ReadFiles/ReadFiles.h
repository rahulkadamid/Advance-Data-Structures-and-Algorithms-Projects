#ifndef READFILES_H
#define READFILES_H

#include <vector>
#include <string>

using namespace std;

class ReadFiles
{
private:
	vector<string> filenames;
public:
	vector<string>  getallfilenames(const char* filepath);
};


#endif // READFILES_H
