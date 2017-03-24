

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

#ifndef TEST_GENINPUT
#define TEST_GENINPUT

void genAscending(vector<int>& ivector);
void genDescending(vector<int>& ivector);
void genRandom(vector<int>& ivector);

int main()
{
	vector<int> Ascending_ivector;
	vector<int> Descending_ivector;
	vector<int> Random_ivector;

	genAscending(Ascending_ivector);
	genDescending(Descending_ivector);
	genRandom(Random_ivector);

	return 0;
}

void genAscending(vector<int>& ivector)
{
	for (int i = 1; i <= 8000; i++)
	{
		ivector.push_back(i);
	}

	int ivector_size = ivector.size();

	ofstream myfile;
	myfile.open("ascending.txt");

	for (int i = 0 ; i < ivector_size; i++)
	{	
		if (i % 10 == 0 && i != 0)
		{
			myfile << "\n";
		}
		myfile << ivector.at(i) << '-';
		
	}
	myfile.close();
}
void genDescending(vector<int>& ivector)
{
	for (int i = 8000; i > 0; i--)
	{
		ivector.push_back(i);
	}

	int ivector_size = ivector.size();

	ofstream myfile2;
	myfile2.open("descending.txt");

	for (int i = 0; i < ivector_size; i++)
	{
		if (i % 10 == 0 && i != 0)
		{
			myfile2 << "\n";
		}
		myfile2 << ivector.at(i) << '-';

	}
	myfile2.close();

}
void genRandom(vector<int>& ivector)
{	
	srand((unsigned int)time(0));

	int random_value;

	for (int i = 1; i <= 8000; i++)
	{	
		random_value = (rand() % 10000) + 1;
		ivector.push_back(random_value);
	}

	int ivector_size = ivector.size();

	ofstream myfile3;
	myfile3.open("random.txt");

	for (int i = 0; i < ivector_size; i++)
	{
		if (i % 10 == 0 && i != 0)
		{
			myfile3 << "\n";
		}
		myfile3 << ivector.at(i) << '-';

	}
	myfile3.close();

}

#endif // !TEST_GENINPUT