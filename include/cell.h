//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_CELL_H
#define LIFE_CELL_H

#include <string>

enum class Cell {
    Dead,
    WillBeBorn,
    Alive,
    WillDie,
};

std::string getCellColor(Cell &cell);

#endif //LIFE_CELL_H
