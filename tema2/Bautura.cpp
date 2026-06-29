#include "Bautura.h"
#include <stdexcept>

Bautura::Bautura(const std::string& nume, float pret_baza, int shot_extra, bool lapte) 
    : Produs(nume, pret_baza), shot_extra_espresso(shot_extra), are_lapte(lapte) {
    if (shot_extra < 0) {
        throw std::invalid_argument("Numarul de shot-uri nu poate fi negativ!");
    }
}

float Bautura::calculeaza_pret() const {
    float pret_final = pret_baza + (shot_extra_espresso * 3.0f);
    if (are_lapte) pret_final += 2.0f;
    return pret_final;
}

Produs* Bautura::clone() const {
    return new Bautura(*this);
}

void Bautura::afisare(std::ostream& os) const {
    os << "Bautura: " << nume << " (+ " << shot_extra_espresso << " shot extra, "
       << (are_lapte ? "cu lapte" : "fara lapte") 
       << ") -> Pret final: " << calculeaza_pret() << " RON";
}