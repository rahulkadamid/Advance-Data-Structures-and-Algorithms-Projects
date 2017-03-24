
#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

Queue::Queue() {
	rear = 0;
	front = 0;
}

void Queue::enqueue(string data) {
	item.push_back(data);
	rear++;
}
string Queue::dequeue() {
	return item[front++];
}
void Queue::display() {
	if (!this->isEmpty()) {
		for (string str : item)
			cout << "    -> " << str << endl;
	}
	else {
		cout << "Queue Underflow" << endl;
	}
}
int Queue::size() {
	return item.size();
}
bool Queue::isEmpty() {
	if (item.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}
void Queue::clear() 
{
	item.clear();
}
