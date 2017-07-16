//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#ifndef PROG2_10_PROJEKT_H
#define PROG2_10_PROJEKT_H


#include <array>
#include "Projektbestandteil.h"

class Projekt : public Projektbestandteil{
public:
    Projekt(const std::string& name, const std::string& beschreibung, const double& stundensatz);
    double getStundensatz() const {
        return this->stundensatz;
    }
    void add(Projektbestandteil* teil);
    void del(std::string name);
    virtual ~Projekt();
    virtual double costs(double costs) const;

private:
    void setStundensatz(double x);
    double stundensatz = 0;
    int count = 0;
    void refill(int i);
    std::array<Projektbestandteil*, 1000> array;
    virtual void output(std::ostream& os) const;
};


#endif //PROG2_10_PROJEKT_H
