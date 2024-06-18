#include "SayNumbers.h"

Say::Say()
{
	ZeroToNine = { {0, ""}, {1, "One "}, {2, "Two "}, {3, "Three "}, {4, "Four "}, {5, "Five "},
	{6, "Six "}, {7, "Seven "}, {8, "Eight "}, {9, "Nine "} };

	TenToNineteen = { {10, "Ten "}, {11, "Eleven "}, {12, "Twelve "}, {13, "Thirteen "}, {14, "Fourteen "}, {15, "Fiftteen "},
	{16, "Sixteen "}, {17, "Seventeen "}, {18, "Eighteen "}, {19, "Nineteen "} };
	
	Tens = { {2, "Twenty "}, {3, "Thirty "}, {4, "Fourty "}, {5, "Fifty "}, {6, "Sixty "}, {7, "Seventy "},
	{8, "Eighty "}, {9, "Ninety "} };

	all = { {0, "Zero"}, {1, "One "}, {2, "Two "}, {3, "Three "}, {4, "Four "}, {5, "Five "},
	{6, "Six "}, {7, "Seven "}, {8, "Eight "}, {9, "Nine "},
	{10, "Ten "}, {11, "Eleven "}, {12, "Twelve "}, {13, "Thirteen "}, {14, "Fourteen "}, {15, "Fiftteen "},
	{16, "Sixteen "}, {17, "Seventeen "}, {18, "Eighteen "}, {19, "Nineteen "},
	{20, "Twenty "}, {30, "Thirty "}, {40, "Fourty "}, {50, "Fifty "}, {60, "Sixty "}, {70, "Seventy "},
	{80, "Eighty "}, {90, "Ninety "} };

	OneToNintyNine = all;

	for (int t = 20; t < 100; t += 10)
	{
		for (int i = 1; i < 10; i++)
		{
			int ti = t + i;
			std::string ka = all.find(t)->second + ZeroToNine.find(i)->second;
			OneToNintyNine.emplace(ti, ka);
		}
	}

}

void Say::Procces()
{
	b.Start();
	int num;
	int maxnum = 10000000;
	std::string chunks;
	std::cout << "Enter a number: " << std::endl;
	std::cin >> num;

	if (std::cin.good())
	{
		if (num > maxnum)
		{
			std::cout << "Number out of range" << std::endl;
			std::cout << '\n';
		}
		else
		{
			chunks = std::to_string(num);
			if (chunks.size() > 3)
			{
				for (int i = int(chunks.size() - 3); i > 0; i -= 3)
				{
					chunks.insert(i, ",");
				}
			}

			std::cout << '\n';
			std::cout << chunks << std::endl;
			std::cout << Translate(num) << std::endl; //change this func to aplly difrent methods...
			std::cout << '\n';
			ouputter.clear();
		}
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << '\n';
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (b.End())
	{
        std::wofstream out("Ben.txt");
		out << std::wstring(b);
	}

	
}

std::string Say::Translate(int input)
{
	std::string out;

	int numcount = input / 1000000;
	input %= 1000000;

	if (numcount > 0)
	{
		out += all.find(numcount)->second;
		out += "Million ";
	}

	numcount = input / 100000;
	input %= 100000;

	if (numcount > 0)
	{
		out += all.find(numcount)->second;
		out += "Hundred ";
	}

	numcount = input / 1000;
	input %= 1000;

	if (numcount > 0)
	{
		out += OneToNintyNine.find(numcount)->second;
		out += "Thousands ";
	}

	numcount = input / 100;
	input %= 100;

	if (numcount > 0)
	{
		out += all.find(numcount)->second;
		out += "Hundred ";
	}

	numcount = input / 1;
	input %= 1;

	if (numcount > 0)
	{
		out += OneToNintyNine.find(numcount)->second;
	}

	return out;
} 

std::string Say::StringParser(int input)  //String parsing algo, handles translations based on the number and pos of the digits
{
	std::string in = std::to_string(input);
	std::string out;
	int temp = 0;   //transfer val to the next loop iteration

	for (int i = int(in.size()) - 1; i >= 0; i--)		//handles digit right to left
	{
		int t = 0;
		t = in[i] - '0';
		if (i == in.size() - 1) //ones
		{
			if (in.size() > 1)
			{
				temp = t;
			}
			else
			{
				out.insert(0, ZeroToNine.find(t)->second);
				if (t == 0)
				{
					out = "Zero";
				}
			}
		}
		else if (i == in.size() - 2)	//tens
		{
			if (t == 1)
			{
				temp += 10;
				out.insert(0, TenToNineteen.find(temp)->second);
			}
			else
			{
				out.insert(0, ZeroToNine.find(temp)->second);
				if (t != 0)
				{
					out.insert(0, Tens.find(t)->second);
				}
			}
			temp = 0;
		}
		else if (i == in.size() - 3)	//hundreds
		{
			if (t != 0)
			{
				out.insert(0, "Hundred ");
				out.insert(0, ZeroToNine.find(t)->second);
			}
		}
		else if (i == in.size() - 4)  //Thousands
		{
			if (temp != 0)
			{
				out.insert(0, ZeroToNine.find(temp)->second);
			}
			out.insert(0, "Thousand ");
			if (in.size() > 4)
			{
				temp = t;
			}
			else
			{
				out.insert(0, ZeroToNine.find(t)->second);
			}
		}
		else if (i == in.size() - 5) //Tens of Thousands
		{
			if (t == 1)
			{
				temp += 10;
				out.insert(0, TenToNineteen.find(temp)->second);
			}
			else
			{
				out.insert(0, ZeroToNine.find(temp)->second);
				if (t != 0)
				{
					out.insert(0, Tens.find(t)->second);
				}
			}
		}
		else if (i == in.size() - 6) //Hundreds of Thousands
		{
			if (t != 0)
			{
				out.insert(0, "Hundred ");
				out.insert(0, ZeroToNine.find(t)->second);
			}
		}
	}

	return out;
}


std::string Say::TranslateRecursive(int input, int div)
{
	int numcount = input / div;
	if (numcount > 0)
	{
		ouputter += OneToNintyNine.find(numcount)->second;
		ouputter += InputCounter(input);
	}
	input %= div;
	if (div == 100000 || div == 100)
	{
		div /= 100;
	}
	else
	{
		div /= 10;
	}
	if (div > 0)
	{
		TranslateRecursive(input, div );
	}
	return ouputter;
}

std::string Say::InputCounter(int input)
{
	std::string in = std::to_string(input);
	std::string out;

	if (in.size() == 7)
	{
		out = "Million ";
	}
	else if (in.size() == 6 )
	{
		out = "Hundred ";
	}
	else if (in.size() == 3)
	{
		out = "Hundred ";
	}
	else if (in.size() == 4 || in.size() == 5)
	{
		out = "Thousand ";
	}
	return out;
}
