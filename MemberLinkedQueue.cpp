//
// Created by Alex on 12/16/2017.
//

#include "MemberLinkedQueue.h"

//Creates an empty queue
MemberLinkedQueue::MemberLinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
MemberLinkedQueue::MemberLinkedQueue(const MemberLinkedQueue& queueToCopy){
    front = nullptr;
    end = nullptr;
    LinkedNode<Member*>* newFront = queueToCopy.front;
    while(newFront != queueToCopy.end){
        Member* itemToCopy = new Member(*newFront->getItem());
        enqueue(itemToCopy);
        newFront = newFront->getNext();
    }
    if(newFront != nullptr) {
        Member* itemToCopy = new Member(*newFront->getItem());
        enqueue(itemToCopy);
    }
    newFront = nullptr;

}

//Destructor
MemberLinkedQueue::~MemberLinkedQueue(){
    while(front != nullptr){
        dequeue();  //the dequeue doesn't delete what's at the end of the pointers. these queues don't own the memory so that's good
    }
}

MemberLinkedQueue& MemberLinkedQueue::operator=(const MemberLinkedQueue& memberQueueToCopy){
    if(this!=&memberQueueToCopy){
        while(front != nullptr){
            dequeue();
        }
        front = nullptr;
        end = nullptr;
        LinkedNode<Member*>* newFront = memberQueueToCopy.front;
        while(newFront != memberQueueToCopy.end){
            Member* itemToCopy = new Member(*newFront->getItem());
            enqueue(itemToCopy);
            newFront = newFront->getNext();
        }
        if(newFront != nullptr) {
            Member* itemToCopy = new Member(*newFront->getItem());
            enqueue(itemToCopy);
        }
        newFront = nullptr;
    }
}

//adds an item to the end of the queue
void MemberLinkedQueue::enqueue(Member* item){
    LinkedNode<Member*>* newNode = new LinkedNode<Member*>(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
Member* MemberLinkedQueue::dequeue(){
    // the queue is empty
    if(front == nullptr && end == nullptr){
        throw std::out_of_range("<Error: Index out of range>");
    }
        // the queue has one item
    else if(front == end){
        Member* queueItem = front->getItem();
        delete front;
        front = nullptr;
        end = nullptr;
        return queueItem;
    }
    // the queue has many items
    LinkedNode<Member*>* tempFront = front;
    Member* queueItem = front->getItem();
    front = front->getNext();
    delete tempFront;
    tempFront = nullptr;
    return queueItem;
}

//returns true if the queue has no items, false otherwise
bool MemberLinkedQueue::isEmpty(){
    return front == nullptr;
}
