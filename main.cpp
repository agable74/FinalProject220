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

void printAssertStringEqual(std::string expected, std::string actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "actual: " << actual << std::endl;
    }
}

void runLibrary(){
    Library theLibrary = Library("AllBooksNew.txt","TestMembers.txt","TestDeliveryIN.txt");
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
    theTestLibrary.printAllOwnedBooks();
    Member testMember = Member("Test McTesty",9529051349,"testDude@test.com");
    //Book testBook = Book("Test Book","Test McTesty",)
}

void BookTester() {
    Book book1 = Book("A Tale of Two Cities", "Charles Dickens", 3904238, 4, 4);
    Book book2 = Book("Doggo's Are Good", "Alex Gable", 2222, 104, 104);
    Book book3 = Book("Great Expectations", "Charles Dickens", 91230102, 1, 1);
    Book book4 = Book("Lord of the Flies", "William Golding", 23197, 98, 98);
    Book book5 = Book("Moby-Dick", "Herman Melville", 219031924, 1, 1);
    Book book6 = Book("Pride and Prejudice", "Jane Austen", 119, 1, 1);
    Member mem1 = Member("Joe Schmoe", 1234567890, "jSchmoe@ithaca.edu", "JS2341657", "Phone call");

    std::cout << "\nTesting getters [should print 5 passes]\n";
    printAssertStringEqual("Doggo's Are Good", book2.getTitle());
    printAssertStringEqual("Alex Gable", book2.getAuthor());
    printAssertEquals(2222, book2.getIsbn());
    printAssertEquals(104, book2.getHaveTotal());
    printAssertEquals(104, book2.getHaveShelf());

    std::cout << "\nTesting CopyConstructor [should print 4 passes]\n";
    Book book1_1 = Book(book1);
    printAssertStringEqual(book1.getTitle(), book1_1.getTitle());
    printAssertStringEqual(book1.toString(), book1_1.toString());
    printAssertEquals(book1.getHaveTotal(), book1_1.getHaveTotal());
    printAssertEquals(book1.getIsbn(), book1_1.getIsbn());

    std::cout << "\nTesting checkBookOut [should print 2 messages and passes]";
    book3.checkBookOut();
    printAssertEquals(0, book3.getHaveShelf());
    book3.checkBookOut();
    printAssertEquals(0, book3.getHaveShelf());

    std::cout << "\nTesting removeBook [should print 2 messages and 4 passes]";
    book5.removeBook();
    printAssertEquals(0, book5.getHaveShelf());
    printAssertEquals(0, book5.getHaveTotal());
    book5.removeBook();
    printAssertEquals(0, book5.getHaveShelf());
    printAssertEquals(0, book5.getHaveTotal());

    std::cout << "\nTesting waitListToString [should print 2 passes]\n";
    printAssertStringEqual("\nMembers waiting on 'Pride and Prejudice':\nnone\n", book6.waitListToString());
    book6.addWaiter(&mem1);
    printAssertStringEqual("\nMembers waiting on 'Pride and Prejudice':\nJoe Schmoe - JS2341657\n", book6.waitListToString());
    book6.removeWaiter();
    printAssertStringEqual("\nMembers waiting on 'Pride and Prejudice':\nnone\n", book6.waitListToString());
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


    runLibrary();
    BookTester();
    //libraryTester();
    //need to add a default constructor in book to store the shelf count
    //need to add the waitlist part in requesting books
    return 0;
}