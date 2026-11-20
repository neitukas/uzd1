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
#include <string>
#include <sstream>

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
long long MatuotiLaika(Funkcija f){
    auto pradzia = chrono::high_resolution_clock::now();

    f();

    auto pabaiga = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::microseconds>(
        pabaiga - pradzia
    ).count();
}

void Skaitymas_ranka(vector<Studentai> & A);
void Skaitymas_generavimas(vector<Studentai> & A);
void Skaitymas_failo(vector<Studentai> & A);
void Rusiavimas(vector<Studentai> & A);
void Rusiavimas_galutinis(vector<Studentai> & A);
void Vidurkiai(vector<Studentai> & A);
void Mediana(vector<Studentai> & A);
void Rasymas(vector<Studentai> & A);
void GeneruotiFailus(int studentu_sk, int nd_skaicius, string failas);
void Skirstymas(vector<Studentai> & A);
