#pragma once
#include <algorithm>
#include <chrono>
#include <ratio>
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "FrameTimer.h"
#include "HelperFunc.h"

class Clock
{
public:
	Clock();
	void ProccesMenu();
	time_t GetTime() const;
private:
	void TellTime();
	void ChangeTime();
	void StopWatch();
	void UpdateTime();
	
private:
	time_t aika;
	struct tm timebuffer;
	
};
