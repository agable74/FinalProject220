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
    List<People> memberList;
    //pointer to list of books in library
    List<Book> inBooks;
    //pointer to list of books checked out
    List<Book> outBooks;

public:
    /**
     * Constructor
     */
    Library();

    /**
     * Copy Constructor
     * @param libraryListToCopy
     */
    Library(const Library& libraryListToCopy);


    /**
     * Copy Constructor
     * @param libraryListToCopy
     * @return
     */
    Library& operator=(const Library& libraryListToCopy);

    /**
     * Destructor
     */
    ~ArrayList();
};
#endif //FINALPROJECT_LIBRARY_H
