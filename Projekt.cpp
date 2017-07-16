//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include "Projekt.h"
using namespace std;

/**
 * Default Constructor
 * @param name
 * @param beschreibung
 * @param stundensatz
 */
Projekt::Projekt(const string& name, const string& beschreibung, const double& stundensatz) : Projektbestandteil(name, beschreibung) {
    setStundensatz(stundensatz);
}

/**
 * Sets hours
 * @param x
 */
void Projekt::setStundensatz(double x) {
    if (x > 0){
        this->stundensatz = x;
    } else
    {
        throw logic_error("Stundensatz > 0 Euro!");
    }
}

/**
 * Adds anouther part to the project
 * @param teil
 */
void Projekt::add(Projektbestandteil *teil) {
    if(this->count < array.max_size()){
        array[this->count] = teil;
        this->count++;
    } else {
        throw length_error("Array has max size: 1000");
    }
}

/**
 * deletes parts
 * @param name
 */
void Projekt::del(string name) {
    bool deleted = false;
    for(int i = 0; i < this->count; i++){
        if(array[i]->getName() == name){
            delete(array[i]);
            array[i] = nullptr;
            refill(i);
            count--;
            deleted = true;
        }
    }
    if(!deleted){
        throw invalid_argument("Name nicht gefunden!");
    }
}

/**
 * makes the array clean again
 * @param i
 */
void Projekt::refill(int i) {
    int size = this->count;
    for(int m = i; m < size-1; m++){
        array[m] = array[m+1];
    }
}

/**
 * destructor
 */
Projekt::~Projekt() {
    for(int i = 0; i < this->count; i++){
        delete(array[i]);
    }
}

/**
 * calculates costs
 * @param costs
 * @return
 */
double Projekt::costs(double costs) const {
    double kosten = 0;
    for(int i = 0; i < this->count; i++){
        kosten += array.at(i)->costs(this->getStundensatz());
    }
    return kosten;
}

/**
 * cout
 * @param os
 */
void Projekt::output(std::ostream &os) const {
    Projektbestandteil::output(os);
    os << "Stundensatz: " << this->stundensatz << endl;
    os << "Unterprojekte: " << endl;
    for(int i = 0; i < this->count; i++){
        os << *array.at(i) << endl;
    }
    os << "Kosten gesamt: " << costs(this->stundensatz) << endl;
    os << "Unterprojekte von " << this->getName() << " Ende" << endl;
}
