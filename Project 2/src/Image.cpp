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

Image::Header Image::GetHeader() {
	return head;
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

void Image::AddPixel(Pixel& p) {
	pixels.push_back(p);
}

int Image::GetPixelVectorCount() {
	return pixels.size();
}

vector<Pixel> Image::GetPixels() {
	return pixels;
}

void Image::ChangePixel(int x, Pixel p) {
	pixels.at(x) = p;
}

Pixel Image::GetIndPixel(int x) {
	return pixels.at(x);
}