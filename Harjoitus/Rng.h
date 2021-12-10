#pragma once
#include <algorithm>
#include <chrono>
#include <ratio>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>

class FrameTimerRng
{
public:
	FrameTimerRng()
	{
		using namespace std::chrono;
		highlast = high_resolution_clock::now();
	}
	uint64_t GetNano()
	{
		using namespace std::chrono;
		nanoseconds n(highlast.time_since_epoch());
		uint64_t  r = (uint64_t)n.count();
		return r;
		
	}
private:
	std::chrono::high_resolution_clock::time_point highlast;
};


class ClockRng
{
public:
	ClockRng()
	{
		UpdateTime();
	}
	time_t GetTime() const
	{
		return aika;
	}
	void UpdateTime()
	{
		aika = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		localtime_s(&timebuffer, &aika);
	}
private:
	time_t aika;
	struct tm timebuffer;
};

class Rng
{
public:
	int rng(int min, int max)
	{
		FrameTimerRng ft;		//initializing timer, clock and dummy array
		clock.UpdateTime();
		int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int arr2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		double time = (double)clock.GetTime();
		
		std::thread::id t_thread = std::this_thread::get_id();		//Getting current thread id number and converting to uint64
		std::stringstream ts;
		ts << t_thread;
		uint64_t id = std::stoull(ts.str());

		time /= 100;						//Getting value from the clock and converting to uint64, only seconds 
		time = std::modf(time, &time);
		time *= 100;
		uint64_t cumval = (uint64_t)time;

		uint64_t nanotimer = ft.GetNano();				//Getting timer value in nanoseconds
		std::string temp = std::to_string(nanotimer);
		char c = temp.back();
		int lastnano = c - '0';				//Saving the last number of the timer
		char c2 = temp[temp.size() - 2];
		int lastnano2 = c2 - '0';

		std::stringstream mem;			//Getting dummy array adress value in hexa based on the lastnano, and converting to uint64 decimal value
		mem << &arr[lastnano];
		std::string memtemp;
		mem >> memtemp;
		std::string memout = memtemp.substr(8, std::string::npos);  //Discarding first 8 hexa numbers
		uint64_t memval = HexaToDecConverion<uint64_t >(memout);
		std::stringstream mem2;			
		mem2 << &arr2[lastnano2];
		std::string memtemp2;
		mem2 >> memtemp2;
		std::string memout2 = memtemp2.substr(8, std::string::npos);  
		uint64_t memval2 = HexaToDecConverion<uint64_t >(memout2);

		cumval = nanotimer / cumval;				//Mixing all of the values together
		cumval -= id;
		cumval -= memval;
		cumval -= memval2;

		cumval %= max;						//Targeting the output range
		int output = (int)cumval;

		if (output < min)					//if val is below min doing recursion
		{
			output = rng(min, max);
		}

		return output;
	}

private:
	template<typename T>
	T HexaToDecConverion(const std::string& input)
	{
		T pow = (T)input.size() - 1;
		T base = 16;
		T num = 0;
		T result = 0;
		for (auto i : input)
		{
			if (std::isdigit(i))
			{
				num = i - '0';
			}
			else
			{
				num = (i - 'A') + 10;
			}
			result += num * (T)std::pow(base, pow);
			pow--;
		}
		return result;
	}

private:
	ClockRng clock;
};