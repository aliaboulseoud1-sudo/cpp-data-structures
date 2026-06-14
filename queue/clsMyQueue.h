#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <typename T>
class clsMyQueue {
protected:
	clsDblLinkedList <T> _MyList;

public:
	void push(const T& item) {
		_MyList.InsertAtEnd(item);
	}

	void Print() {
		if (Size() == 0) {
			cout << "Queue is empty" << endl;
			return;
		}

		cout << "front -> ";

		for (int i = 0; i < Size(); i++) {
			cout << _MyList.getItem(i);

			if (i != Size() - 1) {
				cout << " -> ";
			}
		}

		cout << " <- Back" << endl;
	}

	void pop() {
		if (Size() == 0) throw std::out_of_range("Queue is empty");
		_MyList.DeleteFirstNode();
	}

	int Size() {
		return _MyList.Size();
	}

	const T& front() {
		if (Size() == 0) throw std::out_of_range("Queue is empty");
		return _MyList.getItem(0);
	}

	const T& back() {
		if (Size() == 0) throw std::out_of_range("Queue is empty");
		return _MyList.getItem(Size() - 1);
	}

	bool IsEmpty() {
		return _MyList.IsEmpty();
	}

	T getItem(int index) {
		return _MyList.getItem(index);
	}

	void Reverse() {
		_MyList.Reverse();
	}

	bool UpdateItem(int index, const T& NewValue) {
		return _MyList.UpdateItem(index, NewValue);
	}

	void InsertAfter(int index, const T& value) {
		_MyList.InsertAfter(index, value);
	}

	void InsertAtFront(const T& value) {
		_MyList.InsertAtBeginning(value);
	}

	void InsertAtBack(const T& value) {
		_MyList.InsertAtEnd(value);
	}

	void Clear() {
		_MyList.Clear();
	}
};

