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
	class Logowanie {
		std::string prawidlowe_haslo;
		std::string wprowadzone_haslo;
		char c;
		bool haslo_poprawne;
	public:
		Logowanie(const std::string praw_h, const std::string wpr_h, const char c_, const bool hasl_popr) :
			prawidlowe_haslo(praw_h), wprowadzone_haslo(wpr_h), c(c_), haslo_poprawne(hasl_popr) {}
		Logowanie() {}
		//Metoda ta sprawdza poprawność hasła
		void sprawdzenia_hasla();
	};
}
