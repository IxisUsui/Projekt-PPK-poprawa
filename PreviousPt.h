#pragma once
/*!
Struktura odpowiedzialna za przechowanie danych poprzedników wraz z informacja czy zosta³ ju¿ wykorzystany w algorytmie.
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