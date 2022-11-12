//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_CELL_H
#define LIFE_CELL_H

#include <string>

/**
 * Cell life state
 */
enum class Cell {
    Dead,
    WillBeBorn,
    Alive,
    WillDie,
};

/**
 * Match a color to the cell life state
 * @param cell reference of a Cell variable
 * @return a colored "pixel" with the correct
 */
std::string getCellColor(Cell &cell);

#endif //LIFE_CELL_H
