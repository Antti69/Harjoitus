#include "Clock.h"

Clock::Clock()
{
	aika = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	localtime_s(&timebuffer, &aika);
}

void Clock::ProccesMenu()
{
	int choice;
	do
	{
		std::cout << "0.Back to main menu \n1.Tell Time \n2.Change Time" << std::endl;
		std::cin >> choice;
		std::cout << '\n';

		switch (choice)
		{
		case 0:
			break;
		case 1:
			TellTime();
			break;
		case 2:
			ChangeTime();
			break;
		}
	} while (choice != 0);
}

void Clock::TellTime()
{
	std::cout << std::put_time(&timebuffer, "%R") << std::endl;
}

void Clock::ChangeTime()
{
	int min;
	std::cout << "Add or Subtract Time: " << std::endl;
	std::cin >> min;
	min *= 60;

	time_t temp = time_t(min);
	aika += temp;
	localtime_s(&timebuffer, &aika);
}
