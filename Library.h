//
// Created by Alex on 11/30/2017.
//

#ifndef FINALPROJECT_LIBRARY_H
#define FINALPROJECT_LIBRARY_H

#include "Member.h"
#include "Book.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "ArrayList.h"

class Library{
private:
    //pointer to list of library members
    //ArrayList<Member*> memberList;
    //fstream parts
    std::ifstream libMembersIN;
    std::ofstream libMembersOUT;
    //pointer to list of books owned by library
    List<Book*>* allBooks;
    //fstream parts
    std::ifstream allBooksIN;
    std::ofstream allBooksOUT;
    //pointer to list of books in library
    std::ifstream requestBooksIN;
    std::ofstream requestBooksOUT;
    List<Book*>* shelfBooks;
    //list of people waiting for book
    List<Member*>* members;
    List<Book*>* requestBooks;
    bool runUIBool;
    bool runMasterBool;
    std::string bookListTxt;
    std::string memberListTxt;
    std::string deliveryTxt;

public:
    /**
     * Constructor
     */
    Library(const std::string& allBooksTxtIN, const std::string& memberListTxtIN,const std::string& deliveryTxtIN);

    /**
     * Generates the list of books from the file
     * @param fileToGenerate
     * @return list of books
     */
    void generateAllBookList();

    /**
     * Generates the list of books on the shelf from allBooks list
     * @return list of shelf books
     */
    void generateShelfBookList();

    /**
     * Generates the list of library members from the file
     * @post sets the list of library members
     */
    void generateMemberList();

    /**
     * Saves the list of books to a file
     */
    void saveBooksToFile();

    /**
     * Saves the list of members to a file
     */
    void saveMembersToFile();

    /**
     * Saves the request list of books to a file
     */
    void saveDeliveryRequestToFile();

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
     * @post member added to memberList
     */
    void addMember();

    /**
     * Adds already-created member to member list
     * @param memberToAdd
     */
    void addMember(Member& memberToAdd);

    /**
     * Save the inventory and wait lists in a file and terminate execution.
     */
    void quit();

    /**
     * Sorts the book list alphabetically
     */
    void sortBookList();

    /**
     * adds a book to allBooks
     * @param titleToAdd
     * @param numToAdd
     */
    void addBook(std::string titleToAdd, int numToAdd);

    void addBook(Book& bookToAdd);

    /**
     * Moves a book from the outBooks list to the inBooks list
     * @param bookToReturn
     */
    void returnBook(std::string titleToReturn);

    /**
     * Puts a request in for book to be delivered
     * @param desiredBook
     */
    void requestLoan(std::string desiredBookTitle);

    /**
     * Removes a book from the library due to loss/damage
     * @param bookToRemove
     */
    void removeBook(std::string bookToRemove, int numRemove);

    /**
     * Prints a summary of all available commands
     */
    void libraryHelp();

    /**
     * Print all information for the book
     * @param bookToInquire
     */
    void inquireAboutBook(std::string bookToInquire);

    /**
     * Performs a delivery, increasing haveTotal and haveShelf for already owned books
     * adds books to library which aren't already there
     * @param deliveryFileName
     */
    void bookDelivery(const std::string& deliveryFileName);

    void printAllOwnedBooks();

    void checkOutBook(std::string bookToCheckOut);

    void masterRun();

    bool runUI();


};
#endif //FINALPROJECT_LIBRARY_H
