//
// Created by Alex on 10/3/2017.
//
#include "ArrayLib.h"
#include <iostream>


//Non-recursive


int genRandInt(int min, int max, int& numLinesRun){
    numLinesRun += 4;
    if(max < min){
        std::cout << "Error! Min cannot be greater than Max." << std::endl;
        numLinesRun += 1;
        return -1;
    }
    else{
        int randInt = min + rand() % (max-min+1);
        numLinesRun += 1;
        return randInt;
    }
}

int* genRandArray(int size, int min, int max, int& numLinesRun){
    numLinesRun += 5;
    if(min > max){
        int tempMin = min;
        min = max;
        max = tempMin;
        numLinesRun += 3;
    }
    numLinesRun += 2;
    int* randArray = new int[size];
    for(int i = 0; i < size; i++){
        randArray[i] = genRandInt(min,max,numLinesRun);
        numLinesRun += 1;
    }
    return randArray;
}

int* genShuffledArray(int size, int& numLinesRun){
    numLinesRun += 3;
    if(size < 1){
        return nullptr;
    }

    int* shuffledArray = new int[size]{0};
    numLinesRun += 2;
    for(int i = 0; i < size; i++){
        shuffledArray[i] = 0;
        numLinesRun += 1;
    }
    numLinesRun += 1;
    for(int i = 0; i < size; i++){
        int position = genRandInt(0,size-1, numLinesRun);
        numLinesRun += 2;
        //gen random position, go 0 through size-1
        while(shuffledArray[position] != 0) {
            //if position is taken, find another
            position = genRandInt(0, size-1, numLinesRun);
            numLinesRun += 1;
        }
        shuffledArray[position] = (i+1);
        numLinesRun += 1;
        //set the value for that position
    }


    return shuffledArray;
}

int* copyArray(const int* arrayToCopy, const int size, int& numLinesRun){
    int* newArrayCopy = new int[size];
    numLinesRun += 5;
    for(int i = 0; i < size; i++){
        numLinesRun += 1;
        newArrayCopy[i] = arrayToCopy[i];
    }
    return newArrayCopy;
}

//Uses Selection Sort
void sort(int* arrayToSort, int size, int& numLinesRun){
    numLinesRun += 4;
    for(int j = 0; j < size; j++){
        //loops through the positions
        numLinesRun += 2;
        int minVal = arrayToSort[j];
        for(int i = j; i < size; i++){
            //starts at i=j so that it doesn't go back into the already-sorted section
            //only looks through unsorted section
            numLinesRun += 1;
            if(arrayToSort[i] < minVal){
                //swaps the lowest value with the value at the j position
                numLinesRun += 5;
                minVal = arrayToSort[i];
                int minIndex = i;
                int tempSwap = arrayToSort[j];
                arrayToSort[minIndex] = tempSwap;
                arrayToSort[j] = minVal;
            }
        }

    }
}


//Recursive Implementations


//helper function for the toString function
//tail recursion
std::string toString(const int* const arrayPtr, const int size, const std::string stringSoFar) {
    //base case
    if(size < 1){
        return stringSoFar;
    }else {
        std::string newString;
        //if last element in the array, then don't add an additional comma+space
        if (size == 1) {
            std::string addString = std::to_string(*arrayPtr);
            newString = stringSoFar + addString;
        }
            //add a comma+space
        else {
            std::string addString = std::to_string(*arrayPtr) + ", ";
            newString = stringSoFar + addString;
        }
        //recursive call
        std::string buildString = toString(arrayPtr + 1, size - 1, newString);
        return buildString;
    }
}
//main toString function (stub)
std::string toString(const int* const arrayPtr, const int size){
    //return empty set if size 0
    if(size < 1){
        return "{}";
    }
        //builds the string between the two curly braces
    else{
        return "{" + toString(arrayPtr,size,"") + "}";
    }
}

//helper function for the findMaxIndex function
//tail recursion
int findMaxIndex(const int* const arrayPtr, const int size, const int maxIndex, int& numLinesRun) {
    //base case
    numLinesRun += 5;
    if(size <= 0){
        return maxIndex;
    }
        //recursive call + comparison
    else{
        //updates maxIndex if greater than/equal to (because it loops backwards through array)
        numLinesRun += 1;
        if(arrayPtr[size-1] >= arrayPtr[maxIndex]){
            int newMaxIndex = size-1;
            numLinesRun +=1;
            return findMaxIndex(arrayPtr,size-1,newMaxIndex,numLinesRun);
        }
        else{
            return findMaxIndex(arrayPtr,size-1,maxIndex,numLinesRun);
        }
    }
}

//main findMaxIndex function (stub)
int findMaxIndex(const int* const arrayPtr, const int size, int& numLinesRun) {
    numLinesRun += 4;
    if (size < 1) {
        return -1;
    }
    else {
        return findMaxIndex(arrayPtr, size, 0, numLinesRun);
    }
}

//helper function for find function
//tail recursion
int find(const int* const arrayPtr, int size, const int numToFind, const int matchIndex, int& numLinesRun) {
    //base case
    numLinesRun += 6;
    if (size <= 0){
        return matchIndex;
    }
        //recursive call + comparisons
    else{
        numLinesRun += 1;
        if(arrayPtr[size-1] == numToFind){
            int newMatchIndex = size-1;
            numLinesRun += 1;
            return find(arrayPtr,size-1,numToFind,newMatchIndex,numLinesRun);
        }
        else{
            return find(arrayPtr,size-1,numToFind,matchIndex,numLinesRun);
        }
    }
}

