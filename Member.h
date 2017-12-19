//
// Created by Ben on 12/4/2017.
// Member holds onto information about the members
//

#ifndef FINALPROJECT_MEMBER_H
#define FINALPROJECT_MEMBER_H

#include <string>

class Member {

private:

    std::string name;
    std::string id;
    long phoneNumber;
    std::string email;
    std::string contactPref;
    std::string generateId();


public:

    // default constructor
    Member();
    // constructor
    Member(std::string nameIn, long phoneNumberIn, std::string emailIn, std::string idIn="", std::string contactPrefIn="");
    // copy constructor
    Member(const Member& memberToCopy);
    // destructor
    ~Member();
    // equals operator
    Member&operator=(const Member& memberToCopy);
    // returns member's name
    std::string getName();
    // returns member's ID
    std::string getId();
    // returns member's Phone number
    long getPhoneNumber();
    // returns member's email
    std::string getEmail();
    /**
     * sets the Member's contact preference (call, text, or email)
     * @param cPref: parameter defaultly set so method is called, though will not
     * ask new Member for preference if cPref is an appropriate string value
     * @return member's contact preference
     */
    std::string setContactPref(std::string cPref="");
    // returns member's contact preference (call, text, or email)
    std::string getContactPref();
    // returns Member's name, phone number, email, id, and contact preference
    // each on separate lines
    std::string toString();

};

#endif //FINALPROJECT_MEMBER_H