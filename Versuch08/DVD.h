#ifndef DVD_H
#define DVD_H

#include "Medium.h"

class DVD : public Medium 
{
public:
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
    virtual ~DVD(void);

    void ausgabe(std::ostream& out) const override;
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    int altersfreigabe;
    std::string genre;
};

#endif // DVD_H