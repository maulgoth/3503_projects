#include "LinkedList.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void TestInsertBeforeAfter();
void TestInsertAt();

int main()
{
	int testNum;
	cin >> testNum;
	if (testNum == 1)
		TestInsertBeforeAfter();
	else if (testNum == 2)
		TestInsertAt();
	return 0;
}

void TestInsertBeforeAfter()
{
	LinkedList<int> data;
	data.AddTail(10);
	data.AddHead(9);
	data.AddTail(11);
	data.AddHead(8);
	data.AddTail(12);

	cout << "Initial list: " << endl;
	data.PrintForward();

	LinkedList<int>::Node* node = data.Find(10);
	cout << "\nSearching for node with value of 10..." << endl;

	if (node != nullptr)
	{
		cout << "Node found! Value: " << node->data << endl;
		cout << "Prev value: " << node->prev->data << endl;
		cout << "Next value: " << node->next->data << endl;
	}
	else
		cout << "Error! Returned node was a nullptr.";

	cout << "\nInserting 2048 before node and 4096 after node." << endl;
	data.InsertBefore(node, 2048);
	data.InsertAfter(node, 4096);
	data.PrintForward();
}

void TestInsertAt()
{
	cout << "=====Testing InsertAt() functionality=====" << endl;
	LinkedList<string> data;
	string test = "great benefit linked is the ability to easily into the";
	stringstream x(test);
	string tmp;
	while (getline(x, tmp, ' '))
		data.AddTail(tmp);

	cout << "Initial list: " << endl;
	data.PrintForward();
	cout << "Node count: " << data.NodeCount() << endl;

	cout << "\nInserting words into the list with InsertAt()..." << endl;

	data.InsertAt("One", 0);
	cout << "One " << 0 << " count: " << data.NodeCount() << endl;
	data.InsertAt("of", 3);
	cout << "of " << 3 << " count: " << data.NodeCount() << endl;
	data.InsertAt("lists", 5);
	cout << "lists " << 5 << " count: " << data.NodeCount() << endl;
	data.InsertAt("insert", 10);
	cout << "insert " << 10 << " count: " << data.NodeCount() << endl;
	data.InsertAt("nodes", 11);
	cout << "nodes " << 11 << " count: " << data.NodeCount() << endl;
	data.InsertAt("list.", 15);
	cout << "list. " << 15 << " count: " << data.NodeCount() << endl;

	data.PrintForward();
	cout << "Node count: " << data.NodeCount() << endl;
	
	
	LinkedList<string> rhs;
	rhs = data;
	data.PrintForward();
	rhs.PrintForward();
	//rhs = data;
	if (data == rhs) {
		cout << "true as blue " << endl;
	}
	else {
		cout << "nope" << endl;
	}
	cout << data.NodeCount() << endl;
	cout << rhs.NodeCount() << endl;

}