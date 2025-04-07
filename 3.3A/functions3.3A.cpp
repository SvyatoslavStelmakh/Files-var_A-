#include "Header3.3A.h"

void FillDatabase(DateStudent& currentStudent)
{
	std::cout << "Enter full name of the student: ";
	std::cin.ignore();
	std::cin.getline(currentStudent.full_name, NAME);
age:
	std::cout << "Enter age: ";
	std::cin >> currentStudent.age;
	if (currentStudent.age < 17 || currentStudent.age > 56)
	{
		std::cout << "incorrect value" << std::endl;
		goto age;
	}
course:
	std::cout << "Enter course(1-4): ";
	std::cin >> currentStudent.course;
	if (currentStudent.course < 1 || currentStudent.course > 4)
	{
		std::cout << "incorrect value" << std::endl;
		goto course;
	}
sex:
	std::cout << "Enter sex(m or w): ";
	std::cin >> currentStudent.sex;
	if (currentStudent.sex != 'm' && currentStudent.sex != 'w')
	{
		std::cout << "incorrect value" << std::endl;
		goto sex;
	}
	std::cout << "Enter marks sequentially(0-10): ";
	for (int j = 0; j < 6; ++j)
	{
	grade:
			std::cin >> currentStudent.grade[j];
			if (currentStudent.grade[j] < 0 || currentStudent.grade[j] > 10)
			{
				std::cout << "incorrect value" << std::endl;
				goto grade;
			}
	}
	std::cin.ignore();
	
}

void FillFile(std::ofstream& outFile, DateStudent& currentStudent)
{
	outFile.write(reinterpret_cast<char*>(&currentStudent.full_name), sizeof(currentStudent.full_name));
	outFile.write(reinterpret_cast<char*>(&currentStudent.age), sizeof(short));
	outFile.write(reinterpret_cast<char*>(&currentStudent.course), sizeof(short));
	outFile.write(reinterpret_cast<char*>(&currentStudent.sex), sizeof(char));
	for (int i = 0; i < 6; i++)
	{
		outFile.write(reinterpret_cast<char*>(&currentStudent.grade[i]), sizeof(double));
	}
	
}

bool ReadFile(std::ifstream& inFile, DateStudent& student) 
{
	if (!inFile.read(reinterpret_cast<char*>(&student.full_name), sizeof(student.full_name)))
		std::cout << "Error reading the structure field" << std::endl;
		return false;
	if(!inFile.read(reinterpret_cast<char*>(&student.age), sizeof(short)))
		std::cout << "Error reading the structure field" << std::endl;
		return false;
	if(!inFile.read(reinterpret_cast<char*>(&student.course), sizeof(short)))
		std::cout << "Error reading the structure field" << std::endl;
		return false;
	if(!inFile.read(reinterpret_cast<char*>(&student.sex), sizeof(char)))
		std::cout << "Error reading the structure field" << std::endl;
		return false;
	
	for (int i = 0; i < 6; i++)
	{
		if (!inFile.read(reinterpret_cast<char*>(&student.grade[i]), sizeof(double)))
			std::cout << "Error reading the structure field" << std::endl;
			return false;
	}
	
	return true;
}

void FindUnderachievingStudents(std::ifstream& inFile, int course)
{
	int numberOfUnderachievers = 0;
	DateStudent student;

	std::cout << "Underachieving students" << std::endl;
	while (ReadFile(inFile, student))
	{
		if (student.course == course)
		{
			for (int i = 0; i < 6; i++)
			{
				if (student.grade[i] < 4)
				{
					std::cout << student.full_name << std::endl;
					numberOfUnderachievers++;
					break;
				}
			}
		}
	}

	std::cout << "The number of underachieving students: " << numberOfUnderachievers;
}