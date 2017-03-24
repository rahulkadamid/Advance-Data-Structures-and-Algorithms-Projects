#ifndef COMBSORT_H
#define COMBSORT_H

#include "../ISort/ISort.h"

using namespace std;

class CombSort:public ISort
{
public:
	CombSort() {}
	~CombSort() {}
	void sort(vector<int>& ivector);
	void swap(int &a, int &b);
	int getNextGap(int gap);

};

int CombSort::getNextGap(int gap)
{
	gap = (gap * 10) / 13;

	if (gap < 1)
		return 1;
	return gap;
}


void CombSort::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void CombSort::sort(vector<int>& ivector)
{	
	int ivector_size = ivector.size();

	int gap = ivector_size;

	bool swapped = true;

	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap);

		swapped = false;

		for (int i = 0; i < ivector_size - gap; i++)
		{
			if (ivector[i] > ivector[i + gap])
			{
				swap(ivector[i], ivector[i + gap]);
				swapped = true;
			}
		}
	}

}

#endif // !COMBSORT_H

