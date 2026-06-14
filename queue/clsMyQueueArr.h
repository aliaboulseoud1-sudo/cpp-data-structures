#pragma once

#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

template <typename T>
class clsMyQueueArr {
protected:
	clsDynamicArray <T> _MyDynamicArr;

public:
	void push(const T& item) {
		_MyDynamicArr.InsertAtEnd(item);
	}

	void Print() {
		if (Size() == 0) {
			cout << "Queue is empty" << endl;
			return;
		}

		cout << "front -> ";

		for (int i = 0; i < Size(); i++) {
			cout << _MyDynamicArr.getItem(i);

			if (i != Size() - 1) {
				cout << " -> ";
			}
		}

		cout << " <- Back" << endl;
	}

	void pop() {
		if (Size() == 0) throw std::out_of_range("Queue is empty");
		_MyDynamicArr.DeleteFirstItem();
	}

	int Size() {
		return _MyDynamicArr.Size();
	}

	const T& front() {
		if (Size() == 0) throw std::out_of_range("Queue is empty");
		return _MyDynamicArr.getItem(0);
	}

	const T& back() {
		if (Size() == 0) throw std::out_of_range("Queue is empty");
		return _MyDynamicArr.getItem(Size() - 1);
	}

	bool IsEmpty() {
		return _MyDynamicArr.IsEmpty();
	}

	T getItem(int index) {
		return _MyDynamicArr.getItem(index);
	}

	void Reverse() {
		_MyDynamicArr.Reverse();
	}

	void UpdateItem(int index, const T& NewValue) {
		_MyDynamicArr.SetItem(index, NewValue);
	}

	void InsertAfter(int index, const T& value) {
		_MyDynamicArr.InsertAfter(index, value);
	}

	void InsertAtFront(const T& value) {
		_MyDynamicArr.InsertAtBeginning(value);
	}

	void InsertAtBack(const T& value) {
		_MyDynamicArr.InsertAtEnd(value);
	}

	void Clear() {
		_MyDynamicArr.Clear();
	}
};

