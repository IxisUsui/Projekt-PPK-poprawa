#pragma once
/*! \file FileManagment.h*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "NextPt.h"
#include "PreviousPt.h"
#include "OperationOfDijkstra.h"
/*!
Funkcja wczytujaca z pliku graf Dijsktry.
@param fileWithGraph Nazwa pliku, z ktorego zostaje pobrany graf
@return std::map<int, std::vector<NextPt>> Mapa punktow wraz z ich vektorem nastepnikow i odleglosciami dla danego nastepnika, przechowywane w strukturze NextPt
*/
std::map<int, std::vector<NextPt>> inputGraf(std::string fileWithGraph);
/*!
Funkcja wczytujaca z pliku liste punktow startowych oraz tworzaca dla ich w mapie neighbors punkt z brakiem nastepnika i zerowa odlegloscia.
@param fileWithStarts Nazwa pliku, z ktorego zostaje pobrana lista (wektor) punktow
@param neighbors Mapa przechowujaca wektor struktor, czyli nastepnikow danego punktu, zaznaczonego jako id danej mapy (wpisywany do niej zostaje punkt startowy jako punkt z zerowa odlegloscia).
@return std::vector<int> wektor punktow startowych
*/
std::vector<int> inputStartPkt(std::string fileWithStarts, std::map<int, std::vector<NextPt>> neighbors);
/*!
Funkcja szukajaca poprzednikow dla danego punktu i tworzaca z nich wektor aby mozna bylo odczytac poprzednikow (funkcja uzywana w wypisywaniu danych do pliku).
@param current aktualnie rozpatrywany punkt podawany jako wstaznik na id mapy previousOne
@param previousOne Mapa przechowujaca poprzednikow,odleglosc oraz bool czy dany puntk zostal uzyty dla danego punktu.
@param start Punkt startowy, ktory jest aktualnie rozpatrywany, podawany jako wartosc danego wektora.
@return std::vector<int> wektor posiadajacy poprzednikow danego punktu
*/
std::vector<int> findPrevious(int current, std::map<int, PreviousPt> previousOne, int start);
/*!
Funkcja wypisujaca dane do pliku wyjsciowego.
@param neighbors Mapa przechowujaca wektor struktor, czyli nastepnikow danego punktu, zaznaczonego jako id danej mapy
@param startingPt Punkt startowy, ktory jest aktualnie rozpatrywany
@param previousOne Mapa przechowujaca poprzednikow,odleglosc oraz bool czy dany puntk zostal uzyty dla danego punktu
@param outputFile Nazwa pliku wyjsciowego
*/
void outputDijkstra(std::map<int, std::vector<NextPt>>neighbors, int startingPt, std::map<int, PreviousPt> previousOne, std::string outputFile);