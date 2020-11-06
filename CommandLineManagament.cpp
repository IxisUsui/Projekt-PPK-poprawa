

#include"CommandLineManagament.h"

void showHelp()
{
	std::cout << "Aby program dzia³a³ nale¿y wpisaæ argumenty: " << std::endl << " -g plik z grafem w postaci: punkt -> punkt nastepny : odleglosc /enter" << std::endl <<
		"-w plik z lista punktow startowych " << std::endl << "-o plik wyjsciowy" << std::endl;
}

Files getFiles(int argc, char** argv)
{
	Files files;
	files.areFilesCorrect = true;
	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]) == "-g")
		{

			files.fileWithGraph = argv[++i];
		}
		else if (std::string(argv[i]) == "-w")
		{
			files.fileWithStarts = argv[++i];
		}
		else if (std::string(argv[i]) == "-o")
		{
			files.outputFile = argv[++i];
		}
		else
		{
			std::cout << "Wpisano b³edne argumenty";
			files.areFilesCorrect = false;
			return files;
		}
	}
	return files;	
}


