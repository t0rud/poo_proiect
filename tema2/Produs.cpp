#include "Produs.h"

Produs::Produs(const std::string& nume, float pret_baza) 
    : nume(nume), pret_baza(pret_baza) {}

void Produs::afisare(std::ostream& os) const {
    os << "Produs: " << nume << " | Pret baza: " << pret_baza << " RON";
}