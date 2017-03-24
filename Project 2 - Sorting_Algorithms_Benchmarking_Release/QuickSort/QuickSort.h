#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "../ISort/ISort.h"

using namespace std;

class QuickSort:public ISort
{
public:
	QuickSort() {}
	~QuickSort() {}
	void sort(vector<int>& ivector, int low, int high);
	void sort(vector<int>& ivector);
};

void QuickSort::sort(vector<int>& ivector)
{
	sort(ivector, 0, ivector.size() - 1);

}

void QuickSort::sort(vector<int>& ivector , int low , int high )
{
	int i = low, j = high;
	int tmp;
	int pivot = ivector[(low + high) / 2];

	/* partition */
	while (i <= j) {
		while (ivector[i] < pivot)
			i++;
		while (ivector[j] > pivot)
			j--;
		if (i <= j) {
			tmp = ivector[i];
			ivector[i] = ivector[j];
			ivector[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (low < j)
		sort(ivector, low, j);
	if (i < high)
		sort(ivector, i, high);
}

#endif // !QUICKSORT_H

