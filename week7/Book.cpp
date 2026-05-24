#include <iostream>
#include "Book.h"

using namespace std;

// Default constructor
Book::Book() : title(""), publicationYear(0), isbn(""),  author() {}

// Parameterized Constructor
Book::Book(const string& t, int pY, const string& i, const Author& author)
    : title(t), publicationYear(pY), isbn(i), author(author) {}

// Accessors (getters)
string Book::getTitle() const { return title; }
int Book::getPublicationYear() const { return publicationYear; }
string Book::getISBN() const { return isbn; }
Author Book::getAuthor() const { return author; }

// Mutators
void Book::setPublicationYear(int year) {
    if(year < 0) {
        cout << "Disclaimer: Invalid year. Setting to 0." << endl;
        publicationYear = 0;
    } else {   
        publicationYear = year;
    }
}

// Display 
void Book::printAllBookInfo() const {
    cout << "\"" << title << "\" (" << publicationYear << ")" << endl;
    author.printAuthorInfo();
    cout << "  ISBN: "  << isbn << endl;
}