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

/**
 * Do special stuff to init terminal based on if it's a WIN32 or __unix__ sys
 */
void initTerminal();

/**
 * Restore the special stuff done in init especially on __unix__
 */
void terminateTerminal();

/**
 * Detect and give keyboard key if any key is pressed without waiting for input
 * @return char of the pressed key if there is any or 0 by default
 */
char getKeyPressDown();

/**
 * Detect and give keyboard key and wait for it
 * @return char of the pressed key
 */
char getKey();

/**
 * Remove content of terminal and set cursor to the start
 */
void clearTerminal();

/**
 * Disable blinking terminal cursor
 */
void hideTerminalCursor();

/**
 * Enable blinking terminal cursor
 */
void showTerminalCursor();

/**
 * Calculate the size of the terminal character width and height
 */
void getTerminalSize(int &width, int &height);

#endif //LIFE_INPUT_H
