#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
: Medium(initTitel)
, altersfreigabe(initAltersfreigabe)
, genre(initGenre)
{
}
DVD::~DVD()
{
}
void DVD::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Altersfreigabe: " << altersfreigabe << std::endl;
    out << "Genre: " << genre << std::endl;
}
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    Datum now;
    if (now - person.getGeburtsdatum() >= altersfreigabe * 12)
    {
        Medium::ausleihen(person, ausleihdatum);
        return true;
    }
    else
    {
        std::cout << "Person ist nicht alt genug für die DVD \"" << titel << "\"" << std::endl;
        return false;
    }
}