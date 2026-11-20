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
    bool skirstymas;
};

template <typename Funkcija>
double MatuotiLaika(Funkcija f) {
    auto pradzia = chrono::high_resolution_clock::now();

    f();

    auto pabaiga = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::duration<double>>(
        pabaiga - pradzia
    ).count();
}

void Skaitymas_failo(list<Studentai> & A, string & duomenys);
void Rusiavimas(list<Studentai> & A);
void Vidurkiai(list<Studentai> & A);
void Mediana(list<Studentai> & A);
void Rasymas(list<Studentai> & A);
void Skirstymas(list<Studentai> & A);
void Testavimas(list<Studentai> & A, string & duomenys);
void Rasymas(list<Studentai> & A);
void Skirstymas(list<Studentai> & A);
void Testavimas(list<Studentai> & A, string & duomenys);
