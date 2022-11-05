//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include <vector>

#include "../include/draw.h"
#include "../include/util.h"
#include "../include/growth.h"
#include "../include/game.h"

using namespace std;

void initGame() {
    initTerminal();
}

void startGame() {
    initGame();

    gameLoop();

    endGame();
}

void gameLoop() {
    const int LIFEBOARD_WIDTH = 9;
    const int LIFEBOARD_HEIGHT = 9;

    vector<vector<Cell>> lifeBoard(vector(LIFEBOARD_WIDTH, vector<Cell>(LIFEBOARD_HEIGHT)));

    // TODO: delete later
    lifeBoard[2][2] = Cell::Alive;
    lifeBoard[3][3] = Cell::Alive;
    lifeBoard[4][1] = Cell::Alive;
    lifeBoard[4][2] = Cell::Alive;
    lifeBoard[4][3] = Cell::Alive;

    while (1) {
        draw(lifeBoard);
        processEvolution(lifeBoard);
        processLifeCycle(lifeBoard);
        wait(500);
    }
}

void endGame() {
    terminateTerminal();
}
