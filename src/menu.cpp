//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include <vector>
#include <iostream>
#include "../include/menu.h"
#include "../include/terminal.h"
#include "../include/util.h"
#include "../include/game.h"

using namespace std;

void showMainMenu() {
    const vector<string> options{"Play", "Cell Presets", "Settings"};

    int selectedOptionIndex = 0;

    clearTerminal();
    string tmp;
    char input = 0;
    bool shouldUpdateMenu = true;

    while (true) {
        tmp = "";
        if (input != '\000') {
            switch (input) {
                case 'q':
                    return;
                case 'w':
                    selectedOptionIndex = wrap(selectedOptionIndex - 1, options);
                    shouldUpdateMenu = true;
                    break;
                case 's':
                    selectedOptionIndex = wrap(selectedOptionIndex + 1, options);
                    shouldUpdateMenu = true;
                    break;
                case '\r':

                    mainMenuAction(selectedOptionIndex);
                    shouldUpdateMenu = true;
                    break;
                default:
                    shouldUpdateMenu = false;
                    break;
            }
        }

        if (shouldUpdateMenu) {
            tmp += "\033[s"; // Save cursor position
            tmp += "--- Menu --- \n\r";

            for (int x = 0; x < options.size(); ++x) {
                tmp += "\x1b[38;5;"
                       + (x == selectedOptionIndex ? getColorsCodeStr(TerminalColors::PINK) : getColorsCodeStr(
                        TerminalColors::WHITE))
                       + "m " + options[x] + " \x1b[0m \n\r";
            }

            tmp += "------------ \n\r";
            tmp += "\033[u"; // Restore cursor position

            cout << tmp;
        }

        input = getKeyPressDown();
        shouldUpdateMenu = false;
    }
}

void mainMenuAction(int index) {
    switch (index) {
        case 0:
            gameLoop();
            break;
        case 1:
            // TODO: Cell Presets
            break;
        case 2:
            // TODO: Settings
            break;
        default:
            return;
    }
}