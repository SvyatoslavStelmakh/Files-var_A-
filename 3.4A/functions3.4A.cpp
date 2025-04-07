#include "Header3.4A.h"

void FillDatabase(DateStudent* pDatabase, int numberOfStudents)
{
	for (int i = 0; i < numberOfStudents; ++i)
	{
		std::cout << "Enter full name of the student: ";
		std::cin.ignore();
		std::cin.getline(pDatabase[i].full_name, NAME);
	age:
		std::cout << "Enter age: ";
		std::cin >> pDatabase[i].age;
		if (pDatabase[i].age < 17 || pDatabase[i].age > 56)
		{
			std::cout << "incorrect value" << std::endl;
			goto age;
		}
	course:
		std::cout << "Enter course(1-4): ";
		std::cin >> pDatabase[i].course;
		if (pDatabase[i].course < 1 || pDatabase[i].course > 4)
		{
			std::cout << "incorrect value" << std::endl;
			goto course;
		}
	sex:
		std::cout << "Enter sex(m or w): ";
		std::cin >> pDatabase[i].sex;
		if (pDatabase[i].sex != 'm' && pDatabase[i].sex != 'w')
		{
			std::cout << "incorrect value" << std::endl;
			goto sex;
		}
		std::cout << "Enter marks sequentially(0-10): ";
		for (int j = 0; j < 6; ++j)
		{
		grade:
			std::cin >> pDatabase[i].grade[j];
			if (pDatabase[i].grade[j] < 0 || pDatabase[i].grade[j] > 10)
			{
				std::cout << "incorrect value" << std::endl;
				goto grade;
			}
		}
		std::cin.ignore();
	}
}

void FillFile(std::ofstream& outFile, DateStudent* pDatabase, int numberOfStudents)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		outFile << pDatabase[i].full_name << "\n";
		outFile << pDatabase[i].age << "\n";
		outFile << pDatabase[i].course << "\n";
		outFile << pDatabase[i].sex << "\n";
		for (int j = 0; j < 6; j++)
		{
			outFile << pDatabase[i].grade[j] << "\n";
		}
		
	}
}

void FindUnderachievingStudents(std::ifstream& inFile, int targetCourse, int numberOfStudents)
{
	/*char fullName[NAME];
	int age;
	int course;
	char sex;
	double grade[6];*/
	int numberOfUnderachievers = 0;
	DateStudent currentStudent;
	
	for (int i = 0; i < numberOfStudents; i++)
	{
		inFile.getline(currentStudent.full_name, NAME);
		inFile >> currentStudent.age;
		inFile >> currentStudent.course;
		inFile >> currentStudent.sex;
		for (int j = 0; j < 6; j++)
		{
			inFile >> currentStudent.grade[j];
			
		}
		
		if (currentStudent.course == targetCourse)
		{
			for (int i = 0; i < 6; i++)
			{
				if (currentStudent.grade[i] < 4)
				{
					numberOfUnderachievers++;
					if(numberOfUnderachievers == 1)
						std::cout << "Underachieving students: " << std::endl;
					std::cout << currentStudent.full_name << std::endl;
					break;
				}
			}
		}
	}

	std::cout << "The number of underachieving students: " << numberOfUnderachievers;
}