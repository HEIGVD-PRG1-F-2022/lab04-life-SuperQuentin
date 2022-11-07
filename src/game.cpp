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

    if(firstStart) {
        // TODO: delete later
        lifeBoard[2][2] = Cell::Alive;
        lifeBoard[3][3] = Cell::Alive;
        lifeBoard[4][1] = Cell::Alive;
        lifeBoard[4][2] = Cell::Alive;
        lifeBoard[4][3] = Cell::Alive;
    }

    char input;
    bool shouldUpdateGame = true;

    while (true) {
        firstStart = false;
        if (input != '\000') {
            switch (input) {
                case 'q':
                    clearTerminal();
                    return;
                default:
                    shouldUpdateGame = true;
            }
        }

        if(shouldUpdateGame) {
            draw(lifeBoard);
            processEvolution(lifeBoard);
            processLifeCycle(lifeBoard);
            wait(50);
        }

        input = getKeyPressDown();
    }
}

void endGame() {
    terminateTerminal();
}
