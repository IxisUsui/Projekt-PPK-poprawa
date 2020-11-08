/*! \file Dijkstra.h*/
#include <iostream>
#include <vector>
#include <map>
#include "NextPt.h"
#include "PreviousPt.h"
#include "OperationOfDijkstra.h"

/*!
Funkcja odpowiedzialna za algorytm dijkstry
@param neighbors Mapa przechowujaca wektor struktor, czyli nastepnikow danego punktu, ktory jest id danej mapy.
@param start Punkt od ktorego ma zostac liczona najkrotsza droga do innych punktow grafu.
@param matrix Mapa map imitujaca macierz, po ktorej wyszukiwana zostaje najkrotsza droga do punktow
@return map<int,PreciousPt> Mapa w ktorej znajduje sie struktura punktow z najkrotsza droga oraz poprzednikiem danego punktu
*/
std::map<int, PreviousPt>  dijkstra(std::map<int, std::vector<NextPt>> neighbors, int start, std::map<int, std::map<int, double>> matrix);

