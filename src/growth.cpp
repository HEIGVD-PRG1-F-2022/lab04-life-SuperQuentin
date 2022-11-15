//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include "../include/growth.h"
#include "../include/util.h"

using namespace std;

void processEvolution(vector<vector<Cell>> &lifeBoard) {
    for (int x = 0; auto &row: lifeBoard) {
        for (int y = 0; auto &cell: row) {
            int offsetX, offsetY, neighborCounter = 0, rowSize = static_cast<int>(lifeBoard.size()) - 1, colSize =
                    static_cast<int>(lifeBoard[x].size()) - 1;

            const vector<int> offsetCheckList{
                    // Check top left corner relative to cell coords
                    wrap(x - 1, 0, rowSize),
                    wrap(y - 1, 0, colSize),
                    // Check bottom right corner relative to cell coords
                    wrap(x + 1, 0, rowSize),
                    wrap(y + 1, 0, colSize),
                    // Check top right corner relative to cell coords
                    wrap(x - 1, 0, rowSize),
                    wrap(y + 1, 0, colSize),
                    // Check bottom left corner relative to cell coords
                    wrap(x + 1, 0, rowSize),
                    wrap(y - 1, 0, colSize),
                    // Check top middle relative to cell coords
                    wrap(x - 1, 0, rowSize),
                    wrap(y, 0, colSize),
                    // Check bottom middle relative to cell coords
                    wrap(x + 1, 0, rowSize),
                    wrap(y, 0, colSize),
                    // Check left middle relative to cell coords
                    wrap(x, 0, rowSize),
                    wrap(y - 1, 0, colSize),
                    // Check right middle relative to cell coords
                    wrap(x, 0, rowSize),
                    wrap(y + 1, 0, colSize),
            };

            for (int r = 0; r < offsetCheckList.size(); r = r + 2) {
                offsetX = offsetCheckList[r];
                offsetY = offsetCheckList[r + 1];

                if (lifeBoard[offsetX][offsetY] == Cell::Alive || lifeBoard[offsetX][offsetY] == Cell::WillDie)
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
    for (auto &row: lifeBoard) {
        for (auto &cell: row) {
            if (cell == Cell::WillBeBorn)
                cell = Cell::Alive;

            if (cell == Cell::WillDie)
                cell = Cell::Dead;
        }
    }
}