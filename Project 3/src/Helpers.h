// ***************************************************** //
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online   //
// All code completely original,					   //
// Inspired by Professor Joshua Fox's lectures,       //
// Or from previous COP3503 Projects and Labs        //
// *************************************************//

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