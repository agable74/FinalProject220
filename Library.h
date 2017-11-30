//
// Created by Alex on 11/30/2017.
//

#ifndef FINALPROJECT_LIBRARY_H
#define FINALPROJECT_LIBRARY_H

#include "People.h"
#include "Book.h"

class Library{
private:
    //pointer to list of library members
    People* memberList;
    //pointer to list of books in library
    Book* inBooks;
    //pointer to list of books checked out
    Book* outBooks;

public:
    /**
     * Constructor
     * Creates a library
     */
};
#endif //FINALPROJECT_LIBRARY_H
