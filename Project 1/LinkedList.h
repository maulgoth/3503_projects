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
using namespace std;

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
	// LinkedList<T>& operator=(const LinkedList<T>& rhs);

	/*==== Construction / Destruction ====*/
	LinkedList();
	// LinkedList(const LinkedList<T>& list);
	~LinkedList();


private:
	Node* head;
	Node* tail;
	unsigned int count;

};

template <typename T>
LinkedList<T>::LinkedList() {
	count = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	//cout << "Delete!" << endl;
	Node* n = head;
	while (n != nullptr) {
		//cout << "Deleting: " << n->data << endl;
		Node* x = n;
		n = n->next;
		delete x;
	}
	//cout << "All deleted, thanks!" << endl;
}

template <typename T>
void LinkedList<T>::AddHead(const T& data) {
	//cout << "ADDING: " << data << endl;
	Node* n = new Node;
	n->data = data;
	n->prev = nullptr;
	if (head == nullptr) {
		head = n;
		tail = head;
		n->next = nullptr;
	}
	else {
		head->prev = n;
		n->next = head;
		head = n;
	}


	count++;
	//cout << "SUCCESS! " << data << " added!" << endl;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data) {
	//cout << "ADDING: " << data << endl;
	Node* n = new Node;
	n->data = data;
	n->next = nullptr;
	if (tail == nullptr) {
		tail = n;
		head = tail;
		n->prev = nullptr;
	}
	else {
		tail->next = n;
		n->prev = tail;
		tail = n;
	}
	count++;
	//cout << "SUCCESS! " << data << " added!" << endl;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
	// cout << "Okay lets try it" << endl;
	for (int i = (count-1); i >= 0; --i) {
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
	Node* n;
	n = head;
	while (n != nullptr) {
		cout << n->data << endl;
		//cout << "Head: " << head << " Tail: " << tail << " CURRENT: " << n << " n->next: " << n->next << " n->prev: " << n->prev << endl;
		n = n->next;
	}

}

template <typename T>
void LinkedList<T>::PrintReverse() const {
	Node* n;
	n = tail;
	while (n != nullptr) {
		cout << n->data << endl;
		//cout << "Head: " << head << " Tail: " << tail << " CURRENT: " << n << " n->next: " << n->next << " n->prev: " << n->prev << endl;
		n = n->prev;
	}
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
	return count;
}