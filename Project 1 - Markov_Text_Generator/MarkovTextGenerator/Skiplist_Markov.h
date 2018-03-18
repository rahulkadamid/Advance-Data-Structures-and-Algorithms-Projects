#ifndef SKIPLIST_MARKOV_H
#define SKIPLIST_MARKOV_H

#include "Skiplist_Markov_Node.h"

template<class T>
class Skiplist_Markov : public IMarkov<T> 
{
public:
	Skiplist_Markov() : head(0) {}
	~Skiplist_Markov(){}

	T generate(int i);
	void add(T t1, T t2);
	void clear();
	Skiplist_Markov_Node<T> **find(T t, Skiplist_Markov_Node<T> **first = 0);
	Skiplist_Markov_Node<T> *add(T t);
	Skiplist_Markov_Node<T> *getNode(unsigned i);	

private:
	unsigned sizeOfList();
	Skiplist_Markov_Node<T> *head;
};

template class Skiplist_Markov<std::string>;

template <class T>
void Skiplist_Markov<T>::clear()
{
	Skiplist_Markov_Node<T> *next;
	for (Skiplist_Markov_Node<T> *current = head; current; current = next)
	{
		next = current->next.at(0);
		delete current;
	}
}

template <class T>
Skiplist_Markov_Node<T> **Skiplist_Markov<T>::find(T t, Skiplist_Markov_Node<T> **first) 
{
	if (!head)
		return 0;

	Skiplist_Markov_Node<T> *current = head;

	int levelCount = current->next.size();

	Skiplist_Markov_Node<T> **results = new Skiplist_Markov_Node<T> *[levelCount];


	for (int current_level = levelCount - 1; current_level != -1; --current_level) 
	{

		while (current->next.at(current_level) && t >= current->next.at(current_level)->info)
			current = current->next.at(current_level);
		results[current_level] = current;
	}

	if (first)
		*first = results[0];

	return results;
}

template <class T>
Skiplist_Markov_Node<T> *Skiplist_Markov<T>::add(T t) 
{

	Skiplist_Markov_Node<T> **lefts = find(t);

	if (!lefts)
	{

		head = new Skiplist_Markov_Node<T>(t);
		head->next.push_back(0);
		return head;
	}


	if (lefts[0]->info == t)
	{

		Skiplist_Markov_Node<T> *r = lefts[0];
		delete[] lefts; // forget this and you have some nice memory leakage going on 
		return r;
	}


	unsigned newLevel = 0;
	while (rand() % 2)
		++newLevel;

	Skiplist_Markov_Node<T> *newNode = new Skiplist_Markov_Node<T>(t);

	for (unsigned l = 0; l <= newLevel; ++l)
	{

		if (l < (head->next.size()))
		{

			newNode->next.push_back(lefts[l]->next.at(l));
			lefts[l]->next.at(l) = newNode;
		}
		else 
		{

			newNode->next.push_back(0);
			head->next.push_back(newNode);
		}

	}

	delete[] lefts;
	return newNode;
}

template <class T>
unsigned Skiplist_Markov<T>::sizeOfList() {
	unsigned count = 0;
	for (Skiplist_Markov_Node<T> *current = head; current; current = current->next.at(0))
		++count;
	return count;
}

template <class T>
Skiplist_Markov_Node<T> *Skiplist_Markov<T>::getNode(unsigned i) {
	Skiplist_Markov_Node<T> *current;
	for (current = head; current && i; --i)
		current = current->next.at(0);
	return current;
}


template <class T>
void Skiplist_Markov<T>::add(T t1, T t2) {

	Skiplist_Markov_Node<T> *n1 = add(t1);

	n1->v.push_back(t2);
}

template <class T>
T Skiplist_Markov<T>::generate(int n) 
{
	T final_string;

	Skiplist_Markov_Node<T> *current;

	current = getNode(rand() % sizeOfList());

	T immediate_string = current->info;

	for (int i = 0; i < n && current->info == immediate_string; ++i)
	{
		final_string += immediate_string;
		final_string += ' ';

		immediate_string = current->getRandom();

		delete[] find(immediate_string, &current);
	}

	return final_string;
}

#endif