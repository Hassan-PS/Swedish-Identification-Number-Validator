#include "Samordningsnummer.h"

Samordningsnummer::Samordningsnummer(std::string& number, NumberType type) : Personnummer(number,type) {
    if(Personnummer::validate(number,type)){
        if(Samordningsnummer::validDate(number, type)){
            if(Identifier::luhnCheck(number)){
                std::cout << "Giltigt" << std::endl;
            }else{
                std::cout << "Ogiltigt: kontrollsiffra" << std::endl;

            }
        }
    }
}

bool Samordningsnummer::validDate(const std::string& input, NumberType type) const{    
    int year = std::stoi(input.substr(0, 2));  // ÅÅ
    int month = std::stoi(input.substr(2, 2)); // MM
    int day = std::stoi(input.substr(4, 2));   // DD

    if (type == NumberType::over100) {
        year += 1800;
    }else if (type == NumberType::old)
        year += 1900;
    else if (type ==NumberType::personnummer)
        year += 2000;

    if ((day <= 1 && day >= 31)||(day <= 61 && day >= 91)){
        std::cout << "Ogiltigt: dagnummer fel" << std::endl;
        return false;
    }

    if (month < 1 || month > 12) {
        std::cout << "Ogiltigt: Månadsnummer fel" << std::endl;
        return false;
    }

    //days in month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Leap year check
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }
    return true;
}