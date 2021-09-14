#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>


class Database
{
private:
	class Entry
	{
		friend class Database;
	public:
		Entry(int grade, std::string name);
	private:
		int grade;
		std::string name;
	};
public:
	void Process();
private:
	void Add();
	void Load();
	void Save();
	void PrintGrade() const;
	void PrintAllStudents();

private:
	std::vector<Entry> entries;
};