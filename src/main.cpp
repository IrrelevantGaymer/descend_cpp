#include <descend_cpp.h>

#include <iostream>
#include <string>

#include "raylib.h"
#include "app_state.h"
#include "option.h"

// If you ever need a cheatsheet for raylib stuff, you can go here:
// https://www.raylib.com/cheatsheet/cheatsheet.html

int main(int argc, char *argv[]) {
    Option<std::string> test = Option<std::string>::Some("Some variant");

    IF_LET_SOME(testing, test) {
        std::cout << testing << "\n\n\n\n" << std::endl;
    }

    AppState::Scene scene = AppState::Tutorial::Cards;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIDDEN);
    InitWindow(800, 450, "Descend");

    int32_t frame = 0;

    while (!WindowShouldClose()) {
        // We make the window visible then maximize a couple frames after window creation
        // so we can avoid a graphical bug where the window is pure white before we
        // draw anything to the window
        if (frame == 2) {
            ClearWindowState(FLAG_WINDOW_HIDDEN);
        } else if (frame == 3) {
            MaximizeWindow();
        }
        
        // Handle Input

        DrawScene(scene);

        frame++;
    }

    CloseWindow();

    return 0;
}