#pragma once
#include "Produs.h"

class Patiserie : public Produs {
private:
    bool incalzit;
    int stoc_disponibil;

public:
    Patiserie(const std::string& nume, float pret_baza, bool incalzit, int stoc);

    float calculeaza_pret() const override;
    Produs* clone() const override;
    void afisare(std::ostream& os) const override;
    
    void scade_stoc();
};