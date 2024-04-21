/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

struct Person{
    string sNachname, sVorname;
    int iGeburtsjahr, iAlter;
};
ostream& operator <<(ostream& os, const Person& person) {
    return os   << "First name:    " << person.sVorname << endl
                << "Last name:     " << person.sNachname << endl
                << "Year of birth: " << person.iGeburtsjahr << endl
                << "Age:           " << person.iAlter << endl;
}

int main()
{
    Person nBenutzer;
    cout << "last name?\n";
    getline(cin, nBenutzer.sNachname);
    cout << "first name?\n";
    getline(cin, nBenutzer.sVorname);
    cout << "year of birth?\n";
    string input;
    getline(cin, input);
    nBenutzer.iGeburtsjahr = stoi(input);
    cout << "how old?\n";
    getline(cin, input);
    nBenutzer.iAlter = stoi(input);
    cout << "\n";
    cout << "You have entered the following information: ";
    cout << nBenutzer.sVorname + " " + nBenutzer.sNachname + ", ";
    cout << "born " << nBenutzer.iGeburtsjahr << ", ";
    cout << "age: " << nBenutzer.iAlter << "\n";
    
    cout << "\n";
    Person nKopieEinzeln, nKopieGesamt;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;
    
    cout << "\n";
    cout << nKopieEinzeln;
    
    nKopieGesamt = nBenutzer;
    cout << "\n";
    cout << nKopieGesamt;
    return 0;
    
}
