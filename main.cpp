#include "Identifier.h"
#include "Personnummer.h"
#include "Samordningsnummer.h"
#include "Organisationsnummer.h"

NumberType identifierHelper (std::string number);
NumberType orgTest(std::string input);
NumberType ageTest(std::string number);
NumberType SamTest(std::string number);

int main() {
    std::ifstream inputFile("input3.txt");
    std::string line;
    NumberType type;
    std::vector<std::pair<NumberType, std::string>> personPairs;
    std::vector<std::pair<NumberType, std::string>> samPairs;
    std::vector<std::pair<NumberType, std::string>> orgPairs;
    

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            type = identifierHelper(line);
            if(type == personnummer ||  type == old || type == over100 || type == notOld)
                personPairs.emplace_back(type, line);
            else if (type == samordningsnummer)
                samPairs.emplace_back(type, line);
            else if (type == organisationsnummer)
                orgPairs.emplace_back(type, line);
        }
        inputFile.close();
        }
    else
        std::cerr << "Kunde inte öppna filen." << std::endl;

    line = "";
    type = unknown;
    std::cout<<"Personnummer:\n";
    while(!personPairs.empty()){
        std::pair<NumberType, std::string> ppair = personPairs.back();
        personPairs.pop_back();
        std::cout<<ppair.second<<" ";
        Personnummer p(ppair.second, ppair.first);
    }
    std::cout<<"Samordningsnummer:\n";
    while(!samPairs.empty()){
        std::pair<NumberType, std::string> spair = samPairs.back();
        samPairs.pop_back();
        std::cout<<spair.second<<" ";
        Samordningsnummer s(spair.second, spair.first);
    }
    std::cout<<"Organisationsnummer:\n";
    while(!orgPairs.empty()){
        std::pair<NumberType, std::string> opair = orgPairs.back();
        orgPairs.pop_back();
        std::cout<<opair.second<<" ";
        Organisationsnummer o(opair.second, opair.first);
    }
    
    /*
    std::ifstream inputFile("input.txt");
    std::ifstream inputFile2("input2.txt");
    std::ifstream inputFile3("input3.txt");
    std::ifstream inputFile4("input4.txt");
    std::string line;

    std::cout<<"Personnummer:\n";
    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            std::cout<<line<<" ";
            NumberType age = ageTest(line);
            Personnummer p(line, age);
        }
        inputFile.close();
        }
    else
        std::cerr << "Kunde inte öppna filen." << std::endl;
    
    std::cout << "Nästa fil." << std::endl;
    
    if (inputFile2.is_open()) {
        while (getline(inputFile2, line)) {
            std::cout<<line<<" ";
            NumberType age = ageTest(line);
            Personnummer p(line, age);
        }
        inputFile2.close();
        }
    else
        std::cerr << "Kunde inte öppna filen." << std::endl;
    
    std::cout << "Nästa fil." << std::endl;

    std::cout<<"Samordningsnummer:\n";
    if (inputFile3.is_open()) {
        std::cout << "Samordningsnummer " << line << ": ";
        while (getline(inputFile3, line)) {
            std::cout<<line<<" ";
            NumberType type = samordningsnummer;
            Samordningsnummer s(line, type);
        }
        inputFile3.close();
        }
    else
        std::cerr << "Kunde inte öppna filen." << std::endl;
    
    std::cout << "Nästa fil." << std::endl;

    std::cout<<"Organisationsnummer:\n";
    if (inputFile4.is_open()) {
        while (getline(inputFile4, line)) {
            std::cout<<line<<" ";
            NumberType type = organisationsnummer;
            Organisationsnummer o(line, type);
        }
        inputFile4.close();
    }
    else
        std::cerr << "Kunde inte öppna filen." << std::endl;
    */
    
}

NumberType orgTest(std::string input){
    int middleDigits = std::stoi(input.substr(2, 2));
    if(std::stoi(input.substr(0, 2)) == 16 && input.length() == 12){
        return NumberType::organisationsnummer;
    }
    else if ((input[0] > '1' || input[0] < '9') && middleDigits > 20 && input.length() == 10)
        return NumberType::organisationsnummer;
    else
        return NumberType::unknown;
}

NumberType ageTest(std::string number){
    if (number.find('+') != std::string::npos) {
        return NumberType::over100;
    }
    else if (number.length() == 13){
        if(std::stoi(number.substr(0, 2)) == 18)
            return NumberType::over100;
        else if(std::stoi(number.substr(0, 2)) == 19)
            return NumberType::old;
        else
            return NumberType::notOld;
    }
    else
        return NumberType::unknown;
}

NumberType SamTest(std::string number){
    std::string days_str = number.substr(number.length() - 6, 2);
    int day = std::stoi(days_str);  
    if (day >= 61 && day <= 91)
        return NumberType::samordningsnummer;
    else
        return NumberType::unknown;
}

NumberType identifierHelper (std::string number){
    
    NumberType type = NumberType::unknown;
    type = ageTest(number);
    if(type != NumberType::unknown){
        return type;
    }else
        type = orgTest(number);
    if (type != NumberType::unknown){
        return type;
    }else
        type = SamTest(number);
    if(type != NumberType::unknown){
        return type;
    }else
        return NumberType::personnummer;
}