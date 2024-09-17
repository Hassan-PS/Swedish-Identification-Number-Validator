#include "Personnummer.h"

Personnummer::Personnummer(std::string& number, NumberType type) : Identifier(number,type) {
    if(Personnummer::validate(number,type)){
        if(Personnummer::validDate(number, type)){
            if(Identifier::luhnCheck(number)){
                std::cout << "Giltigt" << std::endl;
            }else{
                std::cout << "Ogiltigt: kontrollsiffra" << std::endl;

            }
        }
    }
}

bool Personnummer::validate(std::string& input, NumberType type) const
{
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

    return true;
}

bool Personnummer::validDate(const std::string& input, NumberType type) const{   
    int year = std::stoi(input.substr(0, 2));  // ÅÅ
    int month = std::stoi(input.substr(2, 2)); // MM
    int day = std::stoi(input.substr(4, 2));   // DD

    if (type == NumberType::over100) {
        year += 1800;
    }else if (type == NumberType::old)
        year += 1900;
    else if (type ==NumberType::notOld)
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
    if((day <= 0 || day > daysInMonth[month - 1] && type != NumberType::samordningsnummer)){
        std::cout << "Ogiltigt: fel dag given den månaden (Skottår)" << std::endl;
        return false;
    }
    return true;
}