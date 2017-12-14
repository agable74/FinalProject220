//
// Created by Alex on 11/30/2017.
//

#ifndef FINALPROJECT_LIST_H
#define FINALPROJECT_LIST_H
template <class T>
class List {
public:
    //Destructor
    virtual ~List(){};

    /**
     * appends the new item to the end of the list
     * @param itemToAdd the item to add to the end of the array
     * @post the list has an additional value in it, at the end
     */
    virtual void insertAtEnd(T itemToAdd)=0;

    /**
     * appends the new item to the beginning of the list
     * @param itemToAdd the item to add to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    virtual void insertAtFront(T itemToAdd)=0;

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param itemToAdd the item to add
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
     */
    virtual void insertAt(T itemToAdd, int index)=0;

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    virtual T getValueAt(int index)=0;

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    virtual T removeValueAt(int index)=0;

    /**
     * replaces the item at the index in the list with new item
     * @param index location of thing to replace
     * @param newItem thing to replace with
     */
    virtual void replaceValueAt(int index, T newItem)=0;

    /**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
    virtual bool isEmpty()=0;

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    virtual int itemCount()=0;

    /**
     * removes all valid items from the list (shallow)
     * @post the list is completely clear of valid items
     */
    virtual void clearList()=0;

    /**
     * removes all valid items from the list (deep)
     * @post the list os completely clear of valid items
     */
    virtual void clearData()=0;

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    virtual std::string toString()=0;
};

#endif //FINALPROJECT_LIST_H
