#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>

const int NAME = 100;

struct DateStudent
{
	char full_name[NAME];
	unsigned short age;
	unsigned short course;
	char sex;
	double average_mark = 0;
	//double grade[6];		//массив с средними баллами за 6 предметов;
};

void FillDatabase(DateStudent& currentStudent);
void FillFile(std::ofstream& outFile, DateStudent& currentStudent);
void ReadFile(std::ifstream& inFile, DateStudent& currentStudent);
void PrintStudentData(DateStudent& currentStudent, int indexOfStudent);
void PrintDatabase(std::ifstream& inFile, int numberOfStudents);
void FindUnderachievingStudents(std::ifstream& inFile, int targetCourse, int numberOfStudents);

