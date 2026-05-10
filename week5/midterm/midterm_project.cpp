#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Prototype functions 
void displayMenu ();
void addStudent (int &count, int maxStudents, struct Student students[]);
void removeStudent (int &count, struct Student students[]);
void displayAllStudents (int count, struct Student students[]);
void searchStudent (int count, struct Student students[]);
double calculateClassGPA (int count, struct Student students[]);
void generateAttendanceReport (int count, struct Student students[]);
void listHonorRoll (int count, struct Student students[]);

// Structure definition
struct Student{
    int id;
    string name;
    double gpa;
    int daysPresent;
    int totalDays;
};

int main ()
{
    const int MAX_STUDENTS = 10;
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                addStudent(studentCount, MAX_STUDENTS, students);
                break;
            case 2:
                removeStudent(studentCount, students);
                break;
            case 3:
                displayAllStudents(studentCount, students);
                break;
            case 4:
                searchStudent(studentCount, students);
                break;
            case 5: {
                double avgGPA = calculateClassGPA (studentCount, students);
                cout << fixed << setprecision(2);
                cout << "Class GPA Average: " << avgGPA << endl;
                break;
            }
            case 6:
                generateAttendanceReport(studentCount, students);
                break;
            case 7:
                listHonorRoll(studentCount, students);
                break;
            case 8:
                cout << "Leave Student Tracker program.\n";
                break;
            default:
                cout << "Not a valiid choice. Please choose one of the eight prompted choices.\n";
        }
    }while (choice !=8);
    return 0;
}

void displayMenu()
{
    cout << "=====Student Tracker System=====\n";
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. Display All Students\n";
    cout << "4. Search Student by name or Id\n";
    cout << "5. Calculate Class GPA Average\n";
    cout << "6. Generate Attendance Report\n";
    cout << "7. List of Honor Roll Students\n";
    cout << "8. Leave Student Tracker program.\n";
    cout << "Enter your choice: ";
}

void addStudent (int &count, int maxStudents, Student students[])
{
    if (count >= maxStudents){
        cout << "Unable to add more students, the max amount of students has been reached.\n";
        return;
    }
    cout << "Enter Studnt Id: ";
    cin >> students[count].id;
    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, students[count].name);

    cout << "Enter GPA (0.0-4.0): ";
    cin >> students[count].gpa;

    cout << "Enter days present: ";
    cin >> students[count].daysPresent;

    cout << "Enter totals days of school: ";
    cin >> students[count].totalDays;
    cin.ignore();

    count++;

    cout << "Student added successfully\n";
}

void removeStudent(int &count, Student students[])
{
    if (count == 0) {
        cout << "No students to remove.\n";
        return;
    }
    
    int id;
    cout << "Enter Student Id to remove: ";
    cin >> id;
    cin.ignore();

    bool found = false;
    for (int i = 0; i < count; i++){
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            found = true;
            cout << "Student removed successfully.\n";
            break;
        }
    }
    if (!found) {
        cout << "Student with Id " << id << " is not found.\n";
    }
}

void displayAllStudents (int count, Student students[]) 
{
    if (count == 0){
        cout << "No available students to display.\n";
        return;
    }

    for (int i = 0; i < count; i++){
        cout << "\n Student " << i + 1 << "  \n";
        cout << "Id: " << students[i].id << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << fixed << setprecision(2);
        cout <<"GPA: " << students[i].gpa << "\n";
        double attendancePercent = 0.0;
        if (students[i].totalDays > 0) {
            attendancePercent = (static_cast<double>(students[i].daysPresent) / students[i].totalDays) * 100;
        }
        cout << "Attendance: " << attendancePercent << "% (" << students[i].daysPresent << "/" << students[i].totalDays << ")\n"; 
    }
}

