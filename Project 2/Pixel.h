#pragma once
#include <vector>
using namespace std;

class Pixel {
public:
	Pixel(unsigned char r, unsigned char g, unsigned char b);
	vector<unsigned char> GetRGB();
private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};