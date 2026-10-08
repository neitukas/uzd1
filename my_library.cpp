#include "main.h"

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

void Rusiavimas(vector<Studentai> & A) {
    sort(A.begin(), A.end(),
         [](const Studentai & a, const Studentai & b) {
             return a.vardas < b.vardas;
         });
}

void Vidurkiai(vector<Studentai> & A){
    for(int i=0; i<A.size(); i++){
        double nd_vidurkis = accumulate(A[i].pazymiai_nd.begin(), A[i].pazymiai_nd.end(), 0) / A[i].pazymiai_nd.size();
        double vidurkis = 0.4 * nd_vidurkis + 0.6 * A[i].pazymys_egzaminas;
        A[i].balas_vidurkis = vidurkis;
        if(vidurkis<5)
            A[i].skirstymas = 0;
        else
            A[i].skirstymas = 1;
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
    ofstream fr("rezu.txt");
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
        fr<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis balas (vid.)"<<endl;
        fr<<"-------------------------------------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            fr<<setw(20)<<left<<A[i].vardas<<setw(20)<<left<<A[i].pavarde<<setw(20)<<left<<fixed<<setprecision(2)<<A[i].balas_vidurkis<<endl;
        }
    }
    else if(isvestis==2){
        fr<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis balas (med.)"<<endl;
        fr<<"-------------------------------------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            fr<<setw(20)<<left<<A[i].vardas<<setw(20)<<left<<A[i].pavarde<<setw(20)<<left<<fixed<<setprecision(2)<<A[i].balas_mediana<<endl;
        }
    }
    else if(isvestis==3){
        fr<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(30)<<left<<"Galutinis balas (vid.)"<<setw(20)<<left<<"Galutinis balas (med.)"<<endl;
        fr<<"-------------------------------------------------------------------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            fr<<setw(20)<<left<<A[i].vardas<<setw(20)<<left<<A[i].pavarde<<setw(30)<<left<<fixed<<setprecision(2)<<A[i].balas_vidurkis<<setw(20)<<left<<fixed<<setprecision(2)<<A[i].balas_mediana<<endl;
        }
    }
    cout<<"Jusu rezultatai isvesti i faila 'rezu.txt'."<<endl;
    fr.close();
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

void Skirstymas(vector<Studentai> & A){
    ofstream fr("stud_vargseliai.txt");
    ofstream ft("stud_galvuciai.txt");

    for(int i=0; i<size(A); i++){
        if(A[i].skirstymas == 0){
            fr<<setw(14)<<left<<A[i].vardas<<setw(13)<<left<<A[i].pavarde;
            for(int j=0; j<size(A[i].pazymiai_nd); j++)
                fr<<setw(11)<<left<<A[i].pazymiai_nd[j]<<" ";
            fr<<A[i].pazymys_egzaminas<<endl;
        }
        else{
            ft<<setw(14)<<left<<A[i].vardas<<setw(13)<<left<<A[i].pavarde;
            for(int j=0; j<size(A[i].pazymiai_nd); j++)
                ft<<setw(11)<<left<<A[i].pazymiai_nd[j]<<" ";
            ft<<A[i].pazymys_egzaminas<<endl;
        }
    }

    fr.close();
    ft.close();
}
