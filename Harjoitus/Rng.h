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
	int CreateInt(int min, int max, bool NormalDistr = false);			//Other Create functions will call this one
	float CreateFloat(float min, float max, bool NormalDistr = false);	//Use range as two decimal or less
	unsigned char CreateChar();											//Based on custom Ascci table
	std::string CreateString(int lenght);
	void ReSeed();
private:
	unsigned int seed = (unsigned int)std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 rg{ seed };
};