//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#ifndef PROG2_10_PRODUKT_H
#define PROG2_10_PRODUKT_H


#include "Projektbestandteil.h"

class Produkt : public Projektbestandteil {
public:
    Produkt(const std::string &name, const std::string &beschreibung, const double& kosten);
    double getKosten() const {
        return this->kosten;
    }

private:
    void setKosten(double kosten);
    double kosten = 0;
    virtual void output(std::ostream& os) const;
};


#endif //PROG2_10_PRODUKT_H
