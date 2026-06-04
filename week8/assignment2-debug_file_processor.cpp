#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // Included algorithm for max() and min().
using namespace std;

struct Student {
    string lastName;
    string firstName;
    int g1, g2, g3;
    double average;
    int high;
    int low;
};

int main() {
    // --- Read input file ---
    ifstream inFile("grades.txt");

    // Bug 1 is here
    // BUG: Doesn't check whether grades.txt opened successfully.
    // FIX: Added a check using is_open() to verify the file opened successfully.
    if(!inFile.is_open()) {
        cerr << "Error: Could not open grades.txt." << endl;
        return 1;
    }

    cout << "Reading records from grades.txt..." << endl;

    vector<Student> students;
    string line;
    // stringstream ss;     // Bug 4 is here

    // BUG: Using while(!inFile.eof()) can cause the final record 
    // to be proccessed incorrectly because of .eof() is only set 
    // after a failed read attempt.
    // FIX: Replace with (getline(inFile, line)) for line-by-line reading.
    while (getline(inFile, line)) {
        if (line.empty() || line[0] == '#') 
            continue;

        // Bug 4 continued — ss is never reset between iterations
        // BUG: stringstream was declared outside of the loop 
        // causing parsing data to spread between iterations.
        // FIX: Replaced with stringstream ss(line) inside the loop
        // for each line.
        stringstream ss(line);    // move ss inside loop to fix Bug 4

        Student s;
        if(ss >> s.lastName >> s.firstName >> s.g1 >> s.g2 >> s.g3) {
   
        s.high = max({s.g1, s.g2, s.g3});
        s.low  = min({s.g1, s.g2, s.g3});

        
        int total = s.g1 + s.g2 + s.g3;

        // BUG: Does not take into consideration integer division.
        // FIX: Cast the toal to double and divide by 3.0 to account for decimal precision.
        s.average = static_cast<double>(total) / 3.0;    // Bug 5 is here

        students.push_back(s);
        }
    }

    inFile.close();

    cout << students.size() << " students loaded." << endl << endl;

    // --- Write report ---
    // BUG: Opening the file as it was overwrites previous files 
    // which erases them.
    // FIX: Opening file in append mode ::app to avoid overwriting 
    // previous files.
    ofstream outFile("grade_report.txt", ios::app);   // Bug 3 is here

    // --- Display to console and write to file ---
    auto printReport = [&](ostream& out) {
        out << "GRADE REPORT" << endl;
        out << string(42, '-') << endl;

        out << left
            << setw(24) << "Name"
            << setw(7)  << "Avg"
            << setw(7)  << "High"
            << setw(7)  << "Low"
            << endl;
        out << string(42, '-') << endl;

        double classTotal = 0;
        int topIdx = 0, lowIdx = 0;

        // Bug 6: setw is applied once here, outside the loop
        // out << setw(20);

        for (int i = 0; i < (int)students.size(); i++) {
            Student& s = students[i];
            string name = s.lastName + ", " + s.firstName;
            // BUG: setw(20) was applied only once outside the loop.
            // FIX: Repositioned setw(20) to each row's name.

            // Bug 7: numbers should be right-aligned, not left
            // BUG: Numeric columns were aligned to the left.
            // FIX: Set numbers to be aligned to the right.
            out << left << setw(20) << name
                << right << setw(7)  << fixed << setprecision(1) << s.average
                << setw(7) << s.high
                << setw(7) << s.low
                << endl;

            classTotal += s.average;
            if (s.average > students[topIdx].average) topIdx = i;
            if (s.average < students[lowIdx].average) lowIdx = i;
        }

        double classAvg = classTotal / students.size();

        out << endl << "CLASS STATISTICS" << endl;
        out << string(42, '-') << endl;
        out << fixed << setprecision(1);
        out << "Class average: " << classAvg << endl;
        out << "Top student:   "
            << students[topIdx].lastName << ", "
            << students[topIdx].firstName
            << " (" << students[topIdx].average << ")" << endl;
        out << "Low student:   "
            << students[lowIdx].lastName << ", "
            << students[lowIdx].firstName
            << " (" << students[lowIdx].average << ")" << endl;
    };

    printReport(cout);
    printReport(outFile);
    outFile.close();

    cout << endl << "Report written to grade_report.txt" << endl;
    return 0;
}