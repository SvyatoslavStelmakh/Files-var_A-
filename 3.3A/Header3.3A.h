#pragma once
#include <fstream>
#include <iostream>

const int NAME = 100;

#pragma pack(push, 1)	// push — сохраняет текущие настройки выравнивания в стек
						// 1 — задает новое выравнивание в 1 байт(минимально возможное).
						// то есть все поля структуры будут расположены без промежутков.
						// размер структуры станет равен точной сумме размеров её полей.
struct DateStudent
{
	char full_name[NAME];
	short age = 17;
	short course = 1;
	char sex = 'm';
	double grade[6]{ 0 };		//массив с средними баллами за 6 предметов;
};
#pragma pack(pop)	// pop возвращает настройки, которые были до push

void FillDatabase(DateStudent& currentStudent);
void FillFile(std::ofstream& outFile, DateStudent& currentStudent);
void FindUnderachievingStudents(std::ifstream& inFile, int course);
