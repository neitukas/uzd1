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

using namespace std;

struct Studentai{
    string pavarde;
    string vardas;
    vector<int> pazymiai_nd;
    int pazymys_egzaminas;
    double balas_vidurkis;
    double balas_mediana;
    bool skirstymas;
};

void Skaitymas_ranka(Studentai);
void Skaitymas_generavimas(Studentai);
void Skaitymas_failo(Studentai);
void Rusiavimas(Studentai);
void Vidurkiai(Studentai);
void Mediana(Studentai);
void Rasymas(Studentai);

void GeneruotiFailus(int, int, string);
void Skirstymas(Studentai);
