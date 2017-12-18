//
// Created by Ben on 11/28/2017.
//

#ifndef FINALPROJECT_BOOK_H
#define FINALPROJECT_BOOK_H

#include "MemberLinkedQueue.h"
#include "LinkedList.h"
#include "Member.h"

class Book {

private:

    // title of book
    std::string title;
    // author of book
    std::string author;
    // isbn of book
    int isbn;
    // number of copies of this book owned by the library
    int haveTotal;
    // number of copies of this book on library's shelf available for checkout
    int haveShelf;
    // number of copies desired for ordering (due to none on shelf)
    int wantValue;
    // linked queue of Members waiting for this book (due to none on shelf)
    MemberLinkedQueue* waitList;
    // number of members waiting on this book
    int numWaiters;


public:

    /**
     * constructor
     * @param titleIn : Book's title
     * @param authorIn : Book's author
     * @param isbnIn : Book's ISBN
     * @param haveTotalIn : number of copies of this Book owned by this library
     */
    Book(std::string titleIn="", std::string authorIn="", int isbnIn=-1, int haveTotalIn=-1, int haveShelfIn=-1);

    // copy constructor
    Book (const Book &bookToCopy);
    // destructor
    ~Book();
    // equals operator
    Book& operator=(const Book& bookToCopy);
    // returns title of Book
    std::string getTitle();
    // returns author of Book
    std::string getAuthor();
    // returns ISBN of Book
    int getIsbn();
    // returns number of copies of Book available for checkout
    int getHaveShelf();
    // returns number of copies of Book owned by library
    int getHaveTotal();
    /**
     * change number of books of this title to reflect current number
     * @param change : number of title books being added / subtracted
     * @post Book's haveTotal and shelfTotal are in/decreased by change
     */
    void modHaveTotal(int change);
    /**
     * removes a copy of Book from shelf for checkout
     * @post Book's haveShelf count is decreased by 1
     */
    void checkBookOut();
    /**
     * returns a copy of Book back to shelf by checkin
     * @post Book's haveShelf count is increased by 1
     */
    void checkBookIn();
    /**
     * remove a copy of Book due to circumstances (lost, damaged, etc)
     * @post Book's haveTotal count is decreased by 1
     */
    void removeBook();
    /**
     * generates inquiry on requested book
     * @param book : book to give information about
     * @return string of the book's title, author, ISBN, and number currently available for checkout,
     * each on own separate line
     */
    std::string toString();
    /**
     * adds a Member to waiting list for Book
     * @param waiter - Member ptr representing member on waitlist
     * @post Book's numWaiters increased by 1, Member node added to queue
     */
    void addWaiter(Member* waiter);
    // returns number of members waiting on this book
    int waitListLength();
    /**
     * removes a member from Book's waitList due to ordered book's arrival
     * @return ptr to waitList's removed Member
     * @post waitList's first Member is removed, numWaiters decreased by 1
     */
    Member* removeWaiter();
    // returns names of members in waitList in comma-separated format
    std::string waitListToString();
};

#endif //FINALPROJECT_BOOK_H
