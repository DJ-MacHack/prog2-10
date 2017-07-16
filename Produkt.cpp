//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include "Produkt.h"

/**
 * default constructor
 * @param name
 * @param beschreibung
 * @param kosten
 */
Produkt::Produkt(const std::string &name, const std::string &beschreibung, const double& kosten) : Projektbestandteil(name, beschreibung) {
    setKosten(kosten);
}

/**
 * sets costs
 * @param kosten
 */
void Produkt::setKosten(double kosten) {
    if (kosten >= 0){
        this->kosten = kosten;
    } else
    {
        throw std::logic_error("Kosten >= 0 Euro!");
    }
}

/**
 * cout
 * @param os
 */
void Produkt::output(std::ostream &os) const {
    Projektbestandteil::output(os);
    os << "Kosten: " << this->kosten << " Euro" << std::endl;
}

/**
 * calculates costs
 * @param costs
 * @return
 */
double Produkt::costs(double costs) const {
    return this->getKosten();
}


