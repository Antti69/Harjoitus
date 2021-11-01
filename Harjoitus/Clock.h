#pragma once
#include <algorithm>
#include <chrono>
#include <ratio>
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "FrameTimer.h"
#include <conio.h>

class Clock
{
public:
	Clock();
	void ProccesMenu();
private:
	void TellTime();
	void ChangeTime();
	void StopWatch();
private:
	time_t aika;
	struct tm timebuffer;
};