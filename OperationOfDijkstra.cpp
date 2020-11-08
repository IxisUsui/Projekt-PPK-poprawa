#include "OperationOfDijkstra.h"

std::map<int, std::map<int, double>> mapToMatrix(std::map<int, std::vector<NextPt>>neighbors)
{
	std::map<int, std::map<int, double>>matrix;
	int n = neighbors.size();
	for (const auto& neighbor : neighbors)
	{
		for (const auto& neighbor1 : neighbors)
		{
			matrix[neighbor.first][neighbor1.first] = 0;
		}
	}
	for (auto& neighbor : neighbors)
	{
		for (unsigned int i = 0; i < neighbor.second.size(); i++)
		{
			matrix[neighbor.first][neighbor.second[i].nextPt] = neighbor.second[i].distance;
		}
	}
	return matrix;
}
int findMin(std::map<int, PreviousPt> previousOne) //zwraca id mapy
{
	double minOdleglosc = INT_MAX;
	int indeks = -1;
	for (const auto& pkt : previousOne)
	{
		if (!pkt.second.wasUsed and pkt.second.distance < minOdleglosc)
		{
			indeks = pkt.first;
			minOdleglosc = pkt.second.distance;
		}
	}
	return indeks;
}




void operationOfDijkstra(std::string fileWithGraph, std::string fileWithStarts,std::string outputFile) // funckja istnieje aby utworzyc zmienne ktore nastepnie sa przekazywane do funkcji, oraz aby moc dla kazdego nowego punktu startowego liczyc od nowa dijkstre oraz wypisywaac ja w kolejnosci;
{
	std::map<int, std::vector<NextPt>> neighbors = inputGraf(fileWithGraph); 
	std::vector <int> startingPt = inputStartPkt(fileWithStarts, neighbors); 
	std::map<int, std::map<int, double>> matrix = mapToMatrix(neighbors);
	remove(outputFile.c_str()); 
	for (unsigned int i = 0; i < startingPt.size(); i++)
	{
			std::map<int, PreviousPt> previousOne = dijkstra(neighbors, startingPt[i], matrix);
			outputDijkstra(neighbors, startingPt[i], previousOne, outputFile);
	}
	return;
}
