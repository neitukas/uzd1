#include "main.h"
#include "my_library.cpp"

int main(){
    vector<Studentai> A;
    int isvestis = 0;
    int duomenu_ivedimas = 0;

    auto laikas = MatuotiLaika([&](){
        GeneruotiFailus(1000, 3, "stud1000.txt");
    });
    cout<<"Generavimas 1000 eiluciu: "<<laikas<<" mikrosek."<<endl;

    laikas = MatuotiLaika([&](){
        GeneruotiFailus(10000, 3, "stud10000.txt");
    });
    cout<<"Generavimas 10000 eiluciu: "<<laikas<<" mikrosek."<<endl;

    laikas = MatuotiLaika([&](){
        GeneruotiFailus(100000, 3, "stud100000.txt");
    });
    cout<<"Generavimas 100000 eiluciu: "<<laikas<<" mikrosek. arba "<<laikas/1000000<<" sek."<<endl;

    laikas = MatuotiLaika([&](){
        GeneruotiFailus(1000000, 3, "stud1000000.txt");
    });
    cout<<"Generavimas 1000000 eiluciu: "<<laikas<<" mikrosek. arba "<<laikas/1000000<<" sek."<<endl;

    laikas = MatuotiLaika([&](){
        GeneruotiFailus(10000000, 3, "stud10000000.txt");
    });
    cout<<"Generavimas 10000000 eiluciu: "<<laikas<<" mikrosek. arba "<<laikas/60000000<<" min."<<endl;
    
    return 0;
}
