//
// Created by DJ_MacHack on 11.07.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include "Test.h"
#include "Produkt.h"
#include "Aufgabe.h"

using namespace std;

Test::Test() {
    newProject();
}

void Test::addProject(Projekt* pro) {
    string name, beschreibung = "";
    double stunden = 0;
    cout << "Name fuer Projekt" << endl;
    cin >> name;
    cout << "Beschreibung" << endl;
    cin >> beschreibung;
    cout << "Stundensatz in Euro" << endl;
    cin >> stunden;
    Projekt* neu = new Projekt(name, beschreibung, stunden);
    pro->add(neu);
    start(neu);
}

void Test::addProduct(Projekt* pro) {
    string name, beschreibung = "";
    double kosten = 0;
    cout << "Name fuer Produkt" << endl;
    cin >> name;
    cout << "Beschreibung" << endl;
    cin >> beschreibung;
    cout << "Kosten" << endl;
    cin >> kosten;
    Produkt* neu = new Produkt(name, beschreibung, kosten);
    pro->add(neu);
}

void Test::addTask(Projekt* pro) {
    string name, beschreibung = "";
    double stunden = 0;
    cout << "Name fuer Aufgabe" << endl;
    cin >> name;
    cout << "Beschreibung" << endl;
    cin >> beschreibung;
    cout << "Stunden" << endl;
    cin >> stunden;
    Aufgabe* neu = new Aufgabe(name, beschreibung, stunden);
    pro->add(neu);
}

void Test::del(Projekt* pro) {
    cout << "Was soll geloescht werden?" << endl;
    string name = "";
    cin >> name;
    pro->del(name);
}

void Test::print() {
    cout << *this->pro << endl;
}

void Test::newProject() {
    string name, beschreibung = "";
    double stunden = 0;
    cout << "Name fuer Projekt" << endl;
    cin >> name;
    cout << "Beschreibung" << endl;
    cin >> beschreibung;
    cout << "Stundensatz" << endl;
    cin >> stunden;
    Projekt* neu = new Projekt(name, beschreibung, stunden);
    this->pro = neu;
}

void Test::start() {
    start(this->pro);
}

void Test::start(Projekt* projekt) {
    FunktionsTyp funktion = WEITER;
    do {
        try {
            cout << "Projekt " << projekt->getName() << endl;
            funktion = einlesenFunktion();
            ausfuehrenFunktion(funktion, projekt);
        } catch (const string &e) {
            cout << "Ausnahme: " << e << endl;
        } catch (exception& e) {
            cout << e.what() << endl;
        }
        catch (...) {
            cout << "Unbekannter Fehler Ausfuehren!" << endl;
        }

    } while (funktion != ENDE);
}

Test::FunktionsTyp Test::einlesenFunktion() {
    cout << ADDPROJECT << ": Projekt anlegen; "
         << ADDPRODUCT << ": Produkt einfuegen; "
         << ADDTASK << ": Aufgabe einfuegen; "
         << DELETE << ": etwas loeschen; "
         << PRINT << ": auf Konsole ausgeben; "
         << ENDE << ": Projekt bearbeiten beenden -> ";
    int funktion;
    if (cin) {
        cin >> funktion;
        cout << endl;
        return static_cast<FunktionsTyp>(funktion);
    } else {
        cout << "cin error" << endl;
        return ENDE;
    }
}

void Test::ausfuehrenFunktion(Test::FunktionsTyp funktion, Projekt* pro) {
    switch (funktion) {
        case ADDPRODUCT:
            addProduct(pro);
            break;
        case ADDPROJECT:
            addProject(pro);
            break;
        case ADDTASK:
            addTask(pro);
            break;
        case DELETE:
            del(pro);
            break;
        case PRINT:
            print();
            break;
        case ENDE:
            print();
            break;
        default:
            print();
            break;
    }
}
