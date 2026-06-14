/* #include <iostream>
#include "clsMyQueue.h"

using namespace std;

int main() {
	clsMyQueue<int> MyQueue;

	MyQueue.push(10);
	MyQueue.push(20);
	MyQueue.push(30);
	MyQueue.push(40);
	MyQueue.push(50);

	cout << "\nQueue Content:\n";
	MyQueue.Print();

	cout << "\n\nQueue Size: " << MyQueue.Size();
	cout << "\nQueue Front: " << MyQueue.front();
	cout << "\nQueue Back: " << MyQueue.back();


	MyQueue.pop();
	MyQueue.pop();

	cout << "\n\nQueue Content After 2 pop():\n";
	MyQueue.Print();

	cout << "\nQueue Front: " << MyQueue.front();

	cout << "\n\nItem (2): " << MyQueue.getItem(2);

	MyQueue.Reverse();
	cout << "\n\nQueue after reverse():\n";
	MyQueue.Print();

	MyQueue.UpdateItem(2, 600);
	cout << "\n\nQueue after updating item (2) to 600: \n";
	MyQueue.Print();

	MyQueue.InsertAfter(2, 800);
	cout << "\n\nQueue after inserting 800 after item (2): \n";
	MyQueue.Print();

	MyQueue.InsertAtFront(1000);
	cout << "\n\nQueue after inserting 1000 at front: \n";
	MyQueue.Print();

	MyQueue.InsertAtBack(2000);
	cout << "\n\nQueue after inserting 2000 at back: \n";
	MyQueue.Print();

	MyQueue.Clear();
	cout << "\n\nQueue after clear(): \n";
	MyQueue.Print();

	return 0;
}  */