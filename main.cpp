#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    //file IO
    std::ifstream inf;
    inf.open("TestIO.txt");
    std::string author;
    std::string title;
    std::string isbnSTR;
    std::string numBooksSTR;
    if(!inf){
        std::cout << "didn't open" << std::endl;
    }
    while(inf){
        getline(inf, title);
        getline(inf, author);
        getline(inf, isbnSTR);
        getline(inf, numBooksSTR);
        std::cout << title << std::endl;
        std::cout << author << std::endl;
    }

              //<< " " << author << " " << isbnSTR << " " << numBooksSTR << std::endl;
    inf.close();
    return 0;
}