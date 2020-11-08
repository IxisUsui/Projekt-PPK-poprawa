#pragma once
/*!
Struktura odpowiedzialna za przechowanie nastepnikow danego punktu oraz ich krawedzi
@param nextPt Punkt nastepny dla danego punktu poczatkowego
@param distance waga krawedzi w grafie od danego punktu do jego nastepnika
*/

struct NextPt
{
	int nextPt;
	double distance;
};