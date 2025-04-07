#pragma once
#include <fstream>
#include <iostream>

const int NAME = 100;

#pragma pack(push, 1)
struct DateStudent
{
	char full_name[NAME];
	short age = 17;
	short course = 1;
	char sex = 'm';
	double grade[6]{ 0 };		//массив с средними баллами за 6 предметов;
};
#pragma pack(pop)

void FillDatabase(DateStudent& currentStudent);
void FillFile(std::ofstream& outFile, DateStudent& currentStudent);
void FindUnderachievingStudents(std::ifstream& inFile, int course);
