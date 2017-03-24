#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "../ISort/ISort.h"

using namespace std;

class BubbleSort:public ISort
{
public:
	BubbleSort() {}
	~BubbleSort() {}
	void sort(vector<int>& ivector);
	void swap(int &a, int &b);

};

void BubbleSort::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort::sort(vector<int>& ivector)
{
	int i, j;
	
	bool swapped;

	int ivector_size = ivector.size();

	for (i = 0; i < ivector_size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < ivector_size - i - 1; j++)
		{
			if (ivector[j] > ivector[j + 1])
			{
				swap(ivector[j], ivector[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}

}

#endif // !BUBBLESORT_H

