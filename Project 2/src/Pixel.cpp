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

unsigned char Pixel::GetRGB(int x) {
	if (x == 0)
		return red;
	if (x == 1)
		return green;
	if (x == 2)
		return blue;
}