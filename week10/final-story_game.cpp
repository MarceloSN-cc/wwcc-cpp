/*
 * Interactive Story Game - [Echoes of the Holy Sword]
 * Author: [Your Name]
 * Date: [Submission Date]
 *
 * ==== Project Features ====
 * Variables (3+ types): In GAMEFUNCTIONS_H lines: 7, 8 , 9 and 10. And in GameVariables.h line: 17, 18, 19, and 20.
 * If/else: Lines 62, 67, 89, 94, 116, 119, 126, 129, 156, 159, 163, and 166.
 * Switch: Line 43
 * Loop: Main.cpp lines: 42, 57, 151, 154. GameFunctions.cpp lines: 16, 25, 43, 64. 
 * Function w/ return value: In GameFunction.cpp lines: 24
 * Void function: Line In GameFunction.cpp lines: 8, 37, 49.
 * Function w/ parameters: Line In GAMEFUNCTIONS_H lines: 7, 8, 9.
 * Vector or array: Lines In GAMEVARIABLES_H line 20.
 * Struct or class: Lines In GAMEVARIABLES_H lines 7, 16.
 * Enum: in GAMEVARIABLES_H line 7.
 * File reading: Lines In GameFunctions..cpp line 8.
 * File writing: In GameFunctions.cpp line 49.
 * Modern feature 1 (Lambda): in GameFunctions.cpp line 24
 * Modern feature 2 (Range based for loop): in GameFunctions.cpp line 64.
 * ==========================
 */
#include <iostream>
#include <string>
#include "GameVariables.h"
#include "GameFunctions.h"
using namespace std;


