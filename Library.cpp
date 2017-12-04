//
// Created by Alex on 12/3/2017.
//

#include "Library.h"

/**
 * Constructor
 */
Library::Library(const std::string& inBooksTxtIN,const std::string& inBooksTxtOUT,const std::string& allBooksTxtIN,const std::string& allBooksTxtOUT,const std::string& memberListTxt){
    //pointer to list of library members
    //memberList;
    //fstream parts
    libMembersIN = std::ifstream(memberListTxt);
    libMembersOUT = std::ofstream(memberListTxt);

    //fstream parts
    inBooksIN.open(inBooksTxtIN);
    inBooksOUT.open(inBooksTxtOUT);
    //pointer to list of books in library
    //inBooks = generateAllBookList();
    //fstream parts
    allBooksIN.open(allBooksTxtIN);
    allBooksOUT.open(allBooksTxtOUT);
    //pointer to list of books checked out
    allBooks = generateAllBookList();
    //list of people waiting for book
}

/**
     * Generates the list of books from the file
     * @param fileToGenerate
     * @return list of books
     */
ArrayList<Book*> Library::generateAllBookList(){
    ArrayList<Book*> bookList;
    if(!allBooksIN){
        std::cerr << "The file could not be opened!" << std::endl;
    }
    else {
        std::string title;
        std::string author;
        std::string isbnSTR;
        std::string numBooksSTR;
        while (allBooksIN) {
            getline(allBooksIN, title);
            getline(allBooksIN, author);
            getline(allBooksIN, isbnSTR);
            getline(allBooksIN, numBooksSTR);
            if (!title.empty() && title[title.size() - 1] == '\r') {
            title.erase(title.size() - 1);
            }if (!author.empty() && author[author.size() - 1] == '\r') {
                author.erase(author.size() - 1);
            }int isbn = std::stoi(isbnSTR);
            int numBooks = std::stoi(numBooksSTR);
            Book* newBook = new Book(title, author, isbn, numBooks);
            std::cout << newBook->bookInquiry() << std::endl;
            allBooks.insertAtEnd(newBook);
        }
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
        if(allBooks.getValueAt(i)->getTitle() == titleToAdd){
            inList = true;
            allBooks.getValueAt(i)->modHaveTotal(numToAdd);
        }
    }
    if(!inList){
        std::cout << "Who is the author of this book?" << std::endl;
        std::string author;
        std::cin >> author;
        std::cout << "What is the ISBN number of this book?" << std::endl;
        int isbn;
        std::cin >> isbn;
        Book* newBook = new Book(titleToAdd,author,isbn,numToAdd);
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

void Library::printAllOwnedBooks(){
    std::cout << allBooks.toString() << std::endl;
}