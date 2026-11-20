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
#include <type_traits>
#include <sstream>
#include <utility>

using namespace std;

struct Studentai{
    string pavarde;
    string vardas;
    vector<int> pazymiai_nd;
    int pazymys_egzaminas;
    double balas_vidurkis;
    double balas_mediana;
    int skirstymas = -1;
};

template <typename Funkcija>
double MatuotiLaika(Funkcija f) {
    auto pradzia = chrono::high_resolution_clock::now();

    f();

    auto pabaiga = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::duration<double>>(
        (pabaiga - pradzia) 
    ).count();
}

template <typename Container>
void Skaitymas_failo(Container & A, string & duomenys){
    ifstream fd(duomenys);

    if (!fd.is_open()) {
        cout<<"Nepavyko atidaryti failo"<<endl;
    }

    string temp;
    getline(fd, temp);

    while(getline(fd, temp)){
        stringstream ss(temp);
        Studentai m;

        ss>>m.vardas>>m.pavarde;
        vector<int> Pazymiai;
        int p;
        while(ss>>p)
            Pazymiai.push_back(p);

        m.pazymys_egzaminas = Pazymiai.back();
        Pazymiai.pop_back();
        m.pazymiai_nd = Pazymiai;

        A.push_back(m);
    }

    fd.close();
}

template <typename Container>
void Rusiavimas(Container & A) {
    auto palyginimas = [](const Studentai& a, const Studentai& b) {
        return a.balas_vidurkis > b.balas_vidurkis;
    };

    if constexpr (is_same_v<Container, list<Studentai>>) {
        A.sort(palyginimas);
    }
    else {
        sort(A.begin(), A.end(), palyginimas);
    }
}

template <typename Container>
void Vidurkiai(Container & A){
    for(auto & studentas : A){
        double nd_vidurkis = studentas.pazymiai_nd.empty()
            ? 0.0
            : accumulate(studentas.pazymiai_nd.begin(), studentas.pazymiai_nd.end(), 0.0) / studentas.pazymiai_nd.size();
        double vidurkis = 0.4 * nd_vidurkis + 0.6 * studentas.pazymys_egzaminas;
        studentas.balas_vidurkis = vidurkis;
        studentas.skirstymas = vidurkis < 5 ? 0 : 1;
    }
}

template <typename Container>
void Mediana(Container & A){
    for(auto & studentas : A){
        vector<int> G;
        for(int pazymys : studentas.pazymiai_nd)
            G.push_back(pazymys);
        G.push_back(studentas.pazymys_egzaminas);
        sort(G.begin(), G.end());
        if(G.size()%2 == 0)
            studentas.balas_mediana = ( G[G.size()/2-1] + G[G.size()/2] ) / 2.0;
        else
            studentas.balas_mediana = G[G.size()/2];
    }
}

template <typename Container>
void Rasymas_suskirstytas(Container & Galvuciai, Container & Vargseliai, string & failas){
    ofstream fr(failas);

    if(!fr.is_open()){
        cout<<"Nepavyko sukurti failo: "<<failas<<endl;
        return;
    }

    fr<<"Vargseliai (galutinis balas < 5)"<<endl;
    fr<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"
      <<setw(30)<<left<<"Galutinis balas (vid.)"
      <<setw(30)<<left<<"Galutinis balas (med.)"<<endl;
    fr<<"-----------------------------------------------------------------------------------------------------"<<endl;
    for(const auto & studentas : Vargseliai){
        fr<<setw(20)<<left<<studentas.vardas<<setw(20)<<left<<studentas.pavarde
          <<setw(30)<<left<<fixed<<setprecision(2)<<studentas.balas_vidurkis
          <<setw(30)<<left<<fixed<<setprecision(2)<<studentas.balas_mediana<<endl;
    }

    fr<<endl<<"Galvuciai (galutinis balas >= 5)"<<endl;
    fr<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"
      <<setw(30)<<left<<"Galutinis balas (vid.)"
      <<setw(30)<<left<<"Galutinis balas (med.)"<<endl;
    fr<<"-----------------------------------------------------------------------------------------------------"<<endl;
    for(const auto & studentas : Galvuciai){
        fr<<setw(20)<<left<<studentas.vardas<<setw(20)<<left<<studentas.pavarde
          <<setw(30)<<left<<fixed<<setprecision(2)<<studentas.balas_vidurkis
          <<setw(30)<<left<<fixed<<setprecision(2)<<studentas.balas_mediana<<endl;
    }

    fr.close();
}

template <typename Container>
void Skirstymas_1(Container & A, Container & B, Container & C){
    for(const auto & studentas : A){
        if(studentas.balas_vidurkis < 5)
            B.push_back(studentas);
        else
            C.push_back(studentas);
    }
}

template <typename Container>
void Skirstymas_2(Container & A, Container & B) {
    auto p = remove_if(A.begin(), A.end(),
        [&](const auto& x) {
            if (x.balas_vidurkis < 5) {
                B.push_back(x);
                return true;
            }
            return false;
        });
    A.erase(p, A.end());
}

template <typename Container>
void Skirstymas_3(Container & A, Container & B) {
    auto p = partition(A.begin(), A.end(),
    [](const Studentai& S) {
        return S.balas_vidurkis >= 5;
    });

    if constexpr (is_same_v<Container, vector<Studentai>>) {
        B.reserve(B.size() + distance(p, A.end()));
    }

    for (auto it = p; it != A.end(); ++it)
        B.push_back(move(*it));
    A.erase(p, A.end());
}

void Testavimas(list<Studentai> & A, list<Studentai> & Vargseliai, list<Studentai> & Galvuciai, vector<Studentai> & Av, vector<Studentai> & Vargseliaiv, vector<Studentai> & Galvuciaiv, string & duomenys);
void GeneruotiFailus(int studentu_sk, int nd_skaicius, string failas);
