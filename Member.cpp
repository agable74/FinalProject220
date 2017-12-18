//
// Created by Ben on 12/9/2017.
//

#include "Member.h"
#include <iostream>

std::string addLastName() {
    bool badName = true;
    std::string nameUpper;
    while (badName) {
        std::string nameLastIn;
        std::cout << "Member's last name?: ";
        std::cin >> nameLastIn;
        nameUpper = "";
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
        } else if (yesNo[0] == 'y') {
            std::cout << "Last name confirmed.\n";
            badName = false;
        } else {
            std::cout << "Okay, re-enter member's last name.\n";
        }
    }
    return nameUpper;
}

std::string addFirstName() {
    bool badName = true;
    std::string nameUpper;
    while (badName) {
        std::string nameFirstIn;
        std::cout << "Member's first name?: ";
        std::cin >> nameFirstIn;
        nameUpper = "";
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
        } else if (yesNo[0] == 'y') {
            std::cout << "First name confirmed.\n\n";
            badName = false;
        } else {
            std::cout << "Okay, re-enter member's First name.\n";
        }
    }
    std::string nameIn = nameUpper + " " + addLastName();
    std::cout << "Member name is " << nameIn << ".\n\n";
    return nameIn;
}

long checkIfLong(std::string& stringToCheck){
    bool isValidNum = true;
    for(int i = 0; i < stringToCheck.length(); i++){
        if(!isdigit(stringToCheck[i])){
            isValidNum = false;
        }
    }
    while(!isValidNum){
        isValidNum = true;
        std::cout << "Error in your number. Please enter a valid number: ";
        std::cin >> stringToCheck;
        for(int i = 0; i < stringToCheck.length(); i++){
            if(!isdigit(stringToCheck[i])){
                isValidNum = false;
            }
        }
    }
    long validNum = std::stol(stringToCheck);
    return validNum;
}

long addPhoneNumber() {
    std::string tempPhone = "";
    std::cout << "Member phone number?: ";
    std::cin >> tempPhone;
    return checkIfLong(tempPhone);
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
    name = addFirstName();
    phoneNumber = addPhoneNumber();
    email = addEmail();
    id = generateId();
    contactPref = setContactPref();
}

Member::Member(std::string nameIn, long phoneNumberIn, std::string emailIn, std::string idIn, std::string contactPrefIn) {
    name = nameIn;
    phoneNumber = phoneNumberIn;
    email = emailIn;
    if (idIn == "")
        id = generateId();
    else
        id = idIn;
    if (contactPrefIn == "")
        contactPref = setContactPref();
    else
        contactPref = setContactPref(contactPrefIn);
}

Member::Member(const Member& memberToCopy) {
    name = memberToCopy.name;
    phoneNumber = memberToCopy.phoneNumber;
    email = memberToCopy.email;
    id = memberToCopy.id;
    contactPref = memberToCopy.contactPref;
}

Member& Member::operator=(const Member& memberToCopy) {
    if (this != &memberToCopy) {
        name = memberToCopy.name;
        phoneNumber = memberToCopy.phoneNumber;
        email = memberToCopy.email;
        id = memberToCopy.id;
        contactPref = memberToCopy.contactPref;
    }
    return *this;
}

Member::~Member() {}

std::string Member::getName() {
    return name;
}

std::string Member::getId() {
    return id;
}

long Member::getPhoneNumber() {
    return phoneNumber;
}

std::string Member::getEmail() {
    return email;
}

std::string Member::setContactPref(std::string cPref) {
    std::string choice = "";
    std::string choiceIn;
    std::string contPref;
    if (cPref != "") {
        choice += toupper(cPref[0]);
        if (choice == "C" || choice == "P")
            contPref = "Phone call";
        else if (choice == "T")
            contPref = "Text message";
        else if (choice == "E")
            contPref = "Email";
        else
            setContactPref("");
    }
    else {
        std::cout << "Select a preference [Call, Text, or Email]: ";
        std::cin >> choiceIn;
        choice += tolower(choiceIn[0]);
        if (choice == "c" || choice == "t" || choice == "e") {
            if (choice == "c") {
                std::cout << "Contact by phone registered.\n\n";
                contPref = "Phone call";
            } else if (choice == "t") {
                std::cout << "Contact by text registered.\n\n";
                contPref = "Text message";
            } else if (choice == "e") {
                std::cout << "Contact by email registered.\n\n";
                contPref = "Email";
            }
        } else {
            std::cout << "\nInput not accepted. Please try again.\n";
            setContactPref();
        }
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

std::string Member::toString() {
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