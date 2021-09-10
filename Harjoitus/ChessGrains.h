#pragma once
#include <algorithm>
#include <vector>
#include <map>
#include "Vec2.h"
#include <iostream>


class ChessGrains
{
public:
	ChessGrains()
	{
		SquareMap.resize(total);
		unsigned long long int t = 1;
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int i = y * width + x;
				SquareMap[i] = t;
				t *= 2;
			}
		}
	}
	unsigned long long int GetSquareGrains(unsigned long long int x, unsigned long long int y)
	{
		return SquareMap[static_cast<std::vector<unsigned long long, std::allocator<unsigned long long>>::size_type>(y) * width + x];
	}
	unsigned long long int CaculateTotalGrains()
	{
		
		unsigned long long int total = 0;

		for (auto e : SquareMap)
		{
			total += e;
		}
		return total;
	}
	void Process()
	{
		char mark;
		int grainx;
		int grainy;
		std::cout << "Give a chessboard coord?, Example 1.3" << std::endl;
		std::cin >> grainx >> mark >> grainy;
		std::cout << GetSquareGrains(grainx, grainy) << "\n" << std::endl;
		std::cout << "Total number of grains in chessboard is: " << CaculateTotalGrains() << std::endl;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}


private:
	std::vector<unsigned long long int> SquareMap;
	static constexpr int width = 8;
	static constexpr int height = 8;
	static constexpr int total = width * height;
};