//
// Created by Alex on 12/16/2017.
//

#ifndef FINALPROJECT_LINKEDQUEUE_H
#define FINALPROJECT_LINKEDQUEUE_H
#include <string>
#include <stdexcept>
#include "LinkedNode.h
#include "Member.h"

/**
 * Represents a FIFO data structure (First In First Out). Picture a line
 * to wait for something (first person in is the first person out)
 */
class MemberLinkedQueue {
private:
    LinkedNode<Member*>* front;
    LinkedNode<Member*>* end;

public:

    //Creates an empty queue
    MemberLinkedQueue();

    //Copy Constructor
    MemberLinkedQueue(const MemberLinkedQueue& queueToCopy);

    //Destructor
    ~MemberLinkedQueue();

    //Equals operator
    MemberLinkedQueue& operator=(const MemberLinkedQueue& memberQueueToCopy);

    //adds an item to the end of the queue
    void enqueue(Member* item);

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    Member* dequeue();

    //returns true if the queue has no items, false otherwise
    bool isEmpty();

};
#endif //FINALPROJECT_LINKEDQUEUE_H
