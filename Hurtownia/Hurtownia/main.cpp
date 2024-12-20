#include <iostream>
#include "logowanie.h"
#include "magazyn.h"
#include "Towar.h"
#include <cstdlib>

int main() {
	int choise; //wybór
	ap::Magazyn m;
	ap::Logowanie l;
	m.wczyt_z_pliku();
	while (true) {
		std::cout << "Menu\n";
		std::cout << "1. Wprowadzic dostawe (wprowadzic juz isniejace id) lub zmienic ilosc towaru (podajac istniejace id towaru)\n";
		std::cout << "2. Zmienic cene\n";
		std::cout << "3. Zlozyc zamowienie\n";
		std::cout << "4. Wyjscie z programu\n";
		std::cout << "Prosze wybrac opcje\n";

		std::cin >> choise;

switch (choise) {
		case 1:	
			std::cout << "\nTeraz mozna dodac towar. Dzialaj szefie!\n ";
			l.sprawdzenia_hasla();
			m.dodaj_towar();
			break;
		case 2:
			l.sprawdzenia_hasla();
			m.zmiana_ceny();
			break;
		case 3:
			m.wyswietlanie();
			m.zlozenie_zamowienia();
			std::cin.ignore();
			getchar();		
			break;
		case 4:
			return 0;
		default:
			std::cout << "Prosze nauczyc sie dobrze klepac po klawiaturze!!!";
		}
		m.wpis_do_pliku();
		system("cls");
	}
}