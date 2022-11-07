//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include "../include/growth.h"

using namespace std;

void processEvolution(vector<vector<Cell>> &lifeBoard) {
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

            for (int r = 0; r < offsetCheckList.size(); r = r + 2) {
                offsetX = offsetCheckList[r];
                offsetY = offsetCheckList[r + 1];

                if (lifeBoard[offsetX][offsetY] == Cell::Alive ||
                    lifeBoard[offsetX][offsetY] == Cell::WillDie)
                    neighborCounter++;
            }

            if (cell == Cell::Dead && neighborCounter == 3)
                cell = Cell::WillBeBorn;
            if (cell == Cell::Alive && (neighborCounter < 2 || neighborCounter > 3))
                cell = Cell::WillDie;

            ++y;
        }
        ++x;
    }
}

void processLifeCycle(vector<vector<Cell>> &lifeBoard) {
    for (int x = 0; auto &row: lifeBoard) {
        for (int y = 0; auto &cell: row) {
            if (cell == Cell::WillBeBorn)
                cell = Cell::Alive;
            if (cell == Cell::WillDie)
                cell = Cell::Dead;
        }
    }
}