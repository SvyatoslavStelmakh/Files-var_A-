#include "Header3.4A.h"

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
	std::cout << "Enter average mark: ";
	std::cin >> currentStudent.average_mark;
	if (currentStudent.average_mark < 0 || currentStudent.average_mark > 10)
	{
		std::cout << "incorrect value" << std::endl;
		goto average_mark;
	}
	std::cin.ignore();
}

void FillFile(std::ofstream& outFile, DateStudent& currentStudent)
{
	outFile.seekp(0, std::ios::end);
	outFile << currentStudent.full_name << "\n";
	outFile << currentStudent.age << "\n";
	outFile << currentStudent.course << "\n";
	outFile << currentStudent.sex << "\n";
	outFile << currentStudent.average_mark << "\n";
	//outFile << "\n";	// записываем в файл символ новой строки после каждого записанного студента
}

void ReadFile(std::ifstream& inFile, DateStudent& currentStudent)
{

	inFile.getline(currentStudent.full_name, NAME);
	inFile >> currentStudent.age;
	inFile >> currentStudent.course;
	inFile >> currentStudent.sex;
	inFile >> currentStudent.average_mark;
}

//void PrintStudentData(DateStudent& currentStudent, int indexOfStudent)
//{
//	std::cout << std::setw(3) << (indexOfStudent + 1)
//			<< std::setw(14) << currentStudent.full_name 
//			<< std::setw(9) << currentStudent.age 
//			<< std::setw(9) << currentStudent.course 
//			<< std::setw(9) << currentStudent.sex 
//			<< std::setw(14) << currentStudent.average_mark << std::endl;
//}

void PrintDatabase(std::ifstream& inFile, int numberOfStudents)
{
	DateStudent currentStudent;
	std::cout << std::setw(3) << "#"
		<< std::setw(14) << "Full Name" 
		<< std::setw(9) << "Age" 
		<< std::setw(9) << "Course" 
		<< std::setw(9) << "Gender" 
		<< std::setw(14) << "Average mark" << std::endl;
	for (int i = 0; i < numberOfStudents; i++)
	{
		ReadFile(inFile, currentStudent);
		std::cout << std::setw(3) << (i + 1)
			<< std::setw(14) << currentStudent.full_name
			<< std::setw(9) << currentStudent.age
			<< std::setw(9) << currentStudent.course
			<< std::setw(9) << currentStudent.sex
			<< std::setw(14) << currentStudent.average_mark << std::endl;
	}
}

void FindUnderachievingStudents(std::ifstream& inFile, int targetCourse, int numberOfStudents)
{
	int numberOfUnderachievers = 0;
	DateStudent currentStudent;

	for (int i = 0; i < numberOfStudents; i++)
	{
		ReadFile(inFile, currentStudent);
		
		if (currentStudent.course == targetCourse)
		{
			if (currentStudent.average_mark < 4)
			{
				numberOfUnderachievers++;
				if (numberOfUnderachievers == 1)
					std::cout << "Underachieving students: " << std::endl;
				std::cout << currentStudent.full_name << std::endl;
			}
		}
	}

	std::cout << "The number of underachieving students: " << numberOfUnderachievers;
}