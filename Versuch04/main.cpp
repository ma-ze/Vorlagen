//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

int main()
{
    Vektor e1(1, 0, 0);
    Vektor e2(0, 1, 0);
    Vektor e3(0, 0, 1);
    Vektor testvektor(1,1,1);
    std::cout << "Einheitsvektoren:\n";
    e1.ausgabe();
    e2.ausgabe();
    e3.ausgabe();
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Winkel e1-e2: " << e1.winkel(e2) << "\n";
    std::cout << "Winkel e2-e3: " << e2.winkel(e3) << "\n";
    std::cout << "Winkel e3-e1: " << e1.winkel(e3) << "\n";
    std::cout << "\n";
    std::cout << "Testvektor:\n";
    testvektor.ausgabe();
    std::cout << "Laenge: " << testvektor.laenge() << "\n";
    std::cout << "Winkel zu e1: " << testvektor.winkel(e1) << "\n";
    std::cout << "Winkel zu e2: " << testvektor.winkel(e2) << "\n";
    std::cout << "Winkel zu e3: " << testvektor.winkel(e3) << "\n";
    std::cout << "Rotieren um pi (180grad):\n";
    testvektor.rotiereUmZ(M_PI);
    testvektor.ausgabe();
    std::cout << "neue winkel:\n";
    std::cout << "Winkel zu e1: " << testvektor.winkel(e1) << "\n";
    std::cout << "Winkel zu e2: " << testvektor.winkel(e2) << "\n";
    std::cout << "Winkel zu e3: " << testvektor.winkel(e3) << "\n";
    std::cout << "\n\n\n\n\n\n\n"; 
    return 0;

}
