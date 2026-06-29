#pragma once
#include <string>
#include <iostream>

class Produs {
protected:
    std::string nume;
    float pret_baza;

public:
    Produs(const std::string& nume, float pret_baza);
    virtual ~Produs() = default; // Destructor virtual

    virtual float calculeaza_pret() const = 0; // Funcție virtuală pură
    virtual Produs* clone() const = 0;         // Pentru copiere polimorfică

    virtual void afisare(std::ostream& os) const;

    // Supraîncărcare operator<< 
    friend std::ostream& operator<<(std::ostream& os, const Produs& p) {
        p.afisare(os);
        return os;
    }
};