#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include <string>


class Say
{
public:
	Say();
	void Procces();

private:
	std::string Translate(int input);

private:
	std::map<int, std::string> ZeroToNine;
	std::map<int, std::string> TenToNineteen;
	std::map<int, std::string> Tens;
};