#pragma once
#include "Produs.h"

class Bautura : public Produs {
private:
    int shot_extra_espresso;
    bool are_lapte;

public:
    Bautura(const std::string& nume, float pret_baza, int shot_extra = 0, bool lapte = false);

    float calculeaza_pret() const override;
    Produs* clone() const override;
    void afisare(std::ostream& os) const override;
};