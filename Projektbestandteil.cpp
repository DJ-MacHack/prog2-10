//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include "Projektbestandteil.h"

/**
 * get name
 * @return
 */
std::string Projektbestandteil::getName() const {
    return this->name;
}

/**
 * get description
 * @return
 */
std::string Projektbestandteil::getBeschreibung() const {
    return this->beschreibung;
}

/**
 * constructor
 * @param name
 * @param beschreibung
 */
Projektbestandteil::Projektbestandteil(const std::string& name, const std::string& beschreibung) {
    setName(name);
    setBeschreibung(beschreibung);
}

/**
 * sets name
 * @param name
 */
void Projektbestandteil::setName(const std::string name) {
    if(name != "") {
        this->name = name;
    } else {
        throw std::logic_error("Leerer Name!");
    }
}

/**
 * sets description
 * @param beschreibung
 */
void Projektbestandteil::setBeschreibung(std::string beschreibung) {
    this->beschreibung = beschreibung;
}

/**
 * cout
 * @param os
 * @param projektbestandteil
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Projektbestandteil &projektbestandteil) {
    projektbestandteil.output(os);
    return os;
}

/**
 * destructor
 */
Projektbestandteil::~Projektbestandteil() {

}

/**
 * costs
 * @param cost
 * @return
 */
double Projektbestandteil::costs(double cost) const {
    return cost;
}

/**
 * cout
 * @param os
 */
void Projektbestandteil::output(std::ostream &os) const{
    os << "Name: " << this->name << std::endl;
    os << "Beschreibung: " << this->beschreibung << std::endl;
}
