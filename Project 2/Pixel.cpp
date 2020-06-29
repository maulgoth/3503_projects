#include <iostream>
#include <string>
#include <vector>
#include "Pixel.h"
using namespace std;



Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b) {
	red = r;
	green = g;
	blue = b;
}

vector<unsigned char> Pixel::GetRGB() {
	vector<unsigned char> rgb;
	rgb.push_back(red);
	rgb.push_back(green);
	rgb.push_back(blue);
	return rgb;
}