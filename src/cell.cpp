//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include "../include/cell.h"
#include "../include/util.h"

using namespace std;

string getCellColor(Cell &cell) {
    switch (cell) {
        case Cell::WillBeBorn:
            return "\x1b[38;5;" + getColorsCodeStr(TerminalColors::GREEN) + "m * \x1b[0m";
        case Cell::Alive:
            return "\x1b[38;5;" + getColorsCodeStr(TerminalColors::BLUE) + "m * \x1b[0m";
        case Cell::WillDie:
            return "\x1b[38;5;" + getColorsCodeStr(TerminalColors::RED) + "m * \x1b[0m";
        case Cell::Dead:
        default:
            return "\x1b[38;5;" + getColorsCodeStr(TerminalColors::BLACK) + "m * \x1b[0m";
    }
}