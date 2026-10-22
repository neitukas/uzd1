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

