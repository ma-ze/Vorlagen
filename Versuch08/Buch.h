#ifndef BUCH_H
#define BUCH_H

#include "Medium.h"

class Buch : public Medium 
{
public:
    Buch(std::string initTitel, std::string initAuthor);
    virtual ~Buch(void);

    // Override the ausgabe() method to include the author
    void ausgabe(std::ostream& out) const override;

private:
    std::string author;

};
#endif // BUCH_H