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
			outF.write(reinterpret_cast<char*>(&temp), sizeof(temp));
			evenCount++;
		}

		if (temp % 2 != 0 && oddCount < number / 2)
		{
			outF.write(reinterpret_cast<char*>(&temp), sizeof(temp));
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
	int amount = 0;
	
	outFile.open("file.bin", std::ios::binary);
	if (!outFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	std::cout << "Enter the file size(it must be number, that is completely divisible by 4.): ";
	std::cin >> amount;

	if (amount % 4 != 0)
	{
		std::cout << "You entered incorrect number.";
		return 0;
	}

	FillFile(outFile, amount);	//заполнение файла
	outFile.close();

	inFile.open("file.bin", std::ios::binary);		//связывание потоковой переменной вывода с исходным файлом
	if (!inFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	outFile.open("even.bin", std::ios::binary);		//связывание потоковой переменной ввода с файлом, в котором будут хранится четные числа
	if (!outFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	outFile1.open("odd.bin", std::ios::binary);		//связывание потоковой переменной ввода с файлом, в котором будут хранится нечетные числа
	if (!outFile1)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	int temp = 0;
	std::cout << "Origin file" << std::endl;

	while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))			//вывод исходного файла и заполнение файлов с четными и нечетными числами
	{
		std::cout << temp << " ";

		if (temp % 2 == 0)
			outFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		else
			outFile1.write(reinterpret_cast<char*>(&temp), sizeof(temp));
	}
	
	inFile.close();
	outFile.close();
	outFile1.close();

	inFile.open("even.bin", std::ios::binary);	//создание потоковой переменной для считывания файла с четными числами
	if (!inFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	inFile1.open("odd.bin", std::ios::binary);	//создание потоковой переменной для считывания файла с нечетными числами
	if (!inFile1)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	outFile.open("result.bin", std::ios::binary);
	if (!outFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	
	while (!inFile.eof())
	{
		//вводим 2 четных числа
		inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		outFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		outFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		//вводим 2 нечетных числа
		inFile1.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		outFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		inFile1.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		outFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
	}

	outFile.close();	//закрытие потока ввода в результирующий файл
	inFile.close();
	inFile1.close();


	inFile.open("result.bin", std::ios::binary);
	if (!inFile)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	std::cout << "\nResult file" << std::endl;
	for (int i = 0; i < amount; i++)
	{
		inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		std::cout << temp << " ";
	}

	inFile.close();
}