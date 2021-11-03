
#include "ChessGrains.h"
#include "Database.h"
#include "SayNumbers.h"
#include "RobotFactory.h"
#include "Clock.h"
#include "HelperFunc.h"
#include <iterator>


void fpoint(void(*funct)(int), int a) //fuctio pointer harjoitteluu, tutki my�hemmin saako t�ll� mit��n j�rkev�� aikaseks
									  //Leap year ja Space age k�ytt�� toistaseks..
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
		std::cout << "Raindrop bullshit corresponding:  " << FactorCac(num) << std::endl;
		Help::ClearStream();
	}
}

namespace Pangram  //rangill� paremmaks?
{
	bool PangramCheck(std::string& input) //kikkailua ja testailua voi tehd� lyhyemminki...
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

namespace DnaStuff
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
	template<typename Container, typename T>
	int BinSearch(Container cont, T val)
	{
		auto l = std::begin(cont);
		auto r = std::end(cont);
		auto size = std::distance(l, r);

		int index = -1;
		
		while (l <= r)
		{
			auto mid = l + (r - l) / 2;
			if (*mid == val)
			{
				index = *mid;
				break;
			}
			if (*mid < val)
			{
				*l = *mid + 1;
			}
			if (*mid > val)
			{
				*r = *mid - 1;
			}
		}
		return index;
	}
	void Process()
	{
		std::vector<int> test;
		for (int i = 0; i < 100; i++)
		{
			test.push_back(i);
		}
		std::cout << "Input a number" << std::endl;
		int num;
		std::cin >> num;
		std::cout << "Number found at the: " << BinSearch(test, num) << std::endl;
		Help::ClearStream();
	}
}


int main()
{
	Database db;
	ChessGrains c;
	RobotFactory r;
	Clock clock;
	QueenAttackTest::QueenAttack q;
	Say s;
	int choice;
	do
	{
		std::cout << "Anna komento\n \n0.Exit \n1.Leap Year caculator\n2.String reverse\n3.Seconds to Year\n" << std::endl;
		std::cout << "4.ChessGrain \n5.RainDrop \n6.Pangram \n7.TwoFer \n8.Grade School \n" << std::endl;
		std::cout << "9.Dna stuff \n10.CollatzConjecture \n11.Nth Prime number \n12.Queen Attack \n" << std::endl;
		std::cout << "13.NumToWords \n14.Gigaseconds \n15.Secret Handshake \n16.Allergies \n" << std::endl;
		std::cout << "17.SumOfMulti \n18.Prime Factors \n19.RobotFactory \n20.Clock \n" << std::endl;
		std::cout << "21.AtbashCipher \n22.Trinary \n23.BinaryTest " << std::endl;
		
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

		}


	} while (choice != 0);

	return 0;
}