//
// Created by Ben on 12/9/2017.
//

#include "MemberB.h"
#include <iostream>

std::string addLastName() {
    std::string nameLastIn;
    std::cout << "Member's last name?: ";
    std::cin >> nameLastIn;
    std::string nameUpper = "";
    nameUpper += toupper(nameLastIn[0]);
    int i = 1;
    while (nameLastIn[i]) {
        nameUpper += nameLastIn[i];
        i++;
    }
    std::string yesNo;
    std::cout << "Is " << nameUpper << " correct? ";
    std::cin >> yesNo;
    if (yesNo[0] != 'y' && yesNo[0] != 'n') {
        std::cout << "Try again.\n";
        addLastName();
    }
    else {
        if (yesNo[0] == 'y') {
            std::cout << "Last name confirmed.\n";
        } else {
            std::cout << "Okay, re-enter member's last name.\n";
            addLastName();
        }
    }
    return nameUpper;
}

std::string addFirstName() {
    std::string nameFirstIn;
    std::cout << "Member's first name?: ";
    std::cin >> nameFirstIn;
    // convert input to cap'd version: abc -> Abc
    std::string nameUpper = "";
    nameUpper += toupper(nameFirstIn[0]);
    int i = 1;
    while (nameFirstIn[i]) {
        nameUpper += nameFirstIn[i];
        i++;
    }
    std::string yesNo;
    std::cout << "Is " << nameUpper << " correct? ";
    std::cin >> yesNo;
    if (yesNo[0] != 'y' && yesNo[0] != 'n') {
        std::cout << "Try again.\n";
        addFirstName();
    }
    else {
        if (yesNo[0] == 'y') {
            std::cout << "First name confirmed.\n\n";
        } else {
            std::cout << "Okay, re-enter member's first name.\n";
            addFirstName();
        }
    }
    std::string nameIn = nameUpper + " " + addLastName();
    std::cout << "Member name is " << nameIn << ".\n\n";
    return nameIn;
}

long long addPhoneNumber() {
    std::string tempPhone = "";
    std::cout << "Member phone number?: ";
    std::cin >> tempPhone;
    if (toascii(tempPhone[0]) < 48 || toascii(tempPhone[0]) > 57) {
        std::cout << "Invalid input. Please try again.\n\n";
        addPhoneNumber();
    }
    else {
        long long phoneNumberIn = std::stol(tempPhone);
        std::string yesNo;
        std::cout << "Is " << tempPhone << " correct? ";
        std::cin >> yesNo;
        if (yesNo[0] != 'y' && yesNo[0] != 'n') {
            std::cout << "Try again.\n";
            addPhoneNumber();
        } else {
            if (yesNo[0] == 'y') {
                std::cout << "Phone number confirmed.\n\n";
                return phoneNumberIn;
            } else {
                std::cout << "\nOkay, re-enter member phone number.\n";
                addPhoneNumber();
            }
        }
    }
}

std::string addEmail() {
    std::string emailIn;
    std::cout << "Member email?: ";
    std::cin >> emailIn;
    std::string yesNo;
    std::cout << "Is " << emailIn << " correct? ";
    std::cin >> yesNo;
    if (yesNo[0] != 'y' && yesNo[0] != 'n') {
        std::cout << "Try again.\n";
        addEmail();
    }
    else {
        if (yesNo[0] == 'y') {
            std::cout << "Email confirmed.\n\n";
        } else {
            std::cout << "Okay, re-enter member email.\n";
            addEmail();
        }
    }
    return emailIn;
}

Member::Member() {
    //createMember();
    name = addFirstName();
    phoneNumber = addPhoneNumber();
    email = addEmail();
    id = generateId();
    contactPref = setContactPref();
}

Member::Member(std::string nameIn, long long phoneNumberIn, std::string emailIn) {
    name = nameIn;
    phoneNumber = phoneNumberIn;
    email = emailIn;
    id = generateId();
    contactPref = setContactPref();
}

std::string Member::getName() {
    return name;
}

std::string Member::getId() {
    return id;
}

long long Member::getPhoneNumber() {
    return phoneNumber;
}

std::string Member::getEmail() {
    return email;
}

std::string Member::setContactPref() {
    std::string choice;
    std::cout << "Select a preference [Call, Text, or Email]: ";
    std::cin >> choice;
    std::string choiceIn = "";
    choiceIn += choice[0];
    std::string contPref;
    if (choiceIn == "c" || choiceIn == "t" || choiceIn == "e") {
        if (choiceIn == "c") {
            std::cout << "Contact by phone registered.\n\n";
            contPref = "Phone call";
        } else if (choiceIn == "t") {
            std::cout << "Contact by text registered.\n\n";
            contPref = "Text message";
        } else if (choiceIn == "e") {
            std::cout << "Contact by email registered.\n\n";
            contPref = "Email";
        }
    }
    else {
        std::cout << "\nInput not accepted. Please try again.\n";
        setContactPref();
    }
    return contPref;
}

std::string Member::getContactPref() {
    return contactPref;
}

std::string Member::generateId() {
    srand(time(NULL));
    char lastInit = ' ';
    int ind = 0;
    while (name[ind] != lastInit)
        ind++;
    lastInit = name[ind+1];
    std::string ltrNum;
    ltrNum += name[0];
    ltrNum += lastInit;
    int idNumRaw = abs(rand() * 3265797);
    std::string idNumStr = std::to_string(idNumRaw);
    std::string idNum = "";
    for (int i = 0; i < 7; i++)
        idNum += idNumStr[i];
    return ltrNum + idNum;
}

std::string Member::memberInfo() {
    if (phoneNumber) {
        std::string pStr = std::to_string(phoneNumber);
        std::string phoneOut = "";
        phoneOut += pStr[0]; phoneOut += pStr[1]; phoneOut += pStr[2];
        phoneOut += "-"; phoneOut += pStr[3]; phoneOut += pStr[4];
        phoneOut += pStr[5]; phoneOut += "-"; phoneOut += pStr[6];
        phoneOut += pStr[7]; phoneOut += pStr[8]; phoneOut += pStr[9];
        std::string printOut = "\nPatron name: " + name + "\nPhone number: " +
                phoneOut + "\nMember ID: " + id  + "\nEmail: " + email +
                "\nContact by: " + contactPref + "\n";
        return printOut;
    }
}