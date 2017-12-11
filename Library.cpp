//
// Created by Alex on 12/3/2017.
//

#include "Library.h"

/**
 * Constructor
 */
Library::Library(const std::string& allBooksTxtIN,const std::string& allBooksTxtOUT,const std::string& memberListTxt){
    //pointer to list of library members
    //memberList;
    //fstream parts
    libMembersIN = std::ifstream(memberListTxt);
    libMembersOUT = std::ofstream(memberListTxt);
    //fstream parts
    allBooksIN.open(allBooksTxtIN);
    allBooksOUT.open(allBooksTxtOUT);
    //pointer to list of books checked out
    allBooks = new ArrayList<Book*>;
    shelfBooks = new ArrayList<Book*>;
    //generate the list from text file
    generateAllBookList();
    //generate shelf from allBooks
    generateShelfBookList();
    //list of people waiting for book
}

/**
     * Generates the list of books from the file
     * @param fileToGenerate
     * @return list of books
     */
void Library::generateAllBookList(){
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
            if(allBooksIN) {    //makes sure that it doesn't duplicate the last line, and works on empty text files
                if (!title.empty() && title[title.size() - 1] == '\r') {
                    title.erase(title.size() - 1);
                }
                if (!author.empty() && author[author.size() - 1] == '\r') {
                    author.erase(author.size() - 1);
                }
                int isbn = std::stoi(isbnSTR);
                int numBooks = std::stoi(numBooksSTR);
                Book *newBook = new Book(title, author, isbn, numBooks);
                bool inList = false;
                for (int i = 0; i < allBooks->itemCount(); i++) {
                    if (allBooks->getValueAt(i)->getTitle() == newBook->getTitle()) {
                        inList = true;
                        allBooks->getValueAt(i)->modHaveTotal(newBook->getHaveTotal());
                    }
                }
                if (!inList) {
                    allBooks->insertAtEnd(newBook);
                }
            }
        }
    }
}

    /**
    * Generates the list of books on the shelf from allBooks list
    * @return list of shelf books
    */
void Library::generateShelfBookList(){
    for(int i=0; i<allBooks->itemCount();i++){
        if(allBooks->getValueAt(i)->getHaveTotal()>0){
            shelfBooks->insertAtEnd(allBooks->getValueAt(i));
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
 * Save the inventory and wait lists in a file and terminate execution. Clean up too!
 */
void Library::quit(){
    libMembersOUT.close();
    allBooksOUT.close();
}

/**
 * Adds book to inBooks list
 * @param bookToAdd
 */
void Library::addBook(std::string titleToAdd, int numToAdd){
    //looks in book list to see if it exists
    bool inList = false;
    for(int i = 0; i < allBooks->itemCount(); i++){
        if(allBooks->getValueAt(i)->getTitle() == titleToAdd){
            inList = true;
            allBooks->getValueAt(i)->modHaveTotal(numToAdd);
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
        allBooks->insertAtEnd(newBook);
    }
}

void Library::addBook(Book bookToAdd){
    allBooks->insertAtEnd(&bookToAdd);
}

/**
 * Moves a book from the outBooks list to the inBooks list
 * @param bookToReturn
 */
void Library::returnBook(std::string titleToReturn){
    bool inList = false;
    for(int i = 0; i < allBooks->itemCount(); i++){
        if(allBooks->getValueAt(i)->getTitle() == titleToReturn){
            inList = true;
            allBooks->getValueAt(i)->checkBookIn();
        }
    }
    if(!inList){
        std::cout << "That book does not belong to this library." << std::endl;
    }
}

/**
 * Puts a request in for book to be delivered
 * @param desiredBook
 */
void Library::requestLoan(std::string desiredBookTitle){
//    bool inList = false;
//    for(int i = 0; i < allBooks.itemCount(); i++){
//        if(allBooks.getValueAt(i)->getTitle() == desiredBookTitle){
//            inList = true;
//            allBooks.getValueAt(i)->modHaveTotal(numToAdd);
//        }
//    }
//    if(!inList){
//        std::cout << "Who is the author of this book?" << std::endl;
//        std::string author;
//        std::cin >> author;
//        std::cout << "What is the ISBN number of this book?" << std::endl;
//        int isbn;
//        std::cin >> isbn;
//        Book* newBook = new Book(titleToAdd,author,isbn,numToAdd);
//        allBooks.insertAtEnd(newBook);
//    }
}

/**
 * Removes a book from the library due to loss/damage
 * @param bookToRemove
 */
void Library::removeBook(std::string bookToRemove, int numRemove){
    bool inList = false;
    for(int i = 0; i < allBooks->itemCount(); i++){
        if(allBooks->getValueAt(i)->getTitle() == bookToRemove){
            inList = true;
            allBooks->getValueAt(i)->modHaveTotal(-numRemove);
        }
    }
    if(!inList){
        std::cout << "That book does not belong to this library." << std::endl;
    }
}

/**
 * Prints a summary of all available commands
 */
void Library::libraryHelp(){}


/**
 * Print all information for the book
 * @param bookToInquire
 */
void Library::inquireAboutBook(std::string bookToInquire){
    bool inList = false;
    for(int i = 0; i < allBooks->itemCount(); i++){
        if(allBooks->getValueAt(i)->getTitle() == bookToInquire){
            inList = true;
            std::cout << "Information about " << bookToInquire << ":" << std::endl;
            std::cout << allBooks->getValueAt(i)->bookInquiry() << std::endl;
        }
    }
    if(!inList){
        std::cout << "That book does not belong to this library." << std::endl;
    }
}


/**
 * Performs a delivery, increasing haveTotal and haveShelf for already owned books
 * adds books to library which aren't already there
 * @param deliveryFileName
 */
void Library::bookDelivery(const std::string& deliveryFileName){
    std::ifstream deliveryIN;
    deliveryIN.open(deliveryFileName);
    if(!deliveryIN){
        std::cerr << "The file could not be opened!" << std::endl;
    }
    else {
        std::string title;
        std::string author;
        std::string isbnSTR;
        std::string numBooksSTR;
        while (deliveryIN) {
            getline(deliveryIN, title);
            getline(deliveryIN, author);
            getline(deliveryIN, isbnSTR);
            getline(deliveryIN, numBooksSTR);
            if(deliveryIN){ //makes sure that it doesn't duplicate the last line, and works on empty text files
                if (!title.empty() && title[title.size() - 1] == '\r') {
                    title.erase(title.size() - 1);
                }
                if (!author.empty() && author[author.size() - 1] == '\r') {
                    author.erase(author.size() - 1);
                }
                int isbn = std::stoi(isbnSTR);
                int numBooks = std::stoi(numBooksSTR);
                Book *newBook = new Book(title, author, isbn, numBooks);
                bool inList = false;
                for (int i = 0; i < allBooks->itemCount(); i++) {
                    if (allBooks->getValueAt(i)->getTitle() == newBook->getTitle()) {
                        inList = true;
                        allBooks->getValueAt(i)->modHaveTotal(newBook->getHaveTotal());
                    }
                }
                if (!inList) {
                    allBooks->insertAtEnd(newBook);
                }
            }
        }
    }
}

void Library::printAllOwnedBooks(){
    std::cout << allBooks->toString() << std::endl;
}

void Library::checkOutBook(std::string bookToCheckOut){
    bool inList = false;
    for(int i = 0; i < allBooks->itemCount(); i++){
        if(allBooks->getValueAt(i)->getTitle() == bookToCheckOut){
            inList = true;
            allBooks->getValueAt(i)->checkBookOut();
        }
    }
    if(!inList){
        std::cout << "That book does not belong to this library." << std::endl;
    }
}