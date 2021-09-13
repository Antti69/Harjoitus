#include "Database.h"

void Database::Add()
{
	int grade;
	std::string name;
	std::cout << "Input a grade" << std::endl;
	std::cin >> grade;
	std::cout << "Input a name" << std::endl;
	std::cin >> name;
	std::cout << '\n';

	entries.emplace_back(Entry(grade, name));
}

void Database::Load()
{
	std::ofstream in("data.txt");

	for (auto& i : entries)
	{
		in >> i
	}

}

void Database::Save()
{
	std::ofstream out("data.txt");
	
	for (auto& i : entries)
	{
		out << i.grade << '.' << i.name << '\n';
	}

}

void Database::Process()
{
	int choice;
	do
	{
		std::cout << "0.Back to main menu \n1.Select grade to print \n2.Print all of the students\n3.Add Student" << std::endl;
		std::cout << "4.Save Roster \n5.Load Roster" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			PrintGrade();
			break;
		case 2:
			PrintAllStudents();
			break;
		case 3:
			Add();
			break;
		case 4:
			Save();
			break;
		case 5:
			Load();
			break;
		}
	} while (choice != 0);
}

void Database::PrintGrade() const
{
	int grade;
	std::cout << "Input grade" << std::endl;
	std::cin >> grade;
	std::cout << "Students are \n" << std::endl;

	for (auto& i : entries)
	{
		if (i.grade == grade)
		{
			std::cout << i.name << std::endl;
		}
	}
	std::cout << '\n';
}

void Database::PrintAllStudents()
{
	if (entries.size() != 0)
	{
		std::sort(entries.begin(), entries.end(), [](const Entry& l, const Entry& r)
		{
			return (l.grade < r.grade) || l.grade == r.grade && l.name < r.name;
		});

		for (auto& i : entries)
		{
			std::cout << i.grade << '.' << i.name << std::endl;
		}
		std::cout << '\n';
	}
	else
	{
		std::cout << "No students found" << std::endl;
	}

}

Database::Entry::Entry(int grade, std::string name)
	:
	grade(grade),
	name(name)
{
}

void Database::Entry::Deserialize(std::ifstream& in)
{
	in.read(reinterpret_cast<char*> (&grade), sizeof(grade));
	in.read(reinterpret_cast<char*> (&name), sizeof(name));
}

void Database::Entry::Serialize(std::ofstream& out)
{
	out.write(reinterpret_cast<char*> (&grade), sizeof(grade));
	out.write(reinterpret_cast<char*> (&name), sizeof(name));
}
