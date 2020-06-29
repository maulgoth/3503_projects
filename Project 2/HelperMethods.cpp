#include "HelperMethods.h"
using namespace HelperMethods;

// Max Min for RGB Pixels
const unsigned char global_max = 255;
const unsigned char global_min = 0;

// Read File
Image HelperMethods::readFile(string path) {
	ifstream file(path, ios_base::binary);
	if (file.is_open()) {

		// Read Header
		Image::Header h;
		file.read(&h.idLength, sizeof(h.idLength));
		file.read(&h.colorMapType, sizeof(h.colorMapType));
		file.read(&h.dataTypeCode, sizeof(h.dataTypeCode));
		file.read((char*)&h.colorMapOrigin, sizeof(h.colorMapOrigin));
		file.read((char*)&h.colorMapLength, sizeof(h.colorMapLength));
		file.read((char*)&h.colorMapDepth, sizeof(h.colorMapDepth));
		file.read((char*)&h.xOrigin, sizeof(h.xOrigin));
		file.read((char*)&h.yOrigin, sizeof(h.yOrigin));
		file.read((char*)&h.width, sizeof(h.width));
		file.read((char*)&h.height, sizeof(h.height));
		file.read(&h.bitsPerPixel, sizeof(h.bitsPerPixel));
		file.read(&h.imageDescriptor, sizeof(h.imageDescriptor));

		// Create Temp Image
		Image img = Image(h);

		// Add Pixels
		for (int i = 0; i < (h.height * h.width); ++i) {
			unsigned char r;
			unsigned char g;
			unsigned char b;
			file.read((char*)&b, sizeof(b));
			file.read((char*)&g, sizeof(g));
			file.read((char*)&r, sizeof(r));
			Pixel p = Pixel(r, g, b);
			img.AddPixel(p);
		}

		// Return and close
		file.close();
		return img;
	}
	else {
		cout << "Never triggered" << endl; /////////////////////
	}
}

// Write File
bool HelperMethods::writeFile(string path, Image& img) {
	cout << "Writing: '" << path << "'." << endl; /////////////////////
	ofstream file(path, ios_base::binary);
	if (file.is_open()) {

		// Write Header
		Image::Header h = img.GetHeader();
		file.write(&h.idLength, sizeof(h.idLength));
		file.write(&h.colorMapType, sizeof(h.colorMapType));
		file.write(&h.dataTypeCode, sizeof(h.dataTypeCode));
		file.write((char*)&h.colorMapOrigin, sizeof(h.colorMapOrigin));
		file.write((char*)&h.colorMapLength, sizeof(h.colorMapLength));
		file.write((char*)&h.colorMapDepth, sizeof(h.colorMapDepth));
		file.write((char*)&h.xOrigin, sizeof(h.xOrigin));
		file.write((char*)&h.yOrigin, sizeof(h.yOrigin));
		file.write((char*)&h.width, sizeof(h.width));
		file.write((char*)&h.height, sizeof(h.height));
		file.write(&h.bitsPerPixel, sizeof(h.bitsPerPixel));
		file.write(&h.imageDescriptor, sizeof(h.imageDescriptor));

		// Write Pixels
		vector<Pixel> pixels = img.GetPixels();
		for (int i = 0; i < img.GetPixelVectorCount(); ++i) {
			vector<unsigned char> rgb = pixels.at(i).GetRGB();
			unsigned char r = rgb.at(0);
			unsigned char g = rgb.at(1);
			unsigned char b = rgb.at(2);
			file.write((char*)&b, sizeof(b));
			file.write((char*)&g, sizeof(g));
			file.write((char*)&r, sizeof(r));
		}

		// Close File and Return
		file.close();
		return true;
	}

	// Return False on Failure To Write
	return false;
}

// Compare Two Images:
void HelperMethods::CompareImages(string first, string second) {
	Image FirstImage = readFile(first);
	Image SecondImage = readFile(second);

	cout << "Comparing '" << first << "' - and - '" << second << "'." << endl;

	if (FirstImage.GetHeader().idLength != SecondImage.GetHeader().idLength) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().colorMapType != SecondImage.GetHeader().colorMapType) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().dataTypeCode != SecondImage.GetHeader().dataTypeCode) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().colorMapOrigin != SecondImage.GetHeader().colorMapOrigin) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().colorMapLength != SecondImage.GetHeader().colorMapLength) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().colorMapDepth != SecondImage.GetHeader().colorMapDepth) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().xOrigin != SecondImage.GetHeader().xOrigin) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().yOrigin != SecondImage.GetHeader().yOrigin) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().width != SecondImage.GetHeader().width) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().height != SecondImage.GetHeader().height) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().bitsPerPixel != SecondImage.GetHeader().bitsPerPixel) {
		cout << "HFAIL!";
	}
	if (FirstImage.GetHeader().imageDescriptor != SecondImage.GetHeader().imageDescriptor) {
		cout << "HFAIL!";
	}

	for (int i = 0; i < FirstImage.GetPixelVectorCount(); ++i) {
		for (int j = 0; i < 3; ++i) {
			if (FirstImage.GetPixels().at(i).GetRGB().at(j) != SecondImage.GetPixels().at(i).GetRGB().at(j)) {
				cout << "PFAIL! ";
			}
		}
	}

	cout << "IMAGES MATCH. o.0\n" << endl;
}

