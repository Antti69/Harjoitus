
#include "ChessGrains.h"
#include "Database.h"
#include "SayNumbers.h"
#include "RobotFactory.h"
#include "Clock.h"
#include "HelperFunc.h"
#include <regex>
#include <ranges>
#include "CircularBuffer.h"
#include <thread>
#include "Rng.h"
#include "RngTests.h"

namespace rg = std::ranges;
namespace vi = std::ranges::views;

//Information about the assignments is in https://exercism.org/tracks/cpp/exercises

void fpoint(void(*funct)(int), int a) //fuctio pointer harjoitteluu, tutki myˆhemmin saako t‰ll‰ mit‰‰n j‰rkev‰‰ aikaseks
									  //Leap year ja Space age k‰ytt‰‰ toistaseks..
{
	if (std::cin.good())
	{
		funct(a);
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << '\n';
	}
	Help::ClearStream();
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

	void test(int seconds)
	{
		std::cout << "You are Earths years: " << SecondsToYears(seconds) << std::endl;
		std::cout << "You are Mercury years: " << SecondsToYears(seconds) / 0.2408467 << std::endl;
		std::cout << "You are Venus years: " << SecondsToYears(seconds) / 0.61519726 << std::endl;
		std::cout << "You are Mars years: " << SecondsToYears(seconds) / 1.8808158 << std::endl;
		std::cout << "You are Jupiter years: " << SecondsToYears(seconds) / 11.862615 << std::endl;
		std::cout << "You are Saturn years: " << SecondsToYears(seconds) / 29.447498 << std::endl;
		std::cout << "You are Uranus years: " << SecondsToYears(seconds) / 84.016846 << std::endl;
		std::cout << "You are Neptune years: " << SecondsToYears(seconds) / 164.79132 << std::endl;
	}

	void Process()
	{
		int seconds;
		std::cout << "How old are you in seconds?" << std::endl;
		std::cin >> seconds;
		fpoint(test, seconds);
	
	}
}


namespace InputRev
{
	std::string Reverse(std::string input)
	{
		std::string output;

		for (int i = (int)input.size() - 1; i >= 0; i--)
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

		Help::ClearStream();

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

	void test(int year)
	{
		bool LeapYear = IsLeapYear(year);
		if (LeapYear)
		{
			std::cout << "Is a Leap Year\n" << std::endl;
		}
		else
		{
			std::cout << "Not a Leap Year\n" << std::endl;
		}
	}

	void Procces()
	{
		int year;
		std::cout << "Enter Year" << std::endl;
		std::cin >> year;

		fpoint(test, year);

		/*if (std::cin.good())
		{
			bool LeapYear = IsLeapYear(year);
			if (LeapYear)
			{
				std::cout << "Is a Leap Year\n" << std::endl;
			}
			else
			{
				std::cout << "Not a Leap Year\n" << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}*/
		//ClearStream();
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
		std::cout << "Raindrop corresponding:  " << FactorCac(num) << std::endl;
		Help::ClearStream();
	}
}

namespace Pangram  //rangill‰ paremmaks?
{
	bool PangramCheck(std::string& input) //kikkailua ja testailua voi tehd‰ lyhyemminki...
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
		Help::ClearStream();
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
			Help::ClearStream();
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
		Help::ClearStream();
	}
}

