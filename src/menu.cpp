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

using namespace std;

void showMainMenu() {
    const vector<string> options{"Play", "Cell Presets", "Settings"};

    static int selectedOptionIndex = 0;

    clearTerminal();
    string tmp;
    char input;
    bool updateDisplayFlag = true;

    while (true) {

        if(input != '\000') {
            switch (input) {
                case 'q':
                    return;
                case 'w':
                    selectedOptionIndex = wrap(selectedOptionIndex - 1, options);
                    updateDisplayFlag = true;
                    break;
                case 's':
                    selectedOptionIndex = wrap(selectedOptionIndex + 1, options);
                    updateDisplayFlag = true;
                    break;
                default:
                    updateDisplayFlag = false;
            }
        }

        if (updateDisplayFlag) {
            tmp += "--- Menu --- \n\r";

            for (int x = 0; x < options.size(); ++x) {
                tmp += "\x1b[38;5;"
                       + (x == selectedOptionIndex ? getColorsCodeStr(TerminalColors::PINK) : getColorsCodeStr(
                        TerminalColors::WHITE))
                       + "m " + options[x] + " \x1b[0m \n\r";
            }

            setCursorToStart();
            cout << tmp;
        }

        input = getKeyPressDown();
        updateDisplayFlag = false;
    }
}