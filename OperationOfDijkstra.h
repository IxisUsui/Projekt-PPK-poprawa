#pragma once
/*! \file OperationOfDijkstra.h*/
#include <map>
#include <vector>
#include <stdio.h>
#include "NextPt.h"
#include "PreviousPt.h"
#include "Dijkstra.h"
#include "FileManagment.h"
/*! Funckja konwertujaca mape neighbors na macierz, potrzebna w algorytmie dijkstra.
@param neighbors Mapa przechowujaca wektor struktor, czyli nastepnikow danego punktu, ktory jest id danej mapy.
@return map<int, std::map<int,double>> Zwracana zostaje mapa map imitujaca macierz*/
std::map<int, std::map<int, double>> mapToMatrix(std::map<int, std::vector<NextPt>>neighbors);
/*! Funckja szukajaca minimum w mapie previousOne oraz zwracajaca indeks tej mapy.
@param previousOne Mapa przechowujaca poprzednikow,odleglosc oraz bool czy dany puntk zostal uzyty dla danego punktu.
@return int Zwracany jest indeks na mape z najkrotsza trasa*/
int findMin(std::map<int, PreviousPt> previousOne);
/*! Funkcja w ktorej inicjalizowana zostaja zbiory,funkcje i zmienne, oraz wywolana zostaje funkcja algorytmu dijkstry i wypisywania do pliku dla kazdego punktu startowego. 
@param fileWithGraph Nazwa pliku, w ktorym znajduje sie graf
@param fileWithStarts Nazwa pliku, w ktorym znajduje sie lista punktow startowych
@param outputFile Nazwa pliku wyjsciowego, do ktorgo beda wpisywane dane*/
void operationOfDijkstra(std::string fileWithGraph, std::string fileWithStarts,  std::string outputFile);