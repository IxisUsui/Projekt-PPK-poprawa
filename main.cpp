#include <iostream>
#include <fstream>
#include <string>
#include "OperationOfDijkstra.h"
#include "CommandLineManagament.h"

int main(int argc, char **argv)
{
	Files files;
	if (argc == 1 or (std::string(argv[1]) == "-h" and argc == 2))
	{
		showHelp();
	}
	if (argc == 7)
	{
		files = getFiles(argc, argv);
		if (!files.areFilesCorrect)
		{
			std::cout << "Bledne argumenty funckji, -h pomoc" << std::endl;
			return 1;
		}
	}
	else 
	{
		std::cout << "za mało argumentow programu";
		return 1;
	}

	std::cout << "Dane maja wyswietlic sie w pliku(1) czy konsoli(2) - (wpisz 1 lub 2)"<<std::endl;
	int answer;
	std::cin >> answer;
	bool useFile;
	if (answer == 1){
		useFile = true; 
	}
	else if(answer ==2){

		useFile = false; 
	}
	else
	{
		std::cout << "podano zla dane" << std::endl;
		return 1;
	}
	
	operationOfDijkstra(files.fileWithGraph, files.fileWithStarts, useFile, files.outputFile);
	
	getchar(); getchar();
	return 0;
}