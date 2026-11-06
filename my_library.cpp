#include "main.h"

template <typename Funkcija>
double MatuotiLaika(Funkcija f) {
    auto pradzia = chrono::high_resolution_clock::now();

    f();

    auto pabaiga = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::duration<double, micro>>(
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
        double nd_vidurkis = accumulate(studentas.pazymiai_nd.begin(), studentas.pazymiai_nd.end(), 0.0) / studentas.pazymiai_nd.size();
        double vidurkis = 0.4 * nd_vidurkis + 0.6 * studentas.pazymys_egzaminas;
        studentas.balas_vidurkis = vidurkis;
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
void Rasymas(Container & A){
    ofstream fr("rezu.txt");

    fr<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(30)<<left<<"Galutinis balas (vid.)"<<setw(30)<<left<<"Galutinis balas (med.)"<<setw(30)<<left<<"Adresas"<<endl;
    fr<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(const auto & studentas : A){
        fr<<setw(20)<<left<<studentas.vardas<<setw(20)<<left<<studentas.pavarde<<setw(30)<<left<<fixed<<setprecision(2)<<studentas.balas_vidurkis<<
        setw(30)<<left<<fixed<<setprecision(2)<<studentas.balas_mediana<<setw(30)<<left<<&studentas<<endl;
    }
    fr.close();
}

/*void Skirstymas(list<Studentai> & A){
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
}*/

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

void Testavimas(list<Studentai> & A, list<Studentai> & Vargseliai, list<Studentai> & Galvuciai, vector<Studentai> & Av, vector<Studentai> & Vargseliaiv, vector<Studentai> & Galvuciaiv, string & duomenys){
    cout<<"| "<<duomenys<<" | ";

    Skaitymas_failo(A, duomenys);

    Vargseliai.clear();
    Galvuciai.clear();

    Rusiavimas(A);
    double laikas1 = MatuotiLaika([&](){
            Skirstymas_1(A, Vargseliai, Galvuciai);
        });
    cout<<laikas1<<" | ";

    Vargseliai.clear();
    Galvuciai.clear();

    double laikas2 = MatuotiLaika([&](){
            Skirstymas_2(Vargseliai, Galvuciai);
        });
    cout<<laikas2<<" | ";

    Skaitymas_failo(Av, duomenys);

    Rusiavimas(Av);

    Vargseliaiv.clear();
    Galvuciaiv.clear();

    double laikas3 = MatuotiLaika([&](){
            Skirstymas_1(Av, Vargseliaiv, Galvuciaiv);
        });
    cout<<laikas3<<" | ";

    Vargseliaiv.clear();
    Galvuciaiv.clear();

    double laikas4 = MatuotiLaika([&](){
            Skirstymas_2(Vargseliaiv, Galvuciaiv);
        });
    cout<<laikas4<<" |"<<endl;
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
