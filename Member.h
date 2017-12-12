//
// Created by Alex on 12/3/2017.
//

#ifndef FINALPROJECT_PEOPLE_H
#define FINALPROJECT_PEOPLE_H
#include <iostream>

class People{

private:
    //add email and contact preference (function)

    std::string name; //name of the member
    int cardNumber; //member's library card number
    std:: string email; // member's email
    int phoneNumber;
    std:: string preference;



public:

    People(std::string nameIn="", int cardNumberIn=-1, std::string emailIn="", int phoneNumIn=-1, std::string preferenceIn="");
    ~ People(); //default de-constructor
    int GetphoneNumber();
    int GetNum(); //returns member's number
    std::string Getpreference();
    std::string Getemail();
    std::string GetName(); // returns member's name
    std::string toString(); //returns name and number
    int GenerateNum(); //generates a number for the member

};
#endif //FINALPROJECT_PEOPLE_H
