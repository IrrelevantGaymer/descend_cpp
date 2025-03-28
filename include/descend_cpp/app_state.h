#ifndef SCENE_H
#define SCENE_H

#include <cstdint>
#include <variant>

#include "raylib.h"

namespace AppState {

    const Color BACKGROUND_COLOR = Color {57, 61, 71, 255};
    const Color TEXT_COLOR = Color {252, 252, 255, 255};

    struct MainMenu {};
    struct PlayGame {};
    enum class Tutorial {
        // Shows what pieces are in the game, what the board looks like, and what the winning goal is
        Setup,
        // Shows all the valid cards and their relative order
        Cards,
        // Shows how to place cards, including FREE moves
        Placement,
        // Shows how blocking works
        Blocking,
        // Shows how the winner of a game is decided
        TieBreaks
    };
    struct Settings {};

    typedef std::variant<MainMenu, PlayGame, Tutorial, Settings> Scene;

    void DrawScene(const Scene& scene);

    void DrawMainMenu(const MainMenu& main_menu);
    void DrawPlayGame(const PlayGame& play_game);
    void DrawTutorial(const Tutorial& tutorial);
    void DrawSettings(const Settings& settings);
    
}

std::tuple<int32_t, int32_t> GetScreenCenter();

#endif