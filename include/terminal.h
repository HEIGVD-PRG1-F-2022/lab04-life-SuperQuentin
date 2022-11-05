//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#ifndef LIFE_INPUT_H
#define LIFE_INPUT_H

enum class TerminalColors {
    WHITE = 15,
    PINK = 207,
    RED = 196,
    GREEN = 40,
    BLUE = 21,
    BLACK = 16
};

void initTerminal();

void terminateTerminal();

char getKeyPressDown();

void clearTerminal();

void setCursorToStart();

#endif //LIFE_INPUT_H
