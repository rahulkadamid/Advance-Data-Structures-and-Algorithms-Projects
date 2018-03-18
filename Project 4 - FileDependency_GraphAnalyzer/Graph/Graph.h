#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>

#define NIL -1

using namespace std;

namespace GraphLib
{
	///////////////////////////////////////////////////////////////
	// Vertex class

	template<typename V, typename E>
	class Vertex
	{
	public:
		typedef pair<int, E> Edge;  
		typename typedef vector<Edge>::iterator iterator;
		iterator begin();
		iterator end();
		Vertex(V v, size_t id);
		Vertex(V v);
		void add(Edge& edge);
		Edge& operator[](size_t i);
		Edge operator[](size_t i) const;
		V& value();
		size_t& id();
		size_t size();
		bool& mark();

	private:
		vector<Edge> _edges;
		V _v;
		size_t _id;
		static size_t count;
		bool _mark;
	};
	//----< reserve memory for, and initialize, static count >-----
	template<typename V, typename E>
	size_t Vertex<V, E>::count = 0;

	//----< set and return boolean mark, used for traversal >------
	template<typename V, typename E>
	bool& Vertex<V, E>::mark() { return _mark; }

	//----< return iterator pointing to first edge >---------------
	template<typename V, typename E>
	typename Vertex<V, E>::iterator Vertex<V, E>::begin() { return _edges.begin(); }

	//----< return iterator pointing to one past last edge >-------
	template<typename V, typename E>
	typename Vertex<V, E>::iterator Vertex<V, E>::end() { return _edges.end(); }

	//----< construct instance, specifying id - must be unique >---
	template<typename V, typename E>
	Vertex<V, E>::Vertex(V v, size_t id) : _v(v), _id(id), _mark(false) {}

	//----< construct instance - creates id sequentially >-------
	template<typename V, typename E>
	Vertex<V, E>::Vertex(V v) : _v(v), _id(count++), _mark(false) {}

	//----< add edge to vertex edge collection >-------------------
	template<typename V, typename E>
	void Vertex<V, E>::add(Edge& edge) { _edges.push_back(edge); }

	//----< index non-const vertex's edges >-----------------------
	template<typename V, typename E>
	typename Vertex<V, E>::Edge& Vertex<V, E>::operator[](size_t i) { return _edges[i]; }

	//----< index const vertex's edges >---------------------------
	template<typename V, typename E>
	typename Vertex<V, E>::Edge Vertex<V, E>::operator[](size_t i) const { return _edges[i]; }

	//----< set and read value of vertex's held type, V >----------
	template<typename V, typename E>
	V& Vertex<V, E>::value() { return _v; }

	//----< return vertex's id >-----------------------------------
	template<typename V, typename E>
	size_t& Vertex<V, E>::id() { return _id; }

	//----< return number of edges >-------------------------------
	template<typename V, typename E>
	size_t Vertex<V, E>::size() { return _edges.size(); }

	///////////////////////////////////////////////////////////////
	// Graph class

	template<typename V, typename E>
	class Graph
	{
	public:
		typename typedef vector< Vertex<V, E> >::iterator iterator;
		iterator begin();
		iterator end();
		Vertex<V, E>& operator[](size_t i);
		Vertex<V, E> operator[](size_t i) const;
		void addVertex(Vertex<V, E> v);
		void addEdge(E eval, Vertex<V, E>& parent, Vertex<V, E>& child);
		size_t findVertexIndexById(size_t id);
		size_t size();
		template<typename F>
		void dfs(Vertex<V, E>& v, F f);
		vector< Vertex<V, E> >  getVertexVector();
		void SCC();
		void SCCUtil(Vertex<V, E> u, int disc[], int low[], stack<Vertex<V, E>> *st, bool stackMember[]);
		void topologicalSortUtil(Vertex<V, E> v, bool visited[], stack < Vertex<V, E>> &Stack);
		void topologicalSort();
		bool isCyclicUtil(Vertex<V, E> v, bool visited[], bool *rs);
		bool isCyclic();
	private:
		vector< Vertex<V, E> > adj;
		unordered_map<size_t, size_t> idMap; 
		template<typename F>
		void dfsCore(Vertex<V, E>& v, F f);
	};

	//----< get Vertex Vector>-------------
	template<typename V, typename E>
	vector< Vertex<V, E> > Graph<V, E>::getVertexVector()
	{
		return adj;
	}

	//----< return iterator pointing to first vertex >-------------
	template<typename V, typename E>
	typename Graph<V, E>::iterator Graph<V, E>::begin() { return adj.begin(); }

	//----< return iterator pointing one past last vertex >--------
	template<typename V, typename E>
	typename Graph<V, E>::iterator Graph<V, E>::end() { return adj.end(); }

