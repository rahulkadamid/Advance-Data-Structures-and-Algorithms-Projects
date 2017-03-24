#include <iostream>

#include "HashMap.h"

using namespace std;

HashMap::HashMap() 
{
	for (int i = 0; i < max_size; i++) 
	{
		keys[i] = string();
		values[i] = string();
	}
}

unsigned int HashMap::hash(const string& k)
{
	size_t value = 0;
	size_t klength = k.length();

	for (size_t i = 0; i < klength; i++)
		value = 37 * value + k[i];
	return value;
}

void HashMap::print()
{
	for (long i = 0; i < max_size; i++)
	{
		if (!keys[i].empty())
		{
			cout << keys[i] << "-->" << "\t" << values[i];
			cout << endl;
		}
	}		
}

int HashMap::find_index(const string& key, bool override = true)
{
	long  h = hash(key) % max_size, offset = 0, index;

	while (offset < max_size) 
	{
		index = (h + offset) % max_size;
		if (keys[index].empty() ||
			(override && keys[index] == key))
			return index;
		offset++;
	}
	return -1;
}

void HashMap::insert(const string& key, const string& value)
{
	long index = find_index(key);
	if (index == -1) 
	{
		cout << "Hash Map is full,please decrease number of input files..." << endl;
		return;
	}
	string str = find(key);
	string str2 = value + "  ";
	keys[index] = key;
	string current_str = values[index];
	if (current_str.find(value) == std::string::npos) // If current_str does not contain value
	{
		values[index] += str2;
	}
	
}

string HashMap::find(const string& key) 
{
	long index = find_index(key);
	if (index != -1)
		return values[index];
	return "";
}
