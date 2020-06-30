#include <iostream>
#include <string>
//#include <vector>
#include "Image.h"
using namespace std;

Image::Image(Header x) {
	head = x;
	width = x.width;
	height = x.height;
}

Image::Image() {
	// Default image, when file not found
	head.idLength = 0;
	width = 0;
	height = 0;
}

void Image::PrintHeader() {
	cout << head.idLength << " ";
	cout << head.colorMapType << " ";
	cout << head.dataTypeCode << " ";
	cout << head.colorMapOrigin << " ";
	cout << head.colorMapLength << " ";
	cout << head.colorMapDepth << " ";
	cout << head.xOrigin << " ";
	cout << head.yOrigin << " ";
	cout << head.width << " ";
	cout << head.height << " ";
	cout << head.bitsPerPixel << " ";
	cout << head.imageDescriptor << " //// ";
	cout << "     Pixels: " << GetPixelVectorCount() << endl;
}

const Image::Header Image::GetHeader() const {
	return head;
}

Image::Header Image::GetHeader() {
	return head;
}

void Image::AddPixel(Pixel& p) {
	pixels.push_back(p);
}

const int Image::GetPixelVectorCount() const {
	return pixels.size();
}

int Image::GetPixelVectorCount() {
	return pixels.size();
}

const Pixel Image::GetIndPixel(int x) const {
	return pixels.at(x);
}

Pixel Image::GetIndPixel(int x) {
	return pixels.at(x);
}

const short Image::GetHeight() const {
	return height;
}

const short Image::GetWidth() const {
	return width;
}