// Print Header and Pixel Info for Comparison
void HelperMethods::PrintInfo(Image& img) {
	img.PrintHeader();
}

// Normalize Char from 0 to 1
float HelperMethods::NormChar(unsigned char c, unsigned char top, unsigned char bottom) {
	float temp = ((float)c / (float)(top - bottom));
	return temp;
}

// Multiply
bool HelperMethods::Multiply(string _top, string _bottom, string path) {

	// Load Images, Create Temp
	Image top = readFile(_top);
	Image bottom = readFile(_bottom);
	Image img = Image(top.GetHeader());
	vector<Pixel> pTop = top.GetPixels();
	vector<Pixel> pBottom = bottom.GetPixels();

	// Temporary DEBUG PRINTS ///////////////////// DELETE ME ///////////
	PrintInfo(top);
	PrintInfo(bottom);
	PrintInfo(img);
	cout << "MADE IT " << endl;
	int count = 0;
	vector<Pixel> temps;
	// Mult each pixel
	for (int i = 0; i < top.GetPixelVectorCount(); ++i) {
		//cout << "x";
		unsigned char rgb[3];
		float rgbTB[6];
		for (int j = 0; j < 6; ++j) {
			//if (j < 3)
			//	rgbTB[j] = NormChar(pTop.at(i).GetRGB().at(j), global_max, global_min);
			//else
			//	rgbTB[j] = NormChar(pBottom.at(i).GetRGB().at(j-3), global_max, global_min);
		}
		for (int j = 0; j < 6; ++j) {
			//if (j < 3)
			//	rgbTB[j] = NormChar(pTop.at(i).GetRGB().at(j), global_max, global_min);
			//else
			//	rgbTB[j] = NormChar(pBottom.at(i).GetRGB().at(j - 3), global_max, global_min);
		}
		for (int j = 0; j < 3; ++j) {
			//if (rgbTB[j] * rgbTB[j + 3] > 1) {
			//	rgb[j] = global_max;
			//}
			//else {
			//	rgb[j] = (rgbTB[j] * rgbTB[j + 3]) * 255 + 0.5f;
			//}
		}


		// Add Pixel to Temp
		//Pixel p = Pixel(rgb[0], rgb[1], rgb[2]);
		//img.AddPixel(p);
		//count++;
		//cout << count;
	}

	// Output file
	if (writeFile(path, img) == 1)
		return true;
	else
		return false;
}

// Subtract
bool HelperMethods::Subtract(string _top, string _bottom, string path) {

	// Load Images, Create Temp
	Image top = readFile(_top);
	Image bottom = readFile(_bottom);
	Image img = Image(top.GetHeader());



	//vector<Pixel> pTop = top.GetPixels();
	//vector<Pixel> pBottom = bottom.GetPixels();

	// Temporary DEBUG PRINTS ///////////////////// DELETE ME ///////////
	PrintInfo(top);
	PrintInfo(bottom);
	PrintInfo(img);

	// Subtract each pixel
	for (int i = 0; i < top.GetPixelVectorCount(); ++i) {
		unsigned char rgb[3];
		unsigned char rgbTB[6];
		for (int j = 0; j < 6; ++j) {
			if (j < 3)
				rgbTB[j] = top.GetIndPixel(i).GetRGB().at(j);
				//rgbTB[j] = pTop.at(i).GetRGB().at(j);
			else
				rgbTB[j] = bottom.GetIndPixel(i).GetRGB().at(j-3);
				//rgbTB[j] = pBottom.at(i).GetRGB().at(j - 3);
		}
		for (int j = 0; j < 3; ++j) {
			if (rgbTB[j+3] - rgbTB[j] < 0) {
				rgb[j] = global_min;
			}
			else {
				rgb[j] = (rgbTB[j+3] - rgbTB[j]);
			}
		}
		// Add Pixel to Temp
		Pixel p = Pixel(rgb[0], rgb[1], rgb[2]);
		img.AddPixel(p);
	}

	cout << "DONE" << endl;

	// Output file
	//Image& imgTemp = img;
	if (writeFile(path, img) == 1)
		return true;
	else
		return false;
}