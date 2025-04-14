#include "Header3.4A.h"

int main()
{
	int numberOfStudents;
	DateStudent student;

	std::cout << "Enter number of students: ";
	std::cin >> numberOfStudents;

	std::ofstream outFile;
	std::ifstream inFile;

	std::remove("Database.txt");	//удаляем файл перед заполнением, если он существует
	outFile.open("Database.txt", std::ios::app);
	if (!outFile)
	{
		std::cout << "Error opening the file for writing";
		return 0;
	}

	for (int i = 0; i < numberOfStudents; i++)	//заполняем файл структурными переменными с информацией о студентах
	{
		FillDatabase(student);
		FillFile(outFile, student);
	}

	outFile.close();

	inFile.open("Database.txt");
	if (!inFile)
	{
		std::cout << "Error opening the file for reading" << std::endl;
		return 0;
	}

	inFile.seekg(0, std::ios::beg);		// перемещаем указатель чтения в начало
	std::cout << "Database of students" << std::endl;
	PrintDatabase(inFile, numberOfStudents);
	inFile.close();

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
	inFile.seekg(0, std::ios::beg);		// перемещаем указатель чтения в начало
	if (!inFile)
	{
		std::cout << "Error opening the file for reading" << std::endl;
		return 0;
	}
	
	FindUnderachievingStudents(inFile, course, numberOfStudents);
	
	inFile.close();

}