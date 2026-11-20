#include "main.h"

void Testavimas(list<Studentai> & A, list<Studentai> & Vargseliai, list<Studentai> & Galvuciai, vector<Studentai> & Av, vector<Studentai> & Vargseliaiv, vector<Studentai> & Galvuciaiv, string & duomenys){
    cout<<"| "<<left<<setw(16)<<duomenys<<" | "<<right<<fixed<<setprecision(6);

    A.clear();
    Skaitymas_failo(A, duomenys);

    Vargseliai.clear();
    Galvuciai.clear();
    Vidurkiai(A);
    Mediana(A);
    Rusiavimas(A);
    double laikas1 = MatuotiLaika([&](){
            Skirstymas_1(A, Vargseliai, Galvuciai);
        });
    cout<<setw(13)<<laikas1<<" | ";

    Vargseliai.clear();
    Galvuciai.clear();
    double laikas2 = MatuotiLaika([&](){
            Skirstymas_2(A, Galvuciai);
        });
    cout<<setw(13)<<laikas2<<" | ";

    Av.clear();
    Skaitymas_failo(Av, duomenys);

    Vargseliaiv.clear();
    Galvuciaiv.clear();
    Vidurkiai(Av);
    Mediana(Av);
    Rusiavimas(Av);
    double laikas3 = MatuotiLaika([&](){
            Skirstymas_1(Av, Vargseliaiv, Galvuciaiv);
        });
    cout<<setw(16)<<laikas3<<" | ";

    Vargseliaiv.clear();
    Galvuciaiv.clear();
    double laikas4 = MatuotiLaika([&](){
            Skirstymas_2(Av, Galvuciaiv);
        });
    cout<<setw(15)<<laikas4<<" | ";

    Av.clear();
    Skaitymas_failo(Av, duomenys);
    Vargseliaiv.clear();
    Galvuciaiv.clear();
    Vidurkiai(Av);
    Mediana(Av);
    Rusiavimas(Av);
    double laikas5 = MatuotiLaika([&](){
            Skirstymas_3(Av, Galvuciaiv);
        });
    cout<<setw(15)<<laikas5<<" |"<<endl;
}

void GeneruotiFailus(int studentu_sk, int nd_skaicius, string failas){
    ofstream fr(failas);
    fr<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde";
    for(int i=0; i<nd_skaicius; i++){
        fr<<"ND"<<setw(10)<<left<<i+1;
    }
    fr<<"Egz."<<endl;
    for(int i=0; i<studentu_sk; i++){

        random_device seed;
        mt19937 gen{seed()};
        uniform_int_distribution<> dist(1, 10);

        fr<<"Vardas"<<setw(14)<<left<<i+1<<"Pavarde"<<setw(13)<<left<<i+1;
        for(int j=0; j<nd_skaicius+1; j++)
            fr<<setw(11)<<left<<dist(gen)<<" ";
        fr<<endl;
    }
    fr.close();
}
