#include "Matrix.h"


std::map<int, std::map<int, double>> mapToMatrix (std::map<int,std::vector<NextPt>>neighbors)
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