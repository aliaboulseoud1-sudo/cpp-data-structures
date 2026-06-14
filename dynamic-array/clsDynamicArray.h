#pragma once

#include <iostream>
using namespace std;

template <typename T> 
class clsDynamicArray {
protected:
	int _size;
	T* _ptr;

public:
	clsDynamicArray(int size = 0) {
		if (size < 0) {
			size = 0;
		}
		
		_size = size;
		_ptr = new T[_size];
	}

	~clsDynamicArray() {
		delete[] _ptr;
	}

	void SetItem(int index, const T& value) {
		if (index >= _size || index < 0) {
			throw out_of_range("Out Of Range Exception: in SetItem(int index, const T& value) --> index >= the max size of array");
		}

		*(_ptr + index) = value;
	}

	bool IsEmpty() const  {
		return _size == 0;
	}

	int Size() const  {
		return _size;
	}

	void Print() const  {
		for (int i = 0; i < _size; i++) {
			cout << *(_ptr + i) << "  ";
		}
		
		cout << "\n";
	}

	void Resize(int NewSize) {
		if (NewSize == _size) return;

		if (NewSize < 0) NewSize = 0;

		T* current = new T[NewSize];

		for (int i = 0; i < min(NewSize, _size); i++) {
			current[i] = _ptr[i];
		}

		delete [] _ptr;
		_ptr = current;
		_size = NewSize;
	}

	T getItem (int index) const {
		if (index < 0 || index >= _size) throw out_of_range("Out Of Range: index is not correct.");
		return _ptr[index];
	}

	void Reverse() {
		if (_size <= 1) {
			return;
		}

		for (int i = 0; i < _size / 2; i++) {
			T temp = _ptr[i];
			_ptr[i] = _ptr[_size - i -1];
			_ptr[_size - i - 1] = temp;
		}
	}

	void Clear() {
		delete[] _ptr;
		_ptr = nullptr;
		_size = 0;
	}

	bool DeleteItemAt(int index) {
		if (index < 0 || index >= _size) {
			return false;
		}

		for (int i = index; i < _size  -1; i++) {
				_ptr[i] = _ptr[i + 1];
		}

		Resize(_size - 1);
		return true;
	}

	bool DeleteFirstItem() {
		return DeleteItemAt(0);
	}

	bool DeleteLastItem() {
		return DeleteItemAt(_size - 1);
	}

	int Find (const T& value) const {
		for (int index = 0; index < _size; index++) {
			if (_ptr[index] == value) {
				return index;
			}
		}

		return -1;
	}

	bool DeleteItem(const T& value) {
		int index = Find(value);
		if (index == -1) return false;
	    DeleteItemAt(index);
		return true;
	}

	bool InsertAt(int index, const T& value) {
		if (index < 0 || index > _size) {
			return false;
		}

		if (index == _size) {
			Resize(_size + 1);
			_ptr[_size - 1] = value;
			return true;
		}

		Resize(_size + 1);

		for(int i = _size - 1; i > index; i--) {
			_ptr[i] = _ptr[i - 1];
		}

		_ptr[index] = value;
		return true;
	}

	bool InsertAtBeginning(const T& value) {
		return InsertAt(0, value);
	}

	bool InsertAtEnd(const T& value) {
		return InsertAt(_size, value);
	}

	bool InsertAfter(int index, const T& value) {
		return InsertAt(index + 1, value);
	}

	bool InsertBefore(int index, const T& value) {
		return InsertAt(index, value);
	}





};