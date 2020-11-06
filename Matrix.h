#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "NextPt.h"
#include "PreviousPkt.h"
#include "FIleMenagment.h"
std::map<int, std::map<int, double>> mapToMatrix(std::map<int, std::vector<NextPt>>neighbors);