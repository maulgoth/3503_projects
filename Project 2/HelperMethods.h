#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Image.h"
using namespace std;

namespace HelperMethods {
	Image readFile(string path);
	bool writeFile(string path, Image& img);
	void CompareImages(string first, string second);
	void PrintInfo(Image& img);
	float NormChar(unsigned char c, unsigned char top, unsigned char bottom);
	bool Multiply(string _top, string _bottom, string path);
	bool Subtract(string _top, string _bottom, string path);
}