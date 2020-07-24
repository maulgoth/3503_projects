#include "Helpers.h"

vector<char> Helpers::readFile(int test_board) {
	if (test_board < 1 || test_board > 3)
		std::cout << "BOARD NOT AVAIL!" << std::endl;

	string fileName = "boards/testboard" + std::to_string(test_board) + ".brd";

	std::cout << "Loading " << fileName << " ...." << std::endl;

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

int Helpers::digitizer(int number) {

}