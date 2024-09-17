//
// Created by Hassan Elghamri on 2021-07-16.
//

#ifndef CODE_PERSONNUMMER_H
#define CODE_PERSONNUMMER_H


#include "Identifier.h"

class Personnummer: public Identifier{
protected:
    Personnummer();
public:
    Personnummer(std::string& number, NumberType type);
    virtual bool validDate(const std::string& input, NumberType type) const;
    virtual bool validate(std::string& input, NumberType type)const override;
};


#endif //CODE_PERSONNUMMER_H
