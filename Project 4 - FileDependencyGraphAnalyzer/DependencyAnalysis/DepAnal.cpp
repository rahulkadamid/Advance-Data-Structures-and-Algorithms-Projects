
#include <iostream>
#include <fstream>
#include "DepAnal.h"

using namespace GraphLib;

typedef Graph<std::string, std::string> graph;
typedef Vertex<std::string, std::string> vertex;
typedef Display<std::string, std::string> display;

map<string, set<string>> DepAnal::getdepmap()
{
	return depmap;
}

graph  DepAnal::getgraph()
{
	return g;
}

void DepAnal::processDependency(string str)
{
	ifstream file1(str);
	size_t start = str.rfind("/");
	size_t end = str.rfind(".");
	string pstr = str.substr(start + 1, end - start - 1);

	string fstr;

	while (getline(file1, fstr))
	{
		if (fstr[0] == '#')
		{
			size_t start = fstr.find("\"");
			size_t end = fstr.rfind(".");
			string depstr = fstr.substr(start + 1, end - start - 1);
			if (pstr != depstr && depstr[0] != '#')
				depmap[pstr].insert(depstr);
		}
	}
}

void DepAnal::displayDependency()
{	
	cout << "   -------------------------------------------------------------------------" << endl;
	cout << "   File Dependencies:" << endl;
	cout << "   -------------------------------------------------------------------------" << endl;

	for (auto a : depmap)
	{
		cout << "    " << a.first << endl;
		for (auto b : a.second)
			cout << "    " << "   ->  " << b << endl;
	}

}

void DepAnal::storeToGraph(vector<string> filenames)
{	
	set<string> package_names;
	for (auto str : filenames)
	{	
		size_t start = str.rfind("/");
		size_t end = str.rfind(".");
		string pstr = str.substr(start + 1, end - start - 1);
		package_names.insert(pstr);		
	}

	for (string pstr : package_names)
	{
		vertex v1(pstr);
		g.addVertex(v1);
	}

	vector< Vertex<string, string> > vertvector = g.getVertexVector();

	set<string> sset;
	
	int edgevalue = 1;
	for (Vertex<string, string> vert : vertvector)
	{
		if (depmap.find(vert.value()) != depmap.end())
		{
			sset = depmap[vert.value()];

			for (string sset_string : sset)
			{
				for (Vertex<string, string> vert2 : vertvector)
				{

					if (vert2.value() == sset_string)
						g.addEdge(to_string(edgevalue++), vert, vert2);
				}
			}
		}
	}
}