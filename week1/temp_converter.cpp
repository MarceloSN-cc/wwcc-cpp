#include <iostream> 
using namespace std;

int main () {
    double temperature; 
    char unit; 
    const double CelToFah = 9.0 / 5.0;
    const double FahToCel = 5.0 / 9.0;
    const int Fah_Balance = 32;

    cout << "Please enter a temperature: " << endl;
    cin >> temperature;
    cout << "Enter temperature unit (C for Celsius, or F for Fahrenheit): " << endl;
    cin >> unit; 
    if (unit == 'C') { 
        cout << "The  temperauter is: " << (temperature - Fah_Balance) * FahToCel; 
    } else if (unit == 'F'){ 
        cout << "The temperature is: " << (temperature * CelToFah) + Fah_Balance; 
    }
   
    return 0;


}