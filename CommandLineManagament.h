#pragma once
#include <string>
#include <iostream>
struct Files
{
	std::string fileWithGraph;
	std::string fileWithStarts;
	std::string outputFile;
	bool areFilesCorrect;
};

void showHelp();
Files getFiles(int argc, char** argv);
