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
	// записываю каждое поле структуры в файл по отдельности
	/*outFile.write(reinterpret_cast<char*>(&currentStudent.full_name), sizeof(currentStudent.full_name));
	outFile.write(reinterpret_cast<char*>(&currentStudent.age), sizeof(short));
	outFile.write(reinterpret_cast<char*>(&currentStudent.course), sizeof(short));
	outFile.write(reinterpret_cast<char*>(&currentStudent.sex), sizeof(char));
	for (int i = 0; i < 6; i++)
	{
		outFile.write(reinterpret_cast<char*>(&currentStudent.grade[i]), sizeof(double));
	}*/

	outFile.write(reinterpret_cast<char*>(&currentStudent), sizeof(DateStudent));
	
}

void ReadFile(std::ifstream& inFile, DateStudent& currentStudent) 
{
	// считываю каждое поле структуры из файла по отдельности
	/*if (!inFile.read(reinterpret_cast<char*>(&student.full_name), sizeof(student.full_name)))
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
	
	return true;*/

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
		ReadFile(inFile, student);
		
		if (student.course == setCourse)
		{
			if (student.average_mark < 4)
			{
				std::cout << student.full_name << std::endl;
				numberOfUnderachievers++;
			}
			/*for (int j = 0; j < 6; j++)
			{
				if (student.grade[j] < 4)
				{
					std::cout << student.full_name << std::endl;
					numberOfUnderachievers++;
					break;
				}
			}*/
		}
	}

	std::cout << "The number of underachieving students: " << numberOfUnderachievers;
}