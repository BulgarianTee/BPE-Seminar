#ifndef SIMPLE_MENU_H
#define SIMPLE_MENU_H

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define KEY_W 'w'
#define KEY_S 's'
#define KEY_E 'e'

void pause_and_wait() {
    printf("\n\nPress any key to return to menu...");
    _getch();
}

void exit_program() {
    exit(0);
}

typedef void (*MenuFunction)();

typedef struct {
    const char* text;
    MenuFunction function;
} MenuOption;

static void clear_screen() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count, cellCount;
    COORD homeCoords = {0, 0};

    if (hOut == INVALID_HANDLE_VALUE) return;

    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hOut, ' ', cellCount, homeCoords, &count);
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, cellCount, homeCoords, &count);
    SetConsoleCursorPosition(hOut, homeCoords);
}

static void run_menu(const char* title, MenuOption options[], int option_count) {
    int selected = 0;

    while (1) {
        clear_screen();

        printf("=== %s ===\n\n", title);

        for (int i = 0; i < option_count; i++) {
            if (i == selected)
                printf("> %s\n", options[i].text);
            else
                printf("  %s\n", options[i].text);
        }

        char input = _getch();

        if (input == KEY_W || input == 'W') {
            selected--;
            if (selected < 0)
                selected = option_count - 1;
        }
        else if (input == KEY_S || input == 'S') {
            selected++;
            if (selected >= option_count)
                selected = 0;
        }
        else if (input == KEY_E || input == 'E') {
            clear_screen();
            options[selected].function();
        }
    }
}

#endif
