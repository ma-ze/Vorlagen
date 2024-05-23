#ifndef MAGAZIN_H
#define MAGAZIN_H

#include "Medium.h"

class Magazin : public Medium 
{
public:
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
    virtual ~Magazin(void);

    void ausgabe(std::ostream& out) const override;
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    Datum datumAusgabe;
    std::string sparte;
};

#endif // MAGAZIN_H