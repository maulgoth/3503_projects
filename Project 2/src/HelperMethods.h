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
	Image Multiply(const Image& top, const Image& bottom);
	Image Subtract(const Image& top, const Image& bottom);
	Image Screen(const Image& top, const Image& bottom, const Image& screen);
	Image Overlay(const Image& top, const Image& bottom);
	Image AddRGB(const Image& top, unsigned char red, unsigned char green, unsigned char blue);
	Image Scale(const Image& top, bool red, float x, bool green, float y, bool blue, float z);
	vector<Image> SepRGB(const Image& top);
	Image Combine(const Image& red, const Image& green, const Image& blue);
	Image Rotate180(const Image& top);
	// Image Rotate90(const Image& top);
	Image Quadrant(const Image& first, const Image& second, const Image& third, const Image& fourth);
}