	//----< index non-const graph's vertex collection >------------
	template<typename V, typename E>
	typename Vertex<V, E>& Graph<V, E>::operator[](size_t i) { return adj[i]; }

	//----< index const graph's vertex collection >----------------
	template<typename V, typename E>
	typename Vertex<V, E> Graph<V, E>::operator[](size_t i) const { return adj[i]; }

	//----< add vertex to graph's vertex collection >--------------
	template<typename V, typename E>
	void Graph<V, E>::addVertex(Vertex<V, E> v)
	{
		adj.push_back(v);
		idMap[v.id()] = adj.size() - 1;
	}
	//----< return number of vertices in graph's collection >------
	template<typename V, typename E>
	size_t Graph<V, E>::size() { return adj.size(); }

	//----< return index of vertex with specified id >-------------
	template<typename V, typename E>
	size_t Graph<V, E>::findVertexIndexById(size_t id)
	{
		return idMap[id];
	}
	//----< add edge from specified parent to child vertices >-----
	template<typename V, typename E>
	void Graph<V, E>::addEdge(E eVal, Vertex<V, E>& parent, Vertex<V, E>& child)
	{
		size_t childIndex = findVertexIndexById(child.id());
		if (childIndex == adj.size())
			throw exception("no edge child");
		size_t parentIndex = findVertexIndexById(parent.id());
		if (parentIndex == adj.size())
			throw exception("no edge parent");
		Vertex<V, E>::Edge e;
		e.first = (int)childIndex;
		e.second = eVal;
		adj[parentIndex].add(e);
	}
	//----< recursive depth first search with action f >-----------
	template<typename V, typename E>
	template<typename F>
	void Graph<V, E>::dfsCore(Vertex<V, E>& v, F f)
	{
		f(v);
		v.mark() = true;
		for (auto edge : v)
		{
			if (adj[edge.first].mark() == false)
				dfsCore(adj[edge.first], f);
		}
		for (auto& vert : adj)
		{
			if (vert.mark() == false)
				dfsCore(vert, f);
		}
	}
	//----< depth first search, clears marks for next search >-----
	template<typename V, typename E>
	template<typename F>
	void Graph<V, E>::dfs(Vertex<V, E>& v, F f)
	{
		dfsCore(v, f);
		for (auto& vert : adj)
			vert.mark() = false;
	}

	template<typename V, typename E>
	void Graph<V, E>::SCC()
	{
		int no_of_vertex = (int)adj.size();
		int *disc = new int[no_of_vertex];
		int *low = new int[no_of_vertex];
		bool *stackMember = new bool[no_of_vertex];
		stack<Vertex<V, E>> *st = new stack<Vertex<V, E>>();

		// Initialize disc and low, and stackMember arrays
		for (int i = 0; i < no_of_vertex; i++)
		{
			disc[i] = NIL;
			low[i] = NIL;
			stackMember[i] = false;
		}

		// Call the recursive helper function to find strongly
		// connected components in DFS tree with vertex 'i'
		for (Vertex<V, E> vert : adj)
		{
			if (disc[vert.id()] == NIL)
				SCCUtil(vert, disc, low, st, stackMember);
		}

	}

	template<typename V, typename E>
	void Graph<V, E>::SCCUtil(Vertex<V, E> u, int disc[], int low[], stack<Vertex<V, E>> *st, bool stackMember[])
	{
		// A static variable is used for simplicity, we can avoid use
		// of static variable by passing a pointer.
		static int time = 0;
		// Initialize discovery time and low value
		disc[u.id()] = low[u.id()] = ++time;
		st->push(u);
		stackMember[u.id()] = true;
		// Go through all vertices adjacent to this
		for (auto i = u.begin(); i != u.end(); ++i)
		{
			Vertex<V, E>::Edge v = *i;  // v is current adjacent of 'u'															
										// If v is not visited yet, then recur for it
			if (disc[v.first] == -1)
			{
				SCCUtil(adj[v.first], disc, low, st, stackMember);

				// Check if the subtree rooted with 'v' has a
				// connection to one of the ancestors of 'u'
				// Case 1 (per above discussion on Disc and Low value)
				low[u.id()] = min(low[u.id()], low[v.first]);
			}
			// Update low value of 'u' only of 'v' is still in stack
			// (i.e. it's a back edge, not cross edge).
			// Case 2 (per above discussion on Disc and Low value)
			else if (stackMember[v.first] == true)
				low[u.id()] = min(low[u.id()], disc[v.first]);
		}
		// head node found, pop the stack and print an SCC

		string out = "";
		if (low[u.id()] == disc[u.id()])
		{
			while (st->top().id() != u.id())
			{
				out = st->top().value();
				cout << "    " << out << "\n";
				stackMember[st->top().id()] = false;
				st->pop();
			}
			out = st->top().value();
			cout << "    " << out << "\n";
			cout << "    -------------------------------------------" << "\n";
			stackMember[st->top().id()] = false;
			st->pop();
		}
	}

