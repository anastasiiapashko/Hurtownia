#include "magazyn.h" //"" -> oznacza: szukaj podanej biblioteki w folderze z projektem
#include <iostream>
#include "logowanie.h"
#include "Towar.h"
#include <fstream> //biblioteka do korzystania z plików tekstowych
#include <cstdlib> //pozwala na korzystanie z funkcji exit
#include <string> 
#include <sstream>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
void ap::Logowanie::sprawdzenia_hasla() {
	std::string prawidlowe_haslo = "wolna";
	std::string wprowadzone_haslo;
	char c;
	bool haslo_poprawne = false;

	while (!haslo_poprawne) {
		std::cout << "Podaj haslo: ";

		while ((c = _getch()) != '\r') { // Czekaj na naciśnięcie klawisza Enter
			if (c == '\b') { // Jeśli wciśnięto Backspace, usuń ostatni wprowadzony znak
				if (!wprowadzone_haslo.empty()) {
					std::cout << "\b \b"; // Usuń znak z konsoli
					wprowadzone_haslo.pop_back(); // Usuń znak z ciągu znaków
				}
			}
			else {
				std::cout << "*";
				wprowadzone_haslo += c; // Dodaj wprowadzony znak do ciągu znaków
			}
		}

		std::cout << std::endl;

		if (wprowadzone_haslo == prawidlowe_haslo) {
			std::cout << "Haslo poprawne!" << std::endl;
			haslo_poprawne = true;
		}
		else {
			std::cout << "Haslo niepoprawne!" << std::endl;
			wprowadzone_haslo.clear(); // Wyczyść wprowadzone hasło
		}
	}

}