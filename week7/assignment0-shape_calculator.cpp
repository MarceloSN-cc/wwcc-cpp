#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle {
private: 
    double length;
    double width;

public: 
    // Constructor and handles cases of negative numbers 
    // by assigning 1 to length and width
    Rectangle(double l, double w)
    : length(1), width(1) {
        setLengthSize(l);
        setWidthSize(w);
    }

    // Accessors (getters)
    double getLengthSize() const;
    double getWidthSize() const;

    // Mutators (setters)
    void setLengthSize(double l);
    void setWidthSize(double w);

    // Overloaded area methods
    double area() const;
    void area(double &result) const;

    // Resize method
    Rectangle& resize(double factor);
};

double Rectangle::getLengthSize() const {return length;}

double Rectangle::getWidthSize() const {return width;}

void Rectangle::setLengthSize(double l) {
    if (l <= 0){
        cout << "The length must be a positive number!" << endl;
        return;
    } 
    length = l;
}

void Rectangle::setWidthSize(double w) {
    if (w <= 0){
        cout << "The width must be a positive number!" << endl;
        return;
    } 
    width = w;
}

double Rectangle::area() const {
    return length * width;
}

void Rectangle::area(double &result) const{
    result = length * width;
}

Rectangle& Rectangle::resize(double factor) {
    if (factor > 0) {
        this->length *= factor;
        this->width *= factor;
    }
    else {
        cout << "Resize factor must be positive!" << endl;
    }
    return *this;
}

class Circle {
private: 
    double radius;

public: 
    // Constructor
    Circle(double r)
    : radius(1) {
        setRadius(r);
    } 

    // Accessor (getter) 
    double getRadius() const;

    // Mutator (setter) with validation
    void setRadius(double r);

    // Const methods
    double area() const;
    double circumference() const;

    // Overloaded print methods
    void print() const;
    void print(bool fullCalculation) const;
};

double Circle::getRadius() const{
    return radius;
}

void Circle::setRadius(double r) {
    if(r <= 0) {
        cout << "The radius must be positive!" << endl;
        return;
    }
    radius = r;
}

double Circle::area() const {
    return 3.14159 * radius * radius;
}

double Circle::circumference() const {
    return 2 * 3.14159 * radius;
}

void Circle::print()  const {
    cout << "Circle (Radius: " << radius << ")"<< endl;
    cout << "Area: " << area() << endl;
    cout << "Circumference: " << circumference() << endl;
}

void Circle::print(bool fullCalculation) const {
    if(fullCalculation) {
        cout << "\nCircle Details:\n";
        cout << " Radius: " << radius << endl;
        cout << " Area: pi * " << radius << "^2 = " << area() << endl;
        cout << " Circumference: 2 * pi * " << radius << " = " << circumference() << endl; 
    } else {
        print();
    }
}

int main () {
    double length, width;
    cout << "Enter rectangle length: ";
    cin >> length;

    cout << "Enter rectangle width: ";
    cin >> width;

    // Rectangle object
    Rectangle rect(length, width);

    cout << fixed << setprecision(2);

    cout << "Rectangle (Length: " << rect.getLengthSize()
         << ", Width: " << rect.getWidthSize() << ")\n";
    cout << "Area: " << rect.area() << endl;
    
    double reference;
    rect.area(reference);
    cout << "Area via reference: " << reference << endl;

    double radius;
    cout << "Enter circle radius: ";
    cin >> radius;

    // Circle object
    Circle circ(radius);

    circ.print();

    // Overloaded full calculation print
    circ.print(true);

    // Method chaining 
    cout << "\nMethod chaining:\n";
    cout << "Original ==> Length: " << rect.getLengthSize() 
         << ", Width: " << rect.getWidthSize() << endl;
    
    double factor;

    cout << "Enter resize factor: ";
    cin >> factor;

    rect.resize(factor);

    cout << "After resize() ==> Length: " << rect.getLengthSize()
         << ", Width: " << rect.getWidthSize() << endl;

    return 0;
}