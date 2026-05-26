#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    //Restuctured, made variables private
    string accountName;
    string accountNumber;
    double balance;
    string accountType;
    bool isActive;

    //Named constants to replace magic numbers
    const double SAVINGS_INTEREST_RATE = 0.03;
    const double CHECKING_INTEREST_RATE = 0.01;
    const double BUSINESS_INTEREST_RATE = 0.005;

public: 
    //Replaced the previous setup() with constructor that validates variables
    BankAccount(const string& accName, const string& accNum, 
          double initialBalance, const string& type) 
        : accountNumber(accNum), accountName(accName), balance(initialBalance), 
          accountType(type), isActive(true) {
            if(accName.empty()) {
                cout << "Error: Account name cannot be empty!" << endl;
                isActive = false;
                return;
            }
            if(accNum.empty()) {
                cout << "Error: Account number cannot be empty!" << endl;
                isActive = false;
                return;
            }
            if(accountType != "Savings" && accountType != "savings"
            && accountType != "Checking" && accountType != "checking"
            && accountType != "Business" && accountType != "business") {
                cout << "Error: Invalid account type!" << endl;
                isActive = false;
                return;
            }
            if(initialBalance < 0) {
                cout << "Warning: Initial balance cannot be negative. Setting balance to 0." << endl;
                balance = 0;
            }
          }
    
    //Addition of accessors (getters) previous code did not include proper getter functions
    string getAccountName() const { return accountName; }
    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    string getAccountType() const { return accountType; }
    bool getIsActive() const { return isActive; }

    //Restructured functions to handle potential negative amount
    void deposit(double amount) {
        if(!isActive) {
            cout << "Error: Account is inactive, cannot deposit." << endl;
            return;
        }
        if(amount <= 0) {
            cout << "Error: The deposit amount must be greater than zero!" << endl;
            return;
        }
        balance += amount;
    }
    //Renamed and added safety net if amount is negative
    bool withdraw(double amount) {
        if(!isActive) {
            cout << "Error: Account is inactive, cannot withdraw." << endl;
            return false;
        }
        if(amount <= 0) {
            cout << "Error: The withdrawal amount must not be less than zero!" << endl;
            return false;
        }
        if(amount > balance) {
            cout << "Error: Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        return true;
    }
    //Use of named constants instead of magic numbers
    void applyInterest() {
        if(isActive && (accountType == "Savings" || accountType == "savings")) {
            balance += balance * SAVINGS_INTEREST_RATE; 
        }
        else if(isActive && (accountType == "Checking" || accountType == "checking")){
            balance += balance * CHECKING_INTEREST_RATE;
        }
        else if(isActive && (accountType == "Business" || accountType == "business")) {
            balance += balance * BUSINESS_INTEREST_RATE;
        }
    }
    //Reorganized, remade, and renamed for clarity
    void closeAccount() {
        if(balance > 0) {
            cout << "Withdraw the remaining " << balance 
            << " funds from your account before closing." << endl;
            return;
        }
        isActive = false;
        cout << accountName << " - " << accountNumber;
        cout << ": Has been succesfully removed!" << endl;
    }
    //Renamed for clarity and names of function calls altered as well
    void printAccountInfo() const {
        cout << fixed << setprecision(2);
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner: " << accountName << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};

int main () {
    BankAccount account1("Marty", "1243", 1000, "savings");

    account1.withdraw(1000);

    account1.printAccountInfo();
    account1.closeAccount();
    
    return 0;
}