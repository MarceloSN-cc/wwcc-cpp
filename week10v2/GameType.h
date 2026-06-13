#ifndef GAMETYPE_H
#define GAMETYPE_H

#include <string>
#include <vector>

enum class GameState {
    INTRO,
    DARKWOODS,
    CRYPT_ENTRANCE,
    PUZZLE_CHAMBER,
    THE_CHAMBER,
    GAME_OVER
};

struct Player {
    std::string name;
    int health = 100;
    bool hasKey = false;
    std::vector<std::string> inventory;
};

#endif