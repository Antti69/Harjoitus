#include "Clock.h"

Clock::Clock()
{
	UpdateTime();
}

void Clock::ProccesMenu()
{
	int choice;
	do
	{
		std::cout << "0.Back to main menu \n1.Tell Time \n2.Change Time \n3.StopWatch" << std::endl;
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
		case 3:
			StopWatch();
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

void Clock::StopWatch()
{
	char start;
	std::cout << "Press enter to start the Clock!" << std::endl;
	std::cin >> start;
	float sec = 0;
	while (!_kbhit())
	{
		FrameTimer ft;
		std::cout << "Timer: " << sec << std::endl;
		system("cls");
		sec += ft.Mark();
	}
	std::cout << "Timer: " << sec << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	sec = 0;
}

void Clock::UpdateTime()
{
	aika = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	localtime_s(&timebuffer, &aika);
}

time_t Clock::GetTime() const
{
	
	return aika;
}
