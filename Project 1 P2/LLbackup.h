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
#include "leaker.h"

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
	// void FindAll(vector<Node*>& outData, const T& value) const;
	// const Node* Find(const T& data) const;
	// Node* Find(const T& data);
	// const Node* GetNode(unsigned int index) const;
	// Node* GetNode(unsigned int index);
	// const Node* Head() const;
	// Node* Head();
	// const Node* Tail() const;
	// Node* Tail();

	/*==== Insertion ====*/
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	// void InsertAfter(Node* node, const T& data);
	// void InsertBefore(Node* node, const T& data);
	// void InsertAt(const T& data, unsigned int index);

	/*==== Removal ====*/
	// bool RemoveHead();
	// bool RemoveTail();
	// unsigned int Remove(const T& data);
	// bool RemoveAt(unsigned int index);
	// void Clear();

	/*==== Operators ====*/
	// const T& operator[](unsigned int index) const;
	// T& operator[](unsigned int index);
	// bool operator==(const LinkedList<T>& rhs) const;
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
	cout << "WEE COPY CONSTRUCT!" << endl;

	count = list.count;

	// delete all nodes
	Node* temp = head;
	Node* n = new Node;
	while (temp != nullptr) {
		n = temp->next;
		delete temp;
		temp = n;
	}
	delete n;
	head = nullptr;
	tail = nullptr;

	// copy old list nodes to new list
	Node* x = list.head;
	while (x != nullptr) {
		cout << "CC X data: " << x->data << endl;
		AddTail(x->data);
		x = x->next;
	}



	cout << "SUCCESS copied!" << endl;
}

// Copy Assignment Operator


template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	cout << "WOO WOO COPY ASSIGNMENT!" << endl;
	if (this != &rhs) {

		count = rhs.count;

		// delete all nodes
		Node* temp = head;
		//Node* y = nullptr;
		//cout << "loop enter ass y: " << y << endl;
		while (temp != nullptr) {
			Node* y = temp->next;
			//y = temp->next;
			cout << "deleting temp: " << temp->data << " temp: " << temp << " y: " << y << endl;
			delete temp;
			temp = y;
			cout << "ass y: " << y << endl;
		}

		//cout << "loop exit ass y: " << y << endl;

		head = nullptr;
		tail = nullptr;

		// copy old list nodes to new list
		Node* x = rhs.head;
		while (x != nullptr) {
			cout << "CC X data: " << x->data << endl;
			AddTail(x->data);
			x = x->next;
		}


	}
	cout << "ASSIGNMENT COMPLETE!" << endl;
	return *this;
}


// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
	cout << "Delete! Just starting" << endl;
	Node* n = head;
	cout << "Deleting List: head: " << head << " tail: " << tail << endl;
	while (n != nullptr) {
		cout << "Deleting node: " << n->data << " " << n << endl;
		Node* x = n;
		n = n->next;
		delete x;
	}
	delete n;
	cout << "All deleted, thanks!" << endl;
}

template <typename T>
void LinkedList<T>::AddHead(const T& data) {
	cout << "ADDING: " << data << " to the head: " << head << endl;
	Node* n = new Node;
	n->data = data;
	n->next = nullptr;
	n->prev = nullptr;

	if (head == nullptr) {
		//cout << "addhead head==nullptr " << "head: " << head << " tail: " << tail << endl;
		head = n;
		tail = n;
	}
	else {
		//cout << "addhead else " << "head: " << head << " tail: " << tail << endl;
		head->prev = n;
		n->next = head;
		head = n;
	}

	count++;
	//cout << "SUCCESS! " << data << " added!" << endl;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data) {
	cout << "ADDING: " << data << " to the tail: " << tail << endl;
	Node* n = new Node;
	n->data = data;
	n->next = nullptr;
	n->prev = nullptr;

	if (head == nullptr) {
		//cout << "addtail head==nullptr " << "head: " << head << " tail: " << tail << endl;
		head = n;
		tail = n;
	}
	else {
		//cout << "addtail else " << "head: " << head << " tail: " << tail << endl;
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = n;
		n->prev = temp;
		tail = n;
	}
	count++;
	//cout << "SUCCESS! " << data << " added!" << endl;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
	// cout << "Okay lets try it" << endl;
	for (int i = (count - 1); i >= 0; --i) {
		// cout << "trying: " << data[i] << endl;
		this->AddHead(data[i]);
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
	for (unsigned int i = 0; i < count; i++) {
		this->AddTail(data[i]);
	}
}

template <typename T>
void LinkedList<T>::PrintForward() const {
	cout << "head: " << head << " tail: " << tail << endl;
	Node* n;
	n = head;
	while (n != nullptr) {
		cout << n->data << endl;
		//cout << n->data << " n: " << n << " next: " << n->next << " prev: " << n->prev << endl;
		//cout << "Head: " << head << " Tail: " << tail << " CURRENT: " << n << " n->next: " << n->next << " n->prev: " << n->prev << endl;
		n = n->next;
	}

}

template <typename T>
void LinkedList<T>::PrintReverse() const {
	cout << "head: " << head << " tail: " << tail << endl;
	Node* n;
	n = tail;
	while (n != nullptr) {
		cout << n->data << endl;
		//cout << n->data << " " << n << endl;
		//cout << "Head: " << head << " Tail: " << tail << " CURRENT: " << n << " n->next: " << n->next << " n->prev: " << n->prev << endl;
		n = n->prev;
	}
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
	return count;
}