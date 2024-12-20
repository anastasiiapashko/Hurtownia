#include "magazyn.h" //"" -> oznacza: szukaj podanej biblioteki w folderze z projektem
#include "Towar.h"
#include <iostream>
#include <fstream> //biblioteka do korzystania z plików tekstowych
#include <cstdlib> //pozwala na korzystanie z funkcji exit
#include <string> 
#include <limits>
#include <sstream>
#include <stdio.h>
#include <iomanip>
#include <conio.h>// pozwala na odczytanie pojedynczego znaku z klawiatury bez potrzeby naciśnięcia klawisza Enter
void ap::Magazyn::wczyt_z_pliku() {
	std::ifstream Wodczyt("magazyn.txt");
	std::string rodzaj;
	std::string wiersz;
	std::string identyfikator;
	std::string nazwa;
	std::string producent;
	std::string model;
	std::string wymiary;
	std::string kolor;
	double waga;
	int ilosc;
	double cena;
	std::string dodatek;
	int moc;
	std::string smiec;
	while (!Wodczyt.eof()) 
	{
		std::getline(Wodczyt, wiersz);
		std::stringstream ss(wiersz);
		
		ss >> rodzaj;
		if (rodzaj == "urzadzenie") 
			{
			ss>> identyfikator >> nazwa >> producent >> model >> wymiary >> kolor >> waga >> moc >> dodatek >> smiec >> smiec >> ilosc>>cena;
			//na podstawie argumentów powyżej jest swtworzony obiekt klasy urzadzenia i wkladany do wektora
			//tworzymy obiekt Urzadzenia za pomoca new, ktory jest anonimowym; Urzadzenia() to jest konstruktor parametryczny
			//new zwroci adres na stercie naszego obiektu Urzadzenia
			all_towar.push_back(std::unique_ptr<Towar>(new ap::Urzadzenia(identyfikator, nazwa, producent, model, wymiary, kolor, waga, ilosc, cena, moc, dodatek)));
			}
		else if(rodzaj == "meble")
		{
			ss >> identyfikator >> nazwa >> producent >> model >> wymiary >> kolor >> waga >> smiec >> smiec >> dodatek >> smiec >> ilosc >> cena;
			all_towar.push_back(std::unique_ptr<Towar>(new ap::Meble(identyfikator, nazwa, producent, model, wymiary, kolor, waga, ilosc, cena, dodatek)));
		}
		else if (rodzaj == "akcesoria")
		{
			ss >> identyfikator >> nazwa >> producent >> model >> wymiary >> kolor >> waga >> smiec >> smiec >> smiec >> dodatek >> ilosc >> cena;
			all_towar.push_back(std::unique_ptr<Towar>(new ap::Akcesoria(identyfikator, nazwa, producent, model, wymiary, kolor, waga, ilosc, cena, dodatek)));
		}
		else {
			ss >> smiec >> smiec >> smiec >> smiec >> smiec >> smiec >> smiec >> smiec >> smiec >> smiec >> smiec >> smiec >> smiec;
		}
	}
	Wodczyt.close();

}

void ap::Magazyn::wyswietlanie() {
	for (int i = 0; i < all_towar.size(); i++) {
		std::cout << all_towar[i]->wypisz();
	}
	
}
void ap::Magazyn::dodaj_towar(){
	std::string rodzaj;
	std::string identyfikator;
	std::string nazwa;
	std::string producent;
	std::string model;
	std::string wymiary;
	std::string kolor;
	double waga;
	int ilosc;
	double cena;
	std::string dodatek;
	int moc;
	char t_n = 'N';
	int index_id;
	
	
	while (t_n == 'N') {

		std::cout << "\nIdentyfikator:";
		std::cin >> identyfikator;
			if ((index_id = istnienie_id(identyfikator))>=0){
				std::cout << "Wprowadz ilosc nowego towaru: ";
				std::cin >> ilosc;
				all_towar[index_id]->add_ilosc(ilosc);
			}
			else {
				std::cout << "Rodzaj:";
				std::cin >> rodzaj;
				while (rodzaj != "urzadzenie" && rodzaj != "meble" && rodzaj != "akcesoria") {
					std::cout << "Prosze szefa sprawdzic swoja ortografie ;)\nI napisac prawidlowy rodzaj:" << std::endl;
					std::cin >> rodzaj;
				}
				std::cout << "\nNazwa:";
				std::cin >> nazwa;
				std::cout << "\nProducent:";
				std::cin >> producent;
				std::cout << "\nModel:";
				std::cin >> model;
				std::cin.ignore();
				std::cout << "\nWymiary(cm)(np.10x5x2):";
				std::getline(std::cin, wymiary);
				std::cout << "\nKolor:";
				std::cin >> kolor;
				//sprawdzenie poprawnosci wprowadzonych danych
				while(true) {
					std::cout << "\nWaga(kg):";
					if (std::cin >> waga) {
						break;
					}
					std::cout << "\nWprowadzono nie koreknie dane. Prosze jeszcze raz:\n";
					// Wyczyść błąd wejścia i zignoruj nieprawidłowe znaki
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				} 
				while (true) {
					std::cout << "\nIlosc(sz):";
					if (std::cin >> ilosc) {
						break;
					}
					std::cout << "\nWprowadzono nie koreknie dane. Prosze jeszcze raz:\n";
					// Wyczyść błąd wejścia i zignoruj nieprawidłowe znaki
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				while (true) {
					std::cout << "\nCena(zl):";
					if (std::cin >> cena) {
						break;
					}
					std::cout << "\nWprowadzono nie koreknie dane. Prosze jeszcze raz:\n";
					// Wyczyść błąd wejścia i zignoruj nieprawidłowe znaki
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

				if (rodzaj == "urzadzenie") {
					std::cout << "\nMoc(W):";
					std::cin >> moc;
					std::cout << "\nKlasa_energetyczna:";
					std::cin >> dodatek;
					all_towar.push_back(std::unique_ptr<Towar>(new ap::Urzadzenia(identyfikator, nazwa, producent, model, wymiary, kolor, waga, ilosc, cena, moc, dodatek)));
				}
				else if (rodzaj == "meble") {
					std::cout << "\nMaterial:";
					std::cin >> dodatek;
					all_towar.push_back(std::unique_ptr<Towar>(new ap::Meble(identyfikator, nazwa, producent, model, wymiary, kolor, waga, ilosc, cena, dodatek)));
				}
				else if (rodzaj == "akcesoria") {
					std::cout << "\nKruchosc:";
					std::cin >> dodatek;
					all_towar.push_back(std::unique_ptr<Towar>(new ap::Akcesoria(identyfikator, nazwa, producent, model, wymiary, kolor, waga, ilosc, cena, dodatek)));
				}
			}
		std::cout << "Juz skonczyles wpisywac?[T/N]\n";
		std::cin >> t_n;

	}
}

void ap::Magazyn::wpis_do_pliku() {

	std::ofstream zapis("magazyn.txt");
	if (zapis.is_open()) {
		for (int i = 0; i < all_towar.size(); i++) {
			zapis << all_towar[i]->wypisz();
		}
	}
	else {
		std::cout << "Nie udało się otworzyć pliku." << std::endl;
	}
	zapis.close();
}
int ap::Magazyn::istnienie_id(std::string id_podane) {
	int i = 0;
	while (i < all_towar.size()) {
		if (id_podane == all_towar[i]->get_id()) {
			return i;
		}
		i++;
	}
	return -1;
}
void ap::Magazyn::zmiana_ceny() {
	int nowa_cena;
	std::string id;
	int index_id;
	while (true) {										//petla nieskonczona
		std::cout << "Prosze podac id towaru cene, ktorego szef chce zmienic:";
		std::cin >> id;

		if ((index_id = istnienie_id(id)) >= 0) {
			std::cout << "Wprowadz nowa cene: ";
			std::cin >> nowa_cena;
			all_towar[index_id]->set_cena(nowa_cena);
			break;
		}
	}
}
void ap::Magazyn::zlozenie_zamowienia() {
	std::cout << "Prosze wprowadzic id towaru, co Panstwo se zyczy kupic\n";
	std::string id;
	int id_istniejace;
	int ile;
	bool dalej = true;
	char t_n = 'T';
	double cena_ogolna=0;
	while (dalej) {
		std::cin >> id;
		if ((id_istniejace = istnienie_id(id)) >= 0) {
			std::cout << "Prosze wpwadzic ilosc wybranego towatu: ";
			std::cin >> ile;
			if (ile > all_towar[id_istniejace]->wuluskiwanie_ilosci()) {
				std::cout << "Wprowadzona nadmiarowa ilosc towaru.\n Prosze na nowo wprowadzić id: ";
				continue;
			}
			else if (ile <= 0) {
				std::cout << "Prosze Pana, co Pan robi?\n Wprowadzona ujemna ilosc towaru";
				continue;
			}
			else {
				zamowienia.push_back(std::unique_ptr<ap::dane_do_rachunku>(all_towar[id_istniejace]->wpis_do_zamowienia(ile)));
				cena_ogolna += zamowienia.back()->cena;
			}
			//warunek konca
			std::cout << "Czy skladamy zamowienie dalej? [T/N]";
			std::cin >> t_n;
			if (t_n == 'T') {
				continue;
			}
			else {
				dalej = false;
			}
		}
		else
			std::cout << "Zle id\nProsze wprowadzic id towaru, co Panstwo se zyczy kupic\n";
	}
	std::ofstream zapis("zamowienie.txt", std::ios::app | std::ios::out);//tryb dopisywania
	if (zapis.is_open()) {
		std::cout << "O to twoje zamowienie\n";
		for (int i = 0; i < zamowienia.size(); i++) {
			std::cout<< "id: "<<zamowienia[i]->wypisz();
			zapis << zamowienia[i]->wypisz();
		}
		std::cout << "Suma twego zamowienia: ";
		std::cout << cena_ogolna;
		zapis << "Suma twego zamowienia: " << cena_ogolna<<"\n";
		zapis.close();
	}
	else {
		std::cout << "Nie udało się otworzyć pliku." << std::endl;
	}
	//to tu bedzie metoda do dekrementacji ilosci towaru//petla przelatuje wektor 
	for (const std::unique_ptr<ap::dane_do_rachunku>& dane : zamowienia) {
		//przez dane(wskaznik) -> wuluskujemy id z dane_do_rachunku, co zawieraja id z klasy Towar
		id_istniejace = istnienie_id(dane->id);
		all_towar[id_istniejace]->add_ilosc(-dane->ilosc);
	}
}