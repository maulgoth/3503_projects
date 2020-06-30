// Simple Timer is Duplicate of Professor Joshua Fox
// For the course COP3503 at the University of Florida

#pragma once
#include <chrono>
#include <string>
using std::string;
using highResClock = std::chrono::high_resolution_clock; // alias
using timePoint = highResClock::time_point;

class SimpleTimer {
	string message;
	timePoint start;
	timePoint end;
	std::chrono::duration<double> elapsed;
public:
	SimpleTimer(const char* msg);
	~SimpleTimer();
};