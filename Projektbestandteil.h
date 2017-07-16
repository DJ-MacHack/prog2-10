//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#ifndef PROG2_10_PROJEKTBESTANDTEIL_H
#define PROG2_10_PROJEKTBESTANDTEIL_H
#include<iostream>

class Projektbestandteil {
public:
    Projektbestandteil(const std::string& name, const std::string& beschreibung);
    virtual std::string getName() const;
    virtual std::string getBeschreibung() const;
    friend std::ostream &operator<<(std::ostream &os, const Projektbestandteil &projektbestandteil);
    virtual void output(std::ostream& os) const;
    virtual double costs(double costs) const = 0;
    virtual ~Projektbestandteil();

private:
    virtual void setName(std::string name);
    virtual void setBeschreibung(std::string beschreibung);
    std::string name, beschreibung = "";

};


#endif //PROG2_10_PROJEKTBESTANDTEIL_H
