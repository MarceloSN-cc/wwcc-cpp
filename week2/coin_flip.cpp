#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

     int flips;
     int heads = 0;
     int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;

    if (flips <= 0){
        cout << "Only positve numbers!" << endl;
        return 1;
    }
    cout << "Processing..." << flips << " coin flips "<< endl;

    for (int i = 0; i < flips; i++){
        int result = rand () % 2;

        if(result == 0)
            heads++;
        else 
            tails++;
        }
    double headsPercent = static_cast<double>(heads) / flips * 100;
    double tailsPercent = static_cast<double>(tails) / flips * 100;

    cout << "Results: " << endl;
    cout << "Heads: " << heads << "\t" << headsPercent << "%" << endl;
    cout << "Tails: " << tails << "\t" << tailsPercent << "%" << endl; 

    return 0;
}