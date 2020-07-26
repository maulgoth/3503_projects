#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
using std::ifstream;
using std::vector;
using std::string;

class Helpers
{
private:
public:
	static vector<char> readFile(int test_board);
	static vector<int> digitizer(int number);
};