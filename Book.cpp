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
    waitList = new ArrayList<Member*>;
}

Book::Book (const Book &bookToCopy) {
    title = bookToCopy.title;
    author = bookToCopy.author;
    isbn = bookToCopy.isbn;
    haveTotal = bookToCopy.haveTotal;
    haveShelf = bookToCopy.haveShelf;
    wantValue = bookToCopy.wantValue;
    waitList = new ArrayList<Member*>;
    if (bookToCopy.waitList) {
        for (int i = 0; i < bookToCopy.waitList->itemCount(); ++i) {
            waitList->insertAtEnd(bookToCopy.waitList->getValueAt(i));
        }
    } else
        waitList = nullptr;
}

Book::~Book() {
    for (int i = 0; i < waitListLength(); ++i) {
        delete waitList->getValueAt(i);
    }
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
        std::cout << "\nBook successfully removed from system.\n";
    }
    else
        std::cout << "\nCan't remove a book we don't have!\n";
}

std::string Book::toString() {
    std::string printedInq;
    printedInq = "\nTitle: \t" + getTitle() + "\nAuthor:\t" + getAuthor();
    printedInq += "\nISBN: \t" + std::to_string(getIsbn());
    printedInq += "\nAvail:\t" + std::to_string(getHaveShelf());
    return printedInq;
}

void Book::addWaiter(Member* waiter) {
    int doAdd = 1;
    for (int i = 0; i < waitListLength(); ++i) {
        if (waitList->getValueAt(i)->getId() == waiter->getId()) {
            std::cout << "\n" + waiter->getName() + " is already on the waiting list for '" + getTitle() + "'.\n";
            doAdd = 0;
        }
    }
    if (doAdd)
        waitList->insertAtEnd(waiter);
}

const int Book::waitListLength() {
    return waitList->itemCount();
}

std::string Book::removeWaiter(Member* toRemove) {
    std::string result;
    if (waitList->isEmpty())
        return "\nNo members are waiting for '" + title + "'.\n";
    if (toRemove == nullptr)
        result = waitList->removeValueAt(0)->getName();
    else {
        int doRemove = 0;
        for (int i = 0; i < waitList->itemCount(); ++i) {
            if (waitList->getValueAt(i)->getName() == toRemove->getName()) {
                result = waitList->removeValueAt(i)->getName();
                doRemove = 1;
            }
        }
        if (doRemove)
            return ("\n" + result + " is no longer waiting for '" + title + "'.\n");
        else
            return "\n" + toRemove->getName() + " is not on the waitlist for '" + title + "'.\n";
    }
}

std::string Book::waitListToString() {
    std::string result = "\nMembers waiting on '" + title + "':\n";
    if (waitList->isEmpty())
        result += "none\n";
    else {
        for (int i = 0; i < waitListLength(); ++i)
            result += waitList->getValueAt(i)->getName() + " - " + waitList->getValueAt(i)->getId() + "\n";
    }
    return result;
}