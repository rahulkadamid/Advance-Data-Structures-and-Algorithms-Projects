#ifndef ISORT_H
#define ISORT_H

#include <vector>
using namespace std;

class ISort 
{ 
public:
	ISort() {} 
	virtual ~ISort() {} 
	virtual void sort(vector<int>& ivector) = 0; 

};


#endif // !ISORT_H

