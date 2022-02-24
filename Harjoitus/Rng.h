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
private:
	enum class NormalDistProbabilityRange
	{
		HighProbability,
		MediumProbability,
		LowProbability,
		Invalid
	};
public:
	int CreateInt(int min, int max, bool NormalDistr = false);			//Other Create functions will call this one
	float CreateFloat(float min, float max);							//Use range as two decimal or less
	unsigned char CreateChar();											//Based on custom Ascci table
	std::string CreateString(int lenght);
	void ReSeed();
private:
	int GetRandomNumber(int min, int max);
	NormalDistProbabilityRange GetRange(int num, int range);
private:
	unsigned int seed = (unsigned int)std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 rg{ seed };
	int countertest = 0;
};