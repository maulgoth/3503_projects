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
	bool CompareImages(string first, string second);
	void PrintInfo(Image& img);
	float NormChar(unsigned char c, unsigned char top, unsigned char bottom);
	Image Multiply(Image& top, Image& bottom);
	Image Subtract(Image& top, Image& bottom);
	Image Screen(Image& top, Image& bottom, Image& screen);
	Image Overlay(Image& top, Image& bottom);
	Image AddRGB(Image& top, unsigned char red, unsigned char green, unsigned char blue);
	Image Scale(Image& top, bool red, float x, bool green, float y, bool blue, float z);
	vector<Image> SepRGB(Image& top);
}