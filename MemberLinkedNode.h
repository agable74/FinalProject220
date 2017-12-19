//
// Created by Alex on 12/18/2017.
// Holds onto pointers to members, only for use with waitlist in Book.h
//

#ifndef FINALPROJECT_MEMBERLINKEDNODE_H
#define FINALPROJECT_MEMBERLINKEDNODE_H
#include <string>
#include "Member.h"

class MemberLinkedNode {

private:
    Member* item;
    MemberLinkedNode* next;

public:
    MemberLinkedNode(Member* item);
    MemberLinkedNode(const MemberLinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    ~MemberLinkedNode();
    Member* getItem();
    MemberLinkedNode* getNext();
    void setItem(Member* newItem);
    void setNext(MemberLinkedNode* newNext);
};
#endif //FINALPROJECT_MEMBERLINKEDNODE_H
