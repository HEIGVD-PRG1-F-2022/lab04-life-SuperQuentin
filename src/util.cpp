//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include <chrono>
#include <thread>

#include "../include/util.h"

using namespace std;

void wait(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

string getColorsCodeStr(TerminalColors color){
    return to_string((int) color);
}

int wrap(int value, int min, int max){
    int wrapSize = max - min + 1;

    if(value < min) {
        value += wrapSize * ((min - value)/ wrapSize + 1);
    }

    return min + (value - min) % wrapSize;
}

int wrap(int value, vector<string> vector) {
    int wrapSize = vector.size();

    if(value < 0) {
        value += wrapSize * ((value)/ wrapSize + 1);
    }

    return (value) % wrapSize;
}