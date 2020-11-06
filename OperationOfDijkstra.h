#pragma once
#include <map>
#include <vector>
#include "NextPt.h"
#include "PreviousPkt.h"
#include "Dijkstra.h"
#include "Output.h"

int findMin(std::map<int, PreviousPkt> previousOne);
bool isExistingPkt(std::map<int, std::vector<NextPt>> neighbors, int start);
void operationOfDijkstra(std::string fileWithGraph, std::string fileWithStarts, bool useFile, std::string outputFile);