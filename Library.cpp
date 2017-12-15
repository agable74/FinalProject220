//
// Created by Alex on 12/3/2017.
//

#include "Library.h"

/**
 * Constructor
 */
Library::Library(const std::string& allBooksTxtIN,const std::string& memberListTxtIN,const std::string& deliveryTxtIN){
    //fstream parts
    libMembersIN.open(memberListTxtIN);
    //libMembersOUT = std::ofstream(memberListTxt);
    //fstream parts
    allBooksIN.open(allBooksTxtIN);
    //pointer to list of books checked out
    allBooks = new ArrayList<Book*>;
    shelfBooks = new ArrayList<Book*>;
    //generate the list from text file
    generateAllBookList();
    //generate shelf from allBooks
    generateShelfBookList();
    members = new ArrayList<Member*>;
    generateMemberList();
    requestBooks = new ArrayList<Book*>;
    runUIBool = true;
    runMasterBool = true;
    bookListTxt = allBooksTxtIN;
    memberListTxt = memberListTxtIN;
    deliveryTxt = deliveryTxtIN;
}
int compareBookTitles(Book* book1, Book* book2){
    std::string bookTitle1 = book1->getTitle();
    std::string bookTitle2 = book2->getTitle();
    for(int i = 0; i < bookTitle1.length(); i++){
        if(bookTitle1[i] > bookTitle2[i]){
            return 1;
        }else if(bookTitle1[i] < bookTitle2[i]){
            return 2;
        }
    }
    return 3;
}

