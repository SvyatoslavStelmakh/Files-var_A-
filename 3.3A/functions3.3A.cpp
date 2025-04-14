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
	
average_mark:
	//std::cout << "Enter marks sequentially(0-10): ";
	std::cout << "Enter average mark: ";
	std::cin >> currentStudent.average_mark;
	if (currentStudent.average_mark < 1 || currentStudent.average_mark > 10)
	{
		std::cout << "incorrect value" << std::endl;
		goto average_mark;
	}
	/*for (int j = 0; j < 6; ++j)
	{
	grade:
			std::cin >> currentStudent.grade[j];
			if (currentStudent.grade[j] < 0 || currentStudent.grade[j] > 10)
			{
				std::cout << "incorrect value" << std::endl;
				goto grade;
			}
	}*/
	std::cin.ignore();
	
}

void FillFile(std::ofstream& outFile, DateStudent& currentStudent)
{
	
	outFile.write(reinterpret_cast<char*>(&currentStudent), sizeof(DateStudent));
	
}

void ReadFile(std::ifstream& inFile, DateStudent& currentStudent, int indexOfStudent) 
{
	int sizeByte = sizeof(DateStudent);
	inFile.seekg((indexOfStudent * sizeByte), std::ios::beg);
	inFile.read(reinterpret_cast<char*>(&currentStudent), sizeof(DateStudent));

}

void FindUnderachievingStudents(std::ifstream& inFile, int setCourse)
{
	int numberOfUnderachievers = 0;
	DateStudent student;

	inFile.seekg(0, std::ios::end);
	auto count = inFile.tellg() / sizeof(DateStudent);

	if ((inFile.tellg() % sizeof(DateStudent) != 0) || count == 0)
	{
		std::cout << "Wrong input file size" << std::endl;
		return;
	}

	inFile.seekg(0, std::ios::beg);

	std::cout << "Underachieving students: " << std::endl;
	for (auto i = 0; i < count; i++)
	{
		ReadFile(inFile, student, i);
		
		if (student.course == setCourse)
		{
			if (student.average_mark < 4)
			{
				std::cout << student.full_name << std::endl;
				numberOfUnderachievers++;
			}
		}
	}

	std::cout << "The number of underachieving students: " << numberOfUnderachievers;
}