# v0.3

Sistemos parametrai:
- AMD Ryzen 5 Pro 7535U (12) @ 4.63 GHz
- 16 GB RAM
- SSD

# Testavimas naudojant std::vector konteinerį

Laiko trukmė nurodoma sekundėmis.

| Duomenų kiekis | Failo nuskaitymas | Duomenų skirstymas | Duomenų išvedimas į failą | Iš viso |
| -------------- | ----------------- | ------------------ | ------------------------- | ------- |
| 1000           | 0.001244 | 0.004661 | 0.005582 | 0.011486 |
| 10000          | 0.014507 | 0.036659 | 0.038709 | 0.089876 |
| 100000         | 0.122076 | 0.441179 | 0.550528 | 1.113783 |
| 1000000        | 1.643943 | 4.651052 | 5.035972 | 11.330968 |
| 10000000       | 12.916769 | 46.200074 | 49.484663 | 108.601506 |

Išvesti rezultatai:

<img width="466" height="665" alt="image" src="https://github.com/user-attachments/assets/2ee3d073-d7ec-4cc7-95ab-11c157875035" />

# Testavimas naudojant std::list konteinerį

Laiko trukmė nurodoma sekundėmis.

| Duomenų kiekis | Failo nuskaitymas | Duomenų skirstymas | Duomenų išvedimas į failą | Iš viso |
| -------------- | ----------------- | ------------------ | ------------------------- | ------- |
| 1000           | 0.001178 | 0.041232 | 0.097669 | 0.140079 |
| 10000          | 0.012977 | 0.037863 | 0.039385 | 0.090224 |
| 100000         | 0.133202 | 0.393269 | 0.491578 | 1.018048 |
| 1000000        | 1.359680 | 4.867096 | 5.238275 | 11.465052 |
| 10000000       | 12.723911 | 51.595262 | 52.035516 | 116.354689 |

Išvesti rezultatai:

<img width="482" height="666" alt="image" src="https://github.com/user-attachments/assets/3912f2e8-fb76-4b36-9551-5a6fd3c97d3e" />
