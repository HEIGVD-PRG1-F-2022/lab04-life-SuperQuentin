//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include "../include/draw.h"
#include "../include/terminal.h"

using namespace std;

void draw(vector<vector<Cell>> &lifeBoard) {
    string tmp;

    for (auto &row: lifeBoard) {
        for (auto &cell: row) {
            tmp += getCellColor(cell);
        }
        tmp += "\n";
    }

    setCursorToStart();
    cout << tmp;
}