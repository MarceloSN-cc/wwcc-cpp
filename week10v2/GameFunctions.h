#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include <string>
#include "GameType.h"

void displayPrologue(const std::string& filename, Player& player);
bool validInput(int choice, int min, int max);
void showIneventory(const Player& player);
void saveSummary(const Player& player, const std::string& outcome);

#endif