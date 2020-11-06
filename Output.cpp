#include "Output.h"

std::vector<int> findPrevious(int current, std::map<int, PreviousPkt> previousOne, int start)
{
	std::vector<int> previous;
	while (previousOne[current].previous != start)
	{
		previous.push_back(previousOne[current].previous);
		current = previousOne[current].previous;
	}
	return previous;
}

void writeData(std::map<int, PreviousPkt> previousOne, int start,bool isExisting)
{
	std::vector<int> previousVector;
	if (isExisting)
	{
		std::cout << std::endl << "poszukiwanie najkrotszych drog z punktu: " << start << std::endl;
	}
	else 
	{
		std::cout << std::endl << "poszukiwanie najkrotszych drog z punktu: " << start << std::endl;
		std::cout << "Dany punkt nie istnieje w grafie!" << std::endl;
		return;
	}
	for (auto& previous : previousOne)
	{
		std::cout  <<start << "-> ";
		int tmpI = previous.first;
		std::cout << tmpI;
		if (!previous.second.wasUsed)
		{
			std::cout << "Do tego punktu nie da siê dojœæ";
		}
		else
		{
			if (previous.second.previous == -1)
			{
				std::cout << " wynosi 0 gdyz jest to punkt startowy";
			}
			else
			{
				std::cout << " przez ";
				if (previous.second.previous == start)
				{
					std::cout << previous.second.previous << ", wynosi: " << previous.second.distance;
				}
				else
				{
					previousVector =findPrevious(previous.first, previousOne, start);
					 for (int i = previousVector.size() - 1; i >= 0; i--)
					 {
						 std::cout << previousVector[i];
						 if (previousVector.size() > 1 and i != 0)
						 {
							 std::cout << " i ";
						 }
					 }
					std::cout <<", wynosi: " << previous.second.distance;
				}
			}
				
		}
		std::cout << std::endl;
	}
}
