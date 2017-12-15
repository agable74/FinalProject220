#include <iostream>
#include <fstream>
#include <sstream>
#include "Library.h"

void printAssertEquals(int expected, int actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void runLibrary(){
    Library theLibrary = Library("AllBooksWork.txt","TestMembers.txt","TestDeliveryIN.txt");
    theLibrary.masterRun();
}

void libraryTester(){
    Library theTestLibrary = Library("BooksTester.txt","MembersTester.txt","DeliveryTester.txt");
    Library theTestLibraryCopy = theTestLibrary;
    theTestLibraryCopy.removeBook("Lord of the Flies",7);
    theTestLibrary.inquireAboutBook("Lord of the Flies");
    theTestLibraryCopy.inquireAboutBook("Lord of the Flies");
    theTestLibraryCopy = theTestLibrary;
    theTestLibrary.removeBook("Lord of the Flies",8);
    theTestLibrary.inquireAboutBook("Lord of the Flies");
    theTestLibraryCopy.inquireAboutBook("Lord of the Flies");
    theTestLibrary.removeBook("Lord of the Flies",-1);

}

int main() {
//    //file IO
//    std::ifstream inf;
//    inf.open("TestIO.txt");
//    std::string author;
//    std::string title;
//    std::string isbnSTR;
//    std::string numBooksSTR;
//    if(!inf){
//        std::cout << "didn't open" << std::endl;
//    }
//    while(inf){
//        getline(inf, title);
//        getline(inf, author);
//        getline(inf, isbnSTR);
//        getline(inf, numBooksSTR);
//        std::cout << title << std::endl;
//        std::cout << author << std::endl;
//    }
//
//              //<< " " << author << " " << isbnSTR << " " << numBooksSTR << std::endl;
//    inf.close();

//    Library testLib = Library("AllBooksWork.txt","TestMembers.txt","TestDeliveryIN.txt");
//    testLib.printAllOwnedBooks();
//    Book testBook = Book("Lord of the Flies","William Golding",055235,6);
//    testLib.addBook(testBook);
//    testLib.printAllOwnedBooks();
//    testLib.checkOutBook("Lord of the Flies");
//    testLib.printAllOwnedBooks();
//    testLib.returnBook("Lord of the Flies");
//    testLib.printAllOwnedBooks();
//    testLib.inquireAboutBook("Lord of the Flies");
//    testLib.removeBook("Lord of the Flies", 3);
//    testLib.inquireAboutBook("Lord of the Flies");
//    testLib.bookDelivery("TestDeliveryIN.txt");
//    testLib.inquireAboutBook("Doggo's Are Good");
//    testLib.saveBooksToFile();
//   // testLib.saveMembersToFile();
//    //testLib.masterRun();
//    testLib.printAllOwnedBooks();
//    testLib.sortBookList();
//    testLib.printAllOwnedBooks();
//    testLib.requestLoan("Pride and Prejudice");
//    testLib.saveDeliveryRequestToFile();


    //runLibrary();
    libraryTester();
    //need to add a default constructor in book to store the shelf count
    //need to add the waitlist part in requesting books
    return 0;
}