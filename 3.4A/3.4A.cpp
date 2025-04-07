#include "Header3.4A.h"

int main()
{
	int numberOfStudents;

	std::cout << "Enter number of students: ";
	std::cin >> numberOfStudents;

	DateStudent* pDatabase = new DateStudent[numberOfStudents];
	FillDatabase(pDatabase, numberOfStudents);

	std::ofstream outFile;
	std::ifstream inFile;

	outFile.open("Database.txt");
	if (!outFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	FillFile(outFile, pDatabase, numberOfStudents);

	outFile.close();

	int course;
	std::cout << "Enter the course where academic performance of students will be checked: ";
	std::cin >> course;
course:
	if (course < 1 || course > 4)
	{
		std::cout << "incorrect value" << std::endl;
		goto course;
	}

	inFile.open("Database.txt");
	if (!inFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	FindUnderachievingStudents(inFile, course, numberOfStudents);
	inFile.close();

	delete[] pDatabase;
}