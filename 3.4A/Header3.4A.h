#pragma once
#include <fstream>
#include <iostream>

const int NAME = 100;

struct Subjects
{
	int matanalysis;
	int analytical_geometry;
	int english;
	int electricity;
	int programming;
	int fundamentals_of_law;
};

struct DateStudent
{
	char full_name[NAME];
	unsigned short age;
	unsigned short course;
	char sex;
	double grade[6];		//массив с средними баллами за 6 предметов;
};

void FillDatabase(DateStudent* pDatabase, int numberOfStudents);
void FillFile(std::ofstream& outFile, DateStudent* pDatabase, int numberOfStudents);
void FindUnderachievingStudents(std::ifstream& inFile, int targetCourse, int numberOfStudents);

