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
	int count = 0;
	int test = 0;

	//test = 1;

	if (test == 1) {
		cout << "\nTest 1 Starting... ------------------------/" << endl;

		// Image Paths
		Image top1 = readFile("input/layer1.tga");
		Image bottom1 = readFile("input/pattern1.tga");

		// Multiply
		Image Test1 = Multiply(top1, bottom1);
		if (writeFile("tests/test1.tga", Test1) == 1)
			if (CompareImages("tests/test1.tga", "examples/EXAMPLE_part1.tga") == 1) {
				count++;
				cout << "Test 1: Passed." << endl;
			}
		else
			cout << "Test 1: Fail." << endl;
	}

	//test = 2;

	if (test == 2) {
		cout << "\nTest 2 Starting... ------------------------/" << endl;

		// Load Images
		Image top2 = readFile("input/layer2.tga");
		Image bottom2 = readFile("input/car.tga");

		// Subtract
		Image Test2 = Subtract(top2, bottom2);
		if (writeFile("tests/test2.tga", Test2) == 1)
			if (CompareImages("tests/test2.tga", "examples/EXAMPLE_part2.tga") == 1) {
				count++;
				cout << "Test 2: Passed." << endl;
			}
		else
			cout << "Test 2: Fail." << endl;
	}

	//test = 3;
	
	if (test == 3) {
		cout << "\nTest 3 Starting... ------------------------/" << endl;

		// Load Images
		Image top3 = readFile("input/layer1.tga");
		Image bottom3 = readFile("input/pattern2.tga");
		Image screen = readFile("input/text.tga");

		// Screen
		Image Test3 = Screen(top3, bottom3, screen);
		if (writeFile("tests/test3.tga", Test3) == 1)
			if (CompareImages("tests/test3.tga", "examples/EXAMPLE_part3.tga") == 1) {
				count++;
				cout << "Test 3: Passed." << endl;
			}
		else
			cout << "Test 3: Fail." << endl;
	}

	//test = 4;

	if (test == 4) {
		cout << "\nTest 4 Starting... ------------------------/" << endl;

		// Load Images
		Image top4 = readFile("input/layer2.tga");
		Image bottom4 = readFile("input/circles.tga");
		Image sub = readFile("input/pattern2.tga");

		// Mult and Sub
		Image Test4TempImg = Multiply(top4, bottom4);
		Image Test4 = Subtract(sub, Test4TempImg);
		if (writeFile("tests/test4.tga", Test4) == 1)
			if (CompareImages("tests/test4.tga", "examples/EXAMPLE_part4.tga") == 1) {
				count++;
				cout << "Test 4: Passed." << endl;
			}
		else
			cout << "Test 4: Fail." << endl;
	}

	//test = 5;

	if (test == 5) {
		cout << "\nTest 5 Starting... ------------------------/" << endl;

		// Load Images
		Image top5 = readFile("input/layer1.tga");
		Image bottom5 = readFile("input/pattern1.tga");

		// Subtract
		Image Test5 = Overlay(top5, bottom5);
		if (writeFile("tests/test5.tga", Test5) == 1)
			if (CompareImages("tests/test5.tga", "examples/EXAMPLE_part5.tga") == 1) {
				count++;
				cout << "Test 5: Passed." << endl;
			}
		else
			cout << "Test 5: Fail." << endl;
	}

	//test = 6;

	if (test == 6) {
		cout << "\nTest 6 Starting... ------------------------/" << endl;

		// Load Images
		Image top6 = readFile("input/car.tga");

		// ADD GREEN
		Image Test6 = AddRGB(top6, 0, 200, 0);
		if (writeFile("tests/test6.tga", Test6) == 1)
			if (CompareImages("tests/test6.tga", "examples/EXAMPLE_part6.tga") == 1) {
				count++;
				cout << "Test 6: Passed." << endl;
			}
		else
			cout << "Test 6: Fail." << endl;
	}

	//test = 7;

	if (test == 7) {
		cout << "\nTest 7 Starting... ------------------------/" << endl;

		// Load Images
		Image top7 = readFile("input/car.tga");

		// ADD GREEN
		Image Test7 = Scale(top7, true, 4.0, false, 0.0, true, 0.0);
		if (writeFile("tests/test7.tga", Test7) == 1)
			if (CompareImages("tests/test7.tga", "examples/EXAMPLE_part7.tga") == 1) {
				count++;
				cout << "Test 7: Passed." << endl;
			}
			else
				cout << "Test 7: Fail." << endl;
	}

	//test = 8;

	if (test == 8) {
		cout << "\nTest 8 Starting... ------------------------/" << endl;

		int microCounter = 0;

		// Load Images
		Image top8 = readFile("input/car.tga");

		// ADD GREEN
		vector<Image> Test8 = SepRGB(top8);

		if (writeFile("tests/test8_r.tga", Test8.at(0)) == 1)
			if (CompareImages("tests/test8_r.tga", "examples/EXAMPLE_part8_r.tga") == 1) {
				microCounter++;
				cout << "Test 8 R: Passed." << endl;
			}
			else
				cout << "Test 8 R: Fail." << endl;
		if (writeFile("tests/test8_g.tga", Test8.at(1)) == 1)
			if (CompareImages("tests/test8_g.tga", "examples/EXAMPLE_part8_g.tga") == 1) {
				microCounter++;
				cout << "Test 8 R: Passed." << endl;
			}
			else
				cout << "Test 8 R: Fail." << endl;
		if (writeFile("tests/test8_b.tga", Test8.at(2)) == 1)
			if (CompareImages("tests/test8_b.tga", "examples/EXAMPLE_part8_b.tga") == 1) {
				microCounter++;
				cout << "Test 8 R: Passed." << endl;
			}
			else
				cout << "Test 8 R: Fail." << endl;

		// Check MicroCounter
		if (microCounter == 3) {
			count++;
			cout << "Test 8: Passed." << endl;
		}
		else
			cout << "Test 8: Fail." << endl;
	}

	test = 9;

	if (test == 9) {
		cout << "\nTest 9 Starting... ------------------------/" << endl;

		// Load Images
		Image top9red = readFile("input/layer_red.tga");
		Image top9green = readFile("input/layer_green.tga");
		Image top9blue = readFile("input/layer_blue.tga");

		// ADD GREEN
		Image Test9 = Combine(top9red, top9green, top9blue);
		if (writeFile("tests/test9.tga", Test9) == 1)
			if (CompareImages("tests/test9.tga", "examples/EXAMPLE_part9.tga") == 1) {
				count++;
				cout << "Test 9: Passed." << endl;
			}
			else
				cout << "Test 9: Fail." << endl;
	}

	cout << "\n\nQuitting now! " << count << "/10 Tests Passed.\nExtra Credit? Not yet.\n" << endl; /////////////////////

	return 0;
}