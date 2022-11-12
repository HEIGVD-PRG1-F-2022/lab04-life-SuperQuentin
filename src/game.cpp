//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include <vector>

#include "../include/draw.h"
#include "../include/util.h"
#include "../include/growth.h"
#include "../include/menu.h"
#include "../include/game.h"
#include "../include/cell_preset.h"

using namespace std;

static std::vector<std::vector<Cell>> lifeBoard;

void initGame() {
    initTerminal();

    int width, height;
    getTerminalSize(width, height);

    height -= 2; // 2 = space for commandsHelper lines
    width /= 3; // 3 = space of a displayed "pixel"/* of the life board

    lifeBoard = vector(height, vector<Cell>(width));

    vector<vector<vector<Cell>>> presets{
            getCellPreset(CellPreset::BeeHive),
            getCellPreset(CellPreset::Pulsar),
            getCellPreset(CellPreset::Pentadecathlon),
            getCellPreset(CellPreset::Glider),
    };

    insertPreset(lifeBoard, presets[0], 14, 0);
    insertPreset(lifeBoard, presets[1], 0, 25);
    insertPreset(lifeBoard, presets[2], -7, 0);
    insertPreset(lifeBoard, presets[3], 0, 0);
}

void resetGame() {
    initGame();

    commandsHelper();
}

void startGame() {
    initGame();

    showMainMenu();

    endGame();
}


void gameLoop() {
    char input;
    bool shouldStep = false;

    // use static to not lose state when leaving to menu and returning in game
    static bool gameIsPaused = false, debugDraw = false;
    static unsigned int delay = 50;

    commandsHelper();

    while (true) {
        input = getKeyPressDown();
        if (input != '\000') {
            switch (input) {
                case 'q':
                    clearTerminal();
                    return; // <-- loop exit
                case 'r':
                    resetGame();
                    break;
                case '3':
                    showPresetMenu(lifeBoard);
                    clearTerminal();
                    commandsHelper();
                    break;
                case '+' :
                    delay += delay < 10000 ? 25 : 0;
                    break;
                case '-' :
                    delay -= delay > 25 ? 25 : 0;
                    break;
                case 'i':
                    shouldStep = true;
                    break;
                case '1':
                    debugDraw = !debugDraw;
                    break;
                case 'p':
                    gameIsPaused = !gameIsPaused;
                    break;
                default:
                    break;
            }
        }

        draw(lifeBoard);

        if (!gameIsPaused || shouldStep) {
            processEvolution(lifeBoard);
            if (debugDraw) {
                draw(lifeBoard);
            }
            processLifeCycle(lifeBoard);
            shouldStep = false;
        }

        wait(delay);
    }
}

void endGame() {
    terminateTerminal();
}
