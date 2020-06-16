#include "LinkedList.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void TestFindAll();
void TestCopyCtor();
void TestAssignment();

int main()
{
	int testNum;
	cin >> testNum;
	if (testNum == 1)
		TestFindAll();
	else if (testNum == 2)
		TestCopyCtor();
	else if (testNum == 3)
		TestAssignment();

	return 0;
}

void TestFindAll()
{
	cout << "=====Testing FindAll() functionality=====" << endl;
	LinkedList<int> data;
	int searchVal = 256;

	data.AddTail(searchVal);
	data.AddTail(10);
	data.AddTail(20);
	data.AddTail(searchVal);
	data.AddTail(30);
	data.AddTail(searchVal);
	data.AddTail(40);
	data.AddTail(searchVal);

	cout << "Initial list: " << endl;
	data.PrintForward();

	cout << "\nTESTING HEAD():" << endl;
	cout << "data: " << data.Head()->data << " mem: " << data.Head() << endl;
	cout << "\nTESTING TAIL():" << endl;
	cout << "data: " << data.Tail()->data << " mem: " << data.Tail() << endl;


	vector<LinkedList<int>::Node*> nodes;
	data.FindAll(nodes, searchVal);
	/*
	cout << "\nFinding 30: " << endl;
	cout << "Found " << 30 << " at memory: " << data.Find(30) << endl;
	cout << "GetNode(0) testing:" << endl;
	cout << "N(0): " << data.GetNode(0) << endl;
	cout << "GetNode(7) testing:" << endl;
	cout << "N(7): " << data.GetNode(7) << endl;
	cout << "GetNode(8) testing:" << endl;
	cout << "N(8): " << data.GetNode(8) << endl;
	*/


	cout << "\nNodes found: " << nodes.size() << endl;
	for (unsigned int i = 0; i < nodes.size(); i++)
	{
		cout << "Node #" << (i + 1) << ":\n";
		cout << "Value: " << nodes[i]->data << endl;

		cout << "Prev value: ";
		if (nodes[i]->prev != nullptr)
			cout << nodes[i]->prev->data;
		else
			cout << "nullptr";

		cout << "\nNext value: ";
		if (nodes[i]->next != nullptr)
			cout << nodes[i]->next->data;
		else
			cout << "nullptr";
		cout << endl;
	}
}

void TestCopyCtor()
{
	cout << "=====Testing Copy Constructor functionality=====" << endl;
	LinkedList<int> original;
	for (int i = 0; i <= 10; i += 5)
		original.AddTail(i);

	cout << "Printing original:" << endl;
	original.PrintForward();
	cout << endl;

	cout << "Printing copy:" << endl;
	LinkedList<int> copy = original;
	copy.PrintForward();
	cout << endl;

	cout << "Changing copy... adding to head and tail..." << endl;
	copy.AddHead(99);
	copy.AddTail(-102);
	cout << "Printing copy again:" << endl;
	copy.PrintForward();
	cout << endl;

	cout << "Printing original again:" << endl;
	original.PrintForward();
	cout << endl;
}

void TestAssignment()
{
	cout << "=====Testing Copy Assignment Operator functionality=====" << endl;
	LinkedList<int> first;
	LinkedList<int> second;

	for (int i = 20; i <= 30; i += 5)
		first.AddTail(i);
	for (int i = 17; i < 100; i += 22)
		second.AddTail(i);

	cout << "Printing first list:" << endl;
	first.PrintForward();
	cout << endl;

	cout << "Printing second list:" << endl;
	second.PrintForward();
	cout << endl;

	cout << "Assigning one list to another..." << endl;
	first = second;

	cout << "Printing after copying:" << endl;
	first.PrintForward();
	cout << endl;

	cout << "Changing both lists..." << endl;
	first.AddTail(66);
	second.AddTail(19);
	first.AddHead(-100);
	second.AddHead(-512);
	cout << "Printing first list: " << endl;
	first.PrintForward();
	cout << endl;
	cout << "Printing second list: " << endl;
	second.PrintForward();
}