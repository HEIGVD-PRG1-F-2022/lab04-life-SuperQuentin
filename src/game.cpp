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

static bool firstStart = true;
static int width = 28, height = 28;
static std::vector<std::vector<Cell>> lifeBoard;

void initGame() {
    initTerminal();

    lifeBoard = vector(width, vector<Cell>(height));

    if (firstStart) {
        vector<vector<Cell>> preset = getCellPreset(CellPreset::Pulsar);
        //insertPreset(lifeBoard, preset, -7, -7);
        //insertPreset(lifeBoard, preset, 7, 7);
    }
}

void resetGame() {
    firstStart = true;
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
    bool shouldUpdateGame = true, shouldStep = false;
    static bool gameIsPaused = false, debugDraw = false;
    static unsigned int delay = 50;

    commandsHelper();

    while (true) {
        firstStart = false;
        if (input != '\000') {
            switch (input) {
                case 'r':
                    resetGame();
                    break;
                case '3':
                    showPresetMenu(lifeBoard);
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
                case 'q':
                    clearTerminal();
                    return;
                default:
                    shouldUpdateGame = true;
            }
        }

        if (shouldUpdateGame) {
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

        input = getKeyPressDown();
    }
}

void endGame() {
    terminateTerminal();
}
