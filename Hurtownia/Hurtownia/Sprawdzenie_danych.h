#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdio.h>
//#include <memory>//do inteligentnego wskaznika
//namespace ap {
//    class Sprawdzenie_danych{
//    public:
//        Sprawdzenie_danych& operator()() noexcept {
//            Sprawdzenie_danych dane(*this);
//
//            while (true) {
//                std::cout << "\Waga: ";
//
//                if (std::cin >> dane) {
//                    break;  // Jeśli wprowadzono poprawną liczbę, opuść pętlę
//                }
//
//                std::cout << "Blad! Wprowadzono niepoprawna wartosc" << std::endl;
//
//                // Wyczyść błąd wejścia i zignoruj nieprawidłowe znaki
//                std::cin.clear();
//                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            }
//
//            return dane;
//        }
//    };
//
//}