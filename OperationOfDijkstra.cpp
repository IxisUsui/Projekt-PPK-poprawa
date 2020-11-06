#include "OperationOfDijkstra.h"


int findMin(std::map<int, PreviousPkt> previousOne) //zwraca id mapy
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

bool isExistingPkt(std::map<int, std::vector<NextPt>> neighbors, int start)
{
	for (const auto& neighbor : neighbors)
	{
		if (neighbor.first == start)
		{
			return true;
		}
	}
	return false;
}


void operationOfDijkstra(std::string fileWithGraph, std::string fileWithStarts, bool useFile, std::string outputFile)
{
	// inicjacja zbiorow, zmiennych

	std::map<int, std::vector<NextPt>> neighbors = inputGraf(fileWithGraph); // mapa z lista nastepnikow dla danego punktu
	std::map<int, PreviousPkt> previousOne; // mapa gdzie juz beda rozwiazania po sznurku;
	std::vector <int> startingPkt = inputStartPkt(fileWithStarts, neighbors); // lista punktow startowych
	std::map<int, std::map<int, double>> matrix = mapToMatrix(neighbors);
	bool isExisting;
	if (!useFile)
	{
		for (unsigned int i = 0; i < startingPkt.size(); i++)
		{

			isExisting = isExistingPkt(neighbors, startingPkt[i]);
			previousOne = dijkstra(neighbors, startingPkt[i], matrix);
			writeData(previousOne, startingPkt[i], isExisting);
		}

	}
	else
	{
		outputDijkstra(neighbors, startingPkt, matrix, outputFile);

	}

	return;
}
