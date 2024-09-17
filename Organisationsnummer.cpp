#include "Organisationsnummer.h"

Organisationsnummer::Organisationsnummer(std::string number, NumberType type) : Identifier(number,type) {validate(number,type);}

bool Organisationsnummer::validate(std::string& input, NumberType type) const{
    // Length check, the valid lengths are 10, 11, 12, 13
    size_t length = input.length();
    if (!(length == 10 || length == 11 || length == 12 || length == 13)) {
        std::cout << "Ogiltigt : Längd" << std::endl;
        return false;
    }
    
    // For lengths 11 and 13, remove special characters at positions 6 and 8 respectively
    if (length == 11)
        input.erase(6, 1);
    else if (length == 13){
        input.erase(8, 1);
    }

    //Let's ensure it's only numbers
    if (!(std::all_of(input.begin(), input.end(), ::isdigit))) {
        std::cout << "Ogiltigt: tecken" << std::endl;
        return false;
    }

    // Adjust 12-digit numbers to 10-digit numbers by removing the first two digits 
    if (input.length() == 12) {
        input = input.substr(2); // Remove the first two characters
    }

    // Check if the control digit is correct
    if (!luhnCheck(input)) {
        std::cout << "Ogiltigt: kontrollsiffra" << std::endl;
        return false;
    }

    std::cout << "Giltigt" << std::endl;
    return true;
}