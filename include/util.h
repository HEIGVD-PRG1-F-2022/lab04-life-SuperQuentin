//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_UTIL_H
#define LIFE_UTIL_H

#include <string>
#include <vector>

#include "./terminal.h"

void wait(int milliseconds);

std::string getColorsCodeStr(TerminalColors color);

int wrap(int value, int min, int max);
int wrap(int value, std::vector<std::string> vector);

#endif //LIFE_UTIL_H
