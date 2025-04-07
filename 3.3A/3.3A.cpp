#include "Header3.3A.h"

int main()
{
	int numberOfStudents;
	DateStudent student;
	
	std::cout << "Enter number of students: ";
	std::cin >> numberOfStudents;
	
	std::ofstream outFile;
	std::ifstream inFile;
	
	std::remove("Database.bin");	//удаляем файл перед заполнением, если он существует
	outFile.open("Database.bin", std::ios::binary | std::ios::app);	// открываем файл, для записи информации о студентах, 
																	// с флагом, который позволяет дописывать данные в конец файла
	if (!outFile)
	{
		std::cout << "Error opening the file for writing" << std::endl;
		return 0;
	}

	for (int i = 0; i < numberOfStudents; i++)	//заполняем файл структурными переменными с инфрмацией о студентах
	{
		FillDatabase(student);
		FillFile(outFile, student);
	}

	outFile.close();

	int course;
course:
	std::cout << "Enter the course where academic performance of students will be checked: ";
	std::cin >> course;
	if (course < 1 || course > 4)
	{
		std::cout << "incorrect value" << std::endl;
		goto course;
	}

	inFile.open("Database.bin", std::ios::binary);
	if (!inFile)
	{
		std::cout << "Error opening the file for reading" << std::endl;
		return 0;
	}

	FindUnderachievingStudents(inFile, course);
	inFile.close();

}