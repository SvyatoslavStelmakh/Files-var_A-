#include <fstream> 
#include <iostream> 
#include <ctime>

void FillFile(std::ofstream& outF, int number)
{
	srand(time(NULL));

	int temp = 0, evenCount = 0, oddCount = 0;
	
	while (evenCount < number / 2 || oddCount < number / 2)
	{
		temp = rand() % 21 - 10;
		
		if (temp % 2 == 0 && evenCount < number / 2 && temp != 0)
		{
			outF << temp << " ";
			evenCount++;
		}
			
		if (temp % 2 != 0 && oddCount < number / 2)
		{
			outF << temp << " ";
			oddCount++;
		}
			
	}
}

int main()
{
	std::ofstream outFile;		//создание потоковой переменной для заполнения файла
	std::ofstream outFile1;
	std::ifstream inFile;		//создание потоковой переменной для вывода файла
	std::ifstream inFile1;		
	int amount;

	outFile.open("file.txt");		//связывание потоковой переменной ввода с файлом
	if (!outFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	std::cout << "Enter the file size(it must be an even number.): ";
	std::cin >> amount;

	if (amount % 4 != 0)
	{
		std::cout << "You entered incorrect number.";
		return 0;
	}

	FillFile(outFile, amount);	//заполнение файла

	outFile.close();		//закрытие потока ввода

	inFile.open("file.txt");		//связывание потоковой переменной вывода с исходным файлом
	if (!inFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	outFile.open("even.txt");		//связывание потоковой переменной ввода с файлом, в котором будут хранится четные числа
	if (!outFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	outFile1.open("odd.txt");		//связывание потоковой переменной ввода с файлом, в котором будут хранится нечетные числа
	if (!outFile1)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	
	int temp = 0;
	std::cout << "Origin file" << std::endl;
	for (int i = 0; i < amount; i++)			//вывод исходного файла и заполнение файлов с четными и нечетными числами
	{
		inFile >> temp;
		std::cout << temp << " ";
		if (temp % 2 == 0)
			outFile << temp << " ";
		else
			outFile1 << temp << " ";
	}

	outFile.close();	//закрытие потока ввода в файл с чётными числами
	outFile1.close();	//закрытие потока ввода в файл с нечётными числами
	inFile.close();		//закрытие потока считывания исходного файла

	inFile.open("even.txt");	//создание потоковой переменной для считывания файла с четными числами
	if (!inFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	inFile1.open("odd.txt");	//создание потоковой переменной для считывания файла с нечетными числами
	if (!inFile1)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	outFile.open("result.txt");
	if (!outFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	while (inFile >> temp || inFile1 >> temp)
	{
		//вводим 2 четных числа
		outFile << temp << " ";
		inFile >> temp;
		outFile << temp << " ";
		//вводим 2 нечетных числа
		inFile1 >> temp;
		outFile << temp << " ";
		inFile1 >> temp;
		outFile << temp << " ";
	}
	
	outFile.close();	//закрытие потока ввода в результирующий файл
	inFile.close();
	inFile1.close();

	inFile.open("result.txt");
	if (!inFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	std::cout << "\nResult file" << std::endl;
	for (int i = 0; i < amount; i++)
	{
		inFile >> temp;
		std::cout << temp << " ";
	}
	
	inFile.close();
}