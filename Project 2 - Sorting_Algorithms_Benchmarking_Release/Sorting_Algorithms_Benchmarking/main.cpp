
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

#include "../WindowsStopWatch/WindowsStopWatch.h"
#include "../ISort/ISort.h"
#include "../InsertionSort/InsertionSort.h"
#include "../SelectionSort/SelectionSort.h"
#include "../BubbleSort/BubbleSort.h"
#include "../CombSort/CombSort.h"
#include "../ShellSort/ShellSort.h"
#include "../HeapSort/HeapSort.h"
#include "../MergeSort/MergeSort.h"
#include "../QuickSort/QuickSort.h"
#include "../RadixSort/RadixSort.h"
#include "../IntroSort/IntroSort.h"
#include "../CountingSort/CountingSort.h"

using namespace std;

#ifndef TEST_MAIN
#define TEST_MAIN

void bestCasePerf();
void avgCasePerf();
void worstCasePerf();
vector<int> readNConvert(ifstream& file);
void benchmark(vector<int> &ivector, ISort* isort);
void split(const string &s, char delim, vector<string> &ivector);

int main()
{
	cout << "\n \t \t \t \t \t BenchMarking Sorting Algorithms";
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

	cout << "----------------------------" << endl;
	cout << "BenchMarking Insertion Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* insertion_sort = new InsertionSort();
	benchmark(ascending_vector, insertion_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Selection Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* selection_sort = new SelectionSort();
	benchmark(ascending_vector, selection_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Bubble Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* bubble_sort = new BubbleSort();
	benchmark(ascending_vector, bubble_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Comb Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* comb_sort = new CombSort();
	benchmark(ascending_vector, comb_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Shell Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* shell_sort = new ShellSort();
	benchmark(ascending_vector, shell_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Heap Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* heap_sort = new HeapSort();
	benchmark(ascending_vector, heap_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Merge Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* merge_sort = new MergeSort();
	benchmark(ascending_vector, merge_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Quick Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* quick_sort = new QuickSort();
	benchmark(ascending_vector, quick_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Radix Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* radix_sort = new RadixSort();
	benchmark(ascending_vector, radix_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Intro Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* intro_sort = new IntroSort();
	benchmark(ascending_vector, intro_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Counting Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* counting_sort = new CountingSort();
	benchmark(ascending_vector, counting_sort);
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

	cout << "----------------------------" << endl;
	cout << "BenchMarking Insertion Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* insertion_sort = new InsertionSort();
	benchmark(random_vector, insertion_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Selection Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* selection_sort = new SelectionSort();
	benchmark(random_vector, selection_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Bubble Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* bubble_sort = new BubbleSort();
	benchmark(random_vector, bubble_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Comb Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* comb_sort = new CombSort();
	benchmark(random_vector, comb_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Shell Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* shell_sort = new ShellSort();
	benchmark(random_vector, shell_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Heap Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* heap_sort = new HeapSort();
	benchmark(random_vector, heap_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Merge Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* merge_sort = new MergeSort();
	benchmark(random_vector, merge_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Quick Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* quick_sort = new QuickSort();
	benchmark(random_vector, quick_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Radix Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* radix_sort = new RadixSort();
	benchmark(random_vector, radix_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Intro Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* intro_sort = new IntroSort();
	benchmark(random_vector, intro_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Counting Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* counting_sort = new CountingSort();
	benchmark(random_vector, counting_sort);
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

	cout << "----------------------------" << endl;
	cout << "BenchMarking Insertion Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* insertion_sort = new InsertionSort();
	benchmark(decsending_vector, insertion_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Selection Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* selection_sort = new SelectionSort();
	benchmark(decsending_vector, selection_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Bubble Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* bubble_sort = new BubbleSort();
	benchmark(decsending_vector, bubble_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Comb Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* comb_sort = new CombSort();
	benchmark(decsending_vector, comb_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Shell Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* shell_sort = new ShellSort();
	benchmark(decsending_vector, shell_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Heap Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* heap_sort = new HeapSort();
	benchmark(decsending_vector, heap_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Merge Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* merge_sort = new MergeSort();
	benchmark(decsending_vector, merge_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Quick Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* quick_sort = new QuickSort();
	benchmark(decsending_vector, quick_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Radix Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* radix_sort = new RadixSort();
	benchmark(decsending_vector, radix_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Intro Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* intro_sort = new IntroSort();
	benchmark(decsending_vector, intro_sort);

	cout << "----------------------------" << endl;
	cout << "BenchMarking Counting Sort:" << endl;
	cout << "----------------------------" << endl;
	ISort* counting_sort = new CountingSort();
	benchmark(decsending_vector, counting_sort);
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

#endif // !TEST_MAIN

