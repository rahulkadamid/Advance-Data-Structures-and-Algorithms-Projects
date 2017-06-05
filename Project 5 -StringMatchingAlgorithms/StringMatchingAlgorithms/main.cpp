
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

#include "../WindowsStopWatch/WindowsStopWatch.h"
#include "../KnuthMorrisPrattAlgorithm/KMP.h"
#include "../BoyerMooreAlgorithm/BM.h"
#include "../RabinKarpAlgorithm/RK.h"
#include "../BitOrientedApproach/BO.h"
#include "../AhoCorasickAlgorithm/AC.h"
#include "../SuffixTree/ST.h"

using namespace std;

vector<string> convert(ifstream& file);
void split(const string &s, char delim, vector<string> &ivector);

#ifdef TEST_SMA

void print(const char* str)
{
	//cout << "found substring " << str << "\n";
}

int main()
{
	cout << "\n \t \t \t \t \t Welcome to String Matching Algorithms ";
	cout << "\n \t \t \t \t \t =======================================\n";
	cout << "\n";

	// Read TestFiles from:
	string path = "../TestFiles/";

	// Store Text in a string text
	string text_file = "T.txt";
	ifstream ifs1(path + text_file);
	string text((istreambuf_iterator<char>(ifs1)),(istreambuf_iterator<char>()));
	ifs1.close();

	// Store list of Patterns in a vector
	string pattern_file = "P.txt";
	ifstream ifs2(path + pattern_file);
	vector<string> list_pattern = convert(ifs2);
	ifs2.close();

	WindowsStopWatch wsw;

	// Create Objects for various String Matching Algorithms	
	KMP kmp;
	BM bm;
	RK rk;
	BO bo;
	AC ac;
	ST st;

	int list_pattern_size = list_pattern.size();

	/* Part 1: */

	// Knuth-Morris-Pratt Algorithm
	cout << " Knuth-Morris-Pratt Algorithm:" << endl;
	for (int i = 0; i < list_pattern_size; i++)
	{
		wsw.start();
		kmp.KMPSearch(list_pattern[i], text);
		wsw.stop();
		cout << "     Pattern #" << i + 1 << " Timed: " << wsw.getTime() << endl;
	}
	cout << "\n" << endl;

	// Boyer-Moore Algorithm
	cout << " Boyer-Moore Algorithm:" << endl;
	for (int i = 0; i < list_pattern_size; i++)
	{
		wsw.start();
		bm.search(text, list_pattern[i]);
		wsw.stop();
		cout << "     Pattern #" << i + 1 << " Timed: " << wsw.getTime() << endl;		
	}
	cout << "\n" << endl;

	// Rabin-Karp Algorithm
	cout << " Rabin-Karp Algorithm:" << endl;
	for (int i = 0; i < list_pattern_size; i++)
	{
		int q = 101; // A prime number
		wsw.start();
		rk.search(list_pattern[i], text, q);
		wsw.stop();
		cout << "     Pattern #" << i + 1 << " Timed: " << wsw.getTime() << endl;
	}
	cout << "\n" << endl;

	/* Part 2: */

	// Bit-Oriented Approach
	cout << " Bit-Oriented Approach:" << endl;
	wsw.start();
	for (int i = 0; i < list_pattern_size; i++)
		bo.shiftAnd(list_pattern[i], text);
	wsw.stop();
	cout << "     Total Time:" << wsw.getTime() << endl;
	cout << "\n" << endl;

	// AhoChorasick Algorithm
	cout << " AhoChorasick Algorithm:" << endl;
	for (int i = 0; i < list_pattern_size; i++)
		ac.addString(list_pattern[i].c_str());
	ac.init();
	wsw.start();
	ac.search(text.c_str(), print);
	wsw.stop();
	cout << "     Total Time:" << wsw.getTime() << endl;
	cout << "\n" << endl;

	/* Part 3: */
	cout << " Suffix Tree:" << endl;
	st.text = text;
	st.buildSuffixTree();
	for (int i = 0; i < list_pattern_size; i++)
	{
		wsw.start();
		st.checkForSubString(list_pattern[i]);
		wsw.stop();
		cout << "     Pattern #" << i + 1 << " Timed: " << wsw.getTime() << endl;
	}

	return 0;
}

vector<string> convert(ifstream& file)
{
	vector<string> str_vector;

	string str;

	while (getline(file, str))
	{
		split(str, '\n', str_vector);
	}

	return str_vector;
}

void split(const string &s, char delim, vector<string> &ivector)
{
	string temp;
	for (size_t i = 0; i <s.size(); i++)
	{
		if (s.at(i) != delim)
		{
			temp.append(s, i, 1);

			if (i == s.size() - 1)
				ivector.push_back(temp);
		}
		else if (temp != "")
		{
			ivector.push_back(temp);
			temp = "";
		}
	}
}

#endif