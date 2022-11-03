//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_INPUT_H
#define LIFE_INPUT_H

#include <iostream>

#ifdef _WIN32

#include <windows.h>
#include <conio.h>

#endif

void initTerminal();

void terminateTerminal();

char getKeyPressDown();

void clearTerminal();

void setCursorToStart();

#endif //LIFE_INPUT_H