	template<typename V, typename E>
	void Graph<V, E>::topologicalSortUtil(Vertex<V, E> v, bool visited[], stack < Vertex<V, E>> &Stack)
	{
		visited[v.id()] = true;

		// Recur for all the vertices adjacent to this vertex
		for (auto i = v.begin(); i != v.end(); ++i)
		{
			Vertex<V, E>::Edge v = *i;
			if (!visited[v.first])
				topologicalSortUtil(adj[v.first], visited, Stack);
		}

		// Push current vertex to stack which stores result
		Stack.push(v);
	
	}

	template<typename V, typename E>
	void Graph<V, E>::topologicalSort()
	{
		stack<Vertex<V, E>> Stack;

		int no_of_vertex = (int)adj.size();
		// Mark all the vertices as not visited
		bool *visited = new bool[no_of_vertex];
		for (int i = 0; i < no_of_vertex; i++)
			visited[i] = false;

		// Call the recursive helper function to store Topological
		// Sort starting from all vertices one by one
		for (Vertex<V, E> vert : adj)
		{
			if (visited[vert.id()] == false)
				topologicalSortUtil(vert, visited, Stack);
		}
			

		// Print contents of stack
		while (Stack.empty() == false)
		{
			cout << "    " << Stack.top().value() << " ";
			Stack.pop();
		}
	
	}

	template<typename V, typename E>
	bool Graph<V, E>::isCyclic()
	{	
		int no_of_vertex = (int)adj.size();
		// Mark all the vertices as not visited and not part of recursion
		// stack
		bool *visited = new bool[no_of_vertex];
		bool *recStack = new bool[no_of_vertex];
		for (int i = 0; i < no_of_vertex; i++)
		{
			visited[i] = false;
			recStack[i] = false;
		}

		// Call the recursive helper function to detect cycle in different
		// DFS trees
		for (Vertex<V, E> vert : adj)
		{
			if (isCyclicUtil(vert, visited, recStack))
				return true;
		}
		return false;
	}

	template<typename V, typename E>
	bool Graph<V, E>::isCyclicUtil(Vertex<V, E> v, bool visited[], bool *recStack)
	{
		if (visited[v.id()] == false)
		{
			// Mark the current node as visited and part of recursion stack
			visited[v.id()] = true;
			recStack[v.id()] = true;

			// Recur for all the vertices adjacent to this vertex
	
			for (auto i = v.begin(); i != v.end(); ++i)
			{
				Vertex<V, E>::Edge v = *i;
				if (!visited[v.first] && isCyclicUtil(adj[v.first], visited, recStack))
					return true;
				else if (recStack[v.first])
					return true;
			}

		}
		recStack[v.id()] = false;  // remove the vertex from recursion stack
		return false;
	}
	

	///////////////////////////////////////////////////////////////
	// Display class

	template<typename V, typename E>
	class Display
	{
	public:
		typedef Graph<V, E> graph;
		typedef Vertex<V, E> vertex;
		typedef pair<int, E> edge;

		static vector< Vertex<V, E> > vertsWithNoParents(graph& g)
		{
			vector<size_t> parentCount;
			graph::iterator iter = g.begin();
			while (iter != g.end())
			{
				parentCount.push_back(0);
				++iter;
			}
			iter = g.begin();
			while (iter != g.end())
			{
				vertex v = *iter;
				for (size_t i = 0; i<v.size(); ++i)
				{
					edge e = v[i];
					parentCount[e.first]++;
				}
				++iter;
			}
			vector<vertex> noParents;
			for (size_t j = 0; j<g.size(); ++j)
				if (parentCount[j] == 0)
					noParents.push_back(g[j]);
			return noParents;
		}

		static void show(graph& g)
		{
			graph::iterator iter = g.begin();
			while (iter != g.end())
			{
				vertex v = *iter;
				cout << "\n  vertex id = " << v.id() << ", value = " << (v.value()).c_str();
				for (size_t i = 0; i<v.size(); ++i)
				{
					vertex::Edge edge = v[i];
					cout << "\n    edge points to vertex with id = " << g[edge.first].id();
					cout << " and value = " << g[edge.first].value().c_str();
					cout << ", edge value = " << (edge.second).c_str();
				}
				++iter;
			}
		}
		static void dfsvertexshow(graph& g)
		{
			graph::iterator iter = g.begin();
			while (iter != g.end())
			{
				vertex v = *iter;
				cout << "\n  vertex id = " << v.id() << ", value = " << (v.value()).c_str();
				++iter;
			}
		}
	};
}
#endif
