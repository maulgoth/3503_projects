#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "HelperMethods.h"
using namespace std;
using namespace HelperMethods;

int main() 
{
	string top;
	string bottom;
	int test;

	// Test 1: -------------------------------------------/
	//cout << "Test 1 Starting... ------------------------/" << endl;

	// Image Paths
	//top = "input/layer1.tga";
	//bottom = "input/pattern1.tga";

	// Multiply
	//test = Multiply(top, bottom, "tests/test1/test1.tga");
	//if (test == 1)
	//	cout << "Test 1: Pass." << endl;
	//else
	//	cout << "Test 1: Fail." << endl;

	// Compare
	//CompareImages("tests/test1/test1.tga", "examples/EXAMPLE_part1.tga");

	// Test 2: -------------------------------------------/
	cout << "Test 2 Starting... ------------------------/" << endl;

	// Load Images
	top = "input/layer2.tga";
	bottom = "input/car.tga";

	// Subtract
	test = Subtract(top, bottom, "tests/test1/test2.tga");
	if (test == 1)
		cout << "Test 2: Pass." << endl;
	else
		cout << "Test 2: Fail." << endl;

	// Compare
	CompareImages("tests/test1/test2.tga", "examples/EXAMPLE_part2.tga");


	// Quit ---------------------------------------------/
	cout << "Quitting now!" << endl; /////////////////////

	return 0;
}