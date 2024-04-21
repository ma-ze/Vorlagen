//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int iErste = 0;
    int iZweite = 0;
    //1.
    cout << "Hello! For this experiment we need two whole numbers. Please enter two numbers separated by one space:\n";
    string input;
    getline(cin, input);
    iErste =  stoi(input.substr(0, input.find(" ")));
    iZweite = stoi(input.substr(input.find(" ")));
    cout << "\n";
    cout << "You entered the following numbers...\n iErste: " + to_string(iErste) + " iZweite: " + to_string(iZweite) + "\n";
    cout << "\n";
    int iSumme = iErste + iZweite;
    int iQuotient = iErste/iZweite;
    cout << "iSumme:         " + to_string(iSumme) + "\n";
    cout << "iQuotient:      " + to_string(iQuotient) + "\n";
    //2.
    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;
    cout << "dSumme:         " + to_string(dSumme) + "\n";
    cout << "dQuotient:      " + to_string(dQuotient) + "\n";
    //3.
    double dSummeCast = (double)iErste + (double)iZweite;
    double dQuotientCast = (double)iErste / (double)iZweite;
    cout << "dSummeCast:     " + to_string(dSummeCast) + "\n";
    cout << "dQuotientCast:  " + to_string(dQuotientCast) + "\n";
    //4.
    cout << "\n";
    cout << "Okay. Next, please enter your first name:\n";
    string sVorname;
    getline(cin, sVorname);
    cout << "Now your family name:\n";
    string sNachname;
    getline(cin, sNachname);
    string sVornameName = sVorname + " " + sNachname;
    string sNameVorname = sNachname + ", " + sVorname;
    cout << "\n";
    cout << "Hello, " + sVornameName + ".\n";
    cout << sNameVorname + ", Nice to meet you!\n";
    cout << "\n";
    //5.
    {   //a)
        cout << "iFeld: ";
        int iFeld[2] = {1,2};
        cout << iFeld[0] << ", ";
        cout << iFeld[1] << "\n";
        //b)
        cout << "\n";
        cout << "spielfeld:\n";
        int spielfeld[2][3] = {{1,2,3},{4,5,6}};
        for(int i = 0; i<2; i++){
            for(int j = 0; j<3; j++){
                cout << spielfeld[i][j] << " ";
            }
            cout << "\n";
        }
        //c)
        cout << "\n";
        const int iZweite = 1;
        cout << "iZweite(inside block): ";
        cout << iZweite << "\n";
    }
    cout << "iZweite: ";
    cout << iZweite << "\n";
    cout << "\n";
    //6.
    char iName1 = sVorname[0], iName2 = sVorname[1];
    cout << "Now lets look at the first two letters of your first name. \"" << iName1 << "\" and \"" << iName2 << "\".\nASCII Values:\n";
    cout << (int)iName1 << " | " << (int)iName2 << "\n";
    //7.
    cout << "Positions in the alphabet:\n";
    cout << iName1%32 << " | " << iName2%32 << "\n";
    cout << "\n_________________________________________________\nBYE BYE!\n";
    // Hier folgt Ihr eigener Code
    
    return 0;
    
}
