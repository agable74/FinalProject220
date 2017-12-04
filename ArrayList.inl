//
// Created by Alex on 10/10/2017.
//

template <class T>
void ArrayList<T>::doubleCapacity(){
    currCapacity = 2 * currCapacity;
    T* newArray = new T[currCapacity];
    for(int i = 0; i < currItemCount; i++){
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}
template <class T>
ArrayList<T>::ArrayList(int initialCapacity){
     array = new T[initialCapacity];
     currItemCount = 0;
     currCapacity = initialCapacity;
 }



//Copy Constructor
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& arrayListToCopy){
    currItemCount = arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;
    array = new T[currCapacity];
    for(int i = 0; i < currItemCount; i++){
        array[i] = arrayListToCopy.array[i];
    }
}

//Overloaded Assignment Operator
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arrayListToCopy){
    if(this != &arrayListToCopy){
        delete[] array;
        currItemCount = arrayListToCopy.currItemCount;
        currCapacity = arrayListToCopy.currCapacity;
        array = new T[currCapacity];
        for(int i = 0; i < currItemCount; i++){
            array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}

//Destructor - MUST EDIT FOR CLASSES
template <class T>
ArrayList<T>::~ArrayList(){
    delete[] array;
    array = nullptr;
}

/**
 * appends the new item to the end of the list
 * @param itemToAdd the item to add to the end of the array
 * @post the list has an additional value in it, at the end
 */
template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd){
    if(currItemCount >= currCapacity){
        doubleCapacity();
    }
    array[currItemCount] = itemToAdd;
    currItemCount += 1;
}

/**
 * appends the new item to the beginning of the list
 * @param itemToAdd the item to add to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd){
    if(currItemCount >= currCapacity){
        doubleCapacity();
    }
    currItemCount += 1;
    for(int i = currItemCount-1; i > -1; i--){
        array[i+1] = array[i];
    }
    array[0] = itemToAdd;
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
void ArrayList<T>::insertAt(T itemToAdd, int index){

    if(index < 0 || index > currItemCount){
        throw std::out_of_range("<Error: Index out of range>");
    }
    else {
        currItemCount += 1;
        if (currItemCount >= currCapacity) {
            doubleCapacity();
        }
        for (int i = currItemCount - 1; i > index - 1; i--) {
            array[i + 1] = array[i];
        }
        array[index] = itemToAdd;
    }
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
template <class T>
T ArrayList<T>::getValueAt(int index){
    if(index < 0 || index > currItemCount-1){
        throw std::out_of_range("<Error: Index out of range>");
    }
    else {
        return array[index];
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
T ArrayList<T>::removeValueAt(int index){
    if(index < 0 || index > currItemCount-1){
        throw std::out_of_range("<Error: Index out of range>");
    }
    else{
        T valToReturn = array[index];
        for(int i = index; i < currItemCount; i++){
            array[i] = array[i+1];
        }
        currItemCount--;
        return valToReturn;
    }
}

/**
 * checks if there are any valid items in the list
 * @returns true if there are no valid items in the list, false otherwise
 */
template <class T>
bool ArrayList<T>::isEmpty(){
    if(currItemCount < 1){
        return true;
    }else{
        return false;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
template <class T>
int ArrayList<T>::itemCount(){
    return currItemCount;
}

/**
 * removes all valid items from the list, -MODIFY FOR CLASSES-
 * @post the list is completely clear of valid items
 */
template <class T>
void ArrayList<T>::clearList(){
    currItemCount = 0;
}


template <class T>
std::string ArrayList<Book>::toString(const Book* const arrayPtr, const int size, const std::string stringSoFar) {
    //base case
    if(size < 1){
        return stringSoFar;
    }else {
        std::string newString;
        //if last element in the array, then don't add an additional comma+space
        if (size == 1) {
            std::string addString = *arrayPtr->toString();
            newString = stringSoFar + addString;
        }
            //add a comma+space
        else {
            std::string addString = *arrayPtr->toString() + ", ";
            newString = stringSoFar + addString;
        }
        //recursive call
        std::string buildString = toString(arrayPtr + 1, size - 1, newString);
        return buildString;
    }
}
//main toString function (stub)
template <class T>
std::string ArrayList<T>::toString(const T* const arrayPtr, const int size){
    //return empty set if size 0
    if(size < 1){
        return "{}";
    }
        //builds the string between the two curly braces
    else{
        return "{" + toString(arrayPtr,size,"") + "}";
    }
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
template <class T>
std::string ArrayList<T>::toString(){
    return toString(array,currItemCount);
}