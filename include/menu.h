//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_MENU_H
#define LIFE_MENU_H

#include <vector>
#include "cell.h"

/**
 * Display main menu and listen input
 */
void showMainMenu();

/**
 * Map function/action to the specified index
 * @param index select which action will be performed
 */
void mainMenuAction(int index);

void showPresetMenu(std::vector<std::vector<Cell>> &lifeBoard);

#endif //LIFE_MENU_H
