// ****************************************************//
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online //
// This code comes from Professor Joshua Fox         //
// *************************************************//

#pragma once
#include <random>

class Random
{
public:
	static int Int(int min, int max);
	static float Float(float min, float max);
private:
	static std::mt19937 random;
};

