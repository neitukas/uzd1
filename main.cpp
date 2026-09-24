#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <limits>
#include <random>

using namespace std;

struct Studentai{
    string pavarde;
    string vardas;
    vector<int> pazymiai_nd;
    int pazymys_egzaminas;
    double balas_vidurkis;
    double balas_mediana;
};

void Skaitymas_ranka(vector<Studentai> & A){
    int n=0;
    cout<<"Iveskite studentu skaiciu: ";
    while(n==0){
        cin>>n;
        if(!cin){
            n=0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Ivestis turi buti skaicius. Bandykite dar karta."<<endl;
        }
    }

    for(int i=0; i<n; i++){
        Studentai m;
        cout<<"Studentas nr. "<<i+1<<endl;
        cout<<"Vardas: ";
        cin>>m.vardas;
        cout<<"Pavarde: ";
        cin>>m.pavarde;

        int laikinas=1;
        cout<<"Namu darbu pazymiai 1-10: (pabaigus iveskite 0)"<<endl;
        while(laikinas!=0){
            cin>>laikinas;
            if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                laikinas=1;
                cout<<"Pazymys turi buti skaicius. Bandykite dar karta."<<endl;
                continue;
            }
            else if(laikinas<0 || laikinas>10)
                cout<<"Pazymys turi buti tarp 1 ir 10. Bandykite dar karta."<<endl;
            else if(laikinas!=0)
                m.pazymiai_nd.push_back(laikinas);
        }
        laikinas=11;
        cout<<"Egzamino pazymys 1-10: ";
        while(laikinas<=0 || laikinas>10){
            cin>>laikinas;
            if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                laikinas=11;
                cout<<"Pazymys turi buti skaicius. Bandykite dar karta."<<endl;
                continue;
            }
            else if(laikinas<=0 || laikinas>10)
                cout<<"Pazymys turi buti tarp 1 ir 10. Bandykite dar karta."<<endl;
        }
        m.pazymys_egzaminas = laikinas;
        A.push_back(m);
    }
}

void Skaitymas_generavimas(vector<Studentai> & A){
    int n=0;
    cout<<"Iveskite studentu skaiciu: ";
    while(n==0){
        cin>>n;
        if(!cin){
            n=0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Ivestis turi buti skaicius. Bandykite dar karta."<<endl;
        }
    }

    for(int i=0; i<n; i++){
        Studentai m;
        cout<<"Studentas nr. "<<i+1<<endl;
        cout<<"Vardas: ";
        cin>>m.vardas;
        cout<<"Pavarde: ";
        cin>>m.pavarde;

        int pazymiu_sk=0;
        cout<<"Iveskite namu darbu pazymiu skaiciu: ";
        while(pazymiu_sk==0){
            cin>>pazymiu_sk;
            if(!cin){
                pazymiu_sk=0;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Ivestis turi buti skaicius. Bandykite dar karta."<<endl;
            }
        }

        random_device seed;
        mt19937 gen{seed()};
        uniform_int_distribution<> dist(1, 10);

        cout<<"Sugeneruoti namu darbu pazymiai: ";
        for(int j=0; j<pazymiu_sk; j++){
            m.pazymiai_nd.push_back(dist(gen));
            cout<<m.pazymiai_nd[j]<<" ";
        }
        m.pazymys_egzaminas=dist(gen);
        cout<<endl<<"Sugeneruotas egzamino pazymys: "<<m.pazymys_egzaminas<<endl;
        A.push_back(m);
    }
}

void Skaitymas_failo(vector<Studentai> & A){
    string duomenys;

    cout<<"Iveskite failo pavadinima:"<<endl;
    cin>>duomenys;

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

void Vidurkiai(vector<Studentai> & A){
    for(int i=0; i<A.size(); i++){
        double nd_vidurkis = accumulate(A[i].pazymiai_nd.begin(), A[i].pazymiai_nd.end(), 0) / A[i].pazymiai_nd.size();
        double vidurkis = 0.4 * nd_vidurkis + 0.6 * A[i].pazymys_egzaminas;
        A[i].balas_vidurkis = vidurkis;
    }
}

void Mediana(vector<Studentai> & A){
    for(int i=0; i<A.size(); i++){
        vector<int> G;
        for(int j=0; j<A[i].pazymiai_nd.size(); j++)
            G.push_back(A[i].pazymiai_nd[j]);
        G.push_back(A[i].pazymys_egzaminas);
        sort(G.begin(), G.end());
        if(G.size()%2 == 0)
            A[i].balas_mediana = ( G[G.size()/2] + G[G.size()/2+1] ) / 2;
        else
            A[i].balas_mediana = G[G.size()/2];
    }
}

void Rasymas(vector<Studentai> & A){
    int isvestis = 0;
    cout<<"Kuriuos rodmenis norite matyti? Pasirinkite atitinkama skaiciu:"<<endl;
    cout<<"(1) Vidurkis"<<endl<<"(2) Mediana"<<endl<<"(3) Vidurkis ir mediana"<<endl;
    while(isvestis!=1 && isvestis!=2 && isvestis!=3){
        cin>>isvestis;
        if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                isvestis=0;
                cout<<"Ivestis turi buti skaicius. Bandykite dar karta."<<endl;
                continue;
            }
        else if(isvestis!=1 && isvestis!=2 && isvestis!=3)
            cout<<"Netinkama ivestis. Bandykite dar karta:"<<endl;
    }
    if(isvestis==1){
        cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis balas (vid.)"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            cout<<setw(20)<<left<<A[i].vardas<<setw(20)<<left<<A[i].pavarde<<setw(20)<<left<<fixed<<setprecision(2)<<A[i].balas_vidurkis<<endl;
        }
    }
    else if(isvestis==2){
        cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis balas (med.)"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            cout<<setw(20)<<left<<A[i].vardas<<setw(20)<<left<<A[i].pavarde<<setw(20)<<left<<fixed<<setprecision(2)<<A[i].balas_mediana<<endl;
        }
    }
    else if(isvestis==3){
        cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(30)<<left<<"Galutinis balas (vid.)"<<setw(20)<<left<<"Galutinis balas (med.)"<<endl;
        cout<<"-------------------------------------------------------------------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            cout<<setw(20)<<left<<A[i].vardas<<setw(20)<<left<<A[i].pavarde<<setw(30)<<left<<fixed<<setprecision(2)<<A[i].balas_vidurkis<<setw(20)<<left<<fixed<<setprecision(2)<<A[i].balas_mediana<<endl;
        }
    }
}

int main(){
    vector<Studentai> A;
    int isvestis = 0;
    int duomenu_ivedimas = 0;

    cout<<"Pasirinkite duomenu ivedimo buda ivesdami atitinkama skaiciu:"<<endl;
    cout<<"(1) Rankiniu budu"<<endl<<"(2) Pazymiai generuojami atsitiktiniu budu"<<endl<<"(3) Duomenys skaitomi is failo"<<endl;
    while(duomenu_ivedimas!=1 && duomenu_ivedimas!=2 && duomenu_ivedimas!=3){
        cin>>duomenu_ivedimas;
        if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                duomenu_ivedimas=0;
                cout<<"Netinkama ivestis. Bandykite dar karta."<<endl;
                continue;
            }
    }

    if(duomenu_ivedimas==1)
        Skaitymas_ranka(A);
    else if(duomenu_ivedimas==2)
        Skaitymas_generavimas(A);
    else if(duomenu_ivedimas==3)
        Skaitymas_failo(A);

    Vidurkiai(A);
    Mediana(A);
    Rasymas(A);

    return 0;
}
