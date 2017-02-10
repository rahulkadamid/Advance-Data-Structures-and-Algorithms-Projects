#ifndef IVECTOR_H
#define IVECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class IVector
{
	public:
		void push_back(T t);
		T& at(int i);
		int size();
		IVector();
		~IVector();
		

	private:
		void resize();
		T* array;
		int vsize;
		int capacity;

};

template <class T>
IVector<T>::IVector() {
	vsize = 0;
	capacity = 1;
	array = new T[capacity];
}

template <class T>
IVector<T>::~IVector() {
	delete[] array;
}


template <class T>
void IVector<T>::push_back(T t)
{
	if (vsize + 1 > capacity) 
		resize();
	array[vsize] = t;
	vsize++;

}

template <class T>
T& IVector<T>::at(int i)
{	

	return array[i];

}

template <class T>
int IVector<T>::size()
{
	return vsize;
}

template <class T>
void IVector<T>::resize()
{
	capacity *= 2;
	T* new_array = new T[capacity];
	for (int i = 0; i < vsize; i++)
	{
		new_array[i] = array[i];
	}
	delete[] array;
	array = new_array;

};

#endif