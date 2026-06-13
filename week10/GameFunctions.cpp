#include "GameFunctions.h"
#include <iostream>
#include <fstream>

using namespace std;


void displayPrologue(const string& filename, Player& player) {
    ifstream file(filename);
    if(!file) {
        cerr << "Error: could not open story.txt" << endl;
        return;
    }
    string line;
    cout << "\n=== PROLOUGE (Loaded from " << filename << ") << ===\n";
    while(getline(file, line)) {
        cout << line << endl;
    }
    cout << "=================================\n";
    cout << "\nWelcome, " << player.name << ". Your path begins now.\n";
    file.close();
}

bool validInput(int choice, int min, int max) {
    auto checkRange = [](int val, int low, int high) -> bool {
        return val >= low && val <= high;
    };
    if(cin.fail() || !checkRange(choice, min, max)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please choose one of the prompted choices." << endl;;
        return false;
    }
    return true;
}

void showIneventory(const Player& player) {
    cout << "Current Equipment: ";
    if(player.inventory.empty()) {
        cout << "[No Items Found in Inventory]" << endl;
        return;
    }
    for(size_t i = 0; i < player.inventory.size(); ++i) {
        cout << "[" << player.inventory[i] << "]" << (i == player.inventory.size() - 1 ? "" : ", ");
    }
    cout << "\n";
}

void saveSummary(const Player& player, const string& outcome) {
    ofstream outFile("game_summary.txt");
    if(!outFile) {
        cerr << "Error: could not write summary" << endl;
        return; 
    }

    outFile << "=== Advemture Log ===\n";
    outFile << "Character Name: " << player.name << endl;
    outFile << "Remaining Health: " << (player.health < 0 ? 0 : player.health) << endl;
    outFile << "Ending: " << outcome << endl;
    outFile << "Inventory Items:\n";
    if(player.inventory.empty()) {
        outFile << " -[Empty, no items]\n";
    } else {
        for(const auto& item : player.inventory) {
            outFile << " == " << item << endl;
        }
    }
    cout << "\n Game summary exported successfully to game_summary.txt \n";
    outFile.close();
}