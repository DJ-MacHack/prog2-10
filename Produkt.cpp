//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include "Produkt.h"

Produkt::Produkt(const std::string &name, const std::string &beschreibung, const double& kosten) : Projektbestandteil(name, beschreibung) {
    setKosten(kosten);
}

void Produkt::setKosten(double kosten) {
    if (kosten >= 0){
        this->kosten = kosten;
    } else
    {
        throw std::logic_error("Kosten >= 0 Euro!");
    }
}
