#pragma once

#include <limits.h>
#include <string>
#include <stdio.h>

using namespace std;

# define NO_OF_CHARS 256

class BM
{
public:
	void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]);
	void search(string txt, string pat);
};