#include <iostream>
#include <iomanip>

using namespace std;

double dollarToEuro(double amount);
double dollarToPound(double amount);
double dollarToYen(double amount);
int getConversionCount();

int main () 
{
    char again;
    
    do {
    cout << "CURRENCY CONVERTER" << endl;
    cout << "-------------------" << endl;
    cout << "1. Convert USD to Euro (EUR)" << endl;
    cout << "2. Convert USD to British Pound (GBP)" << endl;
    cout << "3. Convert USD to Japanese Yen (JPY)" << endl;
    cout << "4. Exit" << endl;

    int choice; 
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice){
        case 1 :
            cout << ("Converting USD to Euro");
            break;
        case 2 :
            cout << ("Converting USD to British Pound");
            break;
        case 3 : 
            cout << ("Converting USD to Japanese Yen");
            break;
        default : 
            cout << ("Exiting program...\n");
            continue;
    }

    double amount;
    cout << "\nEnter amount in USD: ";
    cin >> amount;

    if (amount < 0 ){
        cout << "Please enter a positive value!" << endl;
        return 1;
    }

    cout << fixed << setprecision(2);
    if (choice == 1){
        cout << "The conversion from USD to EUR is: " << dollarToEuro(amount) << " Euros." << endl;
    } else if (choice == 2){
        cout << "The conversion from USD to GBP is: " << dollarToPound(amount) << " Pounds." << endl;
    } else {
        cout << "The conversion from USD to JPY is: " << dollarToYen(amount) << " Yen." << endl;
    } 
    cout << getConversionCount() << endl;

    cout << "\nWould you like to make anohter conversion? (y/n)";
    cin >> again;

    } while (again == 'y' || again == 'Y');
    cout << "\nThank you for using currency converter!" << endl;

    return 0;

}

int getConversionCount(){
    static int count = 0;
    count++;
    cout << "Number of conversions performed: ";
    return count;
}



double dollarToEuro(double amount)
{
    double EUR = 0.85;
    amount = amount * EUR;

    return amount;
}

double dollarToPound(double amount)
{
    double GBP = 0.74;
    amount = amount * GBP;

    return amount;
}

double dollarToYen(double amount)
{
    double JPY = 110.33;
    amount = amount * JPY;

    return amount;
}