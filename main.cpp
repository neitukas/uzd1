#include "main.h"
#include "my_library.cpp"

int main(){
    list<Studentai> A;
    list<Studentai> Vargseliai;
    list<Studentai> Galvuciai;

    vector<Studentai> Av;
    vector<Studentai> Vargseliaiv;
    vector<Studentai> Galvuciaiv;

    cout<<"Ka noretumete padaryti?"<<endl;
    cout<<"1 - Failo generavimas;"<<endl;
    cout<<"2 - Failo skaitymas ir studentu skirstymas;"<<endl;
    cout<<"3 - Testavimas;"<<endl;
    cout<<"4 - Baigti darba."<<endl;
    int pasirinkimas;
    cin>>pasirinkimas;
    while(pasirinkimas != 4){
        switch(pasirinkimas){
            case 1:{
                int studentu_sk, nd_skaicius;
                string failas;
                cout<<"Iveskite studentu skaiciu, namu darbu skaiciu ir failo pavadinima: ";
                cin>>studentu_sk>>nd_skaicius>>failas;
                GeneruotiFailus(studentu_sk, nd_skaicius, failas);
                break;
            }
            case 2:{
                string duomenys;
                cout<<"Iveskite failo pavadinima: ";
                cin>>duomenys;
                Av.clear();
                Vargseliaiv.clear();
                Skaitymas_failo(Av, duomenys);
                Vidurkiai(Av);
                Mediana(Av);
                Rusiavimas(Av);
                Vargseliaiv.clear();
                Skirstymas_3(Av, Vargseliaiv);
                cout<<"Iveskite isvedimo failo pavadinima: ";
                string isvedimas;
                cin>>isvedimas;
                Rasymas_suskirstytas(Av, Vargseliaiv, isvedimas);
                cout<<"Studentai suskirstyti ir isvesti i faila: "<<isvedimas<<endl;
                break;
            }
            case 3:{
                cout<<"| Duomenų failas   | <List> 1 budu | <List> 2 budu | <Vector> 1 budu> | <Vector> 2 budu | <Vector> 3 budu |"<<endl;
                cout<<"| ---------------- | ------------- | ------------- | ---------------- | --------------- | --------------- |"<<endl;

                string duom="stud100.txt";
                Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

                duom="stud1000.txt";
                Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

                duom="stud10000.txt";
                Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

                duom="stud100000.txt";
                Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

                duom="stud1000000.txt";
                Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

                break;
            }
            default:
                cout<<"Neteisingas pasirinkimas."<<endl;
        }
        cout<<"Ka noretumete padaryti?"<<endl;
        cout<<"1 - Failo generavimas;"<<endl;
        cout<<"2 - Failo skaitymas ir studentu skirstymas;"<<endl;
        cout<<"3 - Testavimas;"<<endl;
        cout<<"4 - Baigti darba."<<endl;
        cin>>pasirinkimas;
    }
    
    return 0;
}
