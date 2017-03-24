#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <vector>

using namespace std;

class Queue 
{
private:
	vector<string> item;
	int rear;
	int front;
public:
	Queue();
	void enqueue(string);
	string dequeue();
	int size();
	void display();
	bool isEmpty();
	void clear();
};

#endif
