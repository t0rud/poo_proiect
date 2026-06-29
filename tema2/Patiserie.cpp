#include "Patiserie.h"
#include "Exceptii.h"

Patiserie::Patiserie(const std::string& nume, float pret_baza, bool incalzit, int stoc)
    : Produs(nume, pret_baza), incalzit(incalzit), stoc_disponibil(stoc) {}

float Patiserie::calculeaza_pret() const {
    return pret_baza + (incalzit ? 1.5f : 0.0f);
}

Produs* Patiserie::clone() const {
    return new Patiserie(*this);
}

void Patiserie::scade_stoc() {
    if (stoc_disponibil <= 0) {
        throw StocInsuficientException("Stoc epuizat pentru produsul: " + nume);
    }
    stoc_disponibil--;
}

void Patiserie::afisare(std::ostream& os) const {
    os << "Patiserie: " << nume << (incalzit ? " (Incalzit)" : "") 
       << " -> Pret final: " << calculeaza_pret() << " RON";
}