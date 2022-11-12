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

/**
 * Transform enum color to a string ansi code usable when you want to compose colored string
 * @param color wanted color for text to be display
 * @return cast of TerminalColor integer to a string
 */
std::string getColorsCodeStr(TerminalColors color);

/**
 * Apply color transformation on a given text
 * @param text to display
 * @param colors wanted color for text to be display
 * @return string with ansi codes applied to display colored text
 */
std::string getColoredStr(const std::string &text, TerminalColors colors);

/**
 * Wrap value between a min and max value
 * https://stackoverflow.com/a/707426
 * @param value to wrap
 * @param min lower value
 * @param max upper value
 * @return wrapped value
 */
int wrap(int value, int min, int max);

/**
 * Wrap value between a min and max value of a vector<string>
 * https://stackoverflow.com/a/707426
 * @param value to wrap
 * @param vector of string, will be use to set max value
 * @return wrapped value between 0 et vector size
 */
int wrap(int value, const std::vector<std::string> &vector);

#endif // LIFE_UTIL_H
