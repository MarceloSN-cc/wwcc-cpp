#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
using namespace std;

class Author {
private:
    string name;
    int birthYear;

public: 
    // Constructor
    Author();
    Author(const string& name, int birthYear);
    
    // Accessor (getter)
    string getName() const;
    int getBirthYear() const;

    // Displayer
    void printAuthorInfo() const;
};

#endif