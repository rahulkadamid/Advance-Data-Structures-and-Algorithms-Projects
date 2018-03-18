#ifndef DLL_MARKOV_H
#define DLL_MARKOV_H

#include <iostream>
#include <string>
#include "IMarkov.h"
#include "DLL_Markov_Node.h"

template<class T>
class DLL_Markov : public IMarkov<T>
{
public:
	DLL_Markov();
	~DLL_Markov();
	void add(T t1, T t2);
	T generate(int);	
	void printAll();
	void addToDLLTail(const T& el);
	DLL_Markov_Node<T>* find(const T& el) const;
	void clear();
	int sizeOfList(DLL_Markov_Node<T> *temp);

private:
	DLL_Markov_Node<T> *head, *tail;
};

template<class T>
DLL_Markov<T>::DLL_Markov()
{
	head = tail = 0;
}
 
template<class T>
DLL_Markov<T>::~DLL_Markov()
{
	clear();
}

template <class T>
DLL_Markov_Node<T>* DLL_Markov<T>::find(const T& el) const
{
	DLL_Markov_Node<T> *tmp;

	for (tmp = head; tmp != 0 && !(tmp->info == el);tmp = tmp->next);

	if (tmp == 0)
		return 0;
	else 
		return tmp;
}

template<class T>
void DLL_Markov<T>::addToDLLTail(const T& el) {
	if (tail != 0) {
		tail = new DLL_Markov_Node<T>(el, 0, tail);
		tail->prev->next = tail;
	}
	else head = tail = new DLL_Markov_Node<T>(el);
}

template<class T>
void DLL_Markov<T>::printAll()
{	
	DLL_Markov_Node<T> *temp;

	std::cout << "-----------------Nodes and Vectors--------------------" << endl;

	for (temp = head; temp != 0; temp = temp->next)
	{
		std::cout << "\n";
		cout << "Node	 -> " << temp->info << endl;
		cout << "Vectors  -> ";
		for (int i = 0; i < temp->v.size(); i++)
		{
			cout << temp->v.at(i) << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	std::cout << "-----------------Doubly Linked List--------------------" << endl;

	std::cout << "\n";

	for (temp = head; temp != 0; temp = temp->next)
	{
		cout << temp->info << " <-> ";
	}
	std::cout << "\n";

}

template<class T>
void DLL_Markov<T>::clear()
{
	for (DLL_Markov_Node<T> *tmp; head != 0;) 
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template<class T>
int DLL_Markov<T>::sizeOfList(DLL_Markov_Node<T> *temp)
{	
	int lengthoflist = 0;

	for (temp = head; temp != 0; temp = temp->next)
		lengthoflist++;

	return lengthoflist;
}

template<class T>
void DLL_Markov<T>::add(T t1, T t2)
{	
	DLL_Markov_Node<T> *temp;
	temp = find(t1);

	if (temp != 0)
	{
		temp->addNew(t2);
	}
	else
	{
		addToDLLTail(t1);
		tail->addNew(t2);
	}
	
}

template<class T>
T DLL_Markov<T>::generate(int t)
{	

	int lengthoflist = 0;

	DLL_Markov_Node<T> *temp = head;
	
	lengthoflist = sizeOfList(temp);

	int traverse = 0;

	traverse = (rand() % lengthoflist) + 1;

	int count = 0;

	for (temp = head; temp != 0; temp = temp->next)
	{
		if (count == traverse)
			break;
		count++;
	}

	string vector_string, final_string;

	for (int i = 0; i < t; i++)
	{
		final_string += temp->info;

		final_string += " ";

		vector_string = temp->getRandom();

		temp = find(vector_string);			
	}

	return final_string;
}

#endif