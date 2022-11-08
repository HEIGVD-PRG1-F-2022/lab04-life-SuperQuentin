//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include "../include/cell_preset.h"
#include "../include/util.h"

using namespace std;

vector<vector<Cell>> getCellPreset(CellPreset preset) {
    vector<vector<Cell>> cellPreset;
    const string beehive =
            "0110\n"
            "1001\n"
            "0110\n";

    const string pulsar =
            "..111...111..\n"
            ".............\n"
            "1....1.1....1\n"
            "1....1.1....1\n"
            "1....1.1....1\n"
            "..111...111..\n"
            ".............\n"
            "..111...111..\n"
            "1....1.1....1\n"
            "1....1.1....1\n"
            "1....1.1....1\n"
            ".............\n"
            "..111...111..\n";

    const string glider =
            "010\n"
            "001\n"
            "111\n";

    switch (preset) {
        case CellPreset::BeeHive:
            cellPreset = strToCell(beehive);
            break;
        case CellPreset::Pulsar:
            cellPreset = strToCell(pulsar);
            break;
        case CellPreset::Pentadecathlon:
            break;
        case CellPreset::Glider:
            cellPreset = strToCell(glider);
            break;
        default:
            break;
    }
    return cellPreset;
}

void insertPreset(std::vector<std::vector<Cell>> &lifeBoard, std::vector<std::vector<Cell>> &preset, int xOffset,
                  int yOffset) {
    int xLife, yLife;
    for (int x = 0; x < preset.size(); ++x) {
        for (int y = 0; y < preset[x].size(); ++y) {
            int rowSize = lifeBoard.size() - 1, colSize = lifeBoard[0].size() - 1;
            xLife = x + xOffset;
            xLife = wrap(xLife, 0, rowSize);

            yLife = y + yOffset;
            yLife = wrap(yLife, 0, colSize);
            lifeBoard[xLife][yLife] = preset[x][y];
        }
    }
}

vector<vector<Cell>> strToCell(string cellString) {
    vector<vector<Cell>> cellBoard;
    vector<Cell> col;
    for (char &cell: cellString) {
        switch (cell) {
            case '\n':
                cellBoard.push_back(col);
                col.clear();
                break;
            case '-':
            case '1':
                col.push_back(Cell::Alive);
                break;
            case '.':
            case '0':
            default:
                col.push_back(Cell::Dead);
                break;
        }
    }
    return cellBoard;
}