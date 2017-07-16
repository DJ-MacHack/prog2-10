#include <iostream>
#include "Test.h"
using namespace std;
int main() {
    try {
        Test test;
        test.start();
    }
    catch (const string &e) {
        cout << "Ausnahme: " << e << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "Unbekannter Fehler Ausfuehren!" << endl;
    }
}