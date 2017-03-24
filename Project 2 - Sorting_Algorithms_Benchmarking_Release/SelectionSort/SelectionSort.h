#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "../ISort/ISort.h"

using namespace std;

class SelectionSort:public ISort
{
public:
	SelectionSort() {}
	~SelectionSort() {}
	void sort(vector<int>& ivector);
	void swap(int &a , int &b);

};

void SelectionSort::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort::sort(vector<int>& ivector)
{
	int i, j, min_elem;

	int ivector_size = ivector.size();

	for (i = 0; i < ivector_size - 1; i++)
	{
		min_elem = i;
		for (j = i + 1; j < ivector_size; j++)
			if (ivector[j] < ivector[min_elem])
				min_elem = j;

		swap(ivector[min_elem], ivector[i]);
	}

}


#endif // !SELECTIONSORT_H

