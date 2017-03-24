#include <iostream>

#include "HashMap.h"

using namespace std;

#ifdef TEST_HASHMAP

int main()
{

	cout << "Testing HashMap" << endl;


	HashMap hm;

	hm.insert("Rahul", "Rahul V");
	hm.insert("Mala", "Mala V");
	hm.insert("Milind", "Milind V");
	hm.insert("Rahul", "Rahul V2");
	hm.insert("Rahul", "Rahul V");

	hm.print();

	cout << hm.find("Rahul") << endl;
	cout << hm.find("Milind") << endl;


	return 0;
}

#endif