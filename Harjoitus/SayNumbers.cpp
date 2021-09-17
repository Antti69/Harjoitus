#include "SayNumbers.h"

Say::Say()
{
	ZeroToNine = { {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
	{6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"} };

	TenToNineteen = { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fiftteen"},
	{16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"} };
	
	Tens = { {20, "Twenty"}, {30, "Thirty"}, {40, "Fourty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"},
	{80, "Eighty"}, {90, "Ninety"} };
}

void Say::Procces()
{
	int num;
	std::cout << "Enter a number: " << std::endl;
	std::cin >> num;
	if (std::cin.good())
	{
		std::cout << Translate(num) << std::endl;
		std::cout << '\n';
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << '\n';
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string Say::Translate(int input)
{
	std::string output;
	std::string Negative = "Minus";

	if (input > 0 && input < 10 )
	{
		output = ZeroToNine.find(input)->second;
	}
	else if (input >= 10 && input < 20)
	{
		output = TenToNineteen.find(input)->second;
	}

	return output;
}
