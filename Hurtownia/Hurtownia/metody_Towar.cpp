#include "magazyn.h" //"" -> oznacza: szukaj podanej biblioteki w folderze z projektem
#include <iostream>
#include "Towar.h"
#include <fstream> //biblioteka do korzystania z plików tekstowych
#include <cstdlib> //pozwala na korzystanie z funkcji exit
#include <string> 
#include <sstream>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
std::string ap::Urzadzenia::get_id() {
	return identyfikator;
}
void ap::Urzadzenia::add_ilosc(int nowa_ilosc) {
	ilosc += nowa_ilosc;
}
void ap::Urzadzenia::set_cena(int nowa_cena) {
	cena = nowa_cena;
}
ap::dane_do_rachunku* ap::Urzadzenia::wpis_do_zamowienia(int i) {//do wektora zamowienia
	while (i > ilosc) {
		std::cout << "Wprowadz nalezna ilosc towaru: ";
		std::cin >> i;
	}
	dane_do_rachunku* dane = new dane_do_rachunku(identyfikator, nazwa, i, cena);//obiekt z deklaracja jego atrybutow
	return dane;
}
int ap::Urzadzenia::wuluskiwanie_ilosci() {
	return ilosc;
}
//metody dla Mebli
std::string ap::Meble::get_id() {
	return identyfikator;
}
void ap::Meble::add_ilosc(int nowa_ilosc) {
	ilosc += nowa_ilosc;
}
void ap::Meble::set_cena(int nowa_cena) {
	cena = nowa_cena;
}
//zwracane bedzie wskaznik o typie dane_do_rachunku, wrzucane na stercie
ap::dane_do_rachunku* ap::Meble::wpis_do_zamowienia(int i) {

	dane_do_rachunku* dane = new dane_do_rachunku(identyfikator,nazwa,i, i * cena);//obiekt z deklaracja jego atrybutow
	return dane;
}
int ap::Meble::wuluskiwanie_ilosci() {
	return ilosc;
}
//metody dla Akcesoria
std::string ap::Akcesoria::get_id() {
	return identyfikator;
}
void ap::Akcesoria::add_ilosc(int nowa_ilosc) {
	ilosc += nowa_ilosc;
}
void ap::Akcesoria::set_cena(int nowa_cena) {
	cena = nowa_cena;
}
ap::dane_do_rachunku* ap::Akcesoria::wpis_do_zamowienia(int i) {
	dane_do_rachunku* dane = new dane_do_rachunku(identyfikator,nazwa, i, cena);//obiekt z deklaracja jego atrybutow
	return dane;
}
int ap::Akcesoria::wuluskiwanie_ilosci() {
	return ilosc;
}

//metoda do struktury
std::string ap::dane_do_rachunku::wypisz() {
	std::stringstream ss;
	ss << id << " " <<nazwa<<" " << ilosc << " " << cena << "\n";
	return ss.str();
}