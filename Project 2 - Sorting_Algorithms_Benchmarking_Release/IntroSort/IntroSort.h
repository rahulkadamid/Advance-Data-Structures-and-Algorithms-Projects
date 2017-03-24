#ifndef INTROSORT_H
#define INTROSORT_H

#include <algorithm>
#include "../ISort/ISort.h"

using namespace std;

class IntroSort:public ISort
{
public:
	IntroSort() {}
	~IntroSort() {}
	void sort(vector<int>& ivector);
	void IntrosortUtil(vector<int>& ivector, int * begin, int * end, int depthLimit);
	void swapValue(int *a, int *b);
	void InsertionSort(vector<int>& ivector, int *begin, int *end);
	int* Partition(vector<int>& ivector, int low, int high);
	int* MedianOfThree(int * a, int * b, int * c);
};

void IntroSort::sort(vector<int>& ivector)
{	
	int ivector_size = ivector.size();
	int depthLimit = 2 * log(ivector_size);

	int* begin = &ivector[0];
	int* end = &ivector[ivector_size - 1 ];

	IntrosortUtil(ivector, begin, end, depthLimit);
}

int* IntroSort::MedianOfThree(int * a, int * b, int * c)
{
	if (*a < *b && *b < *c)
		return (b);

	if (*a < *c && *c <= *b)
		return (c);

	if (*b <= *a && *a < *c)
		return (a);

	if (*b < *c && *c <= *a)
		return (c);

	if (*c <= *a && *a < *b)
		return (a);

	if (*c <= *b && *b <= *c)
		return (b);
}

void IntroSort::IntrosortUtil(vector<int>& ivector, int * begin, int * end, int depthLimit)
{
	// Count the number of elements
	int size = end - begin;

	// If partition size is low then do insertion sort
	if (size < 16)
	{
		InsertionSort(ivector, begin, end);
		return;
	}

	// If the depth is zero use heapsort
	if (depthLimit == 0)
	{
		make_heap(begin, end + 1);
		sort_heap(begin, end + 1);
		return;
	}

	// Else use a median-of-three concept to
	// find a good pivot
	int * pivot = MedianOfThree(begin, begin + size / 2, end);

	// Swap the values pointed by the two pointers
	swapValue(pivot, end);

	// Perform Quick Sort
	int * partitionPoint = Partition(ivector, begin - &ivector[0], end - &ivector[0]);
	IntrosortUtil(ivector, begin, partitionPoint - 1, depthLimit - 1);
	IntrosortUtil(ivector, partitionPoint + 1, end, depthLimit - 1);

	return;
}

void IntroSort::swapValue(int *a, int *b)
{
	int *temp = a;
	a = b;
	b = temp;
	return;
}

void IntroSort::InsertionSort(vector<int>& ivector, int *begin, int *end)
{
	// Get the left and the right index of the subarray
	// to be sorted
	int left = begin - &ivector[0];
	int right = end - &ivector[0];

	for (int i = left + 1; i <= right; i++)
	{
		int key = ivector[i];
		int j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= left && ivector[j] > key)
		{
			ivector[j + 1] = ivector[j];
			j = j - 1;
		}
		ivector[j + 1] = key;
	}

	return;
}

int* IntroSort::Partition(vector<int>& ivector, int low, int high)
{
	int pivot = ivector[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (ivector[j] <= pivot)
		{
			// increment index of smaller element
			i++;

			swap(ivector[i], ivector[j]);
		}
	}
	swap(ivector[i + 1], ivector[high]);
	return (&ivector[0] + i + 1);
}

#endif // !INTROSORT_H

