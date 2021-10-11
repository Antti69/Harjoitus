#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include <string>


class Say		//This class contains lots of expermential and practice stuff..
{
public:
	Say();
	void Procces();

private:
	std::string Translate(int input);
	std::string StringParser(int input);
	std::string TranslateRecursive(int input, int div);
	std::string InputCounter(int input); //for Recursive method..

private:
	std::map<int, std::string> ZeroToNine;
	std::map<int, std::string> TenToNineteen;
	std::map<int, std::string> Tens;
	std::map<int, std::string> all;
	std::map<int, std::string> OneToNintyNine;
	std::string ouputter; //for Recursive method..
};