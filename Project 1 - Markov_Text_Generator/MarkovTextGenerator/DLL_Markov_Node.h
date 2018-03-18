#ifndef DLL_MARKOV_NODE_H
#define DLL_MARKOV_NODE_H

#include "IVector.h"
#include <iostream>
#include <string>

using namespace std;

template<class T>
class DLL_Markov_Node
{
public:
	DLL_Markov_Node();		
	DLL_Markov_Node(const T& el, DLL_Markov_Node<T> *n = 0, DLL_Markov_Node<T> *p = 0);
	~DLL_Markov_Node();
	void addNew(T t);
	T getRandom();
	T info;
	IVector<T> v;
	DLL_Markov_Node<T> *next, *prev;
	
};


template<class T>
DLL_Markov_Node<T>::DLL_Markov_Node()
{
	next = prev = 0;
}

template<class T>
DLL_Markov_Node<T>::DLL_Markov_Node(const T& el, DLL_Markov_Node<T> *n = 0, DLL_Markov_Node<T> *p = 0)
{
	info = el; next = n; prev = p;
}

template<class T>
DLL_Markov_Node<T>::~DLL_Markov_Node()
{

}

template<class T>
void DLL_Markov_Node<T>::addNew(T t)
{
	v.push_back(t);
}

template<class T>
T DLL_Markov_Node<T>::getRandom()
{	
	int i;

	int size = v.size();
	
	i = (std::rand() % size);

	return v.at(i);

}

#endif