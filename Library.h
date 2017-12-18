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
#include <sstream>

class Library{
private:
    //pointer to list of books owned by library
    List<Book*>* allBooks;
    //fstream parts
    std::ifstream allBooksIN;
    std::ofstream allBooksOUT;

    //pointer to list of books on shelf in library
    List<Book*>* shelfBooks;

    //pointer to list of members
    List<Member*>* memberList;
    //fstream parts
    std::ifstream libMembersIN;
    std::ofstream libMembersOUT;

    //list of books requested
    List<Book*>* requestBooks;
    //fstream parts
    //keeping ifstream as a local variable in the delivery method
    //using sstream as a local variable in the delivery method
    std::ofstream requestBooksOUT;

    //for running the program
    //runMaster determines when the program ends
    bool runMasterBool;
    //runUI determines when the library UI closes, can be restarted without restarting program
    bool runUIBool;


    //for use in methods
    std::string bookListTxt;
    std::string memberListTxt;
    std::string deliveryTxt;

public:
    /**
     * Constructor
     * @param allBooksTxtIN text file of list of all books owned by library
     * @param memberListTxtIN text file of list of all members to the library
     * @param deliveryTxtIN text file of deliveries
     */
    Library(const std::string& allBooksTxtIN, const std::string& memberListTxtIN,const std::string& deliveryTxtIN);

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
     * Generates the List allBooks from the text file
     * @post allBooks is filled with pointers to books
     */
    void generateAllBookList();

    /**
     * Generates the list of books on the shelf from allBooks list
     * @post shelfBooks populated with pointers to the books owned by allBooks
     * for any book with a nonzero book amount on shelf
     */
    void generateShelfBookList();

    /**
     * Generates the list of library members from the file
     * @post members is populated with pointers to members
     */
    void generateMemberList();

    /**
    * Sorts the book list alphabetically
    * Uses mergeSort
    */
    void sortBookList();

    /**
     * Saves the list allBooks to a file determined by allBooksOUT
     */
    void saveBooksToFile();

    /**
     * Saves the list memberList to a file determined by libMembersOUT
     */
    void saveMembersToFile();

    /**
     * Saves the list requestBooks to a file determined by requestBooksOUT
     */
    void saveDeliveryRequestToFile();

    /**
     * Save the inventory and wait lists in a file and terminate execution of UI.
     * @post saves allBooks to file
     * @post saves memberList to file
     * @post saves requestBooks to file
     * @post sets runUI to false
     */
    void quit();

    /**
     * Prints a summary of all available commands
     * @post All available commands printed to screen
     */
    void libraryHelp();

    /**
     * Gets the shelf value of a book
     * @param desiredBook title of book to get value
     * @return amount on shelf
     */
    int getShelfValue(std::string desiredBook);

    /**
     * Creates a new library member (Member) given prompts about information
     * Adds to the memberList
     * @post Member added to memberList
     */
    void addMember();

    /**
     * Adds already-created member to member list
     * @param memberToAdd
     * @post Member added to memberList
     */
    void addMember(Member* memberToAdd);

    /**
     * adds a book to allBooks
     * @param titleToAdd title of book
     * @param numToAdd number to add
     * @post Book is added to allBooks
     */
    void addBook(std::string titleToAdd, int numToAdd);

    /**
     * adds an already-constructed book to allBooks
     * @param bookToAdd pointer to book to add
     * @post Book is added to allBooks
     */
    void addBook(Book& bookToAdd);

    /**
     * increments the amount of the book on the shelf by 1
     * @param titleToReturn title of the book to return
     * @post the shelfAmount of the book is increased by 1 iff the library owns the book
     */
    void returnBook(std::string titleToReturn);

    /**
     * Puts a request in for book to be delivered
     * @param desiredBookTitle book title
     * @param memberName name of the member requesting
     * @post if successful, Member is put on waitlist of the desired Book
     * @post if successful, Book is added to requestBooks list
     */
    void requestLoan(std::string& desiredBookTitle, std::string& memberName);

    /**
     * Puts in a request for a book to be delivered
     * @param bookToRequest pointer to Book requesting
     * @param memberRequesting pointer to Member requesting
     * @post if successful, Member is put on waitlist of the desired Book
     * @post if successful, Book is added to requestBooks list
     */
    void requestLoan(Book* bookToRequest, Member* memberRequesting);
    /**
     * Removes a book from the library due to loss/damage
     * @param bookToRemove title of the book to remove
     * @param numRemove amount to remove
     * @post if successful, haveTotal and haveShelf are reduced by numRemove on the book
     */
    void removeBook(std::string bookToRemove, int numRemove);

    /**
     * Print all information for the book
     * @param bookToInquire title of book to inquire about
     */
    void inquireAboutBook(std::string bookToInquire);

    /**
     * Performs a delivery, increasing haveTotal and haveShelf for already owned books
     * adds books to library which aren't already there
     * @param deliveryFileName txt file of delivery
     * @post allBooks is altered to reflect book delivery
     * @post the delivery file is cleared???
     */
    void bookDelivery(const std::string& deliveryFileName);

    /**
     * Print all owned books
     * @post allBooks is sorted alphabetically by title
     * @post list of allBooks is printed to screen
     */
    void printAllOwnedBooks();

    /**
     * Checks out a book
     * @param bookToCheckOut
     * @post Book's shelfTotal is reduced by 1
     */
    void checkOutBook(std::string bookToCheckOut);

    /**
     * Runs the UI
     * Keeps the program running after the UI ends
     */
    void masterRun();

    /**
     * Starts up the UI of the library
     * @return false when program ends
     */
    bool runUI();


};
#endif //FINALPROJECT_LIBRARY_H
