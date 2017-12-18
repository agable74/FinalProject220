//
// Created by Ben on 12/1/2017.
//

#include "Book.h"
#include <iostream>

Book::Book(std::string titleIn, std::string authorIn, int isbnIn, int haveTotalIn, int haveShelfIn) {
    title = titleIn;
    author = authorIn;
    isbn = isbnIn;
    haveTotal = haveTotalIn;
    if (haveShelfIn == -1)
        haveShelf = haveTotalIn;
    else
        haveShelf = haveShelfIn;
    wantValue = 0;
    waitList = new MemberLinkedQueue;
    numWaiters = 0;
}

Book::Book(const Book &bookToCopy) {
    title = bookToCopy.title;
    author = bookToCopy.author;
    isbn = bookToCopy.isbn;
    haveTotal = bookToCopy.haveTotal;
    haveShelf = bookToCopy.haveShelf;
    wantValue = bookToCopy.wantValue;
    if (bookToCopy.waitList) {
        waitList = new MemberLinkedQueue(*bookToCopy.waitList);
    }
    else
        waitList = nullptr;
}

Book& Book::operator=(const Book &bookToCopy) {
    if (this != &bookToCopy) {
        delete this;
        Book* newBook = new Book(bookToCopy);
        title = bookToCopy.title;
        author = bookToCopy.author;
        isbn = bookToCopy.isbn;
        haveShelf = bookToCopy.haveShelf;
        haveTotal = bookToCopy.haveTotal;
        if (bookToCopy.waitList) {
            waitList = new MemberLinkedQueue(*bookToCopy.waitList);
        } else
            waitList = nullptr;
    }
    return *this;
}

Book::~Book() {}

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
    if (haveTotal + change < 0 || haveShelf + change < 0) {
        if (abs(change) == 1) {
            std::cout << "\nCannot remove " + std::to_string(abs(change)) + " copy of '";
            std::cout << title + "'.\n";
        }
        else {
            std::cout << "\nCannot remove " + std::to_string(abs(change)) + " copies of '";
            std::cout << title + "'.\n";
        }
    }
    else {
        haveTotal += change;
        haveShelf += change;
        std::cout << "\nBook count successfully updated.\n[Changed from " << tempHaveTotal;
        std::cout << " copies to " << haveTotal << "]\n";
    }
}

void Book::checkBookOut() {
    if (haveShelf > 0) {
        haveShelf--;
        std::cout << "\nCopy of " + title + " successfully checked out.\n";
    } else
        std::cout << "\nNo copies of " + title + " are available for checkout.\n";
}

void Book::checkBookIn() {
    haveShelf++;
    std::cout << "\nBook successfully checked in.\n";
}

void Book::removeBook() {
    if (haveTotal > 0 && haveShelf > 0) {
        haveTotal--;
        haveShelf--;
        std::cout << "\nA copy of '" + title + "' was successfully removed from system.\n";
    }
    else
        std::cout << "\nCan't remove a book we don't have!\n";
}

std::string Book::toString() {
    std::string printedInq;
    printedInq = "\nTitle: \t" + title + "\nAuthor:\t" + author;
    printedInq += "\nISBN: \t" + std::to_string(isbn);
    printedInq += "\nAvail:\t" + std::to_string(haveShelf);
    return printedInq;
}

void Book::addWaiter(Member* waiter) {
    numWaiters++;
    waitList->enqueue(waiter);
}

Member* Book::removeWaiter() {
    if (!(waitList->isEmpty())) {
        numWaiters--;
        return waitList->dequeue();
    }
}

int Book::waitListLength() {
    return numWaiters;
}

std::string Book::waitListToString() {
    std::string result = "";
    if (waitList->isEmpty())
        result += "none\n";
    else {
        MemberLinkedQueue* tempWaitList = new MemberLinkedQueue(*waitList);
        while (numWaiters > 0) {
            Member* waiter = tempWaitList->dequeue();
            std::string waiterName = waiter->getName();
            result += waiterName + ", ";
            numWaiters--;
        }
    }
    return result;
}