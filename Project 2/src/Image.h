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
	// Constructors
	Image();
	Image(Header x);

	// Getters
	void PrintHeader();
	const Header GetHeader() const;
	Header GetHeader();
	const Pixel GetIndPixel(int x) const;
	Pixel GetIndPixel(int x);
	const int GetPixelVectorCount() const;
	int GetPixelVectorCount();
	const short GetHeight() const;
	const short GetWidth() const;

	//Setters
	void AddPixel(Pixel& p);
	
private:
	Header head;
	short width;
	short height;
	vector<Pixel> pixels;
};