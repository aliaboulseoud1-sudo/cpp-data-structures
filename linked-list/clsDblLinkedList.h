#pragma once

#include <iostream>

using namespace std;

template <typename T>
class clsDblLinkedList {
private:
	int _size = 0;

public:
	class Node {
	public:
		T value;
		Node* next;
		Node* prev;
	};

	Node* head = nullptr;

	void InsertAtBeginning(T value) {
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = head;
		new_node->prev = nullptr;

		if (head != nullptr) {
			head->prev = new_node;
		}

		head = new_node;

		_size++;
	}

	Node* Find(T value) {
		Node* temp = head;

		while (temp != nullptr) {
			if (temp->value == value) {
				return temp;
			}

			temp = temp->next;
		}

		return nullptr;
	}

	void InsertAfter(Node* current, T value) {
		if (current == nullptr) {
			return;
		}

		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = current->next;
		new_node->prev = current;

		if (current->next != nullptr) {
			current->next->prev = new_node;
		}

		current->next = new_node;

		_size++;
	}

	void InsertAtEnd(T value) {
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = nullptr;

		if (head == nullptr) {
			new_node->prev = nullptr;
			head = new_node;
		}
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}

			new_node->prev = current;
			current->next = new_node;
		}

		_size++;
	}

	void DeleteNode(Node*& NodeToDelete) {
		if (head == nullptr || NodeToDelete == nullptr) {
			return;
		}
		if (head == NodeToDelete) {   // if the NodeToDelete is the first node in the list
			head = NodeToDelete->next;
		}
		if (NodeToDelete->next != nullptr) {
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		if (NodeToDelete->prev != nullptr) {
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		delete NodeToDelete;
		NodeToDelete = nullptr;

		_size--;
	}

	void DeleteFirstNode() {
		if (head == nullptr) {
			return;
		}

		Node* temp = head;
		head = head->next;

		if (head != nullptr) {
			head->prev = nullptr;
		}

		delete temp;

		_size--;
	}

	void DeleteLastNode() {
		if (head == nullptr) {
			return;
		}

		if (head->next == nullptr) {  // if there is only one node in the list
			delete head;
			head = nullptr;
			_size--;
			return;
		}

		Node* current = head;
		while (current->next->next != nullptr) {
			current = current->next;
		}

		Node* temp = current->next;
		current->next = nullptr;
		delete temp;

		_size--;
	}

	void PrintList() {
		Node* temp = head;

		cout << "NULL <- ";
		while (temp != nullptr) {
			cout << temp->value;

			if (temp->next != nullptr) {
				cout << " <-> ";
			}

			temp = temp->next;
		}

		cout << " -> NULL " << endl;
	}

	int Size() {
		return _size;
	}

	bool IsEmpty() {
		return _size == 0;
	}

	void Clear() {
		while (!IsEmpty()) {
			DeleteFirstNode();
		}
	}

	void Reverse() {
		Node* current = head;
		Node* temp = nullptr;   // I will use it in swapping

		while (current != nullptr) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp != nullptr) {
			head = temp->prev; // Move head pointer to the last node to start from it (reverse)
		}
	}

	Node* getNode(int index) {
		if (index < 0 || index >= _size) {
			return nullptr;
		}

		Node* temp = head;
		int counter = 0;

		while (counter < index) {
			temp = temp->next;
			counter++;
		}

		return temp;
	}

	const T& getItem(int index) {
		if (index < 0 || index >= _size) {
			throw std::out_of_range("Index out of bounds");
		}

		Node* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}

		return temp->value;
	}

	bool UpdateItem(int index, const T& NewValue) {
		Node* ItemNode = getNode(index);

		if (ItemNode != nullptr) {
			ItemNode->value = NewValue;
			return true;
		}

		return false;
	}

	bool InsertAfter(int index, const T& value) {
		Node* current = getNode(index);

		if (current != nullptr) {
			InsertAfter(current, value);
			return true;
		}

		return false;
	}
};