//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_DRAW_H
#define LIFE_DRAW_H

#include <vector>
#include "./cell.h"

/**
 * Display list of commands available in game
 */
void commandsHelper();

/**
 * Display life board with * to represent each cell
 * @param lifeBoard 2D vector array of the actual game board
 */
void draw(std::vector<std::vector<Cell>> &lifeBoard);

#endif //LIFE_DRAW_H
