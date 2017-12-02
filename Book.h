//
// Created by Ben on 11/28/2017.
//

#ifndef FINALPROJECT_BOOK_H
#define FINALPROJECT_BOOK_H

#include <string>
#include <iostream>

class Book {

private:

    std::string title;
    std::string author;
    int isbn;
    int haveTotal;
    int haveShelf;
    int wantValue;

public:

    /**
     * constructor
     * @param titleIn : book's title
     * @param authorIn : book's author
     * @param isbnIn : book's ISBN
     * @param haveTotalIn : number of books by this title owned by this library
     */
    Book(std::string titleIn, std::string authorIn, int isbnIn, int haveTotalIn);

    /**
     * copy contructor
     * @param bookToCopy
     */
    Book (const Book &bookToCopy);

    /**
     * assignment operator
     * @param bookToCopy
     */
    Book& operator=(const Book& bookToCopy);

    /**
     * destructor
     */
    ~Book();
    /**
     * getter for book's title
     * @return book's title
     */
    std::string getTitle();
    /**
     * getter for book's author
     * @return book's author
     */
    std::string getAuthor();
    /**
     * getter for book's ISBN
     * @return book's ISBN
     */
    int getIsbn();
    /**
     * getter for number of books of its title on shelf
     * @return number of available books
     */
    int getHaveShelf();
    /**
     * getter for number of books of its title total owned by library
     * @return number of books library owns
     */
    int getHaveTotal();
    /**
     * change number of books of this title to reflect current number
     * @param newTotal : number of books the library -now- has of this title
     * @post book's haveTotal is updated to newTotal
     */
    void setHaveTotal(int newTotal);
    /**
     * decrease available number of books on shelf by 1
     * @post book's haveShelf count is decreased by 1
     */
    void checkBookOut();
    /**
     * increase available number of books on shelf by 1
     * @post book's haveShelf count is increased by 1
     */
    void checkBookIn();
    /**
     * decrease available number of books in library by 1 (due to being lost, damaged, etc.)
     * @post book's haveTotal count is decreased by 1
     */
    void removeBook();
    /**
     * generates inquiry on requested book
     * @param book : book to give information about
     * @return string of the book's title, author, ISBN, and number currently available for checkout,
     * each on own separate line
     */
    std::string printInquiry(Book* book);
};

#endif //FINALPROJECT_BOOK_H
