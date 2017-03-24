#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <string>

using namespace std;

class HashMap	
{
public:
	HashMap();
	string find(const string& key);
	void insert(const string& key, const string& value);
	void print();
protected:
	const static unsigned long max_size = 20000;
	unsigned int hash(const string& key);
	int find_index(const string& key, bool override);	
	string keys[max_size];
	string values[max_size];
};

#endif