# Studentų rezultatų skirstymo programa

## v.pradinė

- generuoja studentų duomenų failus;
- nuskaito duomenis, įvestus rankiniu būdu;
- apskaičiuoja galutinį balą iš namų darbų vidurkio ir egzamino pažymio;
- apskaičiuoja galutinį balą iš namų darbų ir egzamino medianos.

## v0.1

- generuoja studentų duomenų failus;
- nuskaito duomenis iš failo;
- apskaičiuoja galutinį balą iš namų darbų vidurkio ir egzamino pažymio;
- apskaičiuoja galutinį balą iš namų darbų ir egzamino medianos.

## v0.2

- generuoja studentų duomenų failus;
- nuskaito duomenis iš failo;
- studentus skirsto į „galvučius“ ir „vargšelius“:
  - vargšelis – galutinis balas mažesnis nei 5;
  - galvučius – galutinis balas ne mažesnis nei 5;
- matuoja, kiek laiko užtrunka duomenų nuskaitymas ir studentų suskirstymas.

## v0.3

- generuoja studentų duomenų failus;
- nuskaito duomenis iš failo;
- studentus skirsto į „galvučius“ ir „vargšelius“:
  - vargšelis – galutinis balas mažesnis nei 5;
  - galvučius – galutinis balas ne mažesnis nei 5;
- palygina skirtingus studentų skirstymo būdus su `std::list` ir `std::vector` konteineriais laiko atžvilgiu.

## v1.0

- generuoja studentų duomenų failus;
- nuskaito duomenis iš failo;
- apskaičiuoja galutinį balą iš namų darbų vidurkio ir egzamino pažymio;
- apskaičiuoja galutinį balą iš namų darbų ir egzamino medianos;
- studentus skirsto į „galvučius“ ir „vargšelius“:
  - vargšelis – galutinis balas mažesnis nei 5;
  - galvučius – galutinis balas ne mažesnis nei 5;
- išveda suskirstytus studentus į pasirinktą failą;
- palygina skirtingus studentų skirstymo būdus su `std::list` ir `std::vector` konteineriais laiko atžvilgiu;

Skirstymui naudojamas greičiausias skirstymo metodas - `std::vector` konteineris ir skirstymas su std::partition.

## v1.0 greičio testų rezultatai

| Duomenų failas | List 1 būdu | List 2 būdu | Vector 1 būdu | Vector 2 būdu | Vector 3 būdu |
| -------------- | ------------- | ------------- | ---------------- | --------------- | --------------- |
| stud100.txt | 2.142e-05 | 1.2684e-05 | 3.1288e-05 | 6.693e-06 | 7.213e-06 |
| stud1000.txt | 0.000257001 | 0.000107922 | 0.000331571 | 5.9171e-05 | 6.7436e-05 |
| stud10000.txt | 0.00279957 | 0.00142317 | 0.00409161 | 0.000720801 | 0.000665928 |
| stud100000.txt | 0.0346587 | 0.0242837 | 0.0386053 | 0.0138179 | 0.00689135 |
| stud1000000.txt | 0.377681 | 0.289475 | 0.447638 | 0.198554 | 0.0698471 |

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

## v1.0 naudojimas

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
