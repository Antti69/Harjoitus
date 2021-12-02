#pragma once
#include <chrono>

class FrameTimer
{
public:
	FrameTimer()
	{
		using namespace std::chrono;
		last = steady_clock::now();
	}
	template<typename T>
	T Mark()
	{
		using namespace std::chrono;
		const auto old = last;
		last = steady_clock::now();
		const duration<T> frameTime = last - old;
		return frameTime.count();
		
	}
	int Mark_int()
	{
		using namespace std::chrono;
		const auto old = last;
		last = steady_clock::now();
		const duration<int, std::nano> frameTime = last - old;
		return frameTime.count();
	}
	unsigned long long int GetNano()
	{
		using namespace std::chrono;
		nanoseconds n(last.time_since_epoch());
		unsigned long long int r = (unsigned long long int)n.count();
		return r;
	}
private:
	std::chrono::steady_clock::time_point last;
};

