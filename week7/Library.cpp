#include <iostream>
#include <cctype>
#include <algorithm>
#include "Library.h"

using namespace std;

// Default constructor
Library::Library() : name("Nameless Library") {}

// Parameterized Constructor
Library::Library(const string& n) : name(n) {}

// Operations
string Library::getLibraryName() const {
    return name;
}
void Library::addBook(const Book& book) {
    books.push_back(book);
}

string Library::toLower(const string& str) const {
    string result = str;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

void Library::displayAllBooks() const {
    if(books.empty()) {
        cout << "No current books in catalog.\n";
        return;
    }
    cout << "\nCATALOG:\n";
    for(size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". ";
        books[i].printAllBookInfo(); 
        cout << "\n"; 
    }
}

void Library::searchByAuthor(const string& authorName) const {
    string search = toLower(authorName);
    bool found = false;

    for (const Book& book : books) {
        string author = toLower(book.getAuthor().getName());
        if(author.find(search) != string::npos) {
            if(!found) {
                cout << "Books by " << book.getAuthor().getName()
                << ":\n";
            }
            cout << "   - \"" << book.getTitle() << "\" (" 
            << book.getPublicationYear() <<  ")\n";

        found = true;
        }
    }
    if(!found) {
        cout << "No books by " << authorName << " found.\n";
    }
}

void Library::searchByTitle(const string& bookTitle) const {
    string search = toLower(bookTitle);
    bool found = false;

    for(const Book& book : books) {
        string title = toLower(book.getTitle());
        if(title.find(search) != string::npos) {
            cout << "   - \"" << book.getTitle() << "\" ("
            << book.getPublicationYear() << ")\n";

            found = true;
        }
    }
    if(!found) {
        cout << "No books with the title " << bookTitle << " found.\n";
    }
}

void Library::showStats() const {
    cout << "\nSTATS:\n";
    cout << "   Current total books in catalog: " << books.size() << "\n";
}