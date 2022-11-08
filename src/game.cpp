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

using namespace std;

void initGame() {
    initTerminal();
}

void startGame() {
    initGame();

    showMainMenu();

    endGame();
}

void gameLoop() {
    int width = 21, height = 21;
    static bool firstStart = true;


    static vector<vector<Cell>> lifeBoard(vector(width, vector<Cell>(height)));

    if (firstStart) {
        // TODO: delete later
        lifeBoard[2][2] = Cell::Alive;
        lifeBoard[3][3] = Cell::Alive;
        lifeBoard[4][1] = Cell::Alive;
        lifeBoard[4][2] = Cell::Alive;
        lifeBoard[4][3] = Cell::Alive;
    }

    char input;
    bool shouldUpdateGame = true, shouldStep = false;
    static bool gameIsPaused = false, debugDraw = false;
    static unsigned int delay = 50;

    commandsHelper();

    while (true) {
        firstStart = false;
        if (input != '\000') {
            switch (input) {
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
