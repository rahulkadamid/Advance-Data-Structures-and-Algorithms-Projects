#pragma once

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

#define MAX_CHAR 256

struct SuffixTreeNode
{
	struct SuffixTreeNode *children[MAX_CHAR];

	//pointer to other node via suffix link
	struct SuffixTreeNode *suffixLink;

	/*(start, end) interval specifies the edge, by which the
	node is connected to its parent node. Each edge will
	connect two nodes,  one parent and one child, and
	(start, end) interval of a given edge  will be stored
	in the child node. Lets say there are two nods A and B
	connected by an edge with indices (5, 8) then this
	indices (5, 8) will be stored in node B. */
	int start;
	int *end;

	/*for leaf nodes, it stores the index of suffix for
	the path  from root to leaf*/
	int suffixIndex;
};

typedef struct SuffixTreeNode Node;
 //Input string

class ST
{
public:
	//char text[100];
	string text;
	Node *root = NULL; //Pointer to root node

					   /*lastNewNode will point to newly created internal node,
					   waiting for it's suffix link to be set, which might get
					   a new suffix link (other than root) in next extension of
					   same phase. lastNewNode will be set to NULL when last
					   newly created internal node (if there is any) got it's
					   suffix link reset to new internal node created in next
					   extension of same phase. */
	Node *lastNewNode = NULL;
	Node *activeNode = NULL;
	/*activeEdge is represeted as input string character
	index (not the character itself)*/
	int activeEdge = -1;
	int activeLength = 0;
	// remainingSuffixCount tells how many suffixes yet to
	// be added in tree
	int remainingSuffixCount = 0;
	int leafEnd = -1;
	int *rootEnd = NULL;
	int *splitEnd = NULL;
	int size = -1; //Length of input string

	Node *newNode(int start, int *end);
	int edgeLength(Node *n);
	int walkDown(Node *currNode);
	void extendSuffixTree(int pos);
	void print(int i, int j);
	void setSuffixIndexByDFS(Node *n, int labelHeight);
	void freeSuffixTreeByPostOrder(Node *n);
	void buildSuffixTree();
	int traverseEdge(string str, int idx, int start, int end);
	int doTraversalToCountLeaf(Node *n);
	int countLeaf(Node *n);
	int doTraversal(Node *n, string str, int idx);
	void checkForSubString(string str);
};


