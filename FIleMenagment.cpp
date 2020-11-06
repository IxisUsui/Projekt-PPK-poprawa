#include "FileMenagment.h"

//wpisywanie do pliku
std::map<int, std::vector<NextPt>> inputGraf(std::string fileWithGraph)
{
    std::map<int, std::vector<NextPt>> neighbors;
    std::map<int, std::vector<NextPt>> inputGraf(std::string fileWithGraph);
    NextPt next;
    int startPt;
    std::string edge;
    int nextPt;
    double distance;
    char colon;

    std::ifstream file;
    file.open(fileWithGraph);
    if (file.good())
    {

        while (file >> startPt >> edge >> nextPt >> colon >> distance)
        {
            if (edge == "-") //tworzenie punktow o nieskierowanej krawiedzi
            {
                next.nextPt = nextPt;
                next.distance = distance;
                neighbors[startPt].push_back(next);
                next.nextPt = startPt;
                next.distance = distance;
                neighbors[nextPt].push_back(next);
            }
            else //tworzenie pkt o skierowanej krawedzi
            {
            next.nextPt = nextPt;
            next.distance = distance;
            neighbors[startPt].push_back(next);
            }
        }
    }
    else
    {
        std::cout << "otwarcie pliku: ' " << fileWithGraph << " ' nie powiodlo sie" << std::endl;
    }
    file.close();
    return neighbors;
}

std::vector<int> inputStartPkt(std::string fileWithStarts, std::map<int,std::vector<NextPt>> neighbors) 
{
    std::ifstream file;
    file.open(fileWithStarts);
    std::vector<int> startingPkt;
    int point;
    NextPt next;

    if (file.good())
    {
        while (file >> point)
        {
            startingPkt.push_back(point);
            next.nextPt = point;
            next.distance = 0;
            neighbors[point].push_back(next);
        }
    }
    else
    {
        std::cout << "otwarcie pliku: ' " << fileWithStarts << " ' nie powiodlo sie" << std::endl;
    }
    file.close();
    return startingPkt;
}

// wypisywanie do pliku
void outputDijkstra(std::map<int,std::vector<NextPt>>neighbors, std::vector<int> startingPkt, std::map<int, std::map<int, double>> matrix, std::string outputFile)
{
    std::map<int, PreviousPkt> previousOne;
    bool isExisting;
    std::vector<int> previousVector;
    std::ofstream file;
    file.open(outputFile);

    for (int i = 0; i < startingPkt.size(); i++)
    {
        previousOne = dijkstra(neighbors, startingPkt[i], matrix);
        isExisting = isExistingPkt(neighbors, startingPkt[i]);
        if (isExisting)
        {
            file << "poszukiwanie najkrotszych drog z punktu: " << startingPkt[i] << std::endl;

        }
        else
        {
            file << "poszukiwanie najkrotszych drog z punktu: " << startingPkt[i] << std::endl;
            file << "Dany punkt nie istnieje w grafie!" << std::endl;
            return;
        }
        for (auto& previous : previousOne)
        {
            file << startingPkt[i] << "-> ";
            int id = previous.first;
            file << id;
            if (!previous.second.wasUsed)
            {
                file << "Do tego punktu nie da się dojść";
            }
            else
            {
                if (previous.second.previous == -1)
                {
                    file << " wynosi 0 gdyz jest to punkt startowy";
                }
                else
                {
                    file << " przez ";
                    if (previous.second.previous == startingPkt[i])
                    {
                        file << previous.second.previous << ", wynosi: " << previous.second.distance;
                    }
                    else
                    {
                        previousVector = findPrevious(previous.first, previousOne, startingPkt[i]);
                        for (int i = previousVector.size() - 1; i >= 0; i--)
                        {
                            file << previousVector[i];
                            if (previousVector.size() > 1 and i != 0)
                            {
                                file << " i ";
                            }
                        }
                        file << ", wynosi: " << previous.second.distance;
                    }
                }

            }
            file << std::endl;
        }
    }
   
    file.close();
    return;
}

\