#pragma once
#include <string>
#include <iostream>

class Produs {
protected:
    std::string nume;
    float pret_baza;

public:
    Produs(const std::string& nume, float pret_baza);
    virtual ~Produs() = default; // destructor virtual

    virtual float calculeaza_pret() const = 0; // functie virtuala pura
    virtual Produs* clone() const = 0;         // pt copiere polimorfica

    virtual void afisare(std::ostream& os) const;

    // supraincarcare operator<< 
    friend std::ostream& operator<<(std::ostream& os, const Produs& p) {
        p.afisare(os);
        return os;
    }
};