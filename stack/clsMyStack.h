#pragma once

#include <iostream>
#include "clsMyQueue.h"

using namespace std;

template <typename T>
class clsMyStack : public clsMyQueue <T> { // Composition is better, but it is only for learning
public:
	void push(const T& item) {
		clsMyQueue<T>::_MyList.InsertAtBeginning(item);
	}

	const T& Top() {
		return clsMyQueue<T>::front();
	}

	const T& Bottom() {
		return clsMyQueue<T>::back();
	}

	void Print() {
		if (clsMyQueue<T>::Size() == 0) {
			cout << "Stack is empty" << endl;
			return;
		}

		cout << "top -> ";

		for (int i = 0; i < clsMyQueue<T>::Size(); i++) {
			cout << clsMyQueue<T>::_MyList.getItem(i);

			if (i != clsMyQueue<T>::Size() - 1) {
				cout << " <- ";
			}
		}

		cout << endl;
	}
};
