//
// Created by Alex on 12/3/2017.
//

#ifndef FINALPROJECT_PEOPLE_H
#define FINALPROJECT_PEOPLE_H
class People{

private:
    //add email and contact preference (function)

    std::string name; //name of the member
    float cardNumber; //member's library card number
    std:: string email; // member's email
    int phoneNumber;
    std:: string preference;



public:

    People(std::string nameIn, std::string emailIn, int phoneNumIn);
    ~ People(); //default de-constructor
    int GetphoneNumber();
    float GetNum(); //returns member's number
    std::string Getpreference();
    std::string Getemail();
    std::string GetName(); // returns member's name
    std::string toString(); //returns name and number
    float GenerateNum(); //generates a number for the member

};
#endif //FINALPROJECT_PEOPLE_H
