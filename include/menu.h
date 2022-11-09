//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_MENU_H
#define LIFE_MENU_H

#include <vector>
#include "cell.h"

void showMainMenu();

void mainMenuAction(int index);

void showPresetMenu(std::vector<std::vector<Cell>> &lifeBoard);

#endif //LIFE_MENU_H
