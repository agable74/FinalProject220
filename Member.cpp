//
// Created by Pravesh Patel on 12/11/17.
//

#include <iostream>
#include "Member.h"


People::People(std::string nameIn, std::string emailIn, int phoneNumIn) {
    name = nameIn;
    cardNumber = People:: GenerateNum();
    email = emailIn;
    phoneNumber = phoneNumIn;
    preference = Getpreference();
    //email and phone number and contact preference
}
int People::GetphoneNumber() {
    return phoneNumber;
}

std:: string People::Getpreference() {

    std::cout<<"Which would you prefer we use to contact you?"<<std::endl;
    std::cout<<" 1) Email \n 2) Phone Call \n 3) Text"<< std::endl;
    std::string pref;
    std::cin >> pref;
    if (pref == std::to_string(1)){

        preference = " Preference: email";
    }
    else if (pref == std::to_string(2)){

        preference = "Preference: phone";
    }
    else{

        preference = "Preference: text";
    }
    return preference;
}

std::string People::Getemail() {
    return email;
}

float People::GetNum() {
    return cardNumber;
}

std::string People::GetName() {
    return name;
}

std:: string People:: toString() {

    std:: string idNum = std::to_string(cardNumber);
    std:: string phoneNum = std::to_string(phoneNumber);
    return name +":" + idNum + "\n" + email + "\n" + phoneNum;
}

float People::GenerateNum() {
    cardNumber = rand()% 1004356327 + 1000000000;
    return cardNumber;
}


