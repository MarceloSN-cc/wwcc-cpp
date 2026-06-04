#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Function protoypes part 1
void swapValues(int& a, int& b);
int findMaxValue(int* arr, int size);

//Function prototype part 2
void writeNote(ofstream&, const string& note);
void displayNotes(ifstream& file);

int main() {
    
    cout << "===PART 1: MEMORY AND ADDRESSING===";

    int age = 18;
    double gpa = 3.25;
    char grade = 'A';

    cout << "variable values and addresses:\n";
    cout << "   int    age\t" " = " << age;
    cout << "   at address " << &age << endl;

    cout << "   double gpa\t" " = " << gpa;
    cout << "   at address " << &gpa << endl;

    cout << "   char   grade\t" " = '" << grade;
    cout << "'  at address " << &grade << endl;

    cout << "\nReference demonstration: " << endl;

    int ageRef = age;

    cout << "   Before: age = " << age << endl;
    ageRef = 29;

    cout << "\n   After modifying through reference:\n";
    cout << "   age      = " << age << endl;
    cout << "   ageRef   = " << ageRef << endl;

    cout << "\nPointer demonstration:\n";

    int* ptr = nullptr;
    ptr = &age;

    if(ptr != nullptr) {
        cout << "   Pointer stores address: " << ptr << endl;
        cout << "   Value at that address:  " << *ptr << endl;

        *ptr = 100;

        cout << "   After modifying through pointer:\n";
        cout << "   age = " << age << endl;
    }

    cout << "\nSwap function (by reference):\n";
    
    int x = 10, y = 20;
    cout << "   Before swap: x = " << x << ", y = " << y << endl;
    
    swapValues(x, y); 
    
    cout << "\n   After swap: x = " << x << ", y = " << y << endl;

    //Array and Pointer relationship
    int numbers[] = {5, 12, 42, 21, 67};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "\nArray-pointer relationship:\n";

    cout << "   arr[0] = " << numbers[0] << "   *(arr + 0) = " << *(numbers + 0) << endl;
    cout << "   arr[1] = " << numbers[1] << "  *(arr + 1) = " << *(numbers + 1) << endl;

    int max = findMaxValue(numbers, size);

    cout << "   Maximum values (via pointer): " << max << endl;

    cout << "\n=== PART 2: FILE I/O ===\n";

    ofstream outfile("notes.txt", ios::app);

    if(!outfile) {
        cerr << "Error: Failed to open file for writing!" << endl;
        return 1;
    }

    string note;

    for(int i = 1; i <= 3; i++) {
        cout << "Enter note " << i << ": ";
        getline(cin, note);

        writeNote(outfile, note);
    }
    outfile.close();

    cout << "\nNotes written to notes.txt successfully!\n";

    ifstream inFile("notes.txt");
    if(!inFile) {
        cerr << "Error: Unable to open file for reading!" << endl;
        return 1;
    }

    cout << "\nReading notes back from file:\n";
    displayNotes(inFile);
    inFile.close();

    return 0;
}

//Part 1 functions
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int findMaxValue(int* arr, int size) {
    if(arr == nullptr || size <= 0) {
        return 0;
    }
    int maxValue = *arr;

    for(int i = 1; i < size; i++) {
        if(*(arr + 1) > maxValue) {
            maxValue = *(arr + 1);
        }
    }
    return maxValue;
}

//Part 2 functions
void writeNote(ofstream& file, const string& note) {
    file << note << endl;
}

void displayNotes(ifstream& file) {
    string line;

    while(getline(file, line)) {
        cout << " " << line << endl;
    }
}