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

/**
 * Pre-configured cells preset enumeration
 */
enum class CellPreset {
    BeeHive,
    Pulsar,
    Pentadecathlon,
    Glider
};

/**
 * Generate a 2D vector array of cells, base on specified CellPreset enum
 * @param preset wanted preset
 * @return 2D vector array of cells
 */
std::vector<std::vector<Cell>> getCellPreset(CellPreset preset);

/**
 * Convert cells from the form of string with (0,.) for dead cells and (1,-) for alive cells with **\n** for each line return
 * @param cellString multiline string literal
 * @return 2D vector array of cells
 */
std::vector<std::vector<Cell>> strToCell(const std::string &cellString);


/**
 * Will insert 2D vector array of preset into the 2D vector array of a lifeBoard.
 * @param lifeBoard 2D vector array of the actual game board
 * @param preset 2D vector array of the group of cells we want to insert
 * @param xOffset where on the x axis we will insert it, value will be wrap on lifeBoard size
 * @param yOffset where on the y axis we will insert it, value will be wrap on lifeBoard size
 */
void insertPreset(std::vector<std::vector<Cell>> &lifeBoard, std::vector<std::vector<Cell>> &preset, int xOffset = 0, int yOffset = 0);

#endif //LIFE_CELL_PRESETS_H
