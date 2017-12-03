//
// Created by Alex on 12/3/2017.
//

#include "Library.h

/**
 * Constructor
 */
Library::Library(std::string inBooksTxt, std::string allBooksTxt, std::string memberListTxt){
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
List<Book> generateBookList(std::ifstream& fileToGenerate){
    List<Book> bookList;
    if(!fileToGenerate){
        std::cerr << "The file could not be opened!" << std::endl;
    }
    while(fileToGenerate){
        std::string title = fileToGenerate.get("\t");
    }

}

/**
 * Generates the list of library members from the file
 * @param fileToGenerate
 * @return list of members
 */
List<People> generatePeopleList(std::ifstream& fileToGenerate);


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
void Library::quit(){
    libMembersOUT.close();
    inBooksOUT.close();
    outBooksOUT.close();
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
        Book newBook = new Book(titleToAdd,author,isbn,numToAdd);
        allBooks.insertAtEnd(newBook);
    }
}

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
