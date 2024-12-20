#pragma once
#include <iostream>
#include "Towar.h"
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <memory>//do inteligentnego wskaznika
namespace ap {
	class Magazyn {
		//wektor wskaznikow do polimorfizmu
		std::vector<std::unique_ptr<Towar>> all_towar;
		std::vector<std::unique_ptr<dane_do_rachunku>> zamowienia;
	public:
		void wczyt_z_pliku();
		void wyswietlanie();
		void dodaj_towar();
		void wpis_do_pliku();
		int istnienie_id(std::string id_podane);
		void zmiana_ceny();
		void zlozenie_zamowienia();
	};
}