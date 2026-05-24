#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"
using namespace std;

class Book {
private: 
    string title;
    int publicationYear;
    string isbn;
    Author author;

public: 
    // Constructor
    Book();
    Book(const string& t, int pY, const string& i,  const Author& author);

    // Accessors (getters)
    string getTitle() const;
    int getPublicationYear() const;
    string getISBN() const;
    Author getAuthor() const;

    // Mutator (setter)
    void setPublicationYear(int year);

    // Display
    void printAllBookInfo() const;
};

#endif