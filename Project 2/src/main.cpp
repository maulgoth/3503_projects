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
	cout << "Starting Image Editor: " << endl;
	// 1
	// Image Paths
	Image top1 = readFile("input/layer1.tga");
	Image bottom1 = readFile("input/pattern1.tga");
	// Multiply
	Image Test1 = Multiply(top1, bottom1);
	writeFile("tests/test1.tga", Test1);
			
	// 2
	// Load Images
	Image top2 = readFile("input/layer2.tga");
	Image bottom2 = readFile("input/car.tga");

	// Subtract
	Image Test2 = Subtract(top2, bottom2);
	writeFile("tests/test2.tga", Test2);
			
	// 3
	// Load Images
	Image top3 = readFile("input/layer1.tga");
	Image bottom3 = readFile("input/pattern2.tga");
	Image screen = readFile("input/text.tga");

	// Screen
	Image Test3 = Screen(top3, bottom3, screen);
	writeFile("tests/test3.tga", Test3);
			
	// 4
	// Load Images
	Image top4 = readFile("input/layer2.tga");
	Image bottom4 = readFile("input/circles.tga");
	Image sub = readFile("input/pattern2.tga");

	// Mult and Sub
	Image Test4TempImg = Multiply(top4, bottom4);
	Image Test4 = Subtract(sub, Test4TempImg);
	writeFile("tests/test4.tga", Test4);
			
	// 5
	// Load Images
	Image top5 = readFile("input/layer1.tga");
	Image bottom5 = readFile("input/pattern1.tga");

	// Subtract
	Image Test5 = Overlay(top5, bottom5);
	writeFile("tests/test5.tga", Test5);
			
	// 6
	// Load Images
	Image top6 = readFile("input/car.tga");

	// ADD RGB
	Image Test6 = AddRGB(top6, 0, 200, 0);
	writeFile("tests/test6.tga", Test6);

	// 7
	// Load Images
	Image top7 = readFile("input/car.tga");

	// SCALE
	Image Test7 = Scale(top7, true, 4.0, false, 0.0, true, 0.0);
	writeFile("tests/test7.tga", Test7);
			
	// 8
	// Load Images
	Image top8 = readFile("input/car.tga");

	// SEP RGB
	vector<Image> Test8 = SepRGB(top8);

	writeFile("tests/test8_r.tga", Test8.at(0));
			
	writeFile("tests/test8_g.tga", Test8.at(1));
				
	writeFile("tests/test8_b.tga", Test8.at(2));
			
	// 9
	// Load Images
	Image top9red = readFile("input/layer_red.tga");
	Image top9green = readFile("input/layer_green.tga");
	Image top9blue = readFile("input/layer_blue.tga");

	// COMBINE
	Image Test9 = Combine(top9red, top9green, top9blue);
	writeFile("tests/test9.tga", Test9);
			
	// 10
	// Load Images
	Image top10 = readFile("input/text2.tga");

	// ROTATE 180
	Image Test10 = Rotate180(top10);
	writeFile("tests/test10.tga", Test10);

	cout << "All tasks complete. Thank you." << endl;

	return 0;
}