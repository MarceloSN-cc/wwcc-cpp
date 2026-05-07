#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int countVowels(string word);
int countConsonants(string word);
bool isPalindrome(string word);
char firstLetter(string word);
string reverse(string word);

int main (){
    string word;
    char choice;
    do {
        cout << "Enter a word: " << endl;
        getline(cin, word);

        cout << "Word Analyzer!" << endl;
        cout << "---------------" << endl;
        cout << "Original word: " << word << endl;
        cout << "Number of vowels: " << countVowels(word) << endl;
        cout << "Number of consonants: " << countConsonants(word) << endl;
        cout << "First letter: " << firstLetter(word) << endl;
        cout << "Reversed: " << reverse(word) << endl;
        cout << "Is a palindrome: " << (isPalindrome(word) ? "Yes!" : "No!") << endl;

        cout << "Would you like to analyze another word? (y/n): ";
        cin >> choice;
        cin.ignore();

        while (choice != 'y' && choice != 'n'){
            cout << "Please choose either y (for yes) or n (for no)!" << endl;
            cin >> choice;
            cin.ignore();
        }
    }while (tolower(choice) == 'y');

    cout << "Thank you for using Word Analyzer!" << endl;
}
// Function to check for vowels
int countVowels(string word)
{
    int count = 0;
    for (char c : word){
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            count++;
        }
    }
    return count;
}
// Function to count consonants and ignore spaces 
int countConsonants(string word) 
{
    int count = 0;
    for (char c : word) {
        c = tolower(c);
        if (isalpha(c) && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')){
            count ++;
        }
    }
    return count;
}
// Function to reverse words and check if it's a palindrome
bool isPalindrome(string word)
{
    int left = 0;
    int right = word.length() - 1;

    while (left < right) {
        if(tolower(word[left]) != tolower(word[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
// Function to check for empty words, prevents errors if empty, and return the first letter
char firstLetter(string word)
{
    if (word.empty())
    return '\0';

    return word[0];
}
// Function to reverse a word 
string reverse(string word)
{
    string reversedStr = "";
    for ( int i = word.length() -1; i >= 0; i--){
        reversedStr += word[i];
    }
    return reversedStr;
}