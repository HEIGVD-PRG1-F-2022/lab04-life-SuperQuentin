//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include "../include/cell.h"

using namespace std;

string getCellColor(Cell &cell) {
    switch (cell) {
        case Cell::WillBeBorn:
            return "\x1b[38;5;40m * \x1b[0m"; // Green
        case Cell::Alive:
            return "\x1b[38;5;21m * \x1b[0m"; // Blue
        case Cell::WillDie:
            return "\x1b[38;5;196m * \x1b[0m"; // Red
        case Cell::Dead:
        default:
            return "\x1b[38;5;16m * \x1b[0m"; // Black
    }
}