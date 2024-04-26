//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
const double height_m = 555.7 + 1.70;
const double earthr_m = 6371.0;
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
    std::cout << "_________________________________________"; 
    std::cout << "\n\n\n\n\n"; 

    std::cout << "Wie weit entfernt ist der Horizont?\n";
    std::cout << "-----------------------------------\n"; 
    //cast a vector from the origin and from the vantage point
    //calc angle between them
    //if close to 90 degrees - thats the one!
    //calc length of the last vector
    //done bohne
    Vektor vecVantagePoint(0,earthr_m + height_m, 0);
    Vektor vecOrigin(0,earthr_m,0);
    Vektor vecSightline = vecVantagePoint.sub(vecOrigin);
    double angle_deg = 0;
    double sight_angle_deg = 0;
    double step_deg = 1;
    while(sight_angle_deg < 90)
    {   
        angle_deg += step_deg;
        double angle_rad = 1 * M_PI / 180;
        vecOrigin.rotiereUmZ(angle_rad);
        vecSightline = vecVantagePoint.sub(vecOrigin);
        sight_angle_deg = vecSightline.winkel(vecOrigin);
    }
    std::cout << "vecOrigin: \n";
    vecOrigin.ausgabe();
    std::cout << "vecSightline: \n";
    vecSightline.ausgabe();
    std::cout << "angle (deg): \n";
    std::cout << angle_deg;
    std::cout << "\n";
    std::cout << "sightline angle: " << sight_angle_deg << "\n";
    double distance = vecSightline.laenge();
    std::cout << "view dist: " << distance << "\n";    
    return 0;

}
