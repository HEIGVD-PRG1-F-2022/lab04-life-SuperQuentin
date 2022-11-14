//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include <iostream>
#include "../include/draw.h"

using namespace std;

void commandsHelper(){
    string tmp;
    tmp += "q = exit, p = pause, i = step, -/+ = add or sub 25ms (max: 10s, min: 25ms) \n\r";
    tmp += "1 = display debug cell (RED = will die, Green = Will be born), r = to restart the board, 3 = presets \n\r";
    cout << tmp;
}

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