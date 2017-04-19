#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace GraphLib;

typedef Graph<std::string, std::string> graph;
typedef Vertex<std::string, std::string> vertex;
typedef Display<std::string, std::string> display;

#ifdef TEST_GRAPH

/////////////////////////////////////////////////////////////////////////////
// Definition of main() method

int main()
{
	std::cout << "\n  Testing Graph Library";
	std::cout << "\n =======================\n";
	try
	{
		std::cout << "\n  Constructing Graph instance";
		std::cout << "\n -----------------------------";

		graph g;

		vertex v0("0");
		vertex v1("1");
		vertex v2("2");
		vertex v3("3");
		vertex v4("4");
		g.addVertex(v0);
		g.addVertex(v1);
		g.addVertex(v2);
		g.addVertex(v3);
		g.addVertex(v4);
		g.addEdge("e1", v1, v0);
		g.addEdge("e2", v0, v2);
		g.addEdge("e3", v2, v1);
		g.addEdge("e4", v0, v3);
		g.addEdge("e5", v3, v4);

		display::show(g);
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "   Strong Components:" << endl;
		std::cout << "\n";
		g.SCC();				// Performs Strong Components Analysis
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "   Topological Sorting:" << endl;
		std::cout << "\n";
		g.topologicalSort();	// Performs Topological Sort
	}
	catch (std::exception& ex)
	{
		std::cout << "\n\n  " << ex.what() << "\n\n";
	}
	std::cout << "\n\n";
	return 0;
}

#endif

