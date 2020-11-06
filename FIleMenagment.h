#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "NextPt.h"
#include "PreviousPkt.h"
#include "Output.h"
#include "OperationOfDijkstra.h"

std::map<int, std::vector<NextPt>> inputGraf(std::string fileWithGraph);
std::vector<int> inputStartPkt(std::string fileWithStarts, std::map<int, std::vector<NextPt>> neighbors);
void outputDijkstra(std::map<int, std::vector<NextPt>>neighbors, std::vector<int> startingPkt,  std::map<int, std::map<int, double>> matrix, std::string outputFile);