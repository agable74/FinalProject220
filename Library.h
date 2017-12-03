//
// Created by Alex on 11/30/2017.
//

#ifndef FINALPROJECT_LIBRARY_H
#define FINALPROJECT_LIBRARY_H

#include "People.h"
#include "Book.h"
#include "List.h"
#include <iostream>
#include <fstream>

class Library{
private:
    //pointer to list of library members
    List<People> memberList;
    //fstream parts
    std::ifstream libMembersIN;
    std::ofstream libMembersOUT;
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
    //list of people waiting for book

public:
    /**
     * Constructor
     */
    Library(std::string inBooksTxt, std::string outBooksTxt, std::string memberListTxt);

    /**
     * Copy Constructor
     * @param libraryListToCopy
     */
    Library(const Library& libraryToCopy);


    /**
     * Assignment Operator
     * @param libraryListToCopy
     */
    Library& operator=(const Library& libraryToCopy);

    /**
     * Destructor
     */
    ~Library();

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

    /**
     * Puts a request in for book to be delivered
     * @param desiredBook
     */
    void requestLoan(Book desiredBook);

    /**
     * Removes a book from the library due to loss/damage
     * @param bookToRemove
     */
    void removeBook(Book bookToRemove);

    /**
     * Prints a summary of all available commands
     */
    void libraryHelp();

    /**
     * Print all information for the book
     * @param bookToInquire
     */
    void inquireAboutBook(Book bookToInquire);

    /**
     * Performs a delivery, increasing haveTotal and haveShelf for already owned books
     * adds books to library which aren't already there
     * @param deliveryFileName
     */
    void bookDelivery(std::string deliveryFileName);

};
#endif //FINALPROJECT_LIBRARY_H
