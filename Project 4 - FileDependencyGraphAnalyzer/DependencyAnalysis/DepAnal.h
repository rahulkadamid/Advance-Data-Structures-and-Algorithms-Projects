#ifndef DEPANAL_H
#define DEPANAL_H

#include <string>
#include <map>
#include <set>

#include "../Graph/Graph.h"

using namespace GraphLib;
typedef Graph<std::string, std::string> graph;

using namespace std;

class DepAnal
{
private:
	map<string, set<string>> depmap;
	graph g;
public:
	map<string, set<string>> getdepmap();
	graph  getgraph();
	void processDependency(string filename);
	void displayDependency();	
	void storeToGraph(vector<string> filenames);
};



#endif
