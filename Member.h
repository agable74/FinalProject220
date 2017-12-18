//
// Created by Ben on 12/4/2017.
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

    /**
     * Default Constructor
     */
    Member();
    /**
     * Constructor
     */
    Member(std::string nameIn, long phoneNumberIn, std::string emailIn, std::string idIn="", std::string contactPrefIn="");
    /**
     * Copy Constructor
     * @param memberToCopy
     */
    Member(const Member& memberToCopy);

    ~Member();

    /**
     * Assignment Operator
     */
    Member&operator=(const Member& memberToCopy);

    std::string getName();
    std::string getId();
    long getPhoneNumber();
    std::string getEmail();
    std::string setContactPref(std::string cPref="");
    std::string getContactPref();
    std::string toString();

};

#endif //FINALPROJECT_MEMBER_H