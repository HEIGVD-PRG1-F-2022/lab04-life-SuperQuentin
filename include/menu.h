//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_MENU_H
#define LIFE_MENU_H

#include <vector>
#include "cell.h"
#include "cell_preset.h"

/**
 * Display main menu and listen input
 */
void showMainMenu();

/**
 * Map function/action to the specified index
 * @param index select which action will be performed
 */
void mainMenuAction(int index);

/**
 * Presets menu, will let user select what preset he want insert into the lifeBoard
 */
void showPresetMenu(std::vector<std::vector<Cell>> &lifeBoard);

/**
 * Display interface on which coords insert preset
 * @param index
 * @param lifeBoard
 */
void askPresetChoice(CellPreset preset, std::vector<std::vector<Cell>> &lifeBoard);

#endif // LIFE_MENU_H
