#include <iostream>
#include <fstream>
#include <sstream>
#include "Library.h"

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
    Library testLib = Library("TestAllBooksIN.txt","TestAllBooksOUT.txt","TestMembers.txt");
    testLib.printAllOwnedBooks();
    Book testBook = Book("Lord of the Flies","William Golding",055235,6);
    testLib.addBook(testBook);
    testLib.printAllOwnedBooks();
    testLib.checkOutBook("Lord of the Flies");
    testLib.printAllOwnedBooks();
    testLib.returnBook("Lord of the Flies");
    testLib.printAllOwnedBooks();
    testLib.inquireAboutBook("Lord of the Flies");
    testLib.removeBook("Lord of the Flies", 3);
    testLib.inquireAboutBook("Lord of the Flies");
    testLib.bookDelivery("TestDeliveryIN.txt");
    testLib.inquireAboutBook("Doggo's Are Good");

    return 0;
}