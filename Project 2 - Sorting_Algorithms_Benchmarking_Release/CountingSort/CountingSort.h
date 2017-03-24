#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "../ISort/ISort.h"

using namespace std;

class CountingSort:public ISort
{
public:
	CountingSort() {}
	~CountingSort() {}
	void sort(vector<int>& ivector);
	
};


void CountingSort::sort(vector<int>& ivector)
{	
	int min = *std::min_element(ivector.begin(), ivector.end());
	int max = *std::max_element(ivector.begin(), ivector.end());
	int k = max - min + 1;
	
	vector<int> buckets(k, 0);

	auto it = ivector.begin();

	for (auto i : ivector) 
		buckets[i - min] += 1;

	for (int i = min; i <= max; i++) 
	{
		if (!buckets[i - min]) 
			continue;
		fill(it, it + buckets[i - min], i);
		it += buckets[i - min];
	}
	
}

#endif // !COUNTINGSORT_H

