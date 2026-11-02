#include "main.h"
#include "my_library.cpp"

int main(){
    list<Studentai> A;

    string duom = "stud1000.txt";
    Testavimas(A, duom);

    duom = "stud10000.txt";
    Testavimas(A, duom);
    
    duom = "stud100000.txt";
    Testavimas(A, duom);
    
    duom = "stud1000000.txt";
    Testavimas(A, duom);
    
    duom = "stud10000000.txt";
    Testavimas(A, duom);

    return 0;
}
