//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#ifndef PROG2_10_TEST_H
#define PROG2_10_TEST_H


#include "Projekt.h"

class Test {
    enum FunktionsTyp {WEITER, ADDPROJECT, ADDPRODUCT, ADDTASK,
        DELETE, PRINT, ENDE = 9};
public:
    Test();

    void addProject(Projekt* pro);
    void addProduct(Projekt* pro);
    void addTask(Projekt* pro);
    void del(Projekt* pro);
    void print();
    void start(Projekt* pro);
    void start();
    FunktionsTyp einlesenFunktion();
    void ausfuehrenFunktion(FunktionsTyp funktion, Projekt* pro);

private:
    void newProject();
    Projekt* pro;

};


#endif //PROG2_10_TEST_H
