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

    /*GeneruotiFailus(1000, 5, "stud1000.txt");
    GeneruotiFailus(10000, 5, "stud10000.txt");
    GeneruotiFailus(100000, 5, "stud100000.txt");
    GeneruotiFailus(1000000, 5, "stud1000000.txt");
    GeneruotiFailus(10000000, 5, "stud10000000.txt");*/

    cout<<"Laikai pateikiami milisekundemis:"<<endl;
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
