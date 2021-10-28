#pragma once
#include <algorithm>
#include <chrono>
#include <ratio>
#include <iostream>
#include <string>

class Clock
{
public:
	Clock();
	void ProccesMenu();

private:


protected:
	int mins;
	int secons;

private:
	int hour;

};