Book* compareBookTitlesBook(Book* book1, Book* book2){
    std::string bookTitle1 = book1->getTitle();
    std::string bookTitle2 = book2->getTitle();
    for(int i = 0; i < bookTitle1.length(); i++){
        if(bookTitle1[i] > bookTitle2[i]){
            return book1;
        }else if(bookTitle1[i] < bookTitle2[i]){
            return book2;
        }
    }
    return book1;
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
        std::string shelfBooksSTR;
        while (allBooksIN) {
            getline(allBooksIN, title);
            getline(allBooksIN, author);
            getline(allBooksIN, isbnSTR);
            getline(allBooksIN, numBooksSTR);
            getline(allBooksIN, shelfBooksSTR);
            if(allBooksIN) {    //makes sure that it doesn't duplicate the last line, and works on empty text files
                if (!title.empty() && title[title.size() - 1] == '\r') {
                    title.erase(title.size() - 1);
                }
                if (!author.empty() && author[author.size() - 1] == '\r') {
                    author.erase(author.size() - 1);
                }
                int isbn = std::stoi(isbnSTR);
                int numBooks = std::stoi(numBooksSTR);
                int shelfBooks = std::stoi(shelfBooksSTR);
                Book *newBook = new Book(title, author, isbn, numBooks,shelfBooks);
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


//
//List<Book*>* copyArray(List<Book*>* arrayToCopy, const int size, int& numLinesRun){
//    List<Book*>* newArrayCopy = new ArrayList<Book*>;
//    numLinesRun += 5;
//    for(int i = 0; i < size; i++){
//        numLinesRun += 1;
//        newArrayCopy->insertAt(arrayToCopy->getValueAt(i),i);
//    }
//    return newArrayCopy;
//}
//
//List<Book*>* merge(List<Book*>* a1, int size1, List<Book*>* a2, int size2, int& numLinesRun){
//    //checks for two arrays of size 0
//    numLinesRun += 6;
//    if(size1+size2 < 1){
//        return nullptr;
//    }
//    //create a new array to hold the merge values
//    List<Book*>* arrayToReturn = new ArrayList<Book*>(size1+size2);
//    int pos1 = 0;
//    int pos2 = 0;
//    numLinesRun += 4;
//    for (int i = 0; i < size1 + size2; i++) {
//        numLinesRun += 4;
//        //checks both are within the bounds of respective array
//        if(pos2 < size2 && pos1 < size1) {
//            int bookToAdd = compareBookTitles(a1->getValueAt(pos1),a2->getValueAt(pos2));
//            //moves along the index of the array with lesser value
//            if (bookToAdd == 2) {
//                arrayToReturn->insertAt(a1->getValueAt(pos1),i);
//                pos1++;
//                numLinesRun+= 2;
//            } else if (bookToAdd == 1) {
//                arrayToReturn->insertAt(a2->getValueAt(pos2),i);
//                pos2++;
//                numLinesRun += 2;
//            } //if values are equal, I choose to do the first array and continue through loop
//            else if (bookToAdd == 3) {
//                arrayToReturn->insertAt(a1->getValueAt(pos1),i);
//                pos1++;
//                numLinesRun += 2;
//            }
//            //if one array is out of bounds, finish with values of other array
//        }else if(pos2 < size2 && pos1 >= size1){
//            arrayToReturn->insertAt(a2->getValueAt(pos2),i);
//            pos2++;
//            numLinesRun += 2;
//        }else if(pos1 < size1 && pos2 >= size2){
//            arrayToReturn->insertAt(a1->getValueAt(pos1),i);
//            pos1++;
//            numLinesRun += 2;
//        }else{
//            return arrayToReturn;
//        }
//    }
//    return arrayToReturn;
//}
//
//List<Book*>* mergeSort(List<Book*>* arrayToSort, int size, int& numLinesRun){
//    numLinesRun += 5;
//
//    //checks for empty array
//    if(size < 1){
//        return nullptr;
//    }
//        //if size == 1, then send back a copy of array
//    else if(size == 1){
//        List<Book*>* arrayCopy = copyArray(arrayToSort,size,numLinesRun);
//        numLinesRun += 1;
//        return arrayCopy;
//    }
//    else{
//        std::cout << "bark" << std::endl;
//        int midIndex = size / 2;
//        List<Book*>* lowerArray = mergeSort(arrayToSort,size/2,numLinesRun);
//        List<Book*>* upperArray;
//        List<Book*>* mergedArray;
//        numLinesRun += 5;
//        //has to do it one way for even arrays
//        if(size % 2 == 0){
//            //breaks apart and merges in order smaller arrays
//            upperArray = mergeSort(arrayToSort + midIndex, size/2, numLinesRun);
//            mergedArray = merge(lowerArray,size/2,upperArray,size/2,numLinesRun);
//            numLinesRun += 2;
//        }//other way for odd arrays
//        else {
//            upperArray = mergeSort(arrayToSort + midIndex, size / 2 + 1, numLinesRun);
//            mergedArray = merge(lowerArray,size/2,upperArray,size/2+1,numLinesRun);
//            numLinesRun += 2;
//        }
//        //cleanup
//        delete lowerArray;
//        lowerArray = nullptr;
//        delete upperArray;
//        upperArray = nullptr;
//        numLinesRun += 4;
//        return mergedArray;
//    }
//}
//
///**
// * Sorts the allBooks and shelfBooks lists alphabetically
// * @post allBooks and shelfBooks are sorted alphabetically by title
// */



//Uses Insertion Sort
void sort(List<Book*>* arrayToSort, int size, int& numLinesRun){
    numLinesRun += 4;
    for(int j = 0; j < size; j++){
        //loops through the positions
        numLinesRun += 2;
        Book* minVal = arrayToSort->getValueAt(j);
        for(int i = j; i < size; i++){
            //starts at i=j so that it doesn't go back into the already-sorted section
            //only looks through unsorted section
            numLinesRun += 1;
            if(compareBookTitles(arrayToSort->getValueAt(i),minVal)==2){
                //swaps the lowest value with the value at the j position
                numLinesRun += 5;
                minVal = arrayToSort->getValueAt(i);
                int minIndex = i;
                Book* tempSwap = arrayToSort->getValueAt(j);
                arrayToSort->replaceValueAt(minIndex,tempSwap);
                arrayToSort->replaceValueAt(j,minVal);
            }
        }

    }
}

void Library::sortBookList(){
    int numLines = 0;
    sort(allBooks,allBooks->itemCount(),numLines);
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
        std::string name;
        std::string ID;
        std::string phoneSTR;
        std::string email;
        std::string preference;
        while (libMembersIN) {
            getline(libMembersIN, name);
            getline(libMembersIN, phoneSTR);
            getline(libMembersIN, email);
            getline(libMembersIN, ID);
            getline(libMembersIN,preference);
            if(libMembersIN) {    //makes sure that it doesn't duplicate the last line, and works on empty text files
                if (!name.empty() && name[name.size() - 1] == '\r') {
                    name.erase(name.size() - 1);
                }
                if (!ID.empty() && ID[ID.size() - 1] == '\r') {
                    ID.erase(ID.size() - 1);
                }
                long long phone = std::stol(phoneSTR);
                Member* newMember = new Member(name,phone,email,ID,preference);
                bool inList = false;
                for (int i = 0; i < members->itemCount(); i++) {
                    if (members->getValueAt(i)->getName() == newMember->getName()) {
                        inList = true;
                        std::cout << "Member already exists!" << std::endl;
                    }
                }
                if (!inList) {
                    members->insertAtEnd(newMember);
                }
            }
        }
    }
}

void Library::saveBooksToFile(){
    allBooksOUT.open(bookListTxt);
    for(int i = 0; i < allBooks->itemCount(); i++){
        allBooksOUT << allBooks->getValueAt(i)->getTitle() << '\n';
        allBooksOUT << allBooks->getValueAt(i)->getAuthor() << '\n';
        allBooksOUT << allBooks->getValueAt(i)->getIsbn() << '\n';
        allBooksOUT << allBooks->getValueAt(i)->getHaveTotal() << '\n';
        allBooksOUT << allBooks->getValueAt(i)->getHaveShelf() << '\n';
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

void Library::saveDeliveryRequestToFile(){
    requestBooksOUT.open(deliveryTxt);
    for(int i = 0; i < requestBooks->itemCount(); i++){
        requestBooksOUT << requestBooks->getValueAt(i)->getTitle() << '\n';
        requestBooksOUT << requestBooks->getValueAt(i)->getAuthor() << '\n';
        requestBooksOUT << requestBooks->getValueAt(i)->getIsbn() << '\n';
        requestBooksOUT << requestBooks->getValueAt(i)->getHaveTotal() << '\n';
    }
    requestBooksOUT.close();
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
        Book* copyBook = new Book(*libraryToCopy.allBooks->getValueAt(i));
        addBook(*copyBook);
    }

    //fstream parts
    allBooksIN;
    allBooksOUT;
    //pointer to list of books in library
    shelfBooks = new ArrayList<Book*>;
    generateShelfBookList();
    //list of people waiting for book

    requestBooks = new ArrayList<Book*>;
    for(int i = 0; i < libraryToCopy.requestBooks->itemCount(); i++){
        Book* copyBook = new Book(*libraryToCopy.requestBooks->getValueAt(i));
        requestBooks->insertAtEnd(copyBook);
    }

    members = new ArrayList<Member*>;
    for(int i = 0; i < libraryToCopy.members->itemCount(); i++){
        Member* copyMember = new Member(*libraryToCopy.members->getValueAt(i));
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
        requestBooks->clearData();
        allBooks->clearData();
        members->clearData();


        for(int i = 0; i < libraryToCopy.allBooks->itemCount(); i++){
            Book* copyBook = new Book(*libraryToCopy.allBooks->getValueAt(i));
            addBook(*copyBook);
        }
        requestBooks = new ArrayList<Book*>;
        for(int i = 0; i < libraryToCopy.requestBooks->itemCount(); i++){
            Book* copyBook = new Book(*libraryToCopy.requestBooks->getValueAt(i));
            requestBooks->insertAtEnd(copyBook);
        }

        generateShelfBookList();

        for(int i = 0; i < libraryToCopy.members->itemCount(); i++){
            Member* copyMember = new Member(*libraryToCopy.members->getValueAt(i));
            addMember(*copyMember);
        }
    }
    return *this;
}

/**
 * Destructor
 */
Library::~Library(){
    requestBooks->clearData();
    delete requestBooks;
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
    saveDeliveryRequestToFile();
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
        sortBookList();
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
        sortBookList();
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
            if(allBooks->getValueAt(i)->getHaveTotal() > allBooks->getValueAt(i)->getHaveShelf()) {
                allBooks->getValueAt(i)->checkBookIn();
            }else{
                std::cout << "We already have all copies of that book accounted for. This book does not belong to this library." << std::endl;
            }
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
    bool inList = false;
    for(int i = 0; i < allBooks->itemCount(); i++){
        if(allBooks->getValueAt(i)->getTitle() == desiredBookTitle){
            inList = true;
            if(allBooks->getValueAt(i)->getHaveShelf() > 0) {
                std::cout << "We have this book in our library." << std::endl;
            }
            else{
                Book* requestBook = new Book(*allBooks->getValueAt(i));
                requestBook->modHaveTotal(-requestBook->getHaveTotal()+1); //makes it so it only does one
                requestBooks->insertAtEnd(requestBook);
                //add to waitlist
                std::cout << "Adding your request. We will contact you when it arrives." << std::endl;
            }
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
        Book* requestBook = new Book(desiredBookTitle,author,isbn,1);
        requestBooks->insertAtEnd(requestBook);
    }
}

/**
 * Removes a book from the library due to loss/damage
 * @param bookToRemove
 */
void Library::removeBook(std::string bookToRemove, int numRemove){
    bool inList = false;
    if(numRemove > 0){
    for(int i = 0; i < allBooks->itemCount(); i++){
        if(allBooks->getValueAt(i)->getTitle() == bookToRemove){
            inList = true;
            if(allBooks->getValueAt(i)->getHaveTotal() >= numRemove) {
                allBooks->getValueAt(i)->modHaveTotal(-numRemove);
            }else{
                std::cout << "You cannot remove more books than exist at the library! There are currently " << allBooks->getValueAt(i)->getHaveTotal() << " copies owned by this library." << std::endl;
            }
        }
    }
    if(!inList){
        std::cout << "The library does not own that book to remove it." << std::endl;
    }
    }
    else if(numRemove == 0){
        std::cout << "You shouldn't be trying to remove 0 copies." << std::endl;
    }
    else{
        std::cout << "You shouldn't be trying to remove a negative number of copies." << std::endl;
    }
}

/**
 * Prints a summary of all available commands
 */
void Library::libraryHelp(){
    std::cout << "I - Inquire about a book" << std::endl;
    std::cout << "L - List all available books" << std::endl;
    std::cout << "N - Add a new member to the library" << std::endl;
    std::cout << "R - Return a book to the library" << std::endl;
    std::cout << "W - Withdraw a book from the library" << std::endl;
    std::cout << "D - Delivery of books from requests" << std::endl;
    std::cout << "O - Order books through interlibrary loans" << std::endl;
    std::cout << "A - Add a book to the library" << std::endl;
    std::cout << "E - Remove a book which has been damaged or lost" << std::endl;
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
        std::cout << "The library does not own such a book. Consider requesting it through an interlibrary loan." << std::endl;
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
    sortBookList();
    std::cout << "List of all books:" << std::endl;
    std::cout << allBooks->toString() << std::endl;
    std::cout << std::endl;
    std::cout << "End of list" << std::endl;
}

void Library::checkOutBook(std::string bookToCheckOut){
    bool inList = false;
    for(int i = 0; i < allBooks->itemCount(); i++){
        if(allBooks->getValueAt(i)->getTitle() == bookToCheckOut){
            inList = true;
            if(allBooks->getValueAt(i)->getHaveShelf() > 0) {
                allBooks->getValueAt(i)->checkBookOut();
            }else{
                std::cout << "There are currently no copies of that book on the shelves. Try again at a later date." << std::endl;
            }
        }
    }
    if(!inList){
        std::cout << "The library does not own that book. Consider writing the title exactly as listed or request an interlibrary loan." << std::endl;
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
        std::cout << std::endl;
        std::cout << "Type H for a list of functions or type the function which you wish to use: ";
        std::getline (std::cin,userInput);
        std::cout << std::endl;
        while(userInput!="h"&&userInput!="H"&&userInput!="I"&&userInput!="i"&&userInput!="a"&&userInput!="A"&&userInput!="L"&&userInput!="l"&&userInput!="N"&&userInput!="n"&&userInput!="R"&&userInput!="r"&&userInput!="W"&&userInput!="w"&&userInput!="D"&&userInput!="d"&&userInput!="o"&&userInput!="O"&&userInput!="help"&&userInput!="Help"&&userInput!="Q"&&userInput!="q"&&userInput!="quit"&&userInput!="Quit"&&userInput!="e"&&userInput!="E"){
            std::cout << "Invalid input. Please enter the letter corresponding to the command you wish to perform: ";
            std::getline (std::cin,userInput);
        }
        if(userInput=="h"||userInput=="H"){
            libraryHelp();
        }
        else if(userInput == "I" || userInput == "i"){
            std::cout << "You have chosen to inquire about a book. Are you certain?";
            std::string userResponse;
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes) {
                std::string bookTitle;
                std::cout << "Please enter the title of the book which interests you:";
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
            std::cout << "You wish to return a book. Are you certain?";
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
        else if(userInput == "W" || userInput == "w"){
            std::cout << "You have chosen to withdraw a book. Are you certain? ";
            std::string userResponse;
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes){
                std::cout << "Enter the title of the book you wish to withdraw :";
                std::string title;
                std::getline(std::cin,title);
                checkOutBook(title);
                std::cout << "Returning to the main menu" << std::endl;
            }
            else{
                std::cout << "Returning to the main menu" << std::endl;
            }
        }
        else if(userInput == "d" || userInput == "D"){
            std::cout << "You have selected to intake a delivery. Are you certain? ";
            std::string userResponse;
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes){
                //intake delivery from txt file
                bookDelivery(deliveryTxt);
                std::cout << "Returning to the main menu" << std::endl;
            }
            else{
                std::cout << "Returning to the main menu" << std::endl;
            }
        }
        else if(userInput == "o" || userInput == "O"){
            std::cout << "You have selected to order an interlibrary loan. Are you certain? ";
            std::string userResponse;
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes){
                std::string bookTitle;
                std::cout << "Please enter the title of the book you desire: ";
                std::getline(std::cin,bookTitle);
                requestLoan(bookTitle);
                std::cout << "Returning to the main menu" << std::endl;
            }
            else{
                std::cout << "Returning to the main menu" << std::endl;
            }
        }
        else if(userInput == "l" || userInput == "L"){
            std::cout << "You have selected to list all library books. Are you certain? ";
            std::string userResponse;
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes){
                printAllOwnedBooks();
                std::cout << "Returning to the main menu" << std::endl;
            }
            else{
                std::cout << "Returning to the main menu" << std::endl;
            }
        }
        else if(userInput == "e" || userInput == "E"){
            std::cout << "You have selected to remove a book. Are you certain? ";
            std::string userResponse;
            std::getline(std::cin,userResponse);
            bool yes = checkYesOrNo(userResponse);
            if(yes){
                std::string bookTitle;
                std::string numStr;
                std::cout << "Please enter the title of the book you wish to remove: ";
                std::getline(std::cin,bookTitle);
                std::cout << "Please enter the amount you wish to remove: ";
                std::getline(std::cin,numStr);
                int numToRemove = checkIfNum(numStr);
                removeBook(bookTitle, numToRemove);
                std::cout << "Returning to the main menu" << std::endl;
            }
            else{
                std::cout << "Returning to the main menu" << std::endl;
            }
        }
    }
    //Program keeps running after you quit unless you terminate
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