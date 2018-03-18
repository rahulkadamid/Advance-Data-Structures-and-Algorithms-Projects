#ifndef IMARKOV_H
#define IMARKOV_H

template<class T>
class IMarkov
{
public:
	virtual void add(T, T) = 0;
	virtual T generate(int) = 0;
	virtual ~IMarkov() {}
};

#endif