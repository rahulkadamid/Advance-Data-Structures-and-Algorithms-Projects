#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "../ISort/ISort.h"

using namespace std;

class HeapSort:public ISort
{
public:
	HeapSort() {}
	~HeapSort() {}
	void sort(vector<int>& ivector);
	void swap(int &a, int &b);
	void heapify(vector<int>& ivector, int n, int i);

};

void HeapSort::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void HeapSort::heapify(vector<int>& ivector, int n, int i)
{
	int largest = i;   
	int l = 2 * i + 1;   
	int r = 2 * i + 2;  

	if (l < n && ivector[l] > ivector[largest])
		largest = l;

	if (r < n && ivector[r] > ivector[largest])
		largest = r;

	if (largest != i)
	{
		swap(ivector[i], ivector[largest]);
		heapify(ivector, n, largest);
	}
}

void HeapSort::sort(vector<int>& ivector)
{	
	int ivector_size = ivector.size();

	for (int i = ivector_size / 2 - 1; i >= 0; i--)
		heapify(ivector, ivector_size, i);

	for (int i = ivector_size - 1; i >= 0; i--)
	{
		swap(ivector[0], ivector[i]);

		heapify(ivector, i, 0);
	}

}

#endif // !HEAPSORT_H

