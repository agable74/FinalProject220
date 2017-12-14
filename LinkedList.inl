//
// Created by Alex on 12/3/2017.
//

template <class T>
LinkedList<T>::LinkedList(){
    front = nullptr;
    end = nullptr;
    numElements = 0;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& listToCopy){
    front = nullptr;
    end = nullptr;
    numElements = 0;
    LinkedNode<T>* newFront = listToCopy.front;
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
template <class T>
LinkedList<T>::~LinkedList(){
    clearList();
}

//Assignment Operator
template <class T>
LinkedList<T>& LinkedList<T>::operator= ( const LinkedList<T>& listToCopy){
    if(this != &listToCopy){
        clearList();
        LinkedNode<T>* newFront = listToCopy.front;
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
template <class T>
void LinkedList<T>::insertAtEnd(T itemToAdd) {
    LinkedNode<T> *newNode = new LinkedNode<T>(itemToAdd);
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
template <class T>
void LinkedList<T>::insertAtFront(T itemToAdd){
    LinkedNode<T>* newNode = new LinkedNode<T>(itemToAdd);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        LinkedNode<T>* tempFront = front;
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
template <class T>
void LinkedList<T>::insertAt(T itemToAdd, int index) {
    LinkedNode<T> *newNode = new LinkedNode<T>(itemToAdd);
    if ((front == nullptr && end == nullptr && index > 0) || index > numElements || index < 0) {
        throw std::out_of_range("<Error: Index out of range>");
    }
    if (index == 0) {   //insert at front
        if (front == nullptr) {
            front = newNode;
            end = newNode;
        } else {
            LinkedNode<T>* tempFront = front;
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
        LinkedNode<T> *previousNode = front;
        for (int i = 0; i < index-1; i++) {
            previousNode = previousNode->getNext();
        }
        LinkedNode<T> *currentNode = previousNode->getNext();
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
template <class T>
T LinkedList<T>::getValueAt(int index) {
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
        LinkedNode<T>* currentNode = front;
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
template <class T>
T LinkedList<T>::removeValueAt(int index){
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
            LinkedNode<T>* tempFront = front;
            front = front->getNext();
            delete tempFront;
            tempFront = nullptr;
        }
        numElements--;
        return listItem;
    }

    else{
        LinkedNode<T>* previousNode = front;
        for(int i = 0; i < index - 1; i++){
            previousNode = previousNode->getNext();
        }
        LinkedNode<T>* currentNode = previousNode->getNext();
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
     * Replaces the value at an index
     * @param index index to replace
     * @param newItem item to replace old item
     */
    template <class T>
    void replaceValueAt(int index, T newItem){
        //need to implement
    }


/**
 * checks if there are any valid items in the list
 * @returns true if there are no valid items in the list, false otherwise
 */
template <class T>
bool LinkedList<T>::isEmpty(){
    return numElements == 0;
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
template <class T>
int LinkedList<T>::itemCount(){
    return numElements;
}

/**
 * removes all valid items from the list
 * @post the list is completely clear of valid items
 */
template <class T>
void LinkedList<T>::clearList(){
    while(front != nullptr){
        removeValueAt(0);
    }
}

/**
 * removes all valid items from the list (deep)
 * @post the list os completely clear of valid items
 */
template <class T>
void LinkedList<T>::clearData(){
    //needs implementing
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
template <class T>
std::string LinkedList<T>::toString(){
    std::string stringToReturn = "{";
    if(front != nullptr) {
        LinkedNode<T> *currentSpot = front;
        for (int i = 0; i < numElements; i++) {
            T listItem = currentSpot->getItem();
            stringToReturn += listItem.toString();
            if (i != numElements - 1) {
                stringToReturn += ", ";
            }
            currentSpot = currentSpot->getNext();
        }
    }
    stringToReturn += "}";
    return stringToReturn;
}