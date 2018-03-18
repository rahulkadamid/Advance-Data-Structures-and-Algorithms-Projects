#ifndef SKIPLIST_MARKOV_NODE_H
#define SKIPLIST_MARKOV_NODE_H

#include <string>
#include <iostream>

template <class T>
class Skiplist_Markov_Node 
{
public:
	Skiplist_Markov_Node(T t) : info(t) {}
	~Skiplist_Markov_Node() {}
	T getRandom();
	IVector<T> v;
	T info;
	IVector<Skiplist_Markov_Node<T> *> next;

};

template<class T>
T Skiplist_Markov_Node<T>::getRandom()
{	
	int i;

	int size = v.size();

	i = (std::rand() % size);

	return v.at(i);
}


#endif