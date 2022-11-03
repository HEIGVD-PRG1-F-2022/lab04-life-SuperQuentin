#include <iostream>
#include <vector>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "../include/cell.h"

using namespace std;

void evolve(vector<vector<Cell>> &lifeBoard);

string cellColor(Cell &cell);

void birthAndDeath(vector<vector<Cell>> &lifeBoard);

void draw(vector<vector<Cell>> &lifeBoard);

int main() {

    const int LIFEBOARD_WIDTH = 9;
    const int LIFEBOARD_HEIGHT = 9;

    vector<vector<Cell>> lifeBoard(vector(LIFEBOARD_WIDTH, vector<Cell>(LIFEBOARD_HEIGHT)));

    lifeBoard[2][2] = Cell::Alive;
    lifeBoard[3][3] = Cell::Alive;
    lifeBoard[4][1] = Cell::Alive;
    lifeBoard[4][2] = Cell::Alive;
    lifeBoard[4][3] = Cell::Alive;

    for (;;) {
        cout << endl;

        draw(lifeBoard);
        evolve(lifeBoard);
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return EXIT_SUCCESS;
}

string cellColor(Cell &cell) {
    switch(cell) {
        case Cell::WillBeBorn:
            return "\x1b[38;5;40m * \x1b[0m";
        case Cell::Alive:
            return "\x1b[38;5;21m * \x1b[0m";
        case Cell::WillDie:
            return "\x1b[38;5;196m * \x1b[0m";
        case Cell::Dead:
        default:
            return "\x1b[38;5;16m * \x1b[0m";
    }
}

void birthAndDeath(vector<vector<Cell>> &lifeBoard) {
    for (int x = 0; auto &row: lifeBoard) {
        for (int y = 0; auto &cell: row) {
            if (cell == Cell::WillBeBorn) cell = Cell::Alive;
            if (cell == Cell::WillDie) cell = Cell::Dead;
        }
    }
}

void evolve(vector<vector<Cell>> &lifeBoard) {
    for (int x = 0; auto &row: lifeBoard) {
        for (int y = 0; auto &cell: row) {
            int offsetX, offsetY, neighborCounter = 0, rowSize = lifeBoard.size(), colSize = lifeBoard[x].size();

            vector<int> offsetCheckList{
                    // Check top left corner relative to cell coords
                    (x - 1 < 0 ? rowSize + ((x - 1) % rowSize) : ((x - 1) % rowSize)),
                    (y - 1 < 0 ? colSize + ((y - 1) % colSize) : ((y - 1) % colSize)),
                    // Check bottom right corner relative to cell coords
                    ((x + 1) % rowSize),
                    ((y + 1) % colSize),
                    // Check top right corner relative to cell coords
                    (x - 1 < 0 ? rowSize + ((x - 1) % rowSize) : ((x - 1) % rowSize)),
                    ((y + 1) % colSize),
                    // Check bottom left corner relative to cell coords
                    ((x + 1) % rowSize),
                    (y - 1 < 0 ? colSize + ((y - 1) % colSize) : ((y - 1) % colSize)),
                    // Check top middle relative to cell coords
                    (x - 1 < 0 ? rowSize + ((x - 1) % rowSize) : ((x - 1) % rowSize)),
                    (y),
                    // Check bottom middle relative to cell coords
                    ((x + 1) % rowSize),
                    (y),
                    // Check left middle relative to cell coords
                    (x),
                    (y - 1 < 0 ? colSize + ((y - 1) % colSize) : ((y - 1) % colSize)),
                    // Check right middle relative to cell coords
                    (x),
                    ((y + 1) % colSize)
            };

            for(int r = 0; r < offsetCheckList.size(); r = r+2) {
                offsetX = offsetCheckList[r];
                offsetY = offsetCheckList[r+1];

                if (lifeBoard[offsetX][offsetY] == Cell::Alive ||
                    lifeBoard[offsetX][offsetY] == Cell::WillDie)
                    neighborCounter++;
            }

            if (cell == Cell::Dead && neighborCounter == 3) cell = Cell::WillBeBorn;
            if (cell == Cell::Alive && (neighborCounter < 2 || neighborCounter > 3)) cell = Cell::WillDie;

            ++y;
        }
        ++x;
    }

    birthAndDeath(lifeBoard);
}

void draw(vector<vector<Cell>> &lifeBoard) {
    printf("\033[%d;%dH", 0+1, 0+1);
    for (int x = 0; auto &row: lifeBoard) {
        for (int y = 0; auto &cell: row) {
            cout << cellColor(lifeBoard[x][y]);
            ++y;
        }
        cout << endl;
        ++x;
    }
};