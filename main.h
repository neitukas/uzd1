#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <limits>
#include <random>
#include <chrono>
#include <list>

using namespace std;

struct Studentai{
    string pavarde;
    string vardas;
    vector<int> pazymiai_nd;
    int pazymys_egzaminas;
    double balas_vidurkis;
    double balas_mediana;
};

void Skaitymas_ranka(Studentai);
void Skaitymas_generavimas(Studentai);
void Skaitymas_failo(Studentai);
void Rusiavimas(Studentai);
void Vidurkiai(Studentai);
void Mediana(Studentai);
void Rasymas(Studentai);
void Testavimas(Studentai, string, Studentai, Studentai);

void GeneruotiFailus(int, int, string);
void Skirstymas(Studentai);

void Skirstymas_1(Studentai, Studentai, Studentai);
