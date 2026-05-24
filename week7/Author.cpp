#include <iostream>
#include "Author.h"

using namespace std;

//Default constructor 
Author::Author() : name(""), birthYear(0) {}

//Constructor
Author::Author(const string& name, int birthYear)
        : name(name), birthYear(birthYear) {}

//Accessors (getters)
string Author::getName() const {return name;}
int Author::getBirthYear() const {return birthYear;}

//Displayer
void Author::printAuthorInfo() const {
    cout << "Author name: " << name << " (born " << birthYear << ")" << endl;
}