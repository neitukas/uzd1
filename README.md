# Studentų rezultatų skirstymo programa

## Funkcionalumas

- generuoja studentų duomenų failus;
- nuskaito duomenis iš failo;
- apskaičiuoja galutinį balą iš namų darbų vidurkio ir egzamino pažymio;
- apskaičiuoja galutinį balą iš namų darbų medianos;
- studentus skirsto į „galvučius“ ir „vargšelius“:
  - vargšelis – galutinis balas mažesnis nei 5;
  - galvūčius – galutinis balas ne mažesnis nei 5;
- išveda suskirstytus studentus į pasirinktą failą;
- palygina skirtingus studentų skirstymo būdus su `std::list` ir `std::vector` konteineriais.

## Reikalavimai

- Su C++ kompiliatoriumi suderinama operacinė sistema;
- G++ kompiliatorius, palaikantis C++11 ar naujesnę versiją.

## Kompiliavimas

Paleiskite terminalą projekto aplanke:

```bash
g++ -std=c++11 main.cpp -o main
```

Programa atidarius pateikia meniu:

```text
1 - Failo generavimas;
2 - Failo skaitymas ir studentu skirstymas;
3 - Testavimas;
4 - Baigti darba.
```

## Naudojimas

### Duomenų failo generavimas

Pasirinkus `1`, įveskite tris reikšmes atskirtas tarpais:

```text
<studentų skaičius> <namų darbų skaičius> <failo pavadinimas>
```

### Studentų nuskaitymas ir skirstymas

Pasirinkus `2`, įveskite:

1. įvesties failo pavadinimą;
2. išvesties failo pavadinimą.

### Greičio testavimas

Pasirinkus `3`, programa išmatuoja skirtingų skirstymo būdų vykdymo laiką failams nuo `stud100.txt` iki `stud1000000.txt`.

Prieš paleidžiant testavimą, sugeneruokite failus pasirinkus `2`, o failų pavadinimus įveskite nuo `stud100.txt` iki `stud1000000.txt` (6 nuliai).

## Failų formatas

Įvesties failo pirmoje eilutėje turi būti antraštė, pavyzdžiui:

```text
Vardas              Pavarde             ND1  ND2  ND3  Egz.
Jonas               Jonaitis            10   8    9    9
Petras              Petraitis           6    7    8    7
```

Paskutinis skaičius eilutėje laikomas egzamino pažymiu.

## Galutinio balo apskaičiavimas

Galutinis balas pagal namų darbų vidurkį apskaičiuojamas taip:

$$Galutinis = 0.4 \times \overline{ND} + 0.6 \times Egzaminas$$

Taip pat programa apskaičiuoja galutinį balą pagal namų darbų ir egzamino pažymių medianą.

## Projekto struktūra

```text
main.cpp         pagrindinis programos meniu ir paleidimas
main.h           Studentai struktūra ir naudojamos C++ bibliotekos
my_library.cpp   duomenų apdorojimo, skirstymo ir testavimo funkcijos
```
