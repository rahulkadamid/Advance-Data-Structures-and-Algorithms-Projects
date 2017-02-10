#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "IMarkov.h"
#include "DLL_Markov.h"
#include "ML_Markov.h"
#include "Skiplist_Markov.h"
#include "IVector.h"

using namespace std;

void split(const string &s, char delim, IVector<string> &elems);

#ifndef TEST_MAIN
#define TEST_MAIN

int main()
{
	srand((unsigned int)time(0));

	IMarkov<string>* dll_markov = new DLL_Markov<string>();

	IMarkov<string>* ml_markov = new ML_Markov<string>();

	IMarkov<string>* sl_markov = new Skiplist_Markov<string>();

	ifstream file("text.txt");

	string str;

	IVector<string> elems;

	while (getline(file, str))
	{
		split(str, ' ', elems);
	}

	cout << endl;

	cout << "-----------------------------------------Markov Text generation:--------------------------------------" << endl;

	cout << endl;

	/*********************************DLL MARKOV***********************************/

	for (int i = 0; i < elems.size() - 1; i++)
	{
		dll_markov->add(elems.at(i), elems.at(i + 1));
	}

	cout << endl;

	cout << endl;

	cout << "DLL Markov Text :" << endl;
	cout << "------------------" << endl;
	cout << dll_markov->generate(20) << endl;

	cout << endl;

	/*********************************ML MARKOV***********************************/

	for (int i = 0; i < elems.size() - 1; i++)
	{
		ml_markov->add(elems.at(i), elems.at(i + 1));
	}

	cout << endl;

	cout << endl;

	cout << "ML Markov Text :" << endl;
	cout << "------------------" << endl;
	cout << ml_markov->generate(20) << endl;

	cout << endl;

	/*********************************SkipList MARKOV***********************************/

	
	for (int i = 0; i < elems.size() - 1; i++)
	{
		sl_markov->add(elems.at(i), elems.at(i + 1));
	}

	cout << endl;

	cout << "Skiplist Markov Text :" << endl;
	cout << "------------------" << endl;
	cout << sl_markov->generate(20) << endl;

	cout << endl;

	cout << endl;

	return 0;
}
#endif

void split(const string &s, char delim, IVector<string> &elems)
{
	string temp;
	for (size_t i = 0; i <s.size(); i++)
	{
		if (s.at(i) != delim)
		{
			temp.append(s, i, 1);

			if (i == s.size() - 1)
				elems.push_back(temp);
		}
		else if (temp != "")
		{
			elems.push_back(temp);
			temp = "";
		}
	}
}


