#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;

struct Studentai{
    string pavarde;
    string vardas;
    vector<int> pazymiai_nd;
    int pazymys_egzaminas;
    double galutinis_balas;
};

void Skaitymas(vector<Studentai> & A){
    int n;
    cout<<"Iveskite studentu skaiciu:";
    cin>>n;

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
            if(laikinas<0 || laikinas>10)
                cout<<"Pazymys turi buti tarp 1 ir 10. Bandykite dar karta."<<endl;
            else if(laikinas!=0)
                m.pazymiai_nd.push_back(laikinas);
        }
        cout<<"Egzamino pazymys 1-10: ";
        laikinas=11;
        while(laikinas<=0 || laikinas>10){
            cin>>laikinas;
            if(laikinas<=0 || laikinas>10)
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
        A[i].galutinis_balas = vidurkis;
    }
}

void Rasymas(vector<Studentai> & A){
    cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis balas"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    for(int i=0; i<A.size(); i++){
        cout<<setw(20)<<left<<A[i].vardas<<setw(20)<<left<<A[i].pavarde<<setw(20)<<left<<fixed<<setprecision(2)<<A[i].galutinis_balas<<endl;
    }
}

int main(){
    vector<Studentai> A;

    Skaitymas(A);
    Vidurkiai(A);
    Rasymas(A);

    return 0;
}
