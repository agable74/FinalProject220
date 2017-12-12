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
    Member(std::string nameIn, long long phoneNumberIn, std::string emailIn);
    /**
     * Copy Constructor
     * @param memberToCopy
     */
    Member(const Member& memberToCopy);
    /**
     * Assignment Operator
     */
    Member&operator=(const Member& memberToCopy);

    std::string getName();
    std::string getId();
    long long getPhoneNumber();
    std::string getEmail();
    std::string setContactPref();
    std::string getContactPref();
    std::string memberInfo();


};

#endif //FINALPROJECT_MEMBER_H