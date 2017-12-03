//
// Created by Alex on 12/3/2017.
//


LinkedList::LinkedList(){
    front = nullptr;
    end = nullptr;
    numElements = 0;
}
template <class T>
LinkedList::LinkedList(const LinkedList& listToCopy){
    front = nullptr;
    end = nullptr;
    numElements = 0;
    LinkedNode* newFront = listToCopy.front;
    while(newFront != listToCopy.end){
        T itemToCopy = newFront->getItem();
        insertAtEnd(itemToCopy);
        newFront = newFront->getNext();
    }
    if(newFront != nullptr) {
        T itemToCopy = newFront->getItem();
        insertAtEnd(itemToCopy);
    }
    newFront = nullptr;
}

//Destructor
LinkedList::~LinkedList(){
    clearList();
}

//Assignment Operator
LinkedList& LinkedList::operator= ( const LinkedList & listToCopy){
    if(this != &listToCopy){
        clearList();
        LinkedNode* newFront = listToCopy.front;
        while(newFront != listToCopy.end){
            int itemToCopy = newFront->getItem();
            insertAtEnd(itemToCopy);
            newFront = newFront->getNext();
        }
        if(newFront != nullptr) {
            int itemToCopy = newFront->getItem();
            insertAtEnd(itemToCopy);
        }
        newFront = nullptr;
    }
}

/**
 * appends the new item to the end of the list
 * @param itemToAdd the item to add to the end of the array
 * @post the list has an additional value in it, at the end
 */
void IntLinkedList::insertAtEnd(int itemToAdd) {
    LinkedNode *newNode = new LinkedNode(itemToAdd);
    if (front == nullptr) {
        front = newNode;
        end = newNode;
        numElements++;
    } else {
        end->setNext(newNode);
        end = newNode;
        numElements++;
    }
}

/**
 * appends the new item to the beginning of the list
 * @param itemToAdd the item to add to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
void IntLinkedList::insertAtFront(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        LinkedNode* tempFront = front;
        front = newNode;
        newNode->setNext(tempFront);
        tempFront = nullptr;
    }
    numElements++;
}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param itemToAdd the item to add
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
 */
void IntLinkedList::insertAt(int itemToAdd, int index) {
    LinkedNode *newNode = new LinkedNode(itemToAdd);
    if ((front == nullptr && end == nullptr && index > 0) || index > numElements || index < 0) {
        throw std::out_of_range("<Error: Index out of range>");
    }
    if (index == 0) {   //insert at front
        if (front == nullptr) {
            front = newNode;
            end = newNode;
        } else {
            LinkedNode* tempFront = front;
            front = newNode;
            newNode->setNext(tempFront);
            tempFront = nullptr;
        }
        numElements++;
    } else if (index == numElements) {  //insert at end
        end->setNext(newNode);
        end = newNode;
        numElements++;
    } else {    //insert anywhere else
        LinkedNode *previousNode = front;
        for (int i = 0; i < index-1; i++) {
            previousNode = previousNode->getNext();
        }
        LinkedNode *currentNode = previousNode->getNext();
        newNode->setNext(currentNode);
        previousNode->setNext(newNode);
        numElements++;
        previousNode = nullptr;
        currentNode = nullptr;
    }
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int IntLinkedList::getValueAt(int index) {
    // the list is empty
    if ((front == nullptr && end == nullptr) || index >= numElements || index < 0) {
        throw std::out_of_range("<Error: Index out of range>");
    }
    // the list has one item
    if (front == end) {
        int listItem = front->getItem();
        return listItem;
    }
        //the list has many items
    else {
        LinkedNode* currentNode = front;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->getNext();
        }
        int listItem = currentNode->getItem();
        return listItem;
    }
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int IntLinkedList::removeValueAt(int index){
    // the list is empty
    if((front == nullptr && end == nullptr) || index >= numElements || index < 0){
        throw std::out_of_range("<Error: Index out of range>");
    }

    //removing from the front
    if(index == 0){
        int listItem = front->getItem();
        if(numElements == 1){   //one item
            delete front;
            front = nullptr;
            end = nullptr;
        }
        else{
            LinkedNode* tempFront = front;
            front = front->getNext();
            delete tempFront;
            tempFront = nullptr;
        }
        numElements--;
        return listItem;
    }

    else{
        LinkedNode* previousNode = front;
        for(int i = 0; i < index - 1; i++){
            previousNode = previousNode->getNext();
        }
        LinkedNode* currentNode = previousNode->getNext();
        int listItem = currentNode->getItem();
        //checks if last item
        if(index == numElements-1){
            end = previousNode;
            previousNode->setNext(nullptr);
        }
        else{
            previousNode->setNext(currentNode->getNext());
        }
        delete currentNode;
        numElements--;
        currentNode = nullptr;
        previousNode = nullptr;
        return listItem;
    }
}


/**
 * checks if there are any valid items in the list
 * @returns true if there are no valid items in the list, false otherwise
 */
bool IntLinkedList::isEmpty(){
    return numElements == 0;
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
int IntLinkedList::itemCount(){
    return numElements;
}

/**
 * removes all valid items from the list
 * @post the list is completely clear of valid items
 */
void IntLinkedList::clearList(){
    while(front != nullptr){
        removeValueAt(0);
    }
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
std::string IntLinkedList::toString(){
    std::string stringToReturn = "{";
    if(front != nullptr) {
        LinkedNode *currentSpot = front;
        for (int i = 0; i < numElements; i++) {
            int listItem = currentSpot->getItem();
            stringToReturn += std::to_string(listItem);
            if (i != numElements - 1) {
                stringToReturn += ", ";
            }
            currentSpot = currentSpot->getNext();
        }
    }
    stringToReturn += "}";
    return stringToReturn;
}