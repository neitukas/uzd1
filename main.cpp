#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <limits>

using namespace std;

struct Studentai{
    string pavarde;
    string vardas;
    vector<int> pazymiai_nd;
    int pazymys_egzaminas;
    double balas_vidurkis;
    double balas_mediana;
};

void Skaitymas(vector<Studentai> & A){
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

    Skaitymas(A);
    Vidurkiai(A);
    Mediana(A);
    Rasymas(A);

    return 0;
}
