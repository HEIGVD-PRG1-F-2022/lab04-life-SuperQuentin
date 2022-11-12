//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_LIFE_H
#define LIFE_LIFE_H

#include <vector>

#include "./cell.h"
#include "./terminal.h"

/**
 * Setup terminal and default life board with some cells presets
 */
void initGame();

/**
 * Main function, initialize game display menu and close the game at the end
 */
void startGame();

/**
 * Manage input, game logic and game display
 */
void gameLoop();

/**
 * Close terminal politely
 */
void endGame(); // R.I.P. Tony Stark (1970-2023)

#endif //LIFE_LIFE_H
