#include <iostream>
#include <string>
#include "Library.h"
#include "Book.h"
#include "Author.h"

using namespace std;

int main () {
    Library library("Central City Library");

    int choice;

    do{
        cout << "\nLIBRARY MANAGEMENT SYSTEM\n";
        cout << "-----------------------------\n";
        cout << library.getLibraryName() << "\n\n" << endl;

        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search by Author\n";
        cout << "4. Search by Title\n";
        cout << "5. Show Stats\n";
        cout << "6. Exit\n";

        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                string title;
                int publicationYear;
                string isbn;
                string authorName;
                int birthYear;

                cout << "Enter title: ";
                getline(cin, title);

                cout << "Enter publication year: ";
                cin >> publicationYear;
                cin.ignore();

                cout << "Enter ISBN: ";
                getline(cin, isbn);

                cout << "Enter author name: ";
                getline(cin, authorName);

                cout << "Enter author's birth year: ";
                cin >> birthYear;
                cin.ignore();

                // Object calling
                Author author(authorName, birthYear);
                Book book(title, publicationYear, isbn, author);

                // Method calling dot notation
                library.addBook(book);

                cout << "Book added successfully!\n";

                break;
            }
            case 2: 
                library.displayAllBooks();
                break;
            
            case 3: {
                string author;

                cout << "Search by author: ";
                getline(cin, author);

                library.searchByAuthor(author);
                break;
            }
            case 4: {
                string bookTitle;

                cout << "Search by title: ";
                getline(cin, bookTitle);

                library.searchByTitle(bookTitle);
                break;
            }
            case 5: 
                library.showStats();
                break;
            
            case 6: 
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Not a valid option!\n";
        } 
    }while(choice != 6);

    return 0;
}