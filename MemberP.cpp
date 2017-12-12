//
// Created by Pravesh Patel on 12/11/17.
//

#include "MemberP.h"


Member::Member(std::string nameIn, int cardNumberIn, std::string emailIn, int phoneNumIn, std::string preferenceIn) {
    name = nameIn;
    if(cardNumberIn == -1) {
        cardNumber = Member::GenerateNum();
    }
    else{
        cardNumber = cardNumberIn;
    }
    email = emailIn;
    phoneNumber = phoneNumIn;
    if(preferenceIn == "") {
        preference = Getpreference();
    }
    else{
        preference = preferenceIn;
    }
    //email and phone number and contact preference
}
int Member::GetphoneNumber() {
    return phoneNumber;
}

std:: string Member::Getpreference() {

    std::cout<<"Which would you prefer we use to contact you?"<<std::endl;
    std::cout<<" 1) Email \n 2) Phone Call \n 3) Text"<< std::endl;
    std::string pref;
    std::cin >> pref;
    if (pref == std::to_string(1)){

        preference = "Preference: email";
    }
    else if (pref == std::to_string(2)){

        preference = "Preference: phone";
    }
    else{

        preference = "Preference: text";
    }
    return preference;
}

std::string Member::Getemail() {
    return email;
}

int Member::GetNum() {
    return cardNumber;
}

std::string Member::GetName() {
    return name;
}

std:: string Member:: toString() {

    std:: string idNum = std::to_string(cardNumber);
    std:: string phoneNum = std::to_string(phoneNumber);
    return name +":" + idNum + "\n" + email + "\n" + phoneNum;
}

int Member::GenerateNum() {
    cardNumber = rand()% 1004356327 + 1000000000;
    return cardNumber;
}


