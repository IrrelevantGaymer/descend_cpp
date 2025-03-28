#include <cstdint>
#include <tuple>
#include <variant>

#include "raylib.h"
#include "app_state.h"

void AppState::DrawScene(const AppState::Scene& scene) {
    struct SceneVisitor {
        void operator()(const AppState::MainMenu& main_menu) const {
            AppState::DrawMainMenu(main_menu);
        }

        void operator()(const AppState::PlayGame& play_game) const {
            AppState::DrawPlayGame(play_game);
        }

        void operator()(const AppState::Tutorial& tutorial) const {
            AppState::DrawTutorial(tutorial);
        }

        void operator()(const AppState::Settings& settings) const {
            AppState::DrawSettings(settings);
        }
    };

    std::visit(SceneVisitor(), scene);
}

void AppState::DrawMainMenu(const AppState::MainMenu& main_menu) {
    int32_t x, y;
    std::tie(x, y) = GetScreenCenter();
    
    const char* text = "Main Menu";
    const int32_t font_size = 20;
    int32_t text_width = MeasureText(text, 20);
    int32_t text_height = font_size;
    int32_t x_offset = text_width / 2.;
    int32_t y_offset = text_height / 2.;
            
    BeginDrawing();
        ClearBackground(AppState::BACKGROUND_COLOR);
        DrawText(text, x - x_offset, y - y_offset, font_size, AppState::TEXT_COLOR);
    EndDrawing();
}

void AppState::DrawPlayGame(const AppState::PlayGame& play_game) {
    int32_t x, y;
    std::tie(x, y) = GetScreenCenter();

    const char* text = "Play Game";
    const int32_t font_size = 20;
    int32_t text_width = MeasureText(text, 20);
    int32_t text_height = font_size;
    int32_t x_offset = text_width / 2.;
    int32_t y_offset = text_height / 2.;
            
    BeginDrawing();
        ClearBackground(AppState::BACKGROUND_COLOR);
        DrawText(text, x - x_offset, y - y_offset, font_size, AppState::TEXT_COLOR);
    EndDrawing();
}

void AppState::DrawTutorial(const AppState::Tutorial& tutorial) {
    int32_t x, y;
    std::tie(x, y) = GetScreenCenter();
    
    BeginDrawing();
        ClearBackground(AppState::BACKGROUND_COLOR);
        switch (tutorial) {
        case AppState::Tutorial::Setup: {
            const char* text = "Tutorial Setup";
            const int32_t font_size = 20;
            int32_t text_width = MeasureText(text, 20);
            int32_t text_height = font_size;
            int32_t x_offset = text_width / 2.;
            int32_t y_offset = text_height / 2.;
            
            DrawText(text, x - x_offset, y - y_offset, font_size, AppState::TEXT_COLOR);
            break;
        }
        case AppState::Tutorial::Cards: {
            const char* text = "Tutorial Cards";
            const int32_t font_size = 20;
            int32_t text_width = MeasureText(text, 20);
            int32_t text_height = font_size;
            int32_t x_offset = text_width / 2.;
            int32_t y_offset = text_height / 2.;
            
            DrawText(text, x - x_offset, y - y_offset, font_size, AppState::TEXT_COLOR);
            break;
        }
        case AppState::Tutorial::Placement: {
            const char* text = "Tutorial Placement";
            const int32_t font_size = 20;
            int32_t text_width = MeasureText(text, 20);
            int32_t text_height = font_size;
            int32_t x_offset = text_width / 2.;
            int32_t y_offset = text_height / 2.;
            
            DrawText(text, x - x_offset, y - y_offset, font_size, AppState::TEXT_COLOR);
            break;
        }
        case AppState::Tutorial::Blocking: {
            const char* text = "Tutorial Blocking";
            const int32_t font_size = 20;
            int32_t text_width = MeasureText(text, 20);
            int32_t text_height = font_size;
            int32_t x_offset = text_width / 2.;
            int32_t y_offset = text_height / 2.;
            
            DrawText(text, x - x_offset, y - y_offset, font_size, AppState::TEXT_COLOR);
            break;
        }
        case AppState::Tutorial::TieBreaks: {
            const char* text = "Tutorial TieBreaks";
            const int32_t font_size = 20;
            int32_t text_width = MeasureText(text, 20);
            int32_t text_height = font_size;
            int32_t x_offset = text_width / 2.;
            int32_t y_offset = text_height / 2.;
            
            DrawText(text, x - x_offset, y - y_offset, font_size, AppState::TEXT_COLOR);
            break;
        }
        default:
            std::__throw_invalid_argument("unreachable!");
        }
    EndDrawing();
}

void AppState::DrawSettings(const AppState::Settings& settings) {
    int32_t x, y;
    std::tie(x, y) = GetScreenCenter();
    
    const char* text = "Settings";
    const int32_t font_size = 20;
    int32_t text_width = MeasureText(text, 20);
    int32_t text_height = font_size;
    int32_t x_offset = text_width / 2.;
    int32_t y_offset = text_height / 2.;
            
    BeginDrawing();
        ClearBackground(AppState::BACKGROUND_COLOR);
        DrawText(text, x - x_offset, y - y_offset, font_size, AppState::TEXT_COLOR);
    EndDrawing();
}

std::tuple<int32_t, int32_t> GetScreenCenter() {
    return { GetScreenWidth() / 2., GetScreenHeight() / 2. };
}