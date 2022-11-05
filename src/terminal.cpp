//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include <iostream>

#ifdef _WIN32

#include <windows.h>
#include <conio.h>

#endif

#include "../include/terminal.h"

using namespace std;

void initTerminal() {
#ifdef _WIN32
    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); // Set terminal to utf-8 with support of colors
#elif __unix__
    // system("stty raw"); // Set terminal to raw mode, it will help to detect keystroke without interruption
#endif
    clearTerminal();
}

void terminateTerminal() {
#ifdef _WIN32
    // TODO: unset windows utf-8, but i'm kind of lazy now ƪ(˘⌣˘)ʃ
#elif __unix__
    system("stty cooked"); // Set back to default behavior of what we can attend of a marvelous terminal
#endif
}

char getKeyPressDown() {
#ifdef _WIN32
    return getch();
#elif __unix__
    return getchar();
#endif
}

void clearTerminal() {
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
}

void setCursorToStart() {
#ifdef _WIN32
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
#elif __unix__
    printf("\033[%d;%dH", 0 + 1, 0 + 1);
#endif
}

