// **********************************************************
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online
// All code completely original, inspired by Professor Joshua Fox's lectures,
// Or from the following:
// 
// Site: VisualGo.net
// Author: Dr Steven Halim
// URL: https://visualgo.net/en/list
// Link provided by TA in COP3503 Slack Channel
// Pseudo-code examples from VisualGo.net were used to
// Mock up actual C++ code in Project.
// **********************************************************

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
//#include "leaker.h"

template <typename T>
class LinkedList {
public:
	struct Node {
		T data;
		Node* next;
		Node* prev;
	};

	/*==== Behaviors ====*/
	void PrintForward() const;
	void PrintReverse() const;
	// void PrintForwardRecursive(const Node* node) const;
	// void PrintForwardRecursive(const Node* node) const;

	/*==== Accessors ====*/
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);
	const Node* Head() const;
	Node* Head();
	const Node* Tail() const;
	Node* Tail();

	/*==== Insertion ====*/
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	/*==== Removal ====*/
	// bool RemoveHead();
	// bool RemoveTail();
	// unsigned int Remove(const T& data);
	// bool RemoveAt(unsigned int index);
	// void Clear();

	/*==== Operators ====*/
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T>& rhs) const;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	/*==== Construction / Destruction ====*/
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();


private:
	Node* head;
	Node* tail;
	unsigned int count;

};

// Constructor - Default
template <typename T>
LinkedList<T>::LinkedList() {
	count = 0;
	head = nullptr;
	tail = nullptr;
}

// Copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
	count = 0;

	head = nullptr;
	tail = nullptr;

	// copy old list nodes to new list
	Node* x = list.head;
	while (x != nullptr) {
		AddTail(x->data);
		x = x->next;
	}
}

// Copy Assignment Operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	if (this != &rhs) {

		count = 0;

		// delete all nodes
		Node* temp = head;
		while (temp != nullptr) {
			Node* y = temp->next;
			delete temp;
			temp = y;
		}

		head = nullptr;
		tail = nullptr;
		
		// copy old list nodes to new list
		Node* x = rhs.head;
		while (x != nullptr) {
			AddTail(x->data);
			x = x->next;
		}
	}
	return *this;
}


// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
	Node* n = head;
	while (n != nullptr) {
		Node* x = n;
		n = n->next;
		delete x;
	}
	//delete n;
}

// Add Head
template <typename T>
void LinkedList<T>::AddHead(const T& data) {
	Node* n = new Node;
	n->data = data;
	n->next = nullptr;
	n->prev = nullptr;

	if (head == nullptr) {
		head = n;
		tail = n;
	}
	else {
		head->prev = n;
		n->next = head;
		head = n;
	}

	count++;
}

// Add Tail
template <typename T>
void LinkedList<T>::AddTail(const T& data) {
	Node* n = new Node;
	n->data = data;
	n->next = nullptr;
	n->prev = nullptr;

	if (head == nullptr) {
		head = n;
		tail = n;
	}
	else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = n;
		n->prev = temp;
		tail = n;
	}
	count++;
}

// Add Nodes Head
template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
	for (int i = (count-1); i >= 0; --i) {
		this->AddHead(data[i]);
	}
}

// Add Nodes Tail
template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
	for (unsigned int i = 0; i < count; i++) {
		this->AddTail(data[i]);
	}
}

// Print Forward
template <typename T>
void LinkedList<T>::PrintForward() const {
	Node* n;
	n = head;
	while (n != nullptr) {
		cout << n->data << endl;
		n = n->next;
	}
}

// Print Backward
template <typename T>
void LinkedList<T>::PrintReverse() const {
	Node* n;
	n = tail;
	while (n != nullptr) {
		cout << n->data << endl;
		n = n->prev;
	}
}

// Node Count
template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
	return count;
}

// Head Const
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
	return head;
}

// Head
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
	return head;
}

// Tail Const
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
	return tail;
}

// Tail
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
	return tail;
}

// Find All
template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
	Node* n = head;
	while (n != nullptr) {
		if (n->data == value)
			outData.push_back(n);
		n = n->next;
	}
}

// Find Const
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
	Node* n = head;
	while (n != nullptr) {
		if (n->data == data)
			return n;
		n = n->next;
	}
	return nullptr; // if not found, return null
}

// Find
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
	Node* n = head;
	while (n != nullptr) {
		if (n->data == data)
			return n;
		n = n->next;
	}
	return nullptr; // if not found, return null
}

// Get Node Const
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
	// catch out of range
	if (count == 0 || index > count - 1)
		throw out_of_range("Out of range");

	// return 0
	if (index == 0)
		return head;

	// Search for index
	Node* n = head->next;
	unsigned int i;
	for (i = 1; i < index; i++) {
		n = n->next;
	}
	return n;
}

// Get Node
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
	// catch out of range
	if (count == 0 || index > count - 1)
		throw out_of_range("Out of range");

	// return 0
	if (index == 0)
		return head;

	// Search for index
	Node* n = head->next;
	unsigned int i;
	for (i = 1; i < index; i++) {
		n = n->next;
	}
	return n;
}

// Operator[] Overload Const
template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
	// catch out of range
	if (count == 0 || index > count - 1)
		throw out_of_range("Out of range");

	// return 0
	if (index == 0)
		return head->data;

	// Search for index
	Node* n = head->next;
	unsigned int i;
	for (i = 1; i < index; i++) {
		n = n->next;
	}
	return n->data;
}

// Operator[] Overload
template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
	// catch out of range
	if (count == 0 || index > count - 1)
		throw out_of_range("Out of range");

	// return 0
	if (index == 0) {
		return head->data;
	}

	// Search for index
	Node* n = head->next;
	unsigned int i;
	for (i = 1; i < index; i++) {
		n = n->next;
	}
	return n->data;
}


// Insert After
template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
	Node* n = new Node;
	n->data = data;
	n->next = nullptr;
	n->prev = node;

	if (node == tail) {
		tail = n;
	}
	else {
		Node* x = node->next;
		x->prev = n;
		n->next = x;
	}
	node->next = n;
	count++;
}


// Insert Before
template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
	Node* n = new Node;
	n->data = data;
	n->next = node;
	n->prev = nullptr;

	if (node == head) {
		head = n;
	}
	else {
		Node* x = node->prev;
		x->next = n;
		n->prev = x;
	}
	node->prev = n;
	count++;
}

// Insert At
template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
	// catch out of range
	if (count == 0 || index > count)
		throw out_of_range("Out of range");

	// Insert at Head
	if (index == 0)
		InsertBefore(head, data);

	// Insert at Tail
	else if (index == count)
		InsertAfter(tail, data);

	// Insert at index
	else {
		// Search for index
		Node* x = head->next;
		unsigned int i;
		for (i = 1; i < index-1; i++) {
			x = x->next;
		}
		Node* y = x->next;
		Node* n = new Node;
		n->data = data;
		n->prev = x;
		n->next = y;
		x->next = n;
		y->prev = n;
		count++;
	}
}

// Operator == Overload
template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {
	// if count is the same, iterate through each node->data
	if (count == rhs.count) {
		unsigned int i;
		for (i = 0; i < count; i++) {
			if (GetNode(i)->data != rhs.GetNode(i)->data)
				return false;
		}
		return true;
	}
	// else return false
	else
		return false;
}