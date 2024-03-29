//
// Project name : LAB 04 - Life
// Project members :
// - Aellen Quentin
//

#include <iostream>

#ifdef _WIN32

#include <windows.h>
#include <conio.h>

#elif __unix__

#include <sys/ioctl.h>

#endif

#include "../include/terminal.h"

using namespace std;

void initTerminal() {
#ifdef _WIN32
    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); // Set terminal to utf-8 with support of colors
#elif __unix__
    system("stty raw -echo");   // Set terminal to raw mode, it will help to detect keystroke without interruption
#endif
    hideTerminalCursor();
    clearTerminal();
}

void terminateTerminal() {
#ifdef _WIN32
    // TODO: unset windows utf-8, but i'm kind of lazy now ƪ(˘⌣˘)ʃ
#elif __unix__
    system("stty cooked echo"); // Set back to default behavior of what we can attend of a marvelous terminal
#endif
    showTerminalCursor();
    clearTerminal();
}

char getKeyPressDown() {
#ifdef _WIN32
    if (kbhit()) {
        return (char)getch();
    }
    return '\000';
#elif __unix__
    return (char)getchar(); //TODO make it non blocant
#endif
}

char getKey() {
#ifdef _WIN32
    return (char)_getch();
#elif __unix__
    return (char)getchar();
#endif
}

void clearTerminal() {
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
}

void hideTerminalCursor() {
    cout << "\033[?25l";
}

void showTerminalCursor() {
    cout << "\033[?25h";
}


void getTerminalSize(int &width, int &height) {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = (int) (csbi.srWindow.Right - csbi.srWindow.Left + 1);
    height = (int) (csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
#elif __unix__
    struct winsize w;
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    width = (int) (w.ws_col);
    height = (int) (w.ws_row);
#endif
}