//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include <iostream>
#include "../include/draw.h"
#include "../include/terminal.h"

using namespace std;

void draw(vector<vector<Cell>> &lifeBoard) {
    string tmp;

    tmp += "\033[s";

    for (int x = 0; auto &row: lifeBoard) {
        for (int y = 0;auto &cell: row) {
            tmp += getCellColor(cell);
            ++y;
        }
        ++x;
        x < lifeBoard.size() ? tmp += "\n\r" : "";
    }

    tmp += "\033[u";
    cout << tmp;
}