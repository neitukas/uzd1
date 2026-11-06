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

    string duom="stud10000.txt";
    Testavimas(A, Vargseliai, Galvuciai, Av, Vargseliaiv, Galvuciaiv, duom);

    return 0;
}
