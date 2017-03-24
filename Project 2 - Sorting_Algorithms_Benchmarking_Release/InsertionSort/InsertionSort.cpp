
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

#include "InsertionSort.h"
#include "../WindowsStopWatch/WindowsStopWatch.h"

using namespace std;

#ifndef TEST_INSERTIONSORT
#define TEST_INSERTIONSORT

void bestCasePerf();
void avgCasePerf();
void worstCasePerf();
vector<int> readNConvert(ifstream& file);
void benchmark(vector<int> &ivector, ISort* isort);
void split(const string &s, char delim, vector<string> &ivector);

int main()
{
	cout << "\n \t \t \t \t \t BenchMarking Insertion Sort";
	cout << "\n \t \t \t \t \t ===============================\n";
	cout << "\n";

	bestCasePerf();
	avgCasePerf();
	worstCasePerf();

	return 0;
}

void bestCasePerf()
{
	cout << "--------------------------------------" << endl;
	cout << "Demo for Best Case Performance !!!    " << endl;
	cout << "--------------------------------------" << endl;
	cout << "\n";
	cout << "Reading ascending.txt..." << endl;
	ifstream ascending_file("../ascending.txt");
	cout << "\n";
	cout << "Converting 1 Million string's to int's..." << endl;
	vector<int> ascending_vector = readNConvert(ascending_file);
	cout << "\n";
	ISort* insertion_sort = new InsertionSort();
	benchmark(ascending_vector, insertion_sort);
	
}

void avgCasePerf()
{
	cout << "--------------------------------------" << endl;
	cout << "Demo for Average Case Performance !!! " << endl;
	cout << "--------------------------------------" << endl;
	cout << "\n";
	cout << "Reading random.txt..." << endl;
	ifstream random_file("../random.txt");
	cout << "\n";
	cout << "Converting 1 Million string's to int's..." << endl;
	vector<int> random_vector = readNConvert(random_file);
	cout << "\n";
	ISort* insertion_sort = new InsertionSort();
	benchmark(random_vector, insertion_sort);
	
}

void worstCasePerf()
{
	cout << "--------------------------------------" << endl;
	cout << "Demo for Worst Case Performance !!!   " << endl;
	cout << "--------------------------------------" << endl;
	cout << "\n";
	cout << "Reading decsending.txt..." << endl;
	ifstream decsending_file("../decsending.txt");
	cout << "\n";
	cout << "Converting 1 Million string's to int's..." << endl;
	vector<int> decsending_vector = readNConvert(decsending_file);
	cout << "\n";
	ISort* insertion_sort = new InsertionSort();
	benchmark(decsending_vector, insertion_sort);
	
}

void benchmark(vector<int> &ivector, ISort* isort)
{
	WindowsStopWatch wsw;

	int n = 1000;

	while (n <= 1000000)		 
	{
		vector<int> vector1(ivector.begin(), ivector.begin() + n);

		wsw.start();
		isort->sort(vector1);
		wsw.stop();

		cout << "For " << n << " records: " << wsw.getTime() << endl;

		if (n == 1000000)		 
			break;

		n = n * 2;

		if (n > 1000000)		 
			n = 1000000;	 
	}

}

vector<int> readNConvert(ifstream& file)
{
	vector<string> str_vector;

	string str;

	while (getline(file, str))
	{
		split(str, '-', str_vector);
	}

	vector<int> int_vector;

	transform(str_vector.begin(), str_vector.end(), back_inserter(int_vector),
		[](const string& str) { return stoi(str); });

	return int_vector;
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

#endif // !TEST_INSERTIONSORT


