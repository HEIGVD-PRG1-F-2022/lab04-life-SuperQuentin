//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_CELL_PRESETS_H
#define LIFE_CELL_PRESETS_H

#include <vector>
#include <string>

#include "cell.h"

enum class CellPreset {
    BeeHive,
    Pulsar,
    Pentadecathlon,
    Glider
};

std::vector<std::vector<Cell>> getCellPreset(CellPreset preset);
std::vector<std::vector<Cell>> strToCell(std::string cellString);

void insertPreset(std::vector<std::vector<Cell>> &lifeBoard, std::vector<std::vector<Cell>> &preset, int xOffset = 0, int yOffset = 0);

#endif //LIFE_CELL_PRESETS_H
