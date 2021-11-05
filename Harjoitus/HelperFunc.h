#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <functional>
#include <cmath>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <vector>
#include <map>
#include <numeric>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <conio.h>

namespace Help
{
	void ClearStream()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	template<typename T>
	void RemoveMatchElementsVec(std::vector<T>& VecToRem, const std::vector<T>& comp)
	{
		for (int vecr = 0; vecr < VecToRem.size(); vecr++)
		{
			for (int vecco = 0; vecco < comp.size(); vecco++)
			{
				if (VecToRem[vecr] == comp[vecco])
				{
					VecToRem.erase(VecToRem.begin() + vecr);
				}
			}
		}
	}
	template<typename T>
	void PrintVec(const std::vector<T>& out)
	{
		for (auto& i : out)
		{
			std::cout << i << '\n';
		}
		ClearStream();
	}


	template<typename T>
	void PrintCont(const T& beg, const T& end) //Prints Container with set range! Dont use on maps!
	{
		std::for_each(beg, end, [](auto& i) { std::cout << i << '\n'; });
		ClearStream();
	}
	template<typename Cont>
	void PrintCont(const Cont& cont) //Prints the whole Container! Dont use on maps!
	{
		PrintCont(std::begin(cont), std::end(cont));
		ClearStream();
	}
}