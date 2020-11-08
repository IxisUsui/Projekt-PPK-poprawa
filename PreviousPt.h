#pragma once
/*!
Struktura odpowiedzialna za przechowanie danych poprzednik�w wraz z informacja czy zosta� ju� wykorzystany w algorytmie.
@param previous Poprzedni punkt dla daego punktu
@param distance Odleglosc drogi jaka przebywa sie do danego punktu
@param wasUsed Bool ktorego wartosc true powiadamia, iz punkt zostal juz uzyty w algorytmie
*/
struct PreviousPt
{
	int previous;
	double distance;
	bool wasUsed;
};