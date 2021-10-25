#include "RobotFactory.h"
RobotFactory::RobotFactory()
	:
	rng(std::random_device() ())
{
}
void RobotFactory::Process()
{
	int choice;
	do
	{
		std::cout << "0.Back to main menu \n1.Print menu \n2.Add Robo" << std::endl;
		std::cout << "3.Reset Robo \n" << std::endl;
		std::cin >> choice;
		std::cout << '\n';

		switch (choice)
		{
		case 0:
			break;
		case 1:
			PrintRobos();
			break;
		case 2:
			AddRobo();
			break;
		case 3:
			ResetRobo();
			break;
		}
	} while (choice != 0);
}
void RobotFactory::AddRobo()
{
	int k = (int)robotname.size();
	std::string name = GenerateName();
	std::pair<int, std::string> i(k, name);
	robotname.insert(i);
}

void RobotFactory::ResetRobo()
{
	int r;
	std::cout << "Enter number of Robot that you want to a reset: " << std::endl;
	std::cin >> r;
	robotname.find(r)->second = GenerateName();
	std::cout << "Robots new name is: \n" << robotname.find(r)->second << std::endl;
}

void RobotFactory::PrintRobos()
{
	int choice;
	do
	{
		std::cout << "0.Back to Robo menu \n1.Print one Robo \n2.Print all of the Robos" << std::endl;
		std::cin >> choice;
		std::cout << '\n';

		switch (choice)
		{
		case 0:
			break;
		case 1:
		{
			int num;
			std::cout << "Enter robo number" << std::endl;
			std::cin >> num;
			std::cout << "Robot name is: \n " << robotname.find(num)->first << '.' << robotname.find(num)->second << '\n' << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "List of all the Robots: " << std::endl;
			for (auto& i : robotname)
			{
				std::cout << i.first << '.' << i.second << '\n' << std::endl;
			}
			break;
		}
		}
	} while (choice != 0);

}

std::string RobotFactory::GenerateName()
{
	std::string name;
	for (int i = 0; i < 2; i++)
	{
		std::uniform_int_distribution<int> randchars(0, 25);
		char c = 'A' + randchars(rng);
		name.push_back(c);
	}
	std::uniform_int_distribution<int> randnum(100, 999);
	std::string temp = std::to_string(randnum(rng));
	name += temp;
	bool namebad = false;
	for (auto& i : robotname)
	{
		if (i.second == name)
		{
			namebad = true;
		}
	}
	if (namebad == true)
	{
		GenerateName();
	}
	return name;
}
