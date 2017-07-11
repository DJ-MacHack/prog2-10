//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include "Aufgabe.h"

Aufgabe::Aufgabe(const std::string &name, const std::string &beschreibung, double aufwand) : Projektbestandteil(name, beschreibung) {
    setAufwand(aufwand);
}

void Aufgabe::setAufwand(double aufwand) {
    if (aufwand >= 0){
        this->aufwand = aufwand;
    } else
    {
        throw std::logic_error("Aufwand >= 0h!");
    }
}
