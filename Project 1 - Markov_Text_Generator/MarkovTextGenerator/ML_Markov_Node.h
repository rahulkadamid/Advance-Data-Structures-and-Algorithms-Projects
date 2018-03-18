#ifndef ML_MARKOV_NODE_H
#define ML_MARKOV_NODE_H

#include "IVector.h"
#include <iostream>
#include <string>

template<class T>
class ML_Markov_Node
{
public:
	ML_Markov_Node();
	ML_Markov_Node(const T& el, ML_Markov_Node<T> *n = 0, ML_Markov_Node<T> *p = 0);
	~ML_Markov_Node();
	void addNew(ML_Markov_Node<T>* t);
	ML_Markov_Node<T>* getRandom();
	T info;
	IVector<ML_Markov_Node<T>*> v;
	ML_Markov_Node<T> *next, *prev;
	
};

template<class T>
ML_Markov_Node<T>::ML_Markov_Node()
{
	next = prev = 0;
}

template<class T>
ML_Markov_Node<T>::ML_Markov_Node(const T& el, ML_Markov_Node<T> *n = 0, ML_Markov_Node<T> *p = 0)
{
	info = el; next = n; prev = p;
}

template<class T>
ML_Markov_Node<T>::~ML_Markov_Node()
{
}

template<class T>
void ML_Markov_Node<T>::addNew(ML_Markov_Node<T>* t)
{
	v.push_back(t);
}

template<class T>
ML_Markov_Node<T>* ML_Markov_Node<T>::getRandom()
{
	int i;
	int size = v.size();
	
	i = (std::rand() % size);

	return v.at(i);
}

#endif