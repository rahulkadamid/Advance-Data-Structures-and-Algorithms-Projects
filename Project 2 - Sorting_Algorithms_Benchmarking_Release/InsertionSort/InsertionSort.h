#ifndef INSERTIONSORT_H
#define INSETIONSORT_H

#include "../ISort/ISort.h"

using namespace std;

class InsertionSort:public ISort
{
public:
	InsertionSort() {}
	~InsertionSort() {}
	void sort(vector<int>& ivector);

};

void InsertionSort::sort(vector<int>& ivector)
{
	int i, key, j;

	int ivector_size = ivector.size();

	for (i = 1; i < ivector_size; i++)
	{
		key = ivector[i];
		j = i - 1;

		while (j >= 0 && ivector[j] > key)
		{
			ivector[j + 1] = ivector[j];
			j = j - 1;
		}
		ivector[j + 1] = key;
	}

}




#endif // !INSERTIONSORT_H

