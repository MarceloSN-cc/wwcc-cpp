#include <iostream> 
#include <iomanip>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

using namespace std;

void convertTemperature(double temperature, char unit, double &C, double &F, double &K);

int main () 
{
      #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif

    cout << "Temperature converter" << endl;
    
    double temperature, celsius, fahrenheit, kelvin;
    cout << "Enter the temperature: " << endl;
    cin >> temperature;

    char unit;
    cout << "Enter a temperature unit (C for celsius, F for fahrenheit, and K for Kelvin): " << endl;
    cin >> unit;

    if (unit != 'C' && unit != 'c' && unit != 'F' && unit != 'f' && unit != 'K' && unit != 'k'){
        cout << "Please enter a prompted unit!" << endl;
        return 1;
    }

    convertTemperature(temperature, unit, celsius, fahrenheit, kelvin);

    cout << fixed << setprecision(2);
    cout << "Temperature conversions: " << endl;
    cout << "Celsius: " << celsius << "\xC2\xB0 C" << endl;
    cout << "Fahrenheit: " << fahrenheit << "\xC2\xB0 F" << endl;
    cout << "Kelvin: " << kelvin << " K" << endl;

    return 0;

}

void convertTemperature(double temperature, char unit, double &C, double &F, double &K)
{
    switch (unit){
        case 'C' : case 'c':
        C = temperature;
        F = (C * 9.0 /5.0) + 32;
        K = C + 273.15;
        break;
        case 'F' : case 'f' :  
        F = temperature;
        C = (F - 32) * 5.0/9.0;
        K = C + 273.15;
        break;
        case 'K' : case 'k': 
        K = temperature;
        C = K - 273.15;
        F = (C * 9.0/5.0) + 32;
        break;
        default :
            cout << "Invalid unit." << endl;
            break;

    }
}