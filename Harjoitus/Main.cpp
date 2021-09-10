#include <iostream>
#include <string>
#include <algorithm>
#include "ChessGrains.h"
#include <sstream>

void ClearStream()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace SpaceAge
{
	float SecondsToYears(int seconds)
	{
		float years;
		int EarthYear = 31557600;
		years = float(seconds) / EarthYear;

		return years;
	}

	void Process()
	{
		int seconds;
		std::cout << "How old are you in seconds?" << std::endl;
		std::cin >> seconds;
		std::cout << "You are Earths years: " << SecondsToYears(seconds) << std::endl;
		std::cout << "You are Mercury years: " << SecondsToYears(seconds) / 0.2408467 << std::endl;
		std::cout << "You are Venus years: " << SecondsToYears(seconds) / 0.61519726 << std::endl;
		std::cout << "You are Mars years: " << SecondsToYears(seconds) / 1.8808158 << std::endl;
		std::cout << "You are Jupiter years: " << SecondsToYears(seconds) / 11.862615 << std::endl;
		std::cout << "You are Saturn years: " << SecondsToYears(seconds) / 29.447498 << std::endl;
		std::cout << "You are Uranus years: " << SecondsToYears(seconds) / 84.016846 << std::endl;
		std::cout << "You are Neptune years: " << SecondsToYears(seconds) / 164.79132 << std::endl;
		ClearStream();
	}
}


namespace InputRev
{
	std::string Reverse(std::string input)
	{
		std::string output;

		for (int i = int(input.size()); i >= 0; i--)
		{
			output.push_back(input[i]);
		}

		return output;
	}
	void Process()
	{
		std::string input;
		std::cout << "Give me a string" << std::endl;
		std::cin >> input;
		input = Reverse(input);
		std::cout << input << std::endl;

		ClearStream();

	}
}



namespace LeapYear
{
	bool IsLeapYear(int year)
	{
		bool leapYear = false;

		if (year % 4 == 0)
		{
			if (year % 100 == 0 && year % 400 != 0)
			{
				leapYear = false;
			}
			else
			{
				leapYear = true;
			}

		}
		else
		{
			leapYear = false;
		}
		return leapYear;
	}

	void Procces()
	{
		int year;
		std::cout << "Enter Year" << std::endl;
		std::cin >> year;
		bool LeapYear = IsLeapYear(year);
		if (LeapYear)
		{
			std::cout << "Is a Leap Year\n" << std::endl;
		}
		else
		{
			std::cout << "Not a Leap Year\n" << std::endl;
		}
		ClearStream();
	}
}

namespace Raindrop
{
	std::string FactorCac(int num)
	{
		std::string a = "Pling3";
		std::string b = "Plang5";
		std::string c = "Plong7";
		std::string result;
		if (num % 3 == 0 || num % 5 == 0 || num % 7 == 0)
		{
			if (num % 3 == 0)
			{
				result += a;
			}
			if (num % 5 == 0)
			{
				result += b;
			}
			if (num % 7 == 0)
			{
				result += c;
			}
		}
		else
		{
			result = std::to_string(num);
		}
		return result;

	}
	void Process()
	{
		std::string output;
		int num;
		std::cout << "Enter a number" << std::endl;
		std::cin >> num;
		std::cout << "Raindrop bullshit corresponding:  " << FactorCac(num) << std::endl;
		ClearStream();
	}
}

namespace Pangram  //rangillä paremmaks?
{
	bool PangramCheck(std::string& input) //kikkailua ja testailua voi tehdä lyhyemminki...
	{
		bool panagram = false;
		bool nomatch = false;

		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		auto endpos = std::remove(input.begin(), input.end(), ' ');
		input.erase(endpos, input.end());
		
		if (input.size() < 26)
		{
			panagram = false;
		}
		else
		{
			for (char alphabet = 'a'; alphabet < 'z'; alphabet++)
			{
				for (int i = 0; i < int(input.size()); i++)
				{
					if (input[i] == alphabet)
					{
						nomatch = false;
						break;
					}
					if (i == int(input.size()) - 1)
					{
						nomatch = true;
					}
				}
				if (nomatch == true)
				{
					break;
				}
			}
			if (nomatch == false)
			{
				panagram = true;
			}
			else
			{
				panagram = false;
			}
		}


		return panagram;
	}
	void Process()
	{
		std::string input;
		std::cout << "Give a phrase: " << std::endl;

		do
		{
			std::getline(std::cin, input);
		} while (std::cin.get() != '\n');
		

		if (PangramCheck(input))
		{
			std::cout << "Phrase is a Pangram" << std::endl;
		}
		else
		{
			std::cout << "Phrase is NOT a Pangram" << std::endl;
		}

		ClearStream();
	}
}

namespace TwoFer
{
	void TwoFer()
	{
		std::string name;
		std::string defname = "you";
		bool t = true;
		while (t)
		{
			ClearStream();
			std::cout << "Enter a name: " << std::endl;
			if (std::cin.get() == '\n')
			{
				t = false;
				name = defname;
				break;
			}
			else
			{
				std::cin >> name;
				t = false;
				break;
			}
		}
		std::cout << "One for " << name << " one for me" << '\n' << std::endl;
		ClearStream();
	}
}

int main()
{
	ChessGrains c;
	int choice;
	do
	{
		std::cout << "Anna komento \n0.Exit \n1.Leap Year caculator\n2.String reverse\n3.Seconds to Year\n" << std::endl;
		std::cout << "4.ChessGrain \n5.RainDrop \n6.Pangram \n7.TwoFer" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			LeapYear::Procces();
			break;
		case 2:
			InputRev::Process();
			break;
		case 3:
			SpaceAge::Process();
			break;
		case 4:
			c.Process();
			break;
		case 5:
			Raindrop::Process();
			break;
		case 6:
			Pangram::Process();
			break;
		case 7:
			TwoFer::TwoFer();
			break;
		}


	} while (choice != 0);

	return 0;
}