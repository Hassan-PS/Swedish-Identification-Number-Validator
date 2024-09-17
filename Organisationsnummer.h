#ifndef CODE_ORGANISATIONSNUMMER_H
#define CODE_ORGANISATIONSNUMMER_H


#include "Identifier.h"

class Organisationsnummer: public Identifier{
protected:
    Organisationsnummer();
public:
    Organisationsnummer(std::string number, NumberType type);
    Organisationsnummer(std::string number);
    bool validate(std::string& input, NumberType type)const override;
};


#endif //CODE_ORGANISATIONSNUMMER_H
