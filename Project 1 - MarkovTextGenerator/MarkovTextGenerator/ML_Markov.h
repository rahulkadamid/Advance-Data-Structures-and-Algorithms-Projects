#ifndef ML_MARKOV_H
#define ML_MARKOV_H


#include <iostream>
#include <string>
#include "IMarkov.h"
#include "ML_Markov_Node.h"

template<class T>
class ML_Markov : public IMarkov<T>
{
public:
	ML_Markov();
	~ML_Markov();
	void add(T t1, T t2);
	T generate(int);	
	void printAll();
	void addToDLLTail(const T& el);
	ML_Markov_Node<T>* find(const T& el) const;
	void clear();
	int sizeOfList(ML_Markov_Node<T> *temp);

private:
	int size;
	ML_Markov_Node<T> *head, *tail;
};


template<class T>
ML_Markov<T>::ML_Markov()
{
	head = tail = 0;
}

template<class T>
ML_Markov<T>::~ML_Markov()
{
	clear();
}

template<class T>
void ML_Markov<T>::clear()
{
	for (ML_Markov_Node<T> *tmp; head != 0;)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template<class T>
void ML_Markov<T>::addToDLLTail(const T& el) {
	if (tail != 0) {
		tail = new ML_Markov_Node<T>(el, 0, tail);
		tail->prev->next = tail;
	}
	else head = tail = new ML_Markov_Node<T>(el);
}

template<class T>
void ML_Markov<T>::printAll()
{
	ML_Markov_Node<T> *temp;

	std::cout << "-----------------Nodes and Vectors--------------------" << endl;

	for (temp = head; temp != 0; temp = temp->next)
	{
		std::cout << "\n";
		cout << "Node	 -> " << temp->info << endl;
		cout << "Vectors  -> ";
		for (int i = 0; i < temp->v.size(); i++)
		{	
			ML_Markov_Node<T> *temp2;

			temp2 = temp->v.at(i);

			cout << temp2->info << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	std::cout << "-----------------Multi Linked List--------------------" << endl;

	for (temp = head; temp != 0; temp = temp->next)
	{
		cout << temp->info << " <-> ";
	}
	std::cout << "\n";

}

template <class T>
ML_Markov_Node<T>* ML_Markov<T>::find(const T& el) const
{
	ML_Markov_Node<T> *tmp;

	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);

	if (tmp == 0)
		return 0;
	else
		return tmp;
}


template<class T>
int ML_Markov<T>::sizeOfList(ML_Markov_Node<T> *temp)
{
	int lengthoflist = 0;

	for (temp = head; temp != 0; temp = temp->next)
		lengthoflist++;

	return lengthoflist;
}

template<class T>
void ML_Markov<T>::add(T t1, T t2)
{
	if (tail == 0)		 
	{
		head = tail = new ML_Markov_Node<T>(t1);
		tail = new ML_Markov_Node<T>(t2, 0, tail);
		tail->prev->next = tail;
		head->addNew(tail);
	}
	else               
	{
		ML_Markov_Node<T> *temp1;
		temp1 = find(t1);

		ML_Markov_Node<T> *temp2;
		temp2 = find(t2);

		if (temp2 != 0)			 
		{
			temp1->addNew(temp2);
		}
		else                    
		{
			addToDLLTail(t2);
			temp1->addNew(tail);
		}		
	}
}

template<class T>
T ML_Markov<T>::generate(int t)
{	
	int lengthoflist = 0;

	ML_Markov_Node<T> *temp = head;

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
	
	IVector<string> elems;

	string  final_string;

	while (elems.size() != t)
	{
		elems.push_back(temp->info);

		ML_Markov_Node<T>* temp2;
		temp2 = temp->getRandom();
		
		temp = temp2;
		
	}

	for (int i = 0; i < elems.size(); i++)
	{
		final_string += elems.at(i);

		final_string += " ";
	}

	return final_string;

}

#endif