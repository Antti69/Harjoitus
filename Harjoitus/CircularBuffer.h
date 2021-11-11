#pragma once
#include "HelperFunc.h"

template<class T>
class CircularBuffer
{
public:
	CircularBuffer(int maxsize)
		:
		maxsize(maxsize)
	{
		data.reserve(maxsize);
	}
	void Write(T val)
	{
		if (IsFull())
		{
			std::cout << "Buffer Full, unable to write!" << std::endl;
		}
		else
		{
			data.push_back(val);
		}
	}
	void Overwrite(T val)
	{
		if (IsFull())
		{
			data.erase(data.begin());
			data.push_back(val);
			data.shrink_to_fit();
		}
		else
		{
			Write(val);
		}

	}
	T Read()
	{
		T i = data.front();
		data.erase(data.begin());
		data.shrink_to_fit();
		return i;
	}
	void Clear()
	{
		data.clear();
	}
	std::vector<T> CheckElements()
	{
		return data;
	}
private:
	bool IsFull() const
	{
		return data.size() == maxsize;
	}
	std::vector<T> data;
	int maxsize;

};