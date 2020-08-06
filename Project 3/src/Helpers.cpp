// ***************************************************** //
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online   //
// All code completely original,					   //
// Inspired by Professor Joshua Fox's lectures,       //
// Or from previous COP3503 Projects and Labs        //
// *************************************************//

#include "Helpers.h"

vector<char> Helpers::readFile(int test_board) {

	string fileName = "boards/testboard" + std::to_string(test_board) + ".brd";
	vector<char> bombs;
	ifstream file(fileName);

	if (file.is_open()) {
		char value;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 25; j++) {
				file.get(value);
				bombs.push_back(value);
			}
			file.ignore(1);
		}
		file.close();
	}
	return bombs;
}

vector<int> Helpers::digitizer(int number) {
	vector<int> nums;

	// Can't handle < -99
	if (number < -99) {
		nums.push_back(10);
		nums.push_back(9);
		nums.push_back(9);
	}

	// -99 to -10
	else if (number < -9) {
		nums.push_back(10);
		int temp = (number * -1) / 10;
		nums.push_back(temp);
		temp = (number * -1) % 10;
		nums.push_back(temp);
	}

	// - 9 to -1
	else if (number < 0) {
		nums.push_back(10);
		nums.push_back(0);
		nums.push_back(number * -1);
	}

	// 0 to 9
	else if (number < 10) {
		nums.push_back(0);
		nums.push_back(0);
		nums.push_back(number);
	}

	// 10 to 99
	else if (number < 100) {
		nums.push_back(0);
		int temp = number / 10;
		nums.push_back(temp);
		temp = number % 10;
		nums.push_back(temp);
	}

	// 100 to 999 <- In our version, max is 400
	else if (number < 1000) {
		int temp = number / 100;
		nums.push_back(temp);
		temp = number % 100;
		temp /= 10;
		nums.push_back(temp);
		temp = number % 10;
		nums.push_back(temp);
	}

	// Unnecessary for our game but just in case, max at 999
	else if (number > 999) {
		nums.push_back(9);
		nums.push_back(9);
		nums.push_back(9);
	}

	return nums;
}