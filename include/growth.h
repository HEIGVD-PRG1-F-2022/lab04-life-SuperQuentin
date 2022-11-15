//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_GROWTH_H
#define LIFE_GROWTH_H

#include <vector>
#include "./cell.h"

/**
 * Check if the requirements are meet to stay alive, evolve or die the next round.
 * @param lifeBoard 2D vector array of the actual game board
 */
void processEvolution(std::vector<std::vector<Cell>> &lifeBoard);

/**
 * Assassinate targeted cells and help to bring new life on the one's mandated to live
 * @param lifeBoard 2D vector array of the actual game board
 */
void processLifeCycle(std::vector<std::vector<Cell>> &lifeBoard);

#endif //LIFE_GROWTH_H
