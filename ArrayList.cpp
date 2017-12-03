//
// Created by Alex on 10/10/2017.
//
#include <iostream>
#include "ArrayLib.h"
#include "ArrayList.h"


void ArrayList::doubleCapacity(){
    currCapacity = 2 * currCapacity;
    int* newArray = new int[currCapacity];
    for(int i = 0; i < currItemCount; i++){
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

ArrayList::ArrayList(int initialCapacity){
     array = new int[initialCapacity];
     currItemCount = 0;
     currCapacity = initialCapacity;
 }



//Copy Constructor
ArrayList::ArrayList(const ArrayList& arrayListToCopy){
    currItemCount = arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;
    array = new int[currCapacity];
    for(int i = 0; i < currItemCount; i++){
        array[i] = arrayListToCopy.array[i];
    }
}

//Overloaded Assignment Operator
ArrayList& ArrayList::operator=(const ArrayList& arrayListToCopy){
    if(this != &arrayListToCopy){
        delete[] array;
        currItemCount = arrayListToCopy.currItemCount;
        currCapacity = arrayListToCopy.currCapacity;
        array = new int[currCapacity];
        for(int i = 0; i < currItemCount; i++){
            array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}

//Destructor
ArrayList::~ArrayList(){
    delete[] array;
    array = nullptr;
}

/**
 * appends the new item to the end of the list
 * @param itemToAdd the item to add to the end of the array
 * @post the list has an additional value in it, at the end
 */
void ArrayList::insertAtEnd(int itemToAdd){
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
void ArrayList::insertAtFront(int itemToAdd){
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
void ArrayList::insertAt(int itemToAdd, int index){

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
int ArrayList::getValueAt(int index){
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
int ArrayList::removeValueAt(int index){
    if(index < 0 || index > currItemCount-1){
        throw std::out_of_range("<Error: Index out of range>");
    }
    else{
        int valToReturn = array[index];
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
bool ArrayList::isEmpty(){
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
int ArrayList::itemCount(){
    return currItemCount;
}

/**
 * removes all valid items from the list
 * @post the list is completely clear of valid items
 */
void ArrayList::clearList(){
    currItemCount = 0;
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
std::string ArrayList::toString(){
    return ::toString(array,currItemCount);
}

/**
 * finds the largest value in the array
 * @post numLinesRun is updated to include lines run by this function
 * @return the first index of the maximum value, or -1 if size < 1
 */
int ArrayList::findMaxIndex(){
    int timer = 0;
    return ::findMaxIndex(array,currItemCount,timer);
}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int ArrayList::find(int numToFind){
    int timer = 0;
    return ::find(array,currItemCount,numToFind,timer);
}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int ArrayList::findLast(int numToFind){
    int timer = 0;
    return ::findLast(array,currItemCount,numToFind,timer);
}
