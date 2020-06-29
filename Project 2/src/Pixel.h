#pragma once
#include <vector>
using namespace std;

class Pixel {
public:
	Pixel(unsigned char r, unsigned char g, unsigned char b);
	unsigned char GetRGB(int x);
private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};