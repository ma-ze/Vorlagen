#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
: Medium(initTitel)
, datumAusgabe(initDatumAusgabe)
, sparte(initSparte)
{
}
Magazin::~Magazin()
{
}
void Magazin::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    std::cout << "Sparte: " << sparte << std::endl;
    std::cout << "Erscheinungsdatum: " << datumAusgabe << std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    // Only call parent ausleihen function if datumAusgabe is not in current month
    if (ausleihdatum - datumAusgabe > 1)
    {
        Medium::ausleihen(person, ausleihdatum);
        return true;
    }
    std::cout << "Das Magazin \"" << titel << "\" kann nicht ausgeliehen werden, da es erst diesen Monat erschienen ist." << std::endl;
    return false;
}
