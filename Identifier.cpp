#include "Identifier.h"

Identifier::Identifier() {}

Identifier::Identifier(std::string number, NumberType type): number(number), type(type){}

bool Identifier::luhnCheck(const std::string &input) const
{
    int sum = 0;
    bool alternate = true;

    for (int i = input.length() - 2; i >= 0; i--) {  // Skip the control digit at the end
        int n = input[i] - '0';
        if (alternate) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }
        sum += n;
        alternate = !alternate;
    }

    int lastChar = input.back() - '0';
    return ((10 - (sum % 10)) % 10 == lastChar);
}

