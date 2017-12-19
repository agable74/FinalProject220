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

void MemberTester() {
    std::cout << "Testing Member Copy Constructor [should print 2 passes]\n";
    Member mem1 = Member("Ken Pickens", 1052741034, "kp@gmail.com", "KP1234567", "Phone call");
    Member mem2 = Member(mem1);
    printAssertStringEqual(mem1.getName(), mem2.getName());
    printAssertStringEqual(mem1.getId(), mem2.getId());

    std::cout << "Testing Member Assignment Operator [should print 2 passes]\n";
    Member mem3 = Member("Lois Loan", 6072741333, "lLoan@dailyplanet.net", "LL5006886", "Text message");
    mem2 = mem3;
    printAssertStringEqual(mem3.getName(), mem2.getName());
    printAssertStringEqual(mem2.getEmail(), mem3.getEmail());

    std::cout << "\nTesting Member getters [should print 5 passes]\n";
    printAssertStringEqual("Ken Pickens", mem1.getName());
    printAssertEquals(1052741034, mem1.getPhoneNumber());
    printAssertStringEqual("kp@gmail.com", mem1.getEmail());
    printAssertStringEqual("KP1234567", mem1.getId());
    printAssertStringEqual("Phone call", mem1.getContactPref());

    std::cout << "\nTesting Member setContactPref [should print 4 passes]\n";
    printAssertStringEqual("Phone call", mem1.setContactPref("call"));
    printAssertStringEqual("Phone call", mem1.setContactPref("ph"));
    printAssertStringEqual("Text message", mem1.setContactPref("txt"));
    printAssertStringEqual("Email", mem1.setContactPref("E"));

    std::cout << "\nTesting Member toString [should print 1 pass]\n";
    // "Lois Loan", 6072741333, "lLoan@dddailyppplanet.com", "LL5006886", "Text message"
    printAssertStringEqual("\nPatron name: Lois Loan\nPhone number: 607-274-1333\nMember ID: LL5006886"
                                   "\nEmail: lLoan@dailyplanet.net\nContact by: Text message\n", mem3.toString());

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

    std::cout << "\nTesting Book Copy Constructor [should print 4 passes]\n";
    Book book1_1 = book1;
    printAssertStringEqual(book1.getTitle(), book1_1.getTitle());
    printAssertStringEqual(book1.toString(), book1_1.toString());
    printAssertEquals(book1.getHaveTotal(), book1_1.getHaveTotal());
    printAssertEquals(book1.getIsbn(), book1_1.getIsbn());
    std::cout << "\nTesting Book Assignment Operator [should print 5 passes]\n";
    Book rose = Book("Flowery Things", "Rose P. et al", 556655, 5, 3);
    Book mud = Book("Muddy Paths", "Lan Zlide", 555555, 4, 2);
    Book thai = Book("One Night in Bangkok", "Lei Turon", 488484, 1, 1);
    printAssertStringEqual("One Night in Bangkok", thai.getTitle());
    thai = mud;
    printAssertStringEqual(mud.getAuthor(),  thai.getAuthor());
    printAssertEquals(mud.getHaveTotal()-mud.getHaveShelf(), thai.getHaveTotal()-thai.getHaveShelf());
    mud = rose = thai;
    printAssertStringEqual("Lan Zlide", thai.getAuthor());
    printAssertEquals(555555, rose.getIsbn());

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


    std::cout << "\nTesting waitListToString [should print 3 passes]\n";
    printAssertStringEqual("none\n", book6.waitListToString());
    book6.addWaiter(&mem1);
    printAssertStringEqual("Joe Schmoe", book6.waitListToString());
    book6.removeWaiter();
    printAssertStringEqual("none\n", book6.waitListToString());
}

void runLibrary(){
    Library theLibrary = Library("AllBooksNew.txt","TestMembers.txt","TestDeliveryIN.txt");
    theLibrary.masterRun();
}

void libraryTester(){
    BookTester();
    MemberTester();
    Library theTestLibrary = Library("BooksTester.txt","MembersTester.txt","DeliveryTester.txt");
    Library theTestLibraryCopy = theTestLibrary;
    theTestLibraryCopy.removeBook("Lord of the Flies",7);
    theTestLibrary.removeBook("A Tale of Two Cities",2);
    std::cout << "Testing Library Copy constructor. Should print 3 passes." << std::endl;
    printAssertEquals(7,theTestLibrary.getShelfValue("Lord of the Flies")-theTestLibraryCopy.getShelfValue("Lord of the Flies"));
    printAssertEquals(2,theTestLibraryCopy.getShelfValue("A Tale of Two Cities")-theTestLibrary.getShelfValue("A Tale of Two Cities"));
    printAssertEquals(theTestLibrary.getShelfValue("The Great Gatsby"),theTestLibraryCopy.getShelfValue("The Great Gatsby"));

    theTestLibraryCopy = theTestLibrary;
    theTestLibraryCopy.removeBook("Lord of the Flies",8);
    theTestLibrary.removeBook("To Kill a Mockingbird",4);
    std::cout << "Testing Library equals operator. Should print 3 passes." << std::endl;
    printAssertEquals(theTestLibrary.getShelfValue("Pride and Prejudice"),theTestLibraryCopy.getShelfValue("Pride and Prejudice"));
    printAssertEquals(8,theTestLibrary.getShelfValue("Lord of the Flies")-theTestLibraryCopy.getShelfValue("Lord of the Flies"));
    printAssertEquals(4,theTestLibraryCopy.getShelfValue("To Kill a Mockingbird")-theTestLibrary.getShelfValue("To Kill a Mockingbird"));

    Library testIOLibrary("BooksTester2.txt","MembersTester2.txt","DeliveryTester2.txt");
    testIOLibrary.removeBook("Lord of the Flies",9);
    Book* testBook = new Book("Little Women","Louisa May Alcott",34520,0);
    Member* testMember = new Member("Test McTesty",123456789,"test@test.com","TM1235","Phone call");
    Member* testMember2 = new Member("Ken Pickens", 1052741034, "kp@gmail.com", "KP1234567", "Phone call");
    testIOLibrary.addMember(testMember);
    testIOLibrary.addMember(testMember2);
    testIOLibrary.requestLoan(testBook,testMember);
    testIOLibrary.requestLoan(testBook,testMember2);
    testIOLibrary.checkOutBook("The Great Gatsby");
    testIOLibrary.quit();
}



int main() {
    //runLibrary();
    libraryTester();
    //for libraryTester, there are the text files DeliveryTester2.txt, MembersTester2.txt, and BooksTester2.txt
    //which indicate changing of file IO
    return 0;
}