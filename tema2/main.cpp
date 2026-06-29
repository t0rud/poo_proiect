#include <iostream>
#include "Bautura.h"
#include "Patiserie.h"
#include "Comanda.h"
#include "Exceptii.h"

int main() {
    try {
        Comanda comanda_curenta;

        // instantiem obiecte derivate
        Bautura cafea_simpla("Espresso", 8.0f);
        Bautura latte_mare("Latte Macchiato", 12.0f, 2, true); // 2 shot-uri, cu lapte
        Patiserie croissant("Croissant cu unt", 7.0f, true, 2); // stoc 2

        // adaugam polimorfic in comanda
        comanda_curenta.adauga_produs(cafea_simpla);
        comanda_curenta.adauga_produs(latte_mare);
        
        croissant.scade_stoc();
        comanda_curenta.adauga_produs(croissant);
        
        croissant.scade_stoc();
        comanda_curenta.adauga_produs(croissant);

        // aici va arunca exceptia, stocul e deja 0

        std::cout << comanda_curenta << "\n";

        // testam rule of 3 (constructorul de copiere)
        Comanda copie_comanda = comanda_curenta;
        std::cout << "--- Afisare copie comanda ---\n";
        std::cout << copie_comanda << "\n";

    } catch (const StocInsuficientException& e) {
        std::cerr << "[EROARE STOC]: " << e.what() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "[EROARE DATE]: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "[EROARE GENERALA]: " << e.what() << "\n";
    }

    return 0;
}