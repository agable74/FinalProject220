//
// Created by Ben on 12/1/2017.
//

#include "Book.h"

    Book::Book(std::string titleIn, std::string authorIn, int isbnIn, int haveTotalIn) {
        title = titleIn;
        author = authorIn;
        isbn = isbnIn;
        haveTotal = haveTotalIn;
        haveShelf = haveTotalIn;
        wantValue = 0;
    }

    Book::Book (const Book &bookToCopy) {
        title = bookToCopy.title;
        author = bookToCopy.author;
        isbn = bookToCopy.isbn;
        haveTotal = bookToCopy.haveTotal;
        haveShelf = bookToCopy.haveShelf;
        wantValue = bookToCopy.wantValue;
    }

    Book::~Book() {
    }

    std::string Book::getTitle() {
        return title;
    }

    std::string Book::getAuthor() {
        return author;
    }

    int Book::getIsbn() {
        return isbn;
    }

    int Book::getHaveShelf() {
        return haveShelf;
    }

    int Book::getHaveTotal() {
        return haveTotal;
    }

    void Book::modHaveTotal(int change) {
        int tempHaveTotal = haveTotal;
        haveTotal += change;
        haveShelf += change;
        std::cout << "\nBook count successfully updated.\n[Changed from " << tempHaveTotal;
        std::cout << " copies to " << haveTotal << "]\n";
    }

    void Book::checkBookOut() {
        haveShelf--;
        std::cout << "\nBook successfully checked out.\n";
    }

    void Book::checkBookIn() {
        haveShelf++;
        std::cout << "\nBook successfully checked in.\n";
    }

    void Book::removeBook() {
        if (haveTotal > 0) {
            haveTotal--;
            haveShelf--;
            std::cout << "\nBook successfully removed from system.\n";
        }
        else
            std::cout << "\nCan't remove a book we don't have!\n";
    }

    std::string Book::bookInquiry() {
        std::string printedInq;
        printedInq = "\nTitle: \t" + getTitle() + "\nAuthor:\t" + getAuthor();
        printedInq += "\nISBN: \t" + std::to_string(getIsbn());
        printedInq += "\nAvail:\t" + std::to_string(getHaveShelf());
        return printedInq;
    }