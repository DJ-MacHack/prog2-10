#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Test.h"
using namespace std;

/**
 * Splittet einen String bei einem bestimmten char
 * @param eingabe
 * @param sucher
 * @return ausgabe
 */
vector<string> split(string eingabe, char sucher) {
    vector<string> ausgabe;
    stringstream ss(eingabe); //string zu stream
    string token;
    string s(1, sucher);

    while (getline(ss, token, sucher)) {
        ausgabe.push_back(token);
        ausgabe.push_back(s);
    }
    ausgabe.pop_back(); //letzer string zu viel, deshalb muss es weg

    return ausgabe;
}

/**
 * Schreibt Credits in die Konsole
 * Liest credits.txt
 * Sucht das Auge von Tux und macht es rot und blinkend
 * Hintergrund schwarz
 * in Kommentaren Code für Windows
 */
void credits() {
    std::ifstream inFile ("credits.txt");
    std::string input = "";
    //inFile.open("credits.txt");
    if (inFile.is_open()) {
        while (getline (inFile,input)) {
            if(input.find("Q") != std::string::npos){   //Ausgabe von find wenn nichts gefunden wird
                std::vector<std::string> vector = split(input, 'Q');    //split
                int teile = vector.size();
                for(int i = 0; i < teile; i++){
                    if(vector.at(i)=="Q") {     //nur Q soll rot sein
//                        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(handle, FOREGROUND_RED);
                        cout << "\x1B[40m\x1B[5m\x1B[31m" + vector.at(i);
                    } else {
//                        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
//                                                        FOREGROUND_BLUE);
                        cout << "\x1B[0m\x1B[40m\x1B[37m"+vector.at(i);
                    }
                }
                cout << endl;
            } else {
//                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
//                                                FOREGROUND_BLUE);
                std::cout << "\x1B[40m\x1B[37m"+input << std::endl;
            }
        }       //Datei schließen
        cout << "\x1B[0m" <<endl;
        inFile.close();
    } else {
        cout << "Datei kann nicht geoeffnet werden!";
    }

}

/**
 * Main function
 * @return
 */
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
    credits();
}