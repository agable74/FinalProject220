//
// Created by Alex on 11/30/2017.
//

#ifndef FINALPROJECT_LIBRARY_H
#define FINALPROJECT_LIBRARY_H

#include "People.h"
#include "Book.h"
#include <iostream>
#include <fstream>

class Library{
private:
    //pointer to list of library members
    List<People> memberList;
    //pointer to list of books in library
    List<Book> inBooks;
    //fstream parts
    std::ifstream inBooksIN;
    std::ofstream inBooksOUT;
    //pointer to list of books checked out
    List<Book> outBooks;
    //fstream parts
    std::ifstream outBooksIN;
    std::ofstream outBooksOUT;

public:
    /**
     * Constructor
     */
    Library();

    /**
     * Copy Constructor
     * @param libraryListToCopy
     */
    Library(const Library& libraryListToCopy);


    /**
     * Copy Constructor
     * @param libraryListToCopy
     * @return
     */
    Library& operator=(const Library& libraryListToCopy);

    /**
     * Destructor
     */
    ~ArrayList();

    /**
     * Creates a new library member (Person) given prompts about information
     * Adds to the memberList
     * @return true if successful, false if unsuccessful
     */
    bool addMember();

    /**
     * Save the inventory and wait lists in a file and terminate execution.
     */
    void quit();

    /**
     * Adds book to inBooks list
     * @param bookToAdd
     */
    void addBook(Book bookToAdd);

    /**
     * Moves a book from the outBooks list to the inBooks list
     * @param bookToReturn
     */
    void returnBook(Book bookToReturn);
};
#endif //FINALPROJECT_LIBRARY_H
