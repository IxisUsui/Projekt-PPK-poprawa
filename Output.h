#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "NextPt.h"
#include "PreviousPkt.h"

std::vector<int> findPrevious(int current, std::map<int, PreviousPkt> previousOne, int start);
void writeData(std::map<int, PreviousPkt> previousOne, int start,bool isExisting);
