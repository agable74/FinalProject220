//
// Created by Alex on 12/3/2017.
//

#include "MemberLinkedNode.h"
MemberLinkedNode::MemberLinkedNode(Member* item){
    this->item = item;
    next = nullptr;
}

MemberLinkedNode::MemberLinkedNode(const MemberLinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}

Member* MemberLinkedNode::getItem(){
    return item;
}


MemberLinkedNode::~MemberLinkedNode(){
    //delete item;  //can't have the queue delete the item b/c it doesn't own the waitList of members
}

MemberLinkedNode* MemberLinkedNode::getNext(){
    return next;
}

void MemberLinkedNode::setItem(Member* newItem){
    item = newItem;
}

void MemberLinkedNode::setNext(MemberLinkedNode* newNext){
    next = newNext;
}
