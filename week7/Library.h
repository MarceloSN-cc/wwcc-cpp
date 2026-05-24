#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class Library {
private: 
    string name;
    vector<Book> books;

    string toLower(const string& str) const;

public: 
    // Constructors
    Library();
    Library(const string& n);

    // Operations
    string getLibraryName() const;
    void addBook(const Book& book);
    void displayAllBooks() const;
    void searchByAuthor(const string& authorName) const;
    void searchByTitle(const string& bookTitle) const;
    void showStats() const;
};

#endif