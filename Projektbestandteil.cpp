//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include "Projektbestandteil.h"

std::string Projektbestandteil::getName() const {
    return this->name;
}

std::string Projektbestandteil::getBeschreibung() const {
    return this->beschreibung;
}

Projektbestandteil::Projektbestandteil(const std::string& name, const std::string& beschreibung) {
    setName(name);
    setBeschreibung(beschreibung);
}

void Projektbestandteil::setName(const std::string name) {
    if(name != "") {
        this->name = name;
    } else {
        throw std::logic_error("Leerer Name!");
    }
}

void Projektbestandteil::setBeschreibung(std::string beschreibung) {
    this->beschreibung = beschreibung;
}
