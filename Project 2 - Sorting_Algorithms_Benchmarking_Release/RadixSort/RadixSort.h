#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "../ISort/ISort.h"

using namespace std;

class RadixSort:public ISort
{
public:
	RadixSort() {}
	~RadixSort() {}
	void sort(vector<int>& ivector);
	int getMax(vector<int>& ivector, int n);
	void countSort(vector<int>& ivector, int n, int exp);

};

int RadixSort::getMax(vector<int>& ivector, int n)
{
	int max = ivector[0];
	for (int i = 1; i < n; i++)
		if (ivector[i] > max)
			max = ivector[i];
	return max;
}

void RadixSort::countSort(vector<int>& ivector, int n, int exp)
{	
	int ivector_size = ivector.size();

	vector<int> output(ivector_size);

	int i, count[10] = { 0 };


	for (i = 0; i < ivector_size; i++)
		count[(ivector[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(ivector[i] / exp) % 10] - 1] = ivector[i];
		count[(ivector[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		ivector[i] = output[i];
}

void RadixSort::sort(vector<int>& ivector)
{	
	int ivector_size = ivector.size();

	int m = getMax(ivector, ivector_size);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(ivector, ivector_size, exp);

	
}

#endif // !RADIXSORT_H

