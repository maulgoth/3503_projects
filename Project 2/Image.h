#pragma once
#include <vector>
#include "Pixel.h"
using namespace std;

class Image {
public:
	struct Header {
		char idLength;
		char colorMapType;
		char dataTypeCode;
		short colorMapOrigin;
		short colorMapLength;
		char colorMapDepth;
		short xOrigin;
		short yOrigin;
		short width;
		short height;
		char bitsPerPixel;
		char imageDescriptor;
	};
	Image(Header x);
	void PrintHeader();
	void AddPixel(Pixel& p);
	vector<Pixel> GetPixels();
	int GetPixelVectorCount();
	void ChangePixel(int x, Pixel p);
	Header GetHeader();
	Pixel GetIndPixel(int x);
private:
	Header head;
	short width;
	short height;
	vector<Pixel> pixels;
};