//main find (stub)
int find(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun){
    numLinesRun += 5;
    if(size < 1){
        return -1;
    }
    else{
        return find(arrayPtr,size,numToFind,-1,numLinesRun);
    }
}

//helper function for findLast function
//tail recursion
int findLast(const int* const arrayPtr, const int size, const int numToFind, const int matchIndex, int& numLinesRun){
    numLinesRun += 6;
    //base case
    if(size <= 0){
        return matchIndex;
    }
        //recursive call + comparison
    else{
        numLinesRun += 1;
        if(arrayPtr[size-1] == numToFind){
            numLinesRun += 1;
            int newMatchIndex = size-1;
            return newMatchIndex;
        }
        else{
            return findLast(arrayPtr,size-1,numToFind,matchIndex,numLinesRun);
        }
    }
}

//main findLast (stub)
int findLast(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun){
    numLinesRun += 5;
    if(size < 1){
        return -1;
    }
    else{
        return findLast(arrayPtr,size,numToFind,-1,numLinesRun);
    }
}

//main binFind
//non-tail recursion
int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun){
    numLinesRun += 5;
    //base case
    if(size < 1){
        return -1;
    }
    else {
        //this variable isn't super necessary, but it helps stack tracing
        int midIndex = size / 2;

        //if it's middle value, return index
        numLinesRun += 4;
        if (arrayPtr[midIndex] == numToFind) {
            return midIndex;
        }
        //if the number is less than middle value, recursive call on lower half
        else if (numToFind < arrayPtr[midIndex]) {
            numLinesRun += 1;
            int index = binFind(arrayPtr, size / 2, numToFind, numLinesRun);
            return index;
        }
            //if the number is larger than middle value, recursive call on upper half
        else if (numToFind > arrayPtr[midIndex]) {
            numLinesRun += 1;
            int index;
            //if even size, it has to change the array size to be correct
            numLinesRun += 1;
            if (size % 2 == 0) {
                numLinesRun += 1;
                index = binFind(arrayPtr + size / 2 + 1, size / 2 - 1, numToFind, numLinesRun);
            }
                //if odd size, proceed as usual
            else {
                numLinesRun += 1;
                index = binFind(arrayPtr + size / 2 + 1, size / 2, numToFind, numLinesRun);
            }
            //if the number was not found, then continue returning -1
            numLinesRun += 1;
            if (index == -1) {
                return index;
            }
                //if the number was found, perform math on the original index to get true index
            else {
                numLinesRun += 1;
                index = index + size / 2 + 1;
                return index;
            }
        }
    }
}

int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun){
    //checks for two arrays of size 0
    numLinesRun += 6;
    if(size1+size2 < 1){
        return nullptr;
    }
    //create a new array to hold the merge values
    int* arrayToReturn = new int[size1+size2];
    int pos1 = 0;
    int pos2 = 0;
    numLinesRun += 4;
    for (int i = 0; i < size1 + size2; i++) {
        numLinesRun += 4;
        //checks both are within the bounds of respective array
        if(pos2 < size2 && pos1 < size1) {
            //moves along the index of the array with lesser value
            if (a1[pos1] < a2[pos2]) {
                arrayToReturn[i] = a1[pos1];
                pos1++;
                numLinesRun+= 2;
            } else if (a1[pos1] > a2[pos2]) {
                arrayToReturn[i] = a2[pos2];
                pos2++;
                numLinesRun += 2;
            } //if values are equal, I choose to do the first array and continue through loop
            else if (a1[pos1] == a2[pos2]) {
                arrayToReturn[i] = a1[pos1];
                pos1++;
                numLinesRun += 2;
            }
            //if one array is out of bounds, finish with values of other array
        }else if(pos2 < size2 && pos1 >= size1){
            arrayToReturn[i] = a2[pos2];
            pos2++;
            numLinesRun += 2;
        }else if(pos1 < size1 && pos2 >= size2){
            arrayToReturn[i] = a1[pos1];
            pos1++;
            numLinesRun += 2;
        }else{
            return arrayToReturn;
        }
    }
    return arrayToReturn;
}

int* mergeSort(const int* arrayToSort, int size, int& numLinesRun){
    numLinesRun += 5;
    //checks for empty array
    if(size < 1){
        return nullptr;
    }
    //if size == 1, then send back a copy of array
    else if(size == 1){
        int* arrayCopy = copyArray(arrayToSort,size,numLinesRun);
        numLinesRun += 1;
        return arrayCopy;
    }
    else{
        int midIndex = size / 2;
        int* lowerArray = mergeSort(arrayToSort,size/2,numLinesRun);
        int* upperArray;
        int* mergedArray;
        numLinesRun += 5;
        //has to do it one way for even arrays
        if(size % 2 == 0){
            //breaks apart and merges in order smaller arrays
            upperArray = mergeSort(arrayToSort + midIndex, size/2, numLinesRun);
            mergedArray = merge(lowerArray,size/2,upperArray,size/2,numLinesRun);
            numLinesRun += 2;
        }//other way for odd arrays
        else {
            upperArray = mergeSort(arrayToSort + midIndex, size / 2 + 1, numLinesRun);
            mergedArray = merge(lowerArray,size/2,upperArray,size/2+1,numLinesRun);
            numLinesRun += 2;
        }
        //cleanup
        delete[] lowerArray;
        lowerArray = nullptr;
        delete[] upperArray;
        upperArray = nullptr;
        numLinesRun += 4;
        return mergedArray;
    }
}

