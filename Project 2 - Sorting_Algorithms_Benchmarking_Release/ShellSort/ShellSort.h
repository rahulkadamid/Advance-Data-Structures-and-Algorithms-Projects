#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "../ISort/ISort.h"

using namespace std;

class ShellSort:public ISort
{
public:
	ShellSort() {}
	~ShellSort() {}
	void sort(vector<int>& ivector);

};

void ShellSort::sort(vector<int>& ivector)
{
	int ivector_size = ivector.size();

	for (int gap = ivector_size / 2; gap > 0; gap /= 2)
	{

		for (int i = gap; i < ivector_size; i += 1)
		{

			int temp = ivector[i];

			int j;

			for ( j = i; j >= gap && ivector[j - gap] > temp; j -= gap)
				ivector[j] = ivector[j - gap];

			ivector[j] = temp;
		}
	}
}

#endif // !SHELLSORT_H

