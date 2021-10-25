#pragma once
#include <vector>
#include <map>
#include <numeric>
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <functional>


class RobotFactory
{
public:
	RobotFactory();
	void Process();

private:
	void AddRobo();
	void ResetRobo();
	void PrintRobos();
	std::string GenerateName();
private:
	std::map<int, std::string> robotname;
	std::mt19937 rng;
};