
#include <iostream>
#include "../CountingSort/CountingSort.h"

using namespace std;


int main()
{
	vector<int> v1 = { 1, 2, 3 , 4 , 5 , 6 , 7 ,8 , 9, 10 };
	vector<int> v2 = { 2, 1, 3 , 5 , 4 , 3, 2, 1 , 7, 8 };
	vector<int> v3 = { 10, 9, 8 , 7 , 6 , 5 , 4 ,3 , 2, 1 };

	int v1Size = v1.size();
	int v2Size = v2.size();
	int v3Size = v3.size();

	CountingSort cs;

	/**********************************************/
	cout << "\nBest Case:" << endl;

	cout << "\nBefore:" << endl;
	for (int i = 0; i < v1Size; i++)
		cout << v1.at(i) << " " ;
	
	cs.sort(v1);

	cout << "\nAfter:" << endl;
	for (int i = 0; i < v1Size; i++)
		cout << v1.at(i) << " ";
	/**********************************************/
	cout << "\nAvg Case:" << endl;

	cout << "\nBefore:" << endl;
	for (int i = 0; i < v2Size; i++)
		cout << v2.at(i) << " ";

	cs.sort(v2);

	cout << "\nAfter:" << endl;
	for (int i = 0; i < v2Size; i++)
		cout << v2.at(i) << " " ;
	/**********************************************/
	cout << "\nRandom Case:" << endl;

	cout << "\nBefore:" << endl;
	for (int i = 0; i < v3Size; i++)
		cout << v3.at(i) << " ";

	cs.sort(v3);

	cout << "\nAfter:" << endl;
	for (int i = 0; i < v3Size; i++)
		cout << v3.at(i) << " ";


	return 0;
}