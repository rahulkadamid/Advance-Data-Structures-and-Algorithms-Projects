#ifndef MERGESORT_H
#define MERGESORT_H

#include "../ISort/ISort.h"

using namespace std;

class MergeSort:public ISort
{
public:
	MergeSort() {}
	~MergeSort() {}
	void sort(vector<int>& ivector, int l, int r);
	void sort(vector<int>& ivector);
	void merge(vector<int>& ivector, int l, int m, int r);

};

void MergeSort::merge(vector<int>& ivector, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int> L(n1);
	vector<int> R(n2);

	for (i = 0; i < n1; i++)
		L[i] = ivector[l + i];
	for (j = 0; j < n2; j++)
		R[j] = ivector[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			ivector[k] = L[i];
			i++;
		}
		else
		{
			ivector[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		ivector[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		ivector[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort::sort(vector<int>& ivector)
{
	sort(ivector, 0, ivector.size() - 1);
}

void MergeSort::sort(vector<int>& ivector , int l , int r)
{	

	if (l < r)
	{
		
		int m = l + (r - l) / 2;

		sort(ivector, l, m);
		sort(ivector, m + 1, r);

		merge(ivector, l, m, r);
	}
}

#endif // !MERGESORT_H

