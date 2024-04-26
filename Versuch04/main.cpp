//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
const double height_m = 555.7 + 1.70;
const double earthr_m = 6371000.0;
const double step_deg = 0.000001;
const double step_rad = step_deg * M_PI / 180;
int main()
{
    const Vektor e1(1, 0, 0);
    const Vektor e2(0, 1, 0);
    const Vektor e3(0, 0, 1);
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
    std::cout << "_________________________________________"; 
    std::cout << "\n\n\n\n\n";

    //2. Aufgabenteil
    std::cout << "Wie weit entfernt ist der Horizont?\n";
    std::cout << "-----------------------------------\n"; 
    std::cout << std::fixed << std::setprecision(4);

    const Vektor vecVantagePoint(0,earthr_m + height_m, 0);
    Vektor vecOrigin(0,earthr_m,0);
    Vektor vecSightline = vecOrigin.sub(vecVantagePoint);
    double angle_deg = 0; //the angle of the vector from origin to earth surface (beta)
    double sight_angle_deg = vecOrigin.winkel(vecSightline); //the angle between the two vectors

    while(sight_angle_deg > 90)//at 90 degrees, the sighline becomes tangent to the earth circumference, meaning everything further away will be invisible
    {   
        vecOrigin.rotiereUmZ(step_rad);
        vecSightline = vecOrigin.sub(vecVantagePoint);
        sight_angle_deg = vecOrigin.winkel(vecSightline);
        angle_deg += step_deg;
        std::cout << "sightline angle: " << sight_angle_deg << "\n";
    }
    //backtrack 1 step so we don't overshoot
    vecOrigin.rotiereUmZ(-step_rad);
    vecSightline = vecOrigin.sub(vecVantagePoint);
    sight_angle_deg = vecOrigin.winkel(vecSightline);
    angle_deg += step_deg;
    //output the approximation
    std::cout << "sightline angle: " << sight_angle_deg << "\n";
    std::cout << "Sie können " << vecSightline.laenge()/1000 << " Km weit sehen.\n";
    std::cout << "Sie sind " << height_m << " m hoch.\n";
    std::cout << "Der Winkel beträgt " << angle_deg << " Grad.\n";
    std::cout << "Anzahl Schritte: " << (int)(angle_deg / step_deg) << "\n";
    
    return 0;
}