int main() {
    Player player; 
    GameState state = GameState::INTRO;
    string outcomeText = "Abandoned the quest.";
    int choice = 0;

    cout << "===================================\n";
    cout << "     ECHOES OF THE HOLY SWORD      \n";
    cout << "===================================\n";
    cout << "Enter your Hero's name: ";
    getline(cin, player.name);

    while(state != GameState::GAME_OVER) {
        switch(state) {
            case GameState::INTRO: {
                displayPrologue("story.txt", player);
                state = GameState::DARKWOODS;
                break;
            }

            case GameState::DARKWOODS: {
                cout << "\n=== Scene 1: Inside The Darkwoods ===\n";
                cout << "Light barely phasing through the thick woods.\n"; 
                cout << "Two paths lie ahead.\n";
                cout << "[1] Take the Path Where the Light Shines Brightest (Safer, but long)\n";
                cout << "[2] Take the Path Consumed by the Dark (Dangerous, but short)\n";

                do {
                    cout << "Choose your path [1 or 2]: ";
                    cin >> choice;
                } while(!validInput(choice, 1, 2));
                
                if(choice == 1) {
                    cout << "\nSafely, you traverse through the woods, arriving slightly fatigued";
                    cout << " at the front of an ancient crypt entry.\n";
                    player.health -= 10;
                    state = GameState::CRYPT_ENTRANCE;
                } else {
                    cout << "\nWhile taking the shorter route, you're suddenly ambushed!\n";
                    cout << "Creatures of the dark swarm you in bulk.\n"; 
                    cout << "You fight them off the best you can but receive damage as a result.\n";
                    player.health -= 40;
                    state = GameState::CRYPT_ENTRANCE;
                }
                break;
            }
            case GameState::CRYPT_ENTRANCE: {
                cout << "\n=== SCENE 2: The Crypted Entrance ===\n";
                cout << "Current player health: " << player.health << "%\n";
                showIneventory(player);
                cout << "Giant metal doors corroded by time block your path.\n";
                cout << "You notice the doors require a key.\n";
                cout << "[1] Search around for a key.\n";
                cout << "[2] Exhaust yourself by battering down the doors.\n";

                do {
                    cout << "Choose your action [1 or 2]: ";
                    cin >> choice;
                } while(!validInput(choice, 1, 2));
                if (choice == 1) {
                    cout << "\nYour search pays off! You've discovered an oddly triangular shaped key.";
                    player.hasKey = true;
                    player.inventory.push_back("Oddly Triangular Shaped Key");
                    state = GameState::PUZZLE_CHAMBER;
                } else {
                    cout << "\n After some time of repeated battering, the doors break loose off their hinges.";
                    cout << "\n However, you've heavily fatigued yourself in the process.\n";
                    player.health -= 30;
                    state = GameState::PUZZLE_CHAMBER;
                }
                break;
            }
            case GameState::PUZZLE_CHAMBER: {
                cout << "\n=== SCENCE 3: The Ruined Hallway ===\n";
                if(player.health <= 0) {
                    cout << "You've taken too much damage. Wheezing, you collapse onto the cold stone floor...\n";
                    outcomeText = "Defeated by exhuastion and trauma, you fall into eternal sleep...";
                    state = GameState::GAME_OVER;
                    break;
                }
                cout << "As you make your way through the ruined hall, you are faced with a stone wall.\n";
                cout << "Engraved on it reads, 'There are 5 fingers on one human hand, multiply\n";
                cout << "the greatest even number by the number of paths that lead here.'\n";
                cout << "To solve the riddle, enter the correct numeric answer: ";
                cin >> choice;

                if(choice == 8) {
                    cout << "\nCorrect! The stone wall rises, opening a path forward.\n";
                    state = GameState::THE_CHAMBER;
                } else {
                    cout << "\nIncorrect! The halls security system has been triggered.\n";
                    cout << "Hidden cannos begin to shower you in a rain of fire.\n";
                    cout << "At your best attempt to save yourself, you dive onto the side of the wall.\n";
                    cout << "Unfortunately, you weren't fast enough. One of your legs was hit during the barrage.\n";
                    cout << "You cry out in pain.\n";
                    player.health -= 40;
                    if (player.health <= 0) {
                        outcomeText = "Slained by the hall's security system.";
                        state = GameState::GAME_OVER;
                    } else {
                        cout << "\nSuffering from the injuries substained, you spot a gap in the stone wall.\n";
                        cout << "The cannon fire has torn a hole large enough for you to climb through.\n";
                        cout << "You continue your path through the hall.\n";
                        state = GameState::THE_CHAMBER;
                    }
                }
                break;
            }
            case GameState::THE_CHAMBER: {
                cout << "\n=== SCENE 4: The Chamber ===\n";

                cout << "After a short travel, you find yourself inside a chamber.\n";
                cout << "Inside, you find a sword laid on display.\n";
                cout << "The sword echos for you to wield it.\n";
                cout << "You make your way towards it, and although heavy, you manage to lift it.\n";
                cout << "Suddenly the ground begins to violently shake. The place will soon collapse.\n";

                cout << "\nWill you drop the sword and escape, or risk leaving with it?\n";
                cout << "[1] Drop the sword and escape (safe).\n";
                cout << "[2] Keep the sword and escape (Dangerous).\n";

                do {
                    cout << "Make your final choice [1 or 2]: ";
                    cin >> choice;
                } while(!validInput(choice, 1, 2));

                if(choice == 1) {
                    cout << "You manage to escape in time. Unfortunately though,";
                    cout << " the only hope of salvation was left behind...\n";
                } else {
                    cout << "\nYou rush towards the exit slowed by the swords weight. Just as your about to make it out,\n";
                    cout << "you're hit by a boulder crashing down from the collapsing ruins...";
                    player.health -= 40;
                    if (player.health <= 0) {
                        outcomeText = "Succumbing to your injuries, darkness overtakes your sight.";
                        state = GameState::GAME_OVER;
                    } else {
                        cout << "Overwhelmed by pain cause by a hurling boulder, you've survived escaping with the sword.";
                        outcomeText = "Congratualations! You've aquired the holy sowrd that will save humanity!";
                    }
                }

                state = GameState::GAME_OVER;
                break;
            }

            default: 
                state = GameState::GAME_OVER;
                break;
        }
    }

    cout << "\n===================================\n";
    cout << "             GAME OVER               \n";
    cout << "====================================\n";
    cout << "Final Narative Status: " << outcomeText << "\n";
    cout << "Ending Health: " << (player.health < 0 ? 0 : player.health) << "%\n";

    saveSummary(player, outcomeText); 

    return 0;
}
