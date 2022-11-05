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