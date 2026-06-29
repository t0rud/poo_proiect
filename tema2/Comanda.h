#pragma once
#include <vector>
#include <iostream>
#include "Produs.h"

class Comanda {
private:
    std::vector<Produs*> produse;

public:
    Comanda() = default;

    // rule of 3
    Comanda(const Comanda& other);
    Comanda& operator=(const Comanda& other);
    ~Comanda();

    void adauga_produs(const Produs& p);
    float total_comanda() const;

    friend std::ostream& operator<<(std::ostream& os, const Comanda& c);
};