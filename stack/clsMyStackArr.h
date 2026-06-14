#pragma once

#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;

template <typename T>
class clsMyStackArr : public clsMyQueueArr <T> { // Composition is more better, but it is only for learning
public:
	void push(const T& item) {
		clsMyQueueArr<T>::_MyDynamicArr.InsertAtBeginning(item);
	}

	T Top() {
		return clsMyQueueArr<T>::front();
	}

	T Bottom() {
		return clsMyQueueArr<T>::back();
	}

	void Print() {
		if (clsMyQueueArr<T>::Size() == 0) {
			cout << "Stack is empty" << endl;
			return;
		}

		cout << "top -> ";

		for (int i = 0; i < clsMyQueueArr<T>::Size(); i++) {
			cout << clsMyQueueArr<T>::_MyDynamicArr.getItem(i);

			if (i != clsMyQueueArr<T>::Size() - 1) {
				cout << " <- ";
			}
		}

		cout << endl;
	}
};

