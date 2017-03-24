
#include <iostream>

#include "Queue.h"

using namespace std;

int main()
{
	Queue queue;
	int choice;
	string data;
	while (1) 
	{
		cout << "\n1. Enqueue\n2. Dequeue\n3. Size\n4. Display all element\n5. Quit";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "\nEnter data: ";
			cin >> data;
			queue.enqueue(data);			
			break;
		case 2:
			if (!queue.isEmpty()) {
				cout << "The data dequeued is :" << queue.dequeue();
			}
			else {
				cout << "Queue is Emtpy" << endl;
			}
			break;
		case 3:
			cout << "Size of Queue is " << queue.size();
			break;
		case 4:
			queue.display();
			break;
		case 5:
			exit(0);
			break;
		}
	}
	return 0;
}