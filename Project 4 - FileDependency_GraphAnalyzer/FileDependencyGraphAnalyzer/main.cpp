#include <iostream>
#include <string>
#include <vector>

#include "../ReadFiles/ReadFiles.h"
#include "../DependencyAnalysis/DepAnal.h"

using namespace std;

using namespace GraphLib;

typedef Graph<std::string, std::string> graph;
typedef Vertex<std::string, std::string> vertex;
typedef Display<std::string, std::string> display;

void showVert(Vertex<std::string, std::string>& v)
{
	std:cout << "\n  " << v.id();
}

#ifdef TEST_FINAL

// Driver
int main()
{
	ReadFiles rf;

	cout << "\n \t \t \t \t \t Welcome to File Dependency Graph Analyzer ";
	cout << "\n \t \t \t \t \t =========================================\n";
	cout << "\n";

	const char* filepath = "../TestFiles/";				
	
	vector<string> filenames = rf.getallfilenames(filepath);

	cout << "\n\n";
	cout << "   Analyzing files " << filepath << " ..." << endl;
	cout << "\n";

	map<string, set<string>> depmap;

	DepAnal da;

	for (string str : filenames)
	{
		da.processDependency(filepath + str);
	}

	da.displayDependency();

	da.storeToGraph(filenames);

	graph g = da.getgraph();

	cout << "\n\n";
	cout << "   -------------------------------------------------------------------------" << endl;
	cout << "   Graph Constructed:" << endl;
	cout << "   -------------------------------------------------------------------------" << endl;
	display::show(g);
	cout << "\n";	
	
	cout << "\n\n";
	cout << "   -------------------------------------------------------------------------" << endl;
	cout << "   Strong Components:" << endl;
	cout << "   -------------------------------------------------------------------------" << endl;
	g.SCC();
	cout << "\n";

	cout << "\n\n";
	cout << "   -------------------------------------------------------------------------" << endl;
	cout << "   Name of Vertices with DFS:" << endl;
	cout << "   -------------------------------------------------------------------------" << endl;
	display::dfsvertexshow(g);
	cout << "\n";

	cout << "\n\n";
	cout << "   -------------------------------------------------------------------------" << endl;
	cout << "   Topological Sort of vertices:" << endl;
	cout << "   -------------------------------------------------------------------------" << endl;
	
	if (!g.isCyclic())
		g.topologicalSort();
	else
		cout << "    Graph contains a cycle , cannot perform Topological sort ..." << endl;
	cout << "\n\n";

	return 0;
}

#endif