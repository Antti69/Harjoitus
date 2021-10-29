#pragma once
#include <algorithm>
#include <chrono>
#include <ratio>
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

class Clock
{
public:
	Clock();
	void ProccesMenu();
private:
	void TellTime();
	void ChangeTime();

private:
	time_t aika;
	struct tm timebuffer;
};