#include <descend_cpp.h>

#include <iostream>

#include "raylib.h"
#include "option.h"

int main(int argc, char *argv[]) {
    Option<size_t> test = Option<size_t>::Some(4);

    IF_LET_SOME(testing, test) {
        std::cout << testing << "\n\n\n\n" << std::endl;
    }
    
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
