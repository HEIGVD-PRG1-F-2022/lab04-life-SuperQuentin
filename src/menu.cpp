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
    const vector<string> options{"Play", "Rules"};

    int selectedOptionIndex = 0;

    clearTerminal();
    string tmp;
    char input = 0;

    while (true) {
        tmp = "";
        switch (input) {
            case 'q':
                return; // <-- loop exit
            case 'w':
                selectedOptionIndex = wrap(selectedOptionIndex - 1, options);
                break;
            case 's':
                selectedOptionIndex = wrap(selectedOptionIndex + 1, options);
                break;
            case '\r':
                mainMenuAction(selectedOptionIndex);
                break;
            default:
                break;
        }

        tmp += "\033[s"; // Save cursor position
        tmp += "--- Main Menu --- \n\r";

        for (int x = 0; x < options.size(); ++x) {
            tmp += getColoredStr(options[x],
                                 (x == selectedOptionIndex ? TerminalColors::PINK : TerminalColors::WHITE)) + "\n\r";
        }

        tmp += "----------------- \n\r";
        tmp += "\033[u"; // Restore cursor position

        cout << tmp;
        input = getKey();
    }
}

void mainMenuAction(int index) {
    string tmp;
    switch (index) {
        case 0:
            gameLoop();
            break;
        case 1:
            clearTerminal();

            tmp += "Go check wikipedia page, there is the link :\n\r";
            tmp += getColoredStr("https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#Rules\n\r", TerminalColors::BLUE);

            tmp += "Press any key do continue...";

            cout << tmp;

            getKey();
            clearTerminal();
            break;
        default:
            break;
    }
}

void showPresetMenu(vector<vector<Cell>> &lifeBoard) {
    const vector<string> options{"Beehive", "Pulsar", "Pentadecathlon", "Glider"};

    int selectedOptionIndex = 0;

    clearTerminal();
    string tmp;
    char input = 0;

    while (true) {
        tmp = "";
        switch (input) {
            case 'q':
                return;
            case 'w':
                selectedOptionIndex = wrap(selectedOptionIndex - 1, options);
                break;
            case 's':
                selectedOptionIndex = wrap(selectedOptionIndex + 1, options);
                break;
            case '\r':
                askPresetChoice((CellPreset) selectedOptionIndex, lifeBoard);
                return; // <-- loop exit
            default:
                break;
        }

        tmp += "\033[s"; // Save cursor position
        tmp += "--- Presets --- \n\r";

        for (int x = 0; x < options.size(); ++x) {
            tmp += getColoredStr(options[x],
                                 (x == selectedOptionIndex ? TerminalColors::PINK : TerminalColors::WHITE)) + "\n\r";
        }

        tmp += "--------------- \n\r";
        tmp += "\033[u"; // Restore cursor position

        cout << tmp;

        input = getKey();
    }
}

void askPresetChoice(CellPreset preset, vector<vector<Cell>> &lifeBoard) {
    vector<vector<Cell>> tmp_preset;
    tmp_preset = getCellPreset(preset);

    clearTerminal();

    const string boardCurrentSizeDescription =
            "(board size: x:" + to_string(lifeBoard.size() - 1) + ", y:" + to_string(lifeBoard[0].size()) + ") ";
    string tmp;

    tmp += getColoredStr(boardCurrentSizeDescription, TerminalColors::PINK);
    tmp += "Enter coords x, y with a space (ex: 0 4) : \n\r";
    tmp += "> ";

    cout << tmp;

    showTerminalCursor();
    int xOffset = 0, yOffset = 0;
    cin >> xOffset >> yOffset;
    hideTerminalCursor();

    insertPreset(lifeBoard, tmp_preset, xOffset, yOffset);
}