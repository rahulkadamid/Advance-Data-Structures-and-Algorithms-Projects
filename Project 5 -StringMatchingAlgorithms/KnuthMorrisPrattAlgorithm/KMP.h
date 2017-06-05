#pragma once

#include<string>
#include<vector>
using namespace std;

class KMP
{
public:
	void KMPSearch(string pat, string txt);
	void computeLPSArray(string pat, int M, vector<int> lps);
};