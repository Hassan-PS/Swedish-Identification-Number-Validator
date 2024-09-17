//
// Created by Hassan Elghamri on 2021-07-16.
//

#ifndef CODE_SAMORDNINGSNUMMER_H
#define CODE_SAMORDNINGSNUMMER_H


#include "Personnummer.h"

class Samordningsnummer: public Personnummer{
protected:
    Samordningsnummer();
public:
    Samordningsnummer(std::string& number, NumberType type);
    bool validDate(const std::string& input, NumberType type) const override;
};


#endif //CODE_SAMORDNINGSNUMMER_H
