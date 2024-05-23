#include "Buch.h"

Buch::Buch(std::string initTitel, std::string initAuthor)
: Medium(initTitel)
, author(initAuthor)
{
}
Buch::~Buch()
{
}
void Buch::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Autor: " << author << std::endl;
}