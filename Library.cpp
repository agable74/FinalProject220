//
// Created by Alex on 12/3/2017.
//

#include "Library.h

/**
 * Constructor
 */
Library::Library(std::string inBooksTxt, std::string outBooksTxt, std::string memberListTxt){
    //pointer to list of library members
    memberList;
    //fstream parts
    libMembersIN = std::ifstream(memberListTxt);
    libMembersOUT = std::ofstream(memberListTxt);
    //pointer to list of books in library
    inBooks;
    //fstream parts
    inBooksIN = std::ifstream(inBooksTxt);
    inBooksOUT = std::ofstream(inBooksTxt);
    //pointer to list of books checked out
    outBooks;
    //fstream parts
    outBooksIN = std::ifstream(outBooksTxt);
    outBooksOUT = std::ofstream(outBooksTxt);
    //list of people waiting for book
}

/**
 * Copy Constructor
 * @param libraryListToCopy
 */
Library::Library(const Library& libraryToCopy);


/**
 * Assignment Operator
 * @param libraryListToCopy
 */
Library::Library& operator=(const Library& libraryToCopy);

/**
 * Destructor
 */
Library::~Library();

/**
 * Creates a new library member (Person) given prompts about information
 * Adds to the memberList
 * @return true if successful, false if unsuccessful
 */
bool Library::addMember();

/**
 * Save the inventory and wait lists in a file and terminate execution.
 */
void Library::quit();

/**
 * Adds book to inBooks list
 * @param bookToAdd
 */
void Library::addBook(Book bookToAdd);

/**
 * Moves a book from the outBooks list to the inBooks list
 * @param bookToReturn
 */
void Library::returnBook(Book bookToReturn);

/**
 * Puts a request in for book to be delivered
 * @param desiredBook
 */
void Library::requestLoan(Book desiredBook);

/**
 * Removes a book from the library due to loss/damage
 * @param bookToRemove
 */
void Library::removeBook(Book bookToRemove);

/**
 * Prints a summary of all available commands
 */
void Library::libraryHelp();

/**
 * Print all information for the book
 * @param bookToInquire
 */
void Library::inquireAboutBook(Book bookToInquire);

/**
 * Performs a delivery, increasing haveTotal and haveShelf for already owned books
 * adds books to library which aren't already there
 * @param deliveryFileName
 */
void Library::bookDelivery(std::string deliveryFileName);