namespace DnaStuff		//this section contains multiple assignments
{
	bool CheckSeq(std::string Seq)
	{
		return std::all_of(Seq.begin(), Seq.end(), [](char s) { return s == 'C' ||
			s == 'A' || s == 'G' || s == 'T'; });
	}
	void DnaToRna()
	{
		std::string Seq;
		std::cout << "Enter Dna Sequence \nNote: Use Letters: C, A, G, T \n" << std::endl;
		std::cout << "Input Sequence: ";
		std::cin >> Seq;

		std::transform(Seq.begin(), Seq.end(), Seq.begin(), ::toupper);
	
		bool goodS1 = CheckSeq(Seq) && CheckSeq(Seq);

		if (goodS1 == true)
		{
			for (auto i = 0; i < Seq.size(); i++)
			{
				if (Seq[i] == 'A')
				{
					Seq[i] = 'U';
				}
				else if (Seq[i] == 'C')
				{
					Seq[i] = 'G';
				}
				else if (Seq[i] == 'G')
				{
					Seq[i] = 'C';
				}
				else if (Seq[i] == 'T')
				{
					Seq[i] = 'A';
				}
			}
			std::cout << "Rna sequence is: " << Seq << std::endl;
			std::cout << '\n';
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
	void NucleotideCount()
	{
		int adenine = 0;
		int cytosine = 0;
		int guanine = 0;
		int thymine = 0;
		std::string Seq;
		std::cout << "Enter Dna Sequence \nNote: Use Letters: C, A, G, T \n" << std::endl;
		std::cout << "Input Sequence: ";
		std::cin >> Seq;
		
		std::transform(Seq.begin(), Seq.end(), Seq.begin(), ::toupper);

		bool goodS1 = CheckSeq(Seq);

		if (goodS1 == true)
		{
			for (auto i = 0; i < Seq.size(); i++)
			{
				if (Seq[i] == 'A')
				{
					adenine += 1;
				}
				else if (Seq[i] == 'C')
				{
					cytosine += 1;
				}
				else if (Seq[i] == 'G')
				{
					guanine += 1;
				}
				else if (Seq[i] == 'T')
				{
					thymine += 1;
				}
			}
			std::cout << "Dna sequence has following number of Nucleotides: \n " << std::endl;
			std::cout << "Adenine: " << adenine << "\n" << std::endl;
			std::cout << "Cytosine: " << cytosine << "\n" << std::endl;
			std::cout << "Guanine: " << guanine << "\n" << std::endl;
			std::cout << "Thymine: " << thymine << "\n" << std::endl;
			std::cout << '\n';
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}

	void DnaComp()
	{
		int discount = 0;
		std::string firstSeq;
		std::string secondSeq;
		std::cout << "Enter 2 Dna Strands \nNote: Need to be same lenght and using Letters: c, a, g, t \n" << std::endl;
		std::cout << "First Sequence: ";
		std::cin >> firstSeq;
		std::cout << "Second Sequence: ";
		std::cin >> secondSeq;
		std::transform(firstSeq.begin(), firstSeq.end(), firstSeq.begin(), ::toupper);
		std::transform(secondSeq.begin(), secondSeq.end(), secondSeq.begin(), ::toupper);

		bool goodS1 = CheckSeq(firstSeq) && CheckSeq(secondSeq) &&
			firstSeq.size() == secondSeq.size();

		if (goodS1 == true)
		{
			for (auto i = 0; i < firstSeq.size(); i++)
			{
				if (firstSeq[i] != secondSeq[i])
				{
					discount += 1;
				}
			}
			std::cout << "Hamming dist is: " << discount << std::endl;
			std::cout << '\n';
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}

	std::vector<std::string> InputParser(const std::string input)
	{
		std::vector<std::string> output;

		for (int i = 0; i < int(input.size()); i += 3)
		{
			output.push_back(input.substr(i, 3));
		}
		return output;
	}

	std::vector<std::string> CodoTranslator(std::vector<std::string> input)
	{
		std::vector<std::string> output;
		std::map<std::string, std::string> Proteins = { {"AUG", "Methionine"}, {"UUU","Phenylalanine"}, {"UUC", "Phenylalanine"},
			{"UUA", "Leucine"}, {"UUG", "Leucine"}, {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
			{"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},{"UGU", "Cysteine"}, {"UGC", "Cysteine"},{"UGG", "Tryptophan"},
			{"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"} };

		for (int i = 0; i < input.size(); i++)
		{
			if (Proteins.find(input[i])->second == "STOP")
			{
				break;
			}
			else
			{
				output.push_back(Proteins.find(input[i])->second);
			}
		}
		return output;
	}

	void ProcessProteinTranslation()
	{
		std::string input;
		std::cout << "Input a Protein Codons: " << std::endl;
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		bool goodinput = std::all_of(input.begin(), input.end(), [](char l) {return l == 'A' || l == 'U' || l == 'G' || l == 'C'; });
		if (std::cin.good() && goodinput)
		{
			std::vector<std::string> codos = InputParser(input);
			std::vector<std::string> out = CodoTranslator(codos);
			Help::PrintVec(out);
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}

	void ProcessMenu()
	{
		int choice;
		do
		{
			std::cout << "0.Back to main menu \n1.Dna comparison \n2.Nucleotide type count \n3.Dna to Rna \n4.Protein Translation" << std::endl;
			std::cin >> choice;
			std::cout << '\n';

			switch (choice)
			{
			case 0:
				break;
			case 1:
				DnaComp();
				break;
			case 2:
				NucleotideCount();
				break;
			case 3:
				DnaToRna();
				break;
			case 4:
				ProcessProteinTranslation();
				break;
			}
		} while (choice != 0);
	}


}

namespace CollatzConjecture
{
	int CallatzAlgo(int n)
	{
		int stepcount = 0;

		while (n != 1)
		{
			if (n % 2 == 0)
			{
				n /= 2;
			}
			else
			{
				n = (n * 3) + 1;
			}
			stepcount++;
		}
		return stepcount;
	}

	void Process()
	{
		int stepcount;
		std::cout << "Input a number: " << std::endl;
		std::cin >> stepcount;
		if (std::cin.good())
		{
			std::cout << "Number of steps is: " << CallatzAlgo(stepcount) << "\n" << std::endl;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
}

namespace NthPrime
{
	int CaculateNprime(int n)
	{
		std::vector<int> prime;
		prime.reserve(50);
		prime.push_back(2);
		prime.push_back(3);
		int maxnum = 10000; //bigger than 100 000 is too slow with this algorithm
		
		for (int i = 5; i <= maxnum; i += 2)
		{
			for (int modder = (i / 2) + 1; modder > 2; modder--)
			{
				if (i % modder != 0)
				{
					if (modder == 3)
					{
						prime.push_back(i);
					}
				}
				else
				{
					break;
				}
			}
		}
		int nthprime = prime[n];
		return nthprime;
	}
	void Process()
	{
		int prime;
		std::cout << "Enter a number" << std::endl;
		std::cin >> prime;
		if (std::cin.good())
		{
			std::cout << "Nth Prime number is: " << CaculateNprime(prime) << "\n" << std::endl;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
 	}

}

namespace QueenAttackTest
{
	class QueenAttack
	{
	public:
		void Process()
		{
			Vei2 WhitePos;
			Vei2 BlackPos;
			char mark;

			std::cout << "Input White Queen position: " << std::endl;
			std::cin >> WhitePos.x >> mark >> WhitePos.y;
			std::cout << "Input Black Queen position: " << std::endl;
			std::cin >> BlackPos.x >> mark >> BlackPos.y;
			if (std::cin.good())
			{
				SolveAttackVec(WhitePos);
				if (CheckAttackVec(BlackPos))
				{
					std::cout << "Attack is possible" << std::endl;
				}
				else
				{
					std::cout << "Attack is NOT possible" << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid input" << std::endl;
				std::cout << '\n';
			}
			Help::ClearStream();
		}
	private:
		bool CheckAttackVec(Vei2& pos) 
		{
			return std::any_of(AttackVec.begin(), AttackVec.end(), [&pos](Vei2& a) {return a == pos; });
		}
		void SolveAttackVec(const Vei2& pos)
		{
			AttackVec.reserve(40);
			for (int i = 0; i < 8; i++)
			{
				AttackVec.emplace_back(i, pos.y);
			}
			for (int i = 0; i < 8; i++)
			{
				AttackVec.emplace_back(pos.x, i);
			}

			for (int x = pos.x, y = pos.y; x < 8 || y < 8; x++, y++)
			{
				AttackVec.emplace_back(x, y);
			}
			for (int x = pos.x, y = pos.y; x == 0 || y == 0; x--, y--)
			{
				AttackVec.emplace_back(x, y);
			}


		}
	private:
		std::vector<Vei2> AttackVec;
	};
}


namespace Gigasecond
{
	void Process()  // solution without external lib, it works but math sucks.. dosent count the diffrence of days in months
	{
		double gigas = std::pow(10, 9);

		double gyears = (((gigas / 60) / 60) / 24) / 365;

		double gmonths = std::modf(gyears, &gyears);
		gmonths *= 12;

		double gdates = std::modf(gmonths, &gmonths);
		gdates *= 30;

		double ghours = std::modf(gdates, &gdates);
		ghours *= 24;

		double gmins = std::modf(ghours, &ghours);
		gmins *= 60;

		double year;
		double month;
		double date;
		double hours;
		double mins;
		std::cout << "Input moment in time: " << std::endl;
		std::cin >> date >> month >> year >> hours >> mins;
		if (std::cin.good())
		{
			year += gyears;
			mins += gmins;
			if (mins > 60)
			{
				hours += 1;
				mins -= 60;
			}
			hours += ghours;
			if (hours > 24)
			{
				date += 1;
				hours -= 24;
			}
			date += gdates;
			int leap = (int)gyears / 4;
			date -= leap;
			if (date > 31)
			{
				month += 1;
				date -= 31;
			}
			else if (date < 0)
			{
				month -= 1;
				date += 31;
			}
			month += gmonths;
			if (month > 12)
			{
				year += 1;
				month -= 12;
			}

			std::cout << "Time is: " << date << "." << month << " " << year << " " << hours << "." << int(mins) << std::endl;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}

	void ProcessBoost()		//This uses boost time lib
	{
		namespace pt = boost::posix_time;
		namespace gr = boost::gregorian;

		int year;
		int month;
		int day;
		int hour;
		int min;

		std::cout << "Input moment in time: " << std::endl;
		std::cin >> day >> month >> year >> hour >> min;
		std::string moment = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " " +
			std::to_string(hour) + ":" + std::to_string(min) + ":" + "00.000";

		int gigasec = (int)std::pow(10, 9);
		std::string test("2000-11-25 16:11:59.000");
		pt::ptime testaus(pt::time_from_string(moment));

		pt::ptime t(pt::second_clock::local_time());

		std::cout << "Time is: " << testaus + pt::seconds(gigasec) << "\n" << std::endl;
		Help::ClearStream();
	}
}

namespace SecretHandshake
{
	std::vector<std::string> CodeDecipher(unsigned int code)
	{
		std::vector<std::string> res;
		if (code & 1)
		{
			res.push_back("Wink, ");
		}
		if (code & 2)
		{
			res.push_back("Double Wink, ");
		}
		if (code & 4)
		{
			res.push_back("Close your eyes, ");
		}
		if (code & 8)
		{
			res.push_back("Jump, ");
		}
		if (code & 16)
		{
			std::reverse(res.begin(), res.end());
		}
		return res;
	}

	void Process()
	{
		
		unsigned int code;
		std::cout << "Input a number: " << std::endl;
		std::cin >> code;

		if (std::cin.good())
		{
			std::vector<std::string> out = CodeDecipher(code);
			Help::PrintVec(out);
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
}

namespace Allergies
{
	std::vector<std::string> CodeDecipher(unsigned int code)
	{
		std::vector<std::string> res;
		if (code & 1)
		{
			res.push_back("Eggs");
		}
		if (code & 2)
		{
			res.push_back("Peanuts");
		}
		if (code & 4)
		{
			res.push_back("Shellfish");
		}
		if (code & 8)
		{
			res.push_back("Strawberries");
		}
		if (code & 16)
		{
			res.push_back("Tomatoes");
		}
		if (code & 32)
		{
			res.push_back("Chocolate");
		}
		if (code & 64)
		{
			res.push_back("Pollen");
		}
		if (code & 128)
		{
			res.push_back("Cats");
		}
		return res;
	}

	void Process()
	{
		std::vector<std::string> Notallergies = { ("Eggs"), ("Peanuts"), ("Shellfish"), ("Strawberries"), ("Tomatoes"), ("Chocolate"),
		("Pollen"), ("Cats")};
		int score;
		std::cout << "Input a Allergia score: " << std::endl;
		std::cin >> score;
		if (std::cin.good())
		{
			std::cout << "Is allergic to: " << std::endl;
			std::vector<std::string> allergies = CodeDecipher(score);
			Help::PrintVec(allergies);
			std::cout << "Is Not allergic to: " << std::endl;
			Help::RemoveMatchElementsVec(Notallergies, allergies);
			
			Help::PrintVec(Notallergies);
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
}

namespace SumOfMultiplies
{
	int CaculateSumOfMultiples(int maxnum, int firstmul, int secondmul)
	{
		std::vector<int> res;
		for (int i = 1; i < maxnum / firstmul + 1; i++)
		{
			if (firstmul * i < maxnum)
			{
				res.push_back(firstmul * i);
			}
			
		}
		for (int i = 1; i < maxnum / secondmul + 1; i++)
		{
			if (secondmul * i < maxnum)
			{
				res.push_back(secondmul * i);
			}
		}
		std::sort(res.begin(), res.end());
		auto it = std::unique(res.begin(), res.end());
		res.resize(std::distance(res.begin(), it));
		int endval = 0;
		endval = std::accumulate(res.begin(), res.end(), endval);
		return endval;
	}

	void Process()
	{
		int maxnum;
		int firstmul;
		int secondmul;
		std::cout << "Input a MaxNum: " << std::endl;
		std::cin >> maxnum;
		std::cout << "Input two multiples:  " << std::endl;
		std::cin >> firstmul >> secondmul;
		if (std::cin.good())
		{
			std::cout << "Sum of all multiples are: " << CaculateSumOfMultiples(maxnum, firstmul, secondmul) << std::endl;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
}

namespace PrimeFactors
{
	std::vector<int> res;
	std::vector<int> PrimeFactorCac(int num, int divider)
	{
		if (num % divider == 0)
		{
			res.push_back(divider);
			num /= divider;
		}
		else
		{
			divider++;
		}
		if (num > 1)
		{
			PrimeFactorCac(num, divider);
		}
		return res;
	}

	void Process()
	{
		int num;
		std::cout << "Input a number: " << std::endl;
		std::cin >> num;
		if (std::cin.good())
		{
			std::vector<int> out = PrimeFactorCac(num, 2);
			std::cout << "Prime Factors are: " << '\n';
			Help::PrintVec(out);
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
}


namespace AtbashCipher
{

	std::string alpha = "abcdefghijklmnopqrstuvwxyz";
	std::string cipher = InputRev::Reverse(alpha);
	std::string Encoder(std::string& in)
	{
		std::string out;
		for (int i = 0; i < (int)in.size(); i++)
		{
			char c = in[i];
			if (c == ' ')
			{
				continue;
			}
			else
			{
				auto s = alpha.find(c);
				char oc = cipher[s];
				out.push_back(oc);
			}
		}
		return out;

	}
	std::string Decoder(std::string& in)
	{
		std::string out;
		for (int i = 0; i < (int)in.size(); i++)
		{
			char c = in[i];
			if (c == ' ')
			{
				continue;
			}
			else
			{
				auto s = cipher.find(c);
				char oc = alpha[s];
				out.push_back(oc);
			}
		}
		return out;
	}


	void Process()
	{
		std::string input;
		int choice;
		do
		{
			std::cout << "0.Back to main menu \n1.Encode \n2.Decode" << std::endl;
			std::cin >> choice;
			std::cout << '\n';

			switch (choice)
			{
			case 0:
				break;
			case 1:
				std::cout << "Input code" << std::endl;
				Help::ClearStream();
				std::getline(std::cin, input);
				std::cout << "Encoded is: " << Encoder(input) << std::endl;
				input.clear();
				break;
			case 2:
				std::cout << "Input code" << std::endl;
				Help::ClearStream();
				std::getline(std::cin, input);
				std::cout << "Decoded is: " << Decoder(input) << std::endl;
				input.clear();
				break;

			}
		} while (choice != 0);
		Help::ClearStream();
	}
}

namespace Trinary
{
	int CaculateTrinaryToDecimal(const std::string& in)
	{
		int result = 0;
		for (int i = 0, e = (int)in.size() - 1; i < (int)in.size(); i++, e--)
		{
			char c = in[i];
			int temp = std::atoi(&c) * (int)std::pow(3, e);
			result += temp;
		}
		return result;
	}
	void Process()
	{
		std::string tenary;
		std::cout << "Input a tenary number: " << std::endl;
		std::cin >> tenary;
		if (std::cin.good())
		{
			std::cout << "Trinary Number in decimal is: " << CaculateTrinaryToDecimal(tenary) << "\n" << std::endl;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
}

namespace BinarySearch
{
	template<typename T>
	auto BinSearch(T l, T r, int val)	//returns an iterator pointing to val, if not found return iterator pointing to end
	{
		auto left = l;
		auto right = r - 1;

		while (l < r)
		{
			T mid = left + std::distance(left, right) / 2;
			if (val == *mid)
			{
				return mid;
			}
			if (val < *mid)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}
		return r;
	}

	template<typename Container>
	auto BinSearch(Container const& cont, int val)	//template wrapper for difrent containers
	{
		return BinSearch(std::begin(cont), std::end(cont), val);
	}

	void Process()
	{
		std::vector<int> test;
		for (int i = 0; i < 100; i++)
		{
			test.push_back(i);
		}
	
		int arr[] = { 1, 7, 12, 15, 17, 22, 25, 27, 35 };
		auto beg = std::begin(arr);
		std::cout << "Input a number" << std::endl;
		int num;
		std::cin >> num;
		std::cout << "Number found at the: " << BinSearch(arr, num) - beg << std::endl;
		Help::ClearStream();
	}
}

namespace Series
{
	std::vector<std::string> GetSubstrings(const std::string& in, int count)
	{
		std::vector<std::string> out;
		for (int b = 0, e = count - 1; e <= (int)in.size(); b++, e++)
		{
			std::string sub = in.substr(b, count);
			if (sub.size() == count)
			{
				out.push_back(sub);
			}
			else
			{
				continue;
			}
		}
		return out;
	}
	void Process()
	{
		std::string ser;
		std::cout << "Input serial: " << std::endl;
		std::cin >> ser;
		if (std::cin.good())
		{
			std::cout << "All of the 3-digits series is: " << std::endl;
			Help::PrintCont(GetSubstrings(ser, 3));
			std::cout << "All of the 4-digits series is: " << std::endl;
			Help::PrintCont(GetSubstrings(ser, 4));
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
}

namespace RomanNumerials
{
	std::string Translate(int input)
	{
		int num = input;
		std::map<int, std::string> roman = { {1,"I"}, {4,"IV"}, {5,"V"}, {9,"IX"}, {10,"X"}, {40,"XL"}, {50,"L"},
			{90,"XC"}, {100,"C"}, {400,"CD"}, {500,"D"}, {900,"CM"}, {1000,"M"} };
		std::string out;
		
		auto it = roman.rbegin();

		for (it; it != roman.rend(); it++)
		{
			while (num >= it->first)
			{
				num -= it->first;
				out += it->second;
			}
		}
		return out;
	}


	void Process()
	{
		int num;
		std::cout << "Input a number: " << std::endl;
		std::cin >> num;
		if (std::cin.good())
		{
			std::cout << "Number in Roman is:" << Translate(num) << std::endl;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
}

namespace Bob
{
	bool IsQuestion(const std::string& str)
	{
		return std::any_of(str.begin(), str.end(), [](const char& c) {return c == '?'; });
	}
	bool IsAllCapital(const std::string& str)
	{
		return std::all_of(str.begin(), str.end(), [](const char& c) {return std::isupper(c) || c == '?'; });
	}
	void Process()
	{
		std::string input;
		std::cout << "Say somenthing" << std::endl;
		std::cin >> input;
		
		if (IsQuestion(input) || IsAllCapital(input))
		{
			if (IsQuestion(input) && !IsAllCapital(input))
			{
				std::cout << "Sure" << std::endl;
			}
			else if (!IsQuestion(input) && IsAllCapital(input))
			{
				std::cout << "Whoa, chill out!" << std::endl;
			}
			else if (IsQuestion(input) && IsAllCapital(input))
			{
				std::cout << "Calm down, I know what I'm doing" << std::endl;
			}
		}
		else if (input == "fuck you")
		{
			std::cout << "Fine. Be that way!" << std::endl;
		}
		else
		{
			std::cout << "Whatever!" << std::endl;
		}
		Help::ClearStream();
	}
}

namespace WordCount
{
	std::unordered_map<std::string, int> CountWords(std::string& in)
	{
		
		rg::transform(in, in.begin(), ::tolower);
		std::unordered_map<std::string, int> map;
		std::string word = " ";
		int count = 1;
		const std::string igword("+([']*)?!:;,.");
		for (auto& i : in)
		{
			if (i == ' ')
			{
				auto t = map.find(word);
				if (t != map.end())
				{
					t->second += 1;
				}
				else
				{
					std::pair<std::string, int> par(word, count);
					map.insert(par);
				}
				word = ' ';
			}
			else if (rg::any_of(igword, [&i](auto& t) {return i == t; }))
			{
				continue;
			}
			else
			{
				word += i;
				if (&i == &in.back())
				{
					std::pair<std::string, int> par(word, count);
					map.insert(par);
				}
			}
		}
		return map;
	}

	void Process()
	{
		std::string input;
		std::cout << "Enter a sentence!" << std::endl;
		Help::ClearStream();
		do
		{
			std::getline(std::cin, input);

		} while (std::cin.get() != '\n');
		std::cout << "Count of words is: " << std::endl;
		Help::PrintAssociativeContainer(CountWords(input));
		Help::ClearStream();
	}
}

namespace CircularBufferTest
{
	void Procces()
	{
		CircularBuffer<std::string> cb(7);
		std::vector<std::string> res;
		int choice;
		do
		{
			std::cout << "0.Back to main menu \n1.Write \n2.Read \n3.Clear \n4.Overwrite \n5.Check Buff \n6.Check Result" << std::endl;
			std::cin >> choice;
			std::cout << '\n';

			switch (choice)
			{
			case 0:
				break;
			case 1:
			{
				std::string input;
				std::cout << "Input number or word: " << std::endl;
				std::cin >> input;
				cb.Write(input);
				break;
			}
			case 2:
			{
				std::string temp = cb.Read();
				res.push_back(temp);
				std::cout << "Readed a val: " << temp << std::endl;
				break;
			}
				
			case 3:
				cb.Clear();
				break;
			case 4:
			{
				std::string input;
				std::cout << "Input number or word:" << std::endl;
				std::cin >> input;
				cb.Overwrite(input);
				break;
			}
			case 5:
			{
				Help::PrintCont(cb.CheckElements());
				break;
			}
			case 6:
				Help::PrintCont(res);
				break;
			}
		} while (choice != 0);
	}
}


namespace CryptoSquare //chaining functions with fpointers and char marks for the practice sake! Yeah not pretty but works!
{
	std::string Normalize(std::string& in)
	{
		std::string temp;
		auto Normalized = in | vi::filter([](char c) {return std::isalpha(c); })
			| vi::transform(::tolower);

		for (auto i : Normalized)
		{
			temp.push_back(i);
		}
		return temp;
	}
	std::string EncodeTest(std::string& in, char mark)
	{
		std::string out;
		std::string temp = Normalize(in);

		int lenght = (int)temp.size();
		int columns = (int)std::sqrt(lenght);
		int rows = columns;
		int size = 0;
		int rc = 0;
		if (mark == 'e' && lenght % columns != 0)
		{
			columns += 1;
			size = lenght + rows;
			rc = rows;
		}
		else if (mark == 'd' && lenght % columns != 0)
		{
			rows += 1;
			size = lenght + columns;
			rc = columns;
		}
		int sizecorrect = (rows * columns) - lenght;
		size += sizecorrect;
		for (int r = 0; r < rc + sizecorrect; r++)
		{
			temp.push_back(' ');
		}
		out.resize(size);
		int i = 0;
		if (mark == 'e')
		{
			for (int x = 0; x < rows; x++)
			{
				for (int y = 0; y < columns; y++)
				{
					int s = y * columns + x;
					out[s] = temp[i];
					i++;
				}
			}
		}
		else if (mark == 'd')
		{
			for (int y = 0; y < columns + 1; y++)
			{
				for (int x = 0; x < rows; x++)
				{
					int s = x * rows + y;
					if (s < lenght)
					{
						out[s] = temp[i];
						i++;
					}
				}
			}
		}

		return out;
	}
	std::string Encode(std::string& in)
	{
		std::string out;
		std::string temp;
		auto Normalized = in | vi::filter([](char c) {return std::isalpha(c); })
			| vi::transform(::tolower);

		for (auto i : Normalized)
		{
			temp.push_back(i);
		}
		int lenght = (int)temp.size();
		int columns = (int)std::sqrt(lenght);
		int rows = columns;
		int size = lenght + rows;
		if (lenght % columns != 0)
		{
			columns += 1;
		}
		out.resize(size);
		int r = 0;
		for (int i = 0, t = 0; i < size; t++)
		{
			for (int c = t; c < lenght; c += columns)
			{
				out[i] = temp[c];
				i++;
				r++;
				if (r == rows)
				{
					out[i] = ' ';
					i++;
					r = 0;
				}
			}
		}

		return out;
	}
	void Process(std::string(*chain)(std::string&, char), std::string& input, char mark)
	{
		std::cout << "Enter a sentence!" << std::endl;
		Help::ClearStream();
		do
		{
			std::getline(std::cin, input);

		} while (std::cin.get() != '\n');
		if (input.size() < 10)
		{
			std::cout << "invalid input" << std::endl;
		}
		else
		{
			if (mark == 'e')
			{
				std::cout << "Encrypted is: " << chain(input, 'e') << std::endl;
			}
			if (mark == 'd')
			{
				std::cout << "Decrypted is: " << chain(input, 'd') << std::endl;
			}
		}
		Help::ClearStream();
	}
	void ProccesMenu()
	{
		int choice;
		
		do
		{
			std::cout << "0.Back to main menu \n1.Encrypt \n2.Decrypt " << std::endl;
			std::cin >> choice;
			std::cout << '\n';
			switch (choice)
			{
			case 0:
				break;
			case 1:
			{
				std::string input;
				Process(EncodeTest, input, 'e');
				break;
			}

			case 2:
			{
				std::string input;
				Process(EncodeTest, input, 'd');
				break;
			}
			}
		} while (choice != 0);
	}

}

namespace LuhnFormula
{
	bool Check(std::string in)
	{
		int res = 0;
		for (auto& s : in)
		{
			if (s == ' ')
			{
				continue;
			}
			else
			{
				int i = s - '0';
				res += i;
			}
		}
		return res % 10 == 0;
	}
	std::string Caculate(std::string in)
	{
		std::string temp;
		for (auto& i : in)
		{
			if (i != ' ')
			{
				temp.push_back(i);
			}
		}
		int num = 0;
		std::string out;
		for (int i = (int)temp.size() - 1, d = 1; i >= 0; i--, d++)
		{
			num = temp[i] - '0';
			if (Help::IsOdd(d))
			{
				num *= 2;
				if (num >= 10)
				{
					num -= 9;
				}
			}
			out.insert(0, std::to_string(num));
		}
		return out;
	}

	void Process()
	{
		
		std::cout << "Input a number: " << std::endl;
		Help::ClearStream();
		std::string input;
		do
		{
			std::getline(std::cin, input);

		} while (std::cin.get() != '\n');
		if (Check(Caculate(input)))
		{
			std::cout << "Is a valid number" << std::endl;
		}
		else
		{
			std::cout << "Not a valid number" << std::endl;
		}
		std::cout << Caculate(input) << std::endl;
		Help::ClearStream();

	}
}

namespace Acronym
{
	std::string ParseAcronym(const std::string& in)
	{
		std::string out;
		out.resize(1);
		out[0] = in[0];
		for (auto i = 0; i < in.size(); i++)
		{
			if (in[i] == ' ' && i < in.size() - 2)
			{
				out.push_back(in[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) + 1]);
			}
		}
		return out;
	}
	void Process()
	{

		std::cout << "Input a phrase: " << std::endl;
		Help::ClearStream();
		std::string input;
		do
		{
			std::getline(std::cin, input);

		} while (std::cin.get() != '\n');

		std::cout << "Acronym is: " << ParseAcronym(input) << std::endl;
		Help::ClearStream();

	}
}

namespace AmstrongNumber
{
	bool IsAmsNum(int num)
	{
		std::string t = std::to_string(num);
		int lenght = (int)t.size();
		int base = 0;
		int result = 0;
		for (auto i : t)
		{
			base = i - '0';
			result += (int)std::pow(base, lenght);
		}
		return num == result;
	}
	void Process()
	{
		int num;
		std::cout << "Input a number: " << std::endl;
		std::cin >> num;
		if (std::cin.good())
		{
			if (IsAmsNum(num))
			{
				std::cout << "Number is an Amstrong number" << std::endl;
				Help::ClearStream();
			}
			else
			{
				std::cout << "Number is Not an Amstrong number " << std::endl;
				Help::ClearStream();
			}
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
		}
		Help::ClearStream();
	}
}

namespace BinToDec
{
	bool ValidBin(const std::string& input)
	{
		return rg::all_of(input, [](char c) {return c == '0' || c == '1'; });
	}
	bool ValidHexa(const std::string& input)
	{
		return rg::all_of(input, [](char c) {return std::isxdigit(c); });
	}
	int BinToDecConverion(const std::string& input)
	{
		
		int pow = (int)input.size() - 1;
		int base = 2;
		int num = 0;
		int result = 0;
		for (auto i : input)
		{
			num = i - '0';
			result += num * (int)std::pow(base, pow);
			pow--;
		}
		return result;
	}
	template<typename T>
	T HexaToDecConverion(std::string& input)
	{
		T pow = (T)input.size() - 1;
		T base = 16;
		T num = 0;
		T result = 0;
		for (auto i : input)
		{
			if (std::isdigit(i))
			{
				num = i - '0';
			}
			else
			{
				num = (i - 'A') + 10;
			}
			result += num * (T)std::pow(base, pow);
			pow--;
		}
		return result;
	}
	void Process(char mark)
	{
		std::string num;
		std::cout << "Input a number: " << std::endl;
		std::cin >> num;
		rg::transform(num, num.begin(), ::toupper);
		if (mark == 'b' && ValidBin(num))
		{
			std::cout << "Binary to Decimal is: " << BinToDecConverion(num) << std::endl;
			Help::ClearStream();
		}
		else if (mark == 'h' && ValidHexa(num))
		{
			std::cout << "Hexadecimal to Decimal is: " << HexaToDecConverion<int>(num) << std::endl;
			Help::ClearStream();
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << '\n';
			Help::ClearStream();
		}
		Help::ClearStream();
	}
}

namespace Isograms
{
	bool IsIsograms(const std::string& in)
	{
		bool isogram = true;
		for (int i = 0; i < (int)in.size(); i++)
		{
			if (std::count(in.begin() + i, in.end(), in[i]) == 1)
			{
				isogram = true;
			}
			else
			{
				isogram = false;
				break;
			}
		}
		return isogram;
	}
	void Process()
	{
		std::string input;
		std::cout << "Enter a phrase" << std::endl;
		std::cin >> input;
		Help::ClearStream();
		if (IsIsograms(input))
		{
			std::cout << "Phrase is an Isogram!" << std::endl;
			Help::ClearStream();
		}
		else
		{
			std::cout << "Phrase is NOT an Isogram!" << std::endl;
			Help::ClearStream();
		}
		Help::ClearStream();
	}
}

int rng()
{
	FrameTimer ft;
	Clock clock;
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	double time = (double)clock.GetTime();

	std::thread::id t_thread = std::this_thread::get_id();
	std::stringstream ttt;
	ttt << t_thread;
	unsigned long long int id = std::stoull(ttt.str());

	time /= 100;
	time = std::modf(time, &time);
	time *= 100;
	unsigned long long int s = (unsigned long long int)time;

	unsigned long long int i = ft.GetNano();
	std::string temp = std::to_string(i);
	char c = temp.back();
	int lastnano = c - '0';

	std::stringstream mem;
	mem << &arr[lastnano];
	std::string memtemp;
	mem >> memtemp;
	std::string memout = memtemp.substr(8, std::string::npos);
	unsigned long long int memval = BinToDec::HexaToDecConverion<unsigned long long int>(memout);

	s += i;
	s -= id;
	s -= memval;
	s %= 100;
	int r = (int)s;
	return r;
}
void testi()
{

	Rng r1;
	std::vector<float> tt;
	std::vector<int> ttt;
	auto min = 0.0f;
	auto max = 10.0f;
	auto range = max - min;
	auto mid = range / 2 + min;
	auto lou = range / 10;
	auto meu = lou * 2;
	auto hie = range / 3;
	Bencher b;
	b.Start();
	std::cout << r1.CreateString(2000, true) << std::endl;
	for (int s = 0; s < 100; s++)
	{
		tt.push_back(r1.CreateFloat(min, max, true));
	}
	rg::sort(tt);
	int l = 0;
	int m = 0;
	int h = 0;
	auto loww = tt | vi::filter([&](auto num) {return num <= min + lou || num >= max - lou; });
	auto med = tt | vi::filter([&](auto num) {return (num > min + lou && num < mid - meu) || (num > mid + meu && num < max - lou); });
	auto high = tt | vi::filter([&](auto num) {return num >= mid - meu && num <= mid + meu; });
	for (auto& i : loww)
	{
		l++;
	}
	for (auto& i : med)
	{
		m++;
	}
	for (auto& i : high)
	{
		h++;
	}
	std::cout << '\n';
	std::cout << "Lows: " << l << std::endl;
	std::cout << "Meds: " << m << std::endl;
	std::cout << "Highs: " << h << std::endl;


	if (b.End())
	{
		std::wofstream out(L"Ben.txt");
		out << std::wstring(b);
	}
	Help::PrintCont(tt);
	/*Help::PrintCont(ttt);*/
	Help::ClearStream();
	Help::ClearStream();
}



int main()
{
	FrameTimer ft;
	Database db;
	ChessGrains c;
	RobotFactory r;
	Clock clock;
	QueenAttackTest::QueenAttack q;
	Say s;
	
	int choice;
	do
	{
		
		std::cout << "Anna komento     Teht‰v‰t on sivulta: https://exercism.org/tracks/cpp/exercises \n\n0.Exit\n1.Leap Year caculator\n2.String reverse\n3.Seconds to Year\n" << std::endl;
		std::cout << "4.ChessGrain \n5.RainDrop \n6.Pangram \n7.TwoFer \n8.Grade School \n" << std::endl;
		std::cout << "9.Dna stuff \n10.CollatzConjecture \n11.Nth Prime number \n12.Queen Attack \n" << std::endl;
		std::cout << "13.NumToWords \n14.Gigaseconds \n15.Secret Handshake \n16.Allergies \n" << std::endl;
		std::cout << "17.SumOfMulti \n18.Prime Factors \n19.RobotFactory \n20.Clock \n" << std::endl;
		std::cout << "21.AtbashCipher \n22.Trinary \n23.BinaryTest \n24.Serial \n " << std::endl;
		std::cout << "25.Roman Numerials \n26.Bob \n27.Word Counter \n28.Circular Buff \n" << std::endl;
		std::cout << "29.CryptoSquare \n30.LunhFormula \n31.AcronymMaker \n32.Amstrong Number \n" << std::endl;
		std::cout << "33.BinToDecimal \n34.HexaToDecimal \n35.Isogram \n36.Test \n" << std::endl;
		
		std::cin >> choice;
		std::cout << '\n';

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
		case 8:
			db.Process();
			break;
		case 9:
			DnaStuff::ProcessMenu();
			break;
		case 10:
			CollatzConjecture::Process();
			break;
		case 11:
			NthPrime::Process();
			break;
		case 12:
			q.Process();
			break;
		case 13:
			s.Procces();
			break;
		case 14:
			Gigasecond::ProcessBoost();
			break;
		case 15:
			SecretHandshake::Process();
			break;
		case 16:
			Allergies::Process();
			break;
		case 17:
			SumOfMultiplies::Process();
			break;
		case 18:
			PrimeFactors::Process();
			break;
		case 19:
			r.Process();
			break;
		case 20:
			clock.ProccesMenu();
			break;
		case 21:
			AtbashCipher::Process();
			break;
		case 22:
			Trinary::Process();
			break;
		case 23:
			BinarySearch::Process();
			break;
		case 24:
			Series::Process();
			break;
		case 25:
			RomanNumerials::Process();
			break;
		case 26:
			Bob::Process();
			break;
		case 27:
			WordCount::Process();
			break;
		case 28:
			CircularBufferTest::Procces();
			break;
		case 29:
			CryptoSquare::ProccesMenu();
			break;
		case 30:
			LuhnFormula::Process();
			break;
		case 31:
			Acronym::Process();
			break;
		case 32:
			AmstrongNumber::Process();
			break;
		case 33:
			BinToDec::Process('b');
			break;
		case 34:
			BinToDec::Process('h');
			break;
		case 35:
			Isograms::Process();
			break;
		case 36:
			testi();
			break;
		}


	} while (choice != 0);

	return 0;
}