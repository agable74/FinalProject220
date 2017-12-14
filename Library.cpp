//
// Created by Alex on 12/3/2017.
//

#include "Library.h"

/**
 * Constructor
 */
Library::Library(const std::string& allBooksTxtIN,const std::string& memberListTxtIN){
    //pointer to list of library members
    //memberList;
    //fstream parts
    libMembersIN.open(memberListTxtIN);
    //libMembersOUT = std::ofstream(memberListTxt);
    //fstream parts
    allBooksIN.open(allBooksTxtIN);
   // allBooksOUT.open(allBooksTxtOUT);
    //pointer to list of books checked out
    allBooks = new ArrayList<Book*>;
    shelfBooks = new ArrayList<Book*>;
    //generate the list from text file
    generateAllBookList();
    //generate shelf from allBooks
    generateShelfBookList();
    //list of people waiting for book
    members = new ArrayList<Member*>;
    generateMemberList();
    runUIBool = true;
    runMasterBool = true;
    bookListTxt = allBooksTxtIN;
    memberListTxt = memberListTxtIN;
}

int checkIfNum(std::string& stringToCheck){
    bool isValidNum = true;
    for(int i = 0; i < stringToCheck.length(); i++){
        if(!isdigit(stringToCheck[i])){
            isValidNum = false;
        }
    }
    while(!isValidNum){
        isValidNum = true;
        std::cout << "Error in your number. Please enter a valid number: ";
        std::getline(std::cin,stringToCheck);
        for(int i = 0; i < stringToCheck.length(); i++){
            if(!isdigit(stringToCheck[i])){
                isValidNum = false;
            }
        }
    }
    int validNum = std::stoi(stringToCheck);
    return validNum;
}

bool checkYesOrNo(std::string& stringToCheck){
    while(stringToCheck!="y"&&stringToCheck!="Y"&&stringToCheck!="Yes"&&stringToCheck!="yes"&&stringToCheck!="n"&&stringToCheck!="N"&&stringToCheck!="No"&&stringToCheck!="no"){
        std::cout << "Invalid input, please enter 'yes' or 'no': ";
        std::getline(std::cin,stringToCheck);
    }
    if(stringToCheck == "y" || stringToCheck == "Y" || stringToCheck == "yes" || stringToCheck == "Yes"){
        return true;
    }
    else{
        return false;
    }
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
 * @post members list generated from text file
 */
void Library::generateMemberList(){
    if(!libMembersIN){
        std::cerr << "The file could not be opened!" << std::endl;
    }
    else{

    }
}

void Library::saveBooksToFile(){
    allBooksOUT.open(bookListTxt);
    for(int i = 0; i < allBooks->itemCount(); i++){
        allBooksOUT << allBooks->getValueAt(i)->getTitle() << '\n';
        allBooksOUT << allBooks->getValueAt(i)->getAuthor() << '\n';
        allBooksOUT << allBooks->getValueAt(i)->getIsbn() << '\n';
        allBooksOUT << allBooks->getValueAt(i)->getHaveTotal() << '\n';
    }
    allBooksOUT.close();
}

void Library::saveMembersToFile(){
    libMembersOUT.open(memberListTxt);
    for(int i = 0; i < members->itemCount(); i++){
        libMembersOUT << members->getValueAt(i)->getName() << '\n';
        libMembersOUT << members->getValueAt(i)->getPhoneNumber() << '\n';
        libMembersOUT << members->getValueAt(i)->getEmail() << '\n';
        libMembersOUT << members->getValueAt(i)->getId() << '\n';
        libMembersOUT << members->getValueAt(i)->getContactPref() << '\n';
    }
    libMembersOUT.close();
}

/**
 * Copy Constructor
 * @param libraryListToCopy
 */
Library::Library(const Library& libraryToCopy){
    libMembersIN;
    libMembersOUT;
    //pointer to list of books owned by library

    allBooks = new ArrayList<Book*>;
    for(int i = 0; i < libraryToCopy.allBooks->itemCount(); i++){
        Book* copyBook = libraryToCopy.allBooks->getValueAt(i);
        addBook(*copyBook);
    }

    //fstream parts
    allBooksIN;
    allBooksOUT;
    //pointer to list of books in library
    shelfBooks = new ArrayList<Book*>;
    generateShelfBookList();
    //list of people waiting for book

    members = new ArrayList<Member*>;
    for(int i = 0; i < libraryToCopy.members->itemCount(); i++){
        Member* copyMember = libraryToCopy.members->getValueAt(i);
        addMember(*copyMember);
    }

    runUIBool = true;
    bookListTxt = libraryToCopy.bookListTxt;
    memberListTxt = libraryToCopy.memberListTxt;
}


/**
 * Assignment Operator
 * @param libraryListToCopy
 */
Library& Library::operator=(const Library& libraryToCopy){
    if(this!=&libraryToCopy){
        shelfBooks->clearList();
        allBooks->clearData();
        members->clearData();


        for(int i = 0; i < libraryToCopy.allBooks->itemCount(); i++){
            Book* copyBook = libraryToCopy.allBooks->getValueAt(i);
            addBook(*copyBook);
        }

        generateShelfBookList();

        for(int i = 0; i < libraryToCopy.members->itemCount(); i++){
            Member* copyMember = libraryToCopy.members->getValueAt(i);
            addMember(*copyMember);
        }
    }
    return *this;
}

/**
 * Destructor
 */
Library::~Library(){
    shelfBooks->clearList();
    delete shelfBooks;
    allBooks->clearData();
    delete allBooks;
    members->clearData();
    delete members;
}

/**
 * Creates a new library member (Person) given prompts about information
 * Adds to the memberList
 * @return true if successful, false if unsuccessful
 */
void Library::addMember(){
    Member* newMember = new Member();
    members->insertAtEnd(newMember);
}

void Library::addMember(Member& memberToAdd){
    members->insertAtEnd(&memberToAdd);
}

/**
 * Save the inventory and wait lists in a file and terminate execution. Clean up too!
 */
void Library::quit(){
    runUIBool = false;
    saveBooksToFile();
    saveMembersToFile();
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
        std::string author;
        std::cout << "Who is the author of this book?" << std::endl;
        std::getline(std::cin,author);
        std::string isbnStr;
        std::cout << "What is the ISBN number of this book?" << std::endl;
        std::getline(std::cin,isbnStr);
        int isbn = checkIfNum(isbnStr);
        Book* newBook = new Book(titleToAdd,author,isbn,numToAdd);
        allBooks->insertAtEnd(newBook);
    }
}