void searchStudent(int count, Student students[])
{
    if (count == 0) {
        cout << "No students available to search.\n";
        return;
    }
    int option;
    cout << "Search by: 1. Id, or 2. Name. \n";
    cout << "Enter choice: \n";
    cin >> option;
    cin.ignore();

    bool found = false;

    if (option == 1) { 
        int id;
        cout << "Enter Student Id: ";
        cin >> id;
        cin.ignore();
        for (int i = 0; i < count; i++){
            if (students[i].id == id) {
                cout << "Student Found: " << students[i].name << ", GPA: " << students[i].gpa << endl;
                found = true;
                break;
            }
        }
    }else if (option == 2) {
        string name;
        cout << "Enter Student Name: ";
        getline(cin, name);
        for (int i = 0; i < count; i++) {
            if (students[i].name.find(name) != string::npos) {
                cout << "Student Found: Id " << students[i].id << ", Name: " << students[i].name << ". GPA: " << students[i].gpa << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No matching student found.\n";
    }

}

double calculateClassGPA (int count, Student students[])
{
    if (count == 0) {
    return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += students[i].gpa;
        }
    return sum / count;
}

void generateAttendanceReport (int count, Student students[])
{
    if (count == 0){
        cout << "There are no students available for an attendance report.\n";
        return;
    }
    cout << "\n==== Student Attendance Report ====\n";
    for (int i = 0; i < count; i++) {
        double percent = 0.0;
        if (students[i].totalDays > 0) {
            percent = (static_cast<double>(students[i].daysPresent) / students[i].totalDays) * 100;
        }
        cout << students[i].name << " (Id: " << students[i].id << ")" 
        << fixed << setprecision(2) << percent << "% attendance\n"; 
    }
}

void listHonorRoll (int count, Student students[])
{
    if (count == 0) {
        cout << "There are no current students to list an honor roll.\n";
        return;
    }
    bool found = false;

    cout << "\n==== Honor Roll Students ====\n";
    for (int i = 0; i < count; i++) {
        if (students[i].gpa >= 3.5) {

            cout << "Name: " << students[i].name << ", GPA: " << students[i].gpa << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "There are no students that currently meet the honor roll criteria\n";
    }

}

/*=================================   Student Ttracker   ====================================*/

/************************************  CODE BREAKDOWN  **************************************/
/*
*   struct Student{
*    int id;
*    string name;
*    double gpa;
*    int daysPresent;
*    int totalDays;
*
*    This struct defines a student with id, name, gpa, daysPresent, and totalDAys.
*    This struct is used with the array Student students[MAX_STUDENTS] to store multiple students
*
*    ----------------------------------------------------------------------------------------
*
*    void displayMenu()
*
*    cout << "=====Student Tracker System=====\n";
*    cout << "1. Add Student\n";
*    cout << "2. Remove Student\n";
*    cout << "3. Display All Students\n";
*    cout << "4. Search Student by name or Id\n";
*    cout << "5. Calculate Class GPA Average\n";
*    cout << "6. Generate Attendance Report\n";
*    cout << "7. List of Honor Roll Students\n";
*    cout << "8. Leave Student Tracker program.\n";
*    cout << "Enter your choice: ";
*
*    The purpose of this function is to show a clear menu and prompt the user to choose one of the following options
*    and printing them out with cout <<
*
*    ------------------------------------------------------------------------------------------
*
*    void addStudent (int &count, int maxStudents, struct Student students[]);
*
*    The purpose of this function is to add a new student. 
*    It uses parameters &count, maxStudents, and array of student[] structs.
*    It works by 1. checking if there's room to add more students (count >= maxStudents). 2. PRompting the user to input Id, name, GPA
*    days present, and total school days. 3. It store a new student in students[count]. 4. Increments count.
*
*    ------------------------------------------------------------------------------------------
*
*    void removeStudent(int &count, Student students[])
*
*    The purpose of this function is to remove students by their Id.
*    It works by checking if the student count is 0, asks for student Id to remove, searches for the Id in a array, and if Id is found,  
*    the function shifts all students that came after the student removed, left one position to overwrite it and decrements the count--.
*
*    ------------------------------------------------------------------------------------------
*
*    void displayAllStudents (int count, Student students[]) 
*
*    The purpose of this function is to show all current student in the tracker program.
*    It checks first checks if the student count is 0 and if it is, it prints out "No available students to display."
*    It loops through the students array from index [0] to [count -1]. 
*    It prints Id, name, GPA, and attendance percentage % calculated by (daysPresent / totalDays) * 100.
*
*    -------------------------------------------------------------------------------------------
*
*    void searchStudent(int count, Student studetns[])
*
*    The purpsoe of this function is to find a student be their Id or namee.
*    It starts by checking if the student count is 0 and if it is it prints "No students available to search."
*    It prompts the user to choose to search by Id or name.
*    If user chooses Id, it loops through students array to find a match, and if user chooses search by name, the string name is used 
*    to search for the students name with the user input, and utilizing .find() to check if the input exists within the students name records.
*    It then prints out the students Id, name, and GPA if found, and if no match is found after the loop finishes, it prints "No matching student found."
*
*    -------------------------------------------------------------------------------------------
*
*    double calculateClassGPA (int count, Student students[])
*
*    The purpose of this function is to return the average GPA of the class.
*    It starts by checking if the count is 0 and if so, return 0.0. Otherwise, it adds all students[i].gpa to the sum and divides by the count.
*
*    --------------------------------------------------------------------------------------------
*
*    void generateAttendanceReport (imt count, Student students[])
*
*    The purpose of this function is to print out the attendance by % for each student.
*
*    The function starts by checking if the count of studentds is 0 and if so, it prints out "There are no students available for an attendance report."
*    It loops through each student and calculates their attendance by dividing daysPresent by totalDays, handling division by interger with static_cast<double>
*    to ensure floating point division. Afterward, it prints students name, Id, and the calculated attendance % ensuring two decimal places with setprecision(2).
*   
*    ---------------------------------------------------------------------------------------------
*
*    void listHonorRoll (int count, Studebnt students[i])
*
*    The purpose of this function is to list out students with a GPA equal to or greater than 3.5.
*    The function starts by checking if the student count is 0 and printing out "There are no current students to list an honor roll," if so.
*    It sets a boolean flag "found" to false to track if any student meets the honor roll criteria. 
*    It uses a for loop to loop through the students[i].gpa checking if any students GPA is greater than or equaL to 3.5.
*    It then prints out students name and GPA if they meet the honor roll criteria, and the "found" variable is set to true.
*
*/