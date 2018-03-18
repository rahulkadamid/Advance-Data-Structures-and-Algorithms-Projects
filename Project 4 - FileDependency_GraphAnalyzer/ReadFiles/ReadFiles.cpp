
#include "dirent.h"
#include "ReadFiles.h"

vector<string>  ReadFiles::getallfilenames(const char* filepath)
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
