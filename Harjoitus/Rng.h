#pragma once
#include <algorithm>
#include <chrono>
#include <ratio>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>

#include <random>
#include <iostream>



class Rng1
{
public:
	int CreateInt(int min, int max);
	float CreateFloat(float min, float max); //Use range as two decimal or less
	unsigned char CreateChar();
private:
	std::mt19937 rg{ (unsigned int)std::chrono::high_resolution_clock::now().time_since_epoch().count() };
};