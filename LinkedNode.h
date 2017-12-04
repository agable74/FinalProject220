//
// Created by Alex on 11/30/2017.
//

#ifndef FINALPROJECT_LINKEDNODE_H
#define FINALPROJECT_LINKEDNODE_H

#include <string>
template <class T>
class LinkedNode {

private:
    T item;
    LinkedNode* next;

public:
    LinkedNode(T item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    ~LinkedNode();
    T getItem();
    LinkedNode* getNext();
    void setItem(T newItem);
    void setNext(LinkedNode* newNext);
};

#include "LinkedNode.inl"
#endif //FINALPROJECT_LINKEDNODE_H
