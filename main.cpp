#include "main.h"
#include "my_library.cpp"

int main(){
    list<Studentai> A;
    list<Studentai> Vargseliai;
    list<Studentai> Galvuciai;
    list<Studentai> Vargseliai2;

    vector<Studentai> Av;
    vector<Studentai> Vargseliaiv;
    vector<Studentai> Galvuciaiv;
    vector<Studentai> Vargseliai2v;

    cout<<"| Duomenų failas | <List> 1 budu | <List> 2 budu | <Vector> 1 budu | <Vector> 2 budu> |"<<endl;
    cout<<"| -------------- | ------------- | ------------- | --------------- | ---------------- |"<<endl;

    string duom="stud1000.txt";
    Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

    duom="stud10000.txt";
    Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

    duom="stud100000.txt";
    Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

    duom="stud1000000.txt";
    Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

    duom="stud10000000.txt";
    Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);
    
    return 0;
}
