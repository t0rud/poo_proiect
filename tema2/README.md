# Sistem de Gestiune a Comenzilor pentru o Cafenea - Tema 2

Acest proiect reprezinta prima etapa (Tema 2) a unui sistem de gestiune pentru o cafenea. Codul este axat strict pe demonstrarea conceptelor fundamentale de Programare Orientata pe Obiecte (POO), pregatind o arhitectura curata pentru a doua etapa.

## Descriere
Aplicatia gestioneaza o ierarhie de produse (bauturi calde, produse de patiserie) si permite adaugarea acestora in comenzi. Sistemul calculeaza automat pretul final pe baza atributelor fiecarui produs (de ex. shot-uri extra de espresso, taxe de incalzire) si valideaza stocurile disponibile in timp real.

## Concepte OOP Implementate (Conform cerintelor)

* **Mostenire:** A fost implementata o clasa de baza `Produs`, din care deriva public clasele `Bautura` si `Patiserie`.
* **Polimorfism la executie (Functii Virtuale):** * Clasa `Produs` este abstracta, continand metoda virtuala pura `calculeaza_pret()=0`, care este suprascrisa (`override`) in fiecare clasa derivata cu formula specifica de calcul.
  * S-a folosit metoda virtuala `clone()` pentru instantierea polimorfica (Virtual Constructor Idiom).
* **Supraincarcarea operatorilor:** A fost supraincarcat `operator<<` pentru afisarea produselor. Pentru a pastra comportamentul polimorfic, operatorul apeleaza o metoda virtuala `afisare()` definita in clase. De asemenea, operatorul este supraincarcat si pentru afisarea integrala a unei comenzi.
* **Exceptii Custom:** S-a definit clasa `StocInsuficientException` (care mosteneste `std::runtime_error`). Exceptia este aruncata atunci cand se incearca procesarea unui produs cu stoc 0 si este prinsa in siguranta folosind un bloc `try-catch` in functia main, prevenind blocarea aplicatiei.
* **Gestiunea memoriei (Rule of 3):** Deoarece clasa `Comanda` gestioneaza polimorfismul printr-un vector de pointeri alocati dinamic (`std::vector<Produs*>`), au fost implementate manual:
  1. Constructorul de copiere (realizeaza un *deep copy* al produselor).
  2. Operatorul de atribuire (`operator=`).
  3. Destructorul (pentru dealocarea memoriei si prevenirea memory leaks-urilor).

## Structura fisierelor

Proiectul respecta bunele practici de separare a codului in headere si surse:
* `Exceptii.h` - Definirea erorilor personalizate
* `Produs.h` / `Produs.cpp` - Clasa de baza abstracta
* `Bautura.h` / `Bautura.cpp` - Clasa derivata pentru bauturi
* `Patiserie.h` / `Patiserie.cpp` - Clasa derivata pentru mancare
* `Comanda.h` / `Comanda.cpp` - Clasa care gestioneaza pointerii si memoria
* `main.cpp` - Fisierul de testare (demonstratia conceptelor)

## Rulare si Compilare

Proiectul poate fi compilat din terminal folosind `g++`:

```bash
g++ main.cpp Produs.cpp Bautura.cpp Patiserie.cpp Comanda.cpp -o cafenea
./cafenea