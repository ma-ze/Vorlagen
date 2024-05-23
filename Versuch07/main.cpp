#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Student.h"

std::ostream& operator<<( std::ostream& out, Student& student)
{
student.ausgabe(out);
return out;
}
void outputStudentList(std::vector<Student>& studentenListe)
{
    if(!studentenListe.empty())
    {
        std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
        for (auto it = studentenListe.begin(); it != studentenListe.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    else
    {
        std::cout << "Die Liste ist leer!\n\n";
    }
}
int main()
{
    std::vector<Student> studentenListe;
    Student student;
    
    char abfrage;
    /*
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');
    
    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wollnerstr.9");
        studentenListe.push_back(student);
    }
    */

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(5): Datenelement löschen" << std::endl
                  << "(6): Datenelement vorne hinzufuegen" << std::endl
                  << "(7): Datenelement hinten entfernen" << std::endl
                  << "(8): Daten aus Datei einlesen" << std::endl
                  << "(9): Daten in Datei speichern" << std::endl
                  << "(S): Daten sortieren" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        std::cout << student << std::endl;
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                outputStudentList(studentenListe);
                break;
            // Datenbank rueckwaerts ausgeben
            case '4':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
                    for (auto it = studentenListe.rbegin(); it != studentenListe.rend(); ++it)
                    {
                        std::cout << *it << std::endl;
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;
                // Datenelement löschen
            case '5':
                if(!studentenListe.empty())
                {
                    unsigned int matNr = 0;
                    std::cout << "Matrikelnr. des zu löschenden Eintrags eingeben:";
                    std::cin >> matNr;
                    auto it = std::find_if(studentenListe.begin(), studentenListe.end(), [matNr](const Student& s) {
                        return s.getMatNr() == matNr;
                    });
                    if(it != studentenListe.end()){
                        student = *it;
                        std::cout << "Der folgende Eintrag wurde gelöscht:" << std::endl;
                        std::cout << student << std::endl;
                        studentenListe.erase(it);
                        std::cout << "Übrige Einträge:" << std::endl;
                        outputStudentList(studentenListe);
                    }
                    else
                    {
                        std::cout << "Eintrag mit Matrikelnummer " << matNr << " nicht gefunden!" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;
            // Datenelement vorne hinzufuegen
            case '6':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.insert(studentenListe.begin(), student);
                }
                break;
            // Datenelement hinten entfernen
            case '7':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.back();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        std::cout << student << std::endl;
                        studentenListe.pop_back();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;
            // Daten aus Datei einlesen
            case '8':
            {
                std::string filename;
                std::cout << "Bitte geben Sie den Dateinamen ein: ";
                std::cin >> filename;

                // Liste leeren
                studentenListe.clear();

                // Datei öffnen
                std::ifstream file(filename);
                if (file.is_open())
                {
                    std::string line;
                    while (std::getline(file, line))
                    {
                        if(line.empty() || line == "\n" || line == "\r" || line == "\r\n")
                            continue;
                        unsigned int matNr;
                        std::string name;
                        std::string geburtstag;
                        std::string adresse;
                        std::cout << "line: " << line << std::endl;
                        // Matrikelnummer einlesen
                        matNr = std::stoi(line);

                        // Name einlesen
                        std::getline(file, name);

                        // Geburtsdatum einlesen
                        std::getline(file, geburtstag);

                        // Adresse einlesen
                        std::getline(file, adresse);

                        // Neuen Studenten erstellen und zur Liste hinzufügen
                        student = Student(matNr, name, geburtstag, adresse);
                        studentenListe.push_back(student);
                    }

                    file.close();
                    std::cout << "Daten aus Datei erfolgreich eingelesen." << std::endl;
                }
                else
                {
                    std::cout << "Fehler beim Öffnen der Datei." << std::endl;
                }
            }
            break;
            // Daten in Datei speichern
            case '9':
            {
                std::string filename;
                std::cout << "Bitte geben Sie den Dateinamen ein: ";
                std::cin >> filename;

                // Datei öffnen
                std::ofstream file(filename);
                if (file.is_open())
                {
                    // Studentendaten in Datei schreiben
                    for (const auto& student : studentenListe)
                    {
                        file << student.getMatNr() << std::endl;
                        file << student.getName() << std::endl;
                        file << student.getGeburtstag() << std::endl;
                        file << student.getAdresse() << std::endl;
                    }

                    file.close();
                    std::cout << "Daten erfolgreich in Datei gespeichert." << std::endl;
                }
                else
                {
                    std::cout << "Fehler beim Öffnen der Datei." << std::endl;
                }
            }
            break;
            case 'S':
                std::sort(studentenListe.begin(), studentenListe.end(), [](const Student& s1, const Student& s2) {
                    return s1.getMatNr() < s2.getMatNr();
                });
                break;
            // Beenden
            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
