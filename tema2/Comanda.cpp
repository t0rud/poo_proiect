#include "Comanda.h"

// 1. constructor de copiere
Comanda::Comanda(const Comanda& other) {
    for (const auto* p : other.produse) {
        produse.push_back(p->clone());
    }
}

// 2. operator de atribuire
Comanda& Comanda::operator=(const Comanda& other) {
    if (this != &other) {
        for (auto* p : produse) {
            delete p;
        }
        produse.clear();
        
        for (const auto* p : other.produse) {
            produse.push_back(p->clone());
        }
    }
    return *this;
}

// 3. destructor
Comanda::~Comanda() {
    for (auto* p : produse) {
        delete p;
    }
}

void Comanda::adauga_produs(const Produs& p) {
    produse.push_back(p.clone());
}

float Comanda::total_comanda() const {
    float total = 0;
    for (const auto* p : produse) {
        total += p->calculeaza_pret();
    }
    return total;
}

std::ostream& operator<<(std::ostream& os, const Comanda& c) {
    os << "--- Detalii Comanda ---\n";
    for (const auto* p : c.produse) {
        os << "- " << *p << "\n";
    }
    os << "TOTAL DE PLATA: " << c.total_comanda() << " RON\n";
    return os;
}