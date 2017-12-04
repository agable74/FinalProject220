//
// Created by Alex on 12/3/2017.
//

#include "Library.h"

/**
 * Constructor
 */
Library::Library(std::string inBooksTxt, std::string allBooksTxt, std::string memberListTxt){
    //pointer to list of library members
    //memberList;
    //fstream parts
    libMembersIN = std::ifstream(memberListTxt);
    libMembersOUT = std::ofstream(memberListTxt);
    //pointer to list of books in library
    inBooks;
    //fstream parts
    inBooksIN = std::ifstream(inBooksTxt);
    inBooksOUT = std::ofstream(inBooksTxt);
    //pointer to list of books checked out
    allBooks;
    //fstream parts
    allBooksIN = std::ifstream(allBooksTxt);
    allBooksOUT = std::ofstream(allBooksTxt);
    //list of people waiting for book
}

/**
     * Generates the list of books from the file
     * @param fileToGenerate
     * @return list of books
     */
ArrayList<Book> Library::generateBookList(std::ifstream& fileToGenerate){
    ArrayList<Book> bookList;
    if(!fileToGenerate){
        std::cerr << "The file could not be opened!" << std::endl;
    }
    std::string title;
    std::string author;
    std::string isbnSTR;
    std::string numBooksSTR;
    while(fileToGenerate){
        getline(fileToGenerate,title);
        getline(fileToGenerate,author);
        getline(fileToGenerate,isbnSTR);
        getline(fileToGenerate,numBooksSTR);
        int isbn = std::stoi(isbnSTR);
        int numBooks = std::stoi(numBooksSTR);
        Book newBook = Book(title,author,isbn,numBooks);
        allBooks.insertAtEnd(newBook);
    }

}

/**
 * Generates the list of library members from the file
 * @param fileToGenerate
 * @return list of members
 */
//ArrayList<People> generatePeopleList(std::ifstream& fileToGenerate);


/**
 * Copy Constructor
 * @param libraryListToCopy
 */
Library::Library(const Library& libraryToCopy){

}


/**
 * Assignment Operator
 * @param libraryListToCopy
 */
Library& Library::operator=(const Library& libraryToCopy){

}

/**
 * Destructor
 */
Library::~Library(){

}

/**
 * Creates a new library member (Person) given prompts about information
 * Adds to the memberList
 * @return true if successful, false if unsuccessful
 */
bool Library::addMember(){
    return false;
}

/**
 * Save the inventory and wait lists in a file and terminate execution.
 */
void Library::quit(){
    libMembersOUT.close();
    inBooksOUT.close();
    allBooksOUT.close();
}

/**
 * Adds book to inBooks list
 * @param bookToAdd
 */
void Library::addBook(std::string titleToAdd, int numToAdd){
    //looks in book list to see if it exists
    bool inList = false;
    for(int i = 0; i < allBooks.itemCount(); i++){
        if(allBooks.getValueAt(i).getTitle() == titleToAdd){
            inList = true;
            allBooks.getValueAt(i).modHaveTotal(numToAdd);
        }
    }
    if(!inList){
        std::cout << "Who is the author of this book?" << std::endl;
        std::string author;
        std::cin >> author;
        std::cout << "What is the ISBN number of this book?" << std::endl;
        int isbn;
        std::cin >> isbn;
        Book newBook = Book(titleToAdd,author,isbn,numToAdd);
        allBooks.insertAtEnd(newBook);
    }
}

/**
 * Moves a book from the outBooks list to the inBooks list
 * @param bookToReturn
 */
void Library::returnBook(Book bookToReturn){

}

/**
 * Puts a request in for book to be delivered
 * @param desiredBook
 */
void Library::requestLoan(Book desiredBook){

}

/**
 * Removes a book from the library due to loss/damage
 * @param bookToRemove
 */
void Library::removeBook(Book bookToRemove){

}

/**
 * Prints a summary of all available commands
 */
void Library::libraryHelp(){}


/**
 * Print all information for the book
 * @param bookToInquire
 */
void Library::inquireAboutBook(Book bookToInquire){

}


/**
 * Performs a delivery, increasing haveTotal and haveShelf for already owned books
 * adds books to library which aren't already there
 * @param deliveryFileName
 */
void Library::bookDelivery(std::string deliveryFileName){

}