void Library::addBook(Book& bookToAdd){
    bool inList = false;
    for(int i = 0; i < allBooks->itemCount(); i++){
        if(allBooks->getValueAt(i)->getTitle() == bookToAdd.getTitle()){
            inList = true;
            allBooks->getValueAt(i)->modHaveTotal(bookToAdd.getHaveTotal());
        }
    }
    if(!inList) {
        allBooks->insertAtEnd(&bookToAdd);
    }
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
void Library::libraryHelp(){
    std::cout << "I - Inquire about a book" << std::endl;
    std::cout << "L - List all available books" << std::endl;
    std::cout << "A - Add a book to the library" << std::endl;
    std::cout << "N - Add a new member to the library" << std::endl;
    std::cout << "R - Return a book to the library" << std::endl;
    std::cout << "W - Withdraw a book from the library" << std::endl;
    std::cout << "D - Delivery of books from requests" << std::endl;
    std::cout << "O - Order books through interlibrary loans" << std::endl;
    std::cout << "Q - Quit" << std::endl;
}


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
            std::cout << allBooks->getValueAt(i)->toString() << std::endl;
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

void Library::masterRun(){
    while(runMasterBool){
        runUI();
    }
}

bool Library::runUI(){
    std::cout << "Welcome to the library!" << std::endl;
    std::string userInput;
    while(runUIBool){
        std::cout << "Type H for a list of functions or type the function which you wish to use: ";
        std::getline (std::cin,userInput);
        std::cout << std::endl;
        while(userInput!="h"&&userInput!="H"&&userInput!="I"&&userInput!="i"&&userInput!="a"&&userInput!="A"&&userInput!="L"&&userInput!="l"&&userInput!="N"&&userInput!="n"&&userInput!="R"&&userInput!="r"&&userInput!="W"&&userInput!="w"&&userInput!="D"&&userInput!="d"&&userInput!="o"&&userInput!="O"&&userInput!="help"&&userInput!="Help"&&userInput!="Q"&&userInput!="q"&&userInput!="quit"&&userInput!="Quit"){
            std::cout << "Invalid input. Please enter the letter corresponding to the command you wish to perform: ";
            std::getline (std::cin,userInput);
        }
        if(userInput=="h"||userInput=="H"){
            libraryHelp();
        }
        else if(userInput == "I" || userInput == "i"){
            std::cout << "You have chosen to inquire about a book. Are you certain?"
            std::string userResponse;
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes) {
                std::string bookTitle;
                "Please enter the title of the book which interests you:";
                std::getline(std::cin, bookTitle);
                inquireAboutBook(bookTitle);
                std::cout << "Returning to the main menu" << std::endl;
            }
            else{std::cout << "Returning to the main menu" << std::endl;}
        }
        else if(userInput == "a" || userInput == "A"){
            std::cout << "You have chosen to add a book. Are you certain?";
            std::string userResponse;
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes) {
                std::string bookTitle;
                std::string numToAddStr;
                std::cout << "Please enter the title of the book which you wish to add:";
                std::getline(std::cin, bookTitle);
                std::cout << "Please enter the amount of this book you are adding:";
                std::getline(std::cin, numToAddStr);
                int numToAdd = checkIfNum(numToAddStr);
                addBook(bookTitle, numToAdd);
                std::cout << "Returning to the main menu" << std::endl;
            }
            else{
                std::cout << "Returning to the main menu" << std::endl;
            }
        }
        else if(userInput == "q" || userInput == "Q" || userInput == "quit" || userInput == "Quit"){
            std::string userResponse;
            std::cout << "Are you sure you wish to quit? ";
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes){
                quit();
            }
            else{
                std::cout << "Returning to the main menu" << std::endl;
            }
        }
        else if(userInput == "n" || userInput == "N"){
            std::cout << "You wish to add a new member." << std::endl;
            addMember();
        }
        else if(userInput == "r" || userInput == "R"){
            std::cout << "You wish to return a book. Correct? " << std::endl;
            std::string userResponse;
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes){
                std::cout << "Enter the title of the book you wish to return :";
                std::string title;
                std::getline(std::cin,title);
                returnBook(title);
                std::cout << "Returning to the main menu" << std::endl;
            }
            else{
                std::cout << "Returning to the main menu" << std::endl;
            }
        }
    }
    while(!runUIBool){
        std::cout << "Do you wish to terminate the program? ";
        std::string userResponse;
        std::getline(std::cin,userResponse);
        bool yes = checkYesOrNo(userResponse);
        if(!yes){
            std::cout << "Do you wish to begin using the library again?";
            std::getline(std::cin,userResponse);
            yes = checkYesOrNo(userResponse);
            if(yes){
                runUIBool = true;
            }
            else{
                std::cout << "You don't want to end the program, but you don't want to use it. Why? WHY???" << std::endl;
            }
        }
        else{
            std::cout << "Shutting down..." << std::endl;
            runMasterBool = false;
            return false;
        }
    }
}