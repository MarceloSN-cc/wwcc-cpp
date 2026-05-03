#include <iostream>
#include <sstream>
#include <iomanip>
#include <string> 
#include <cctype>

using namespace std;

//Prototype functions 
string format(long long int num);
string format(double num);
string format(double num, int precision);
string format(string text);

int main () 
{
    long long int largeNum;
    cout << "Enter a large number: " << endl; 
    cin >> largeNum;
    cout << "Formatted: " << format(largeNum) << endl;

    double decimalNumPrecTwo;
    cout << "Enter a decimal number for decimal precision to two decimal palces: " << endl;
    cin >> decimalNumPrecTwo;
    cout << "Formatted: " << format(decimalNumPrecTwo) << endl;

    int precision = 4;
    cout << "Integer precision for decimal number: " << precision << "Formatted: \n" 
        << format(decimalNumPrecTwo, precision) << endl;

    cin.ignore();
    string strText;
    cout << "Enter a sentence you would like formmated: " << endl;
    getline(cin, strText);
    cout << "Formatted: " << format(strText) << endl;

    return 0;
}

// Aproach:
/* Converting long long int into to a string using to_string(abs(num)). While loop and s.insert 
 * to add commas every 3 digits and handling negative numbers by adding a negative sign if the number
 * is less than 0.
 */
string format(long long int num)
{
    string s = to_string(abs(num));
    int placePosition = s.length() - 3;

    while (placePosition > 0) {
        s.insert(placePosition, ",");
        placePosition -= 3;
    }
    return (num < 0) ? "-" + s : s;
}

// Aporach:
/* For conveniene, this calls a function that passes a default precision of 2.
*/
string format(double num)
{
    return format(num,2);
}

// Aproach:
/* Using stringstream to build a formatted string. Use of 'fixed' to ensure number is represented in standard 
 * decimal notation. And setprecision(precision) to set how many digits appear after the decimal point.
*/
string format(double num, int precision) 
{
    stringstream stream;
    stream << fixed <<  setprecision(precision) << num;
    return stream.str();
}

// Aproach:
/* If text is empty, returs the input to avoid errors. Using a bool newWord initialized to true because 
 * the first character encountered after each word is the start of a new word. And every loop tracks spaces 
* because after a space the next character will be the start of a new word.
*/
string format(string text) 
{
    if (text.empty()) return text; 

    bool newWord = true;
    for (char &c : text) { 
        if (isspace(c)) {
            newWord = true;
        }else if (newWord) {
            c = toupper(c);
            newWord = false;
        }
    }
    return text;
}