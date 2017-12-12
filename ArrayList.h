//
// Created by Alex on 11/30/2017.
//

#ifndef FINALPROJECT_ARRAYLIST_H
#define FINALPROJECT_ARRAYLIST_H

#include "List.h"

template <class T>
class ArrayList : public List<T> {
private:
    //pointer to the start of the array
    T* array;
    //count of the number of valid items currently stored in the array
    int currItemCount;
    //size of the current array
    int currCapacity;

    /**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     *  O(N)
     */
    void doubleCapacity();

public:
    /**
     * Constructor
     * creates an arrayList
     * @param: initialCapacity (the starting size of the array, defaults to size 5
     * O(1)
     */
    ArrayList(int initialCapacity=5);

    /**
     * Copy Constructor
     * @param arrayListToCopy
     * O(N)
     */
    ArrayList(const ArrayList& arrayListToCopy);

    //Overloaded Assignment Operator
    ArrayList& operator=(const ArrayList& arrayListToCopy);

    //Destructor
    ~ArrayList();

    /**
     * appends the new item to the end of the list
     * @param itemToAdd the item to add to the end of the array
     * @post the list has an additional value in it, at the end
     * O(1)
     */
    void insertAtEnd(T itemToAdd);

    /**
     * appends the new item to the beginning of the list
     * @param itemToAdd the item to add to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     *    O(N)
     */
    void insertAtFront(T itemToAdd);

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param itemToAdd the item to add
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
     * O(N)
     */
    void insertAt(T itemToAdd, int index);

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     * O(1)
     */
    T getValueAt(int index);

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     * O(N)
     */
    T removeValueAt(int index);

    /**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     * O(1)
     */
    bool isEmpty();

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     * O(1)
     */
    int itemCount();

    /**
     * removes all valid items from the list
     * @post the list is completely clear of valid items
     * O(n)
     */
    void clearData();

    /**
     * sets all pointers to nullptrs
     */
    void clearPointers();

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     * O(N)
     */
    std::string toString();
};

#include "ArrayList.inl"
#endif //FINALPROJECT_ARRAYLIST_H
