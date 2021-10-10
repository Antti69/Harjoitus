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
	std::string StringParser(int input);
	std::string TranslateTestRec(int input, int dive);

private:
	std::map<int, std::string> ZeroToNine;
	std::map<int, std::string> TenToNineteen;
	std::map<int, std::string> Tens;
	std::map<int, std::string> all;
	std::map<int, std::string> test;
};