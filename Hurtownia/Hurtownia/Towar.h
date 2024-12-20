#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <memory>//do inteligentnego wskaznika
namespace ap {
	struct dane_do_rachunku {
		std::string id;
		std::string nazwa;
		int ilosc;
		int cena;

		std::string wypisz();
		dane_do_rachunku(const std::string ident,const std::string nazwa_, const int ile, const int wartosc)
			: nazwa(nazwa_),ilosc(ile), cena(wartosc) {
			id = ident;
		}
	};

	class Towar {
	protected:  //dla klas zewnetrznych prywatne atrybuty, a dla dziedziczacych publiczne
		std::string identyfikator;
		std::string nazwa;
		std::string producent;
		std::string model;
		std::string wymiary;
		std::string kolor;
		double waga;
		int ilosc;
		int cena;

	public:
		Towar(const std::string id, const std::string nazw, const std::string prodc, const std::string model_, const std::string wymiar_,
			const std::string kolor_, const double waga_, const int ilosc_, const int cena_) :
			identyfikator(id), nazwa(nazw), producent(prodc), model(model_), wymiary(wymiar_), kolor(kolor_), waga(waga_), ilosc(ilosc_), cena(cena_) {

		}
		//stworzenie metody wirtualne do polimorfizmu, nie wyłowane, bo z tego nie robią się obiekty
		virtual std::string wypisz() = 0;
		virtual std::string get_id() = 0;//pobranie id
		virtual void add_ilosc(int ilosc) = 0;//ustawienie ilosci 
		virtual void set_cena(int cena) = 0;//zmiana ceny
		virtual dane_do_rachunku* wpis_do_zamowienia(int i) = 0;
		virtual int wuluskiwanie_ilosci() = 0;
	};

	class Urzadzenia : public Towar {//klasa dziedziczy publicznie i daje mozliwosc rozszerzyc
		int moc;
		std::string klasa_energetyczna;
		//konstruktor dziedziczący konstruktor klasy Towar
	public:
		Urzadzenia(const std::string id, const std::string nazw, const std::string prodc, const std::string model_, const std::string wymiar_,
			const std::string kolor_, const double waga_, const int ilosc_, const int cena_, const int moc_, const std::string klasa_energ)
			: Towar(id, nazw, prodc, model_, wymiar_, kolor_, waga_, ilosc_, cena_), moc(moc_), klasa_energetyczna(klasa_energ) {
		}
		std::string wypisz() {
			std::stringstream ss;
			ss << std::fixed << "urzadzenie\t" << identyfikator << "\t" << nazwa << std::setw(5) << "\t" << producent << "\t\t" << model <<
				"\t\t" << wymiary << "\t" << kolor << "\t" << std::setprecision(3) << waga <<"\t" << moc << "\t" << klasa_energetyczna << "\t"<<" - "<<"\t"<<" - " << "\t"<< ilosc << "\t" << cena << "\n";
			std::string s = ss.str();
			return s;
		}
		std::string get_id();
		void add_ilosc(int nowa_ilosc);
		void set_cena(int nowa_cena);
		dane_do_rachunku* wpis_do_zamowienia(int i);
		int wuluskiwanie_ilosci();
	};

	class Meble : public Towar {//klasa dziedziczy publicznie i daje mozliwosc rozszerzyc
		std::string material;
	public:
		Meble(const std::string id, const std::string nazw, const std::string prodc, const std::string model_, const std::string wymiar_,
			const std::string kolor_, const double waga_, const int ilosc_, const int cena_, const std::string material_)
			: Towar(id, nazw, prodc, model_, wymiar_, kolor_, waga_, ilosc_, cena_), material(material_) {

		}
		std::string wypisz() {
			std::stringstream ss;
			ss << std::fixed << "meble" << std::setw(13) << identyfikator << "\t" << nazwa << std::setw(5) << "\t" << producent << "\t\t" << model <<
				"\t\t" << wymiary << "\t" << kolor << "\t" << std::setprecision(3) << waga << "\t" << " - " << "\t" << " - "<< "\t" << material << "\t" << " - " << "\t" <<ilosc <<
				"\t" << cena << "\n";
			std::string s = ss.str();
			return s;
		}
		std::string get_id();
		void add_ilosc(int nowa_ilosc);
		void set_cena(int nowa_cena);
		dane_do_rachunku* wpis_do_zamowienia(int i);
		int wuluskiwanie_ilosci();
	};

	class Akcesoria : public Towar {//klasa dziedziczy publicznie i daje mozliwosc rozszerzyc
		std::string kruchosc;
	public:
		Akcesoria(const std::string id, const std::string nazw, const std::string prodc, const std::string model_, const std::string wymiar_,
			const std::string kolor_, const double waga_, const int ilosc_, const int cena_, const std::string kruchosc_)
			: Towar(id, nazw, prodc, model_, wymiar_, kolor_, waga_, ilosc_, cena_), kruchosc(kruchosc_) {

		}
		std::string wypisz() {
			std::stringstream ss;
			ss << std::fixed << "akcesoria\t" << identyfikator << "\t" << nazwa << std::setw(5) << "\t" << producent << "\t\t" << model <<
				"\t\t" << wymiary << "\t" << kolor << "\t" << std::setprecision(3) << waga << "\t" << " - " << "\t" << " - " <<"\t"<<" - "<<"\t" << kruchosc << "\t" << ilosc <<
				"\t" << cena << "\n";
			std::string s = ss.str();
			return s;
		}
		std::string get_id();
		void add_ilosc(int nowa_ilosc);
		void set_cena(int nowa_cena);
		dane_do_rachunku* wpis_do_zamowienia(int i);
		int wuluskiwanie_ilosci();
	};
}