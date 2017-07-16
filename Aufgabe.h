//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#ifndef PROG2_10_AUFGABE_H
#define PROG2_10_AUFGABE_H


#include "Projektbestandteil.h"

class Aufgabe : public Projektbestandteil {
public:
    Aufgabe(const std::string &name, const std::string &beschreibung, double aufwand);
    double getAufwand() const{
        return this->aufwand;
    }
    virtual double costs(double costs) const;

private:
    void setAufwand(double aufwand);
    double aufwand = 0;
    virtual void output(std::ostream& os) const;
};


#endif //PROG2_10_AUFGABE_H
