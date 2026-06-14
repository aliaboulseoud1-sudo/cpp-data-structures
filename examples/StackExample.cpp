/* #include <iostream>
#include "clsMyStack.h"

using namespace std;

int main() {
	clsMyStack <int> MyStack;

	MyStack.push(10);
	MyStack.push(20);
	MyStack.push(30);
	MyStack.push(40);
	MyStack.push(50);

	cout << "\nStack: \n";
	MyStack.Print();


	MyStack.pop();
	cout << "\n\nStack after 1 pop(): \n";
	MyStack.Print();

	cout << "\n\nStack Size: " << MyStack.Size();
	cout << "\nStack Top: " << MyStack.Top();
	cout << "\nStack Bottom: " << MyStack.Bottom();

	cout << "\n\nItem (2): " << MyStack.getItem(2);

	MyStack.Reverse();
	cout << "\n\nStack after reverse():\n";
	MyStack.Print();

	MyStack.UpdateItem(2, 600);
	cout << "\n\nStack after updating item (2) to 600: \n";
	MyStack.Print();

	MyStack.InsertAfter(2, 800);
	cout << "\n\nStack after inserting 800 after item (2): \n";
	MyStack.Print();

	MyStack.InsertAtFront(1000);
	cout << "\n\nStack after inserting 1000 at top: \n";
	MyStack.Print();

	MyStack.InsertAtBack(2000);
	cout << "\n\nStack after inserting 2000 at bottom: \n";
	MyStack.Print();

	MyStack.Clear();
	cout << "\n\nStack after clear(): \n";
	MyStack.Print();



	return 0;
} */