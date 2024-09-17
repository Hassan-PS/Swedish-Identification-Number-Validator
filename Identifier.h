#ifndef CODE_IDENTIFIER_H
#define CODE_IDENTIFIER_H

#include "main.h"

class Identifier {
public:
    //static size_t sizeCount;
    Identifier(std::string number, NumberType type);
    virtual bool validate(std::string& input, NumberType type)const = 0;
    virtual bool luhnCheck(const std::string& input)const;

protected:
    std::string number;
    NumberType type;
    Identifier();
};


#endif //CODE_IDENTIFIER_H
