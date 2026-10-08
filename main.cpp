#include "main.h"
#include "my_library.cpp"

int main(){
    vector<Studentai> A;
    int isvestis = 0;
    int duomenu_ivedimas = 0;

    /*
    GeneruotiFailus(1000, 3, "stud1000.txt");
    GeneruotiFailus(10000, 3, "stud10000.txt");
    GeneruotiFailus(100000, 3, "stud100000.txt");
    GeneruotiFailus(1000000, 3, "stud1000000.txt");
    GeneruotiFailus(10000000, 3, "stud10000000.txt");
    */

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

    Rusiavimas(A);
    Vidurkiai(A);
    Mediana(A);
    Rasymas(A);
    Skirstymas(A);

    return 0;
}
