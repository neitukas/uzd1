#include "main.h"

template <typename Funkcija>
double MatuotiLaika(Funkcija f) {
    auto pradzia = chrono::high_resolution_clock::now();

    f();

    auto pabaiga = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::duration<double>>(
        pabaiga - pradzia
    ).count();
}

void Skaitymas_failo(list<Studentai> & A, string & duomenys){
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

void Rusiavimas(list<Studentai> & A) {
    A.sort([](const Studentai & a, const Studentai & b) {
        return a.vardas < b.vardas;
    });
}

void Vidurkiai(list<Studentai> & A){
    for(auto & studentas : A){
        double nd_vidurkis = accumulate(studentas.pazymiai_nd.begin(), studentas.pazymiai_nd.end(), 0.0) / studentas.pazymiai_nd.size();
        double vidurkis = 0.4 * nd_vidurkis + 0.6 * studentas.pazymys_egzaminas;
        studentas.balas_vidurkis = vidurkis;
        if(vidurkis<5)
            studentas.skirstymas = 0;
        else
            studentas.skirstymas = 1;
    }
}

void Mediana(list<Studentai> & A){
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

void Rasymas(list<Studentai> & A){
    ofstream fr("rezu.txt");

    fr<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(30)<<left<<"Galutinis balas (vid.)"<<setw(20)<<left<<"Galutinis balas (med.)"<<endl;
    fr<<"-------------------------------------------------------------------------------------------"<<endl;
    for(const auto & studentas : A){
        fr<<setw(20)<<left<<studentas.vardas<<setw(20)<<left<<studentas.pavarde<<setw(30)<<left<<fixed<<setprecision(2)<<studentas.balas_vidurkis<<setw(20)<<left<<fixed<<setprecision(2)<<studentas.balas_mediana<<endl;
    }
    fr.close();
}

void Skirstymas(list<Studentai> & A){
    ofstream fr("stud_vargseliai.txt");
    ofstream ft("stud_galvuciai.txt");

    for(const auto & studentas : A){
        if(studentas.skirstymas == 0){
            fr<<setw(14)<<left<<studentas.vardas<<setw(13)<<left<<studentas.pavarde;
            for(int pazymys : studentas.pazymiai_nd)
                fr<<setw(11)<<left<<pazymys<<" ";
            fr<<studentas.pazymys_egzaminas<<endl;
        }
        else{
            ft<<setw(14)<<left<<studentas.vardas<<setw(13)<<left<<studentas.pavarde;
            for(int pazymys : studentas.pazymiai_nd)
                ft<<setw(11)<<left<<pazymys<<" ";
            ft<<studentas.pazymys_egzaminas<<endl;
        }
    }

    fr.close();
    ft.close();
}

void Testavimas(list<Studentai> & A, string & duomenys){
    cout<<"Duomenu failas: "<<duomenys<<endl;

    double laikas1 = MatuotiLaika([&](){
            Skaitymas_failo(A, duomenys);
        });
    cout<<"Failo nuskaitymas: "<<fixed<<setprecision(6)<<laikas1<<" sek. "<<endl;

    Rusiavimas(A);

    double laikas2 = MatuotiLaika([&](){
            Skirstymas(A);
        });
    cout<<"Duomenu skirstymas: "<<laikas2<<" sek."<<endl;

    Vidurkiai(A);
    Mediana(A);

    double laikas3 = MatuotiLaika([&](){
            Rasymas(A);
        });
    cout<<"Duomenu rasymas: "<<laikas3<<" sek."<<endl;

    cout<<"Viso: "<< laikas1 + laikas2 + laikas3 <<" sek."<<endl;

    cout<<endl;
}
