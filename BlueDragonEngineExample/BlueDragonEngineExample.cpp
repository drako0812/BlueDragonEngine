#include "raylib-nuklear.h"
#include <toml++/toml.h>
#include <sol/sol.hpp>
#include "bde.export.hpp"
import bde.base;
import bde.errors;
import bde.engine;
import <cassert>;
import <string>;
import <string_view>;
import <vector>;
import <iostream>;
import <format>;

class ExampleEngine : public bde::Engine {
public:
    sol::load_result onRender;

    virtual void OnLoad() override {
        //UnloadNuklear(NuklearGUI);
        //nuklearFont = GetFontDefault(); int font_size = 10;
        //nuklearFont = LoadFont("resources/7x5.ttf"); int font_size = 8;
        //nuklearFont = LoadFont("resources/Monotype_Gerhilt.ttf"); int font_size = 9; // IMPERFECT PIXEL ALIGNMENT
        //nuklearFont = LoadFont("resources/ProggySquareSZ.ttf"); int font_size = 11; // IMPERFECT HORIZONTAL PIXEL ALIGNMENT
        //NuklearGUI = InitNuklearEx(nuklearFont, font_size);

        // load render script
        using namespace std::string_view_literals;
        onRender = Lua.load("rl.DrawCircle(128, 128, 128.0, rl.YELLOW)"sv);
        if (!onRender.valid()) {
            sol::error err = onRender;
            TraceLog(LOG_ERROR, std::format("Script load failed because: {}", err.what()).c_str());
            assert(false);
        }
    }

    virtual void OnUpdate() override {
        if (nk_begin(NuklearGUI, "BlueDragonEngine Example", nk_rect(256, 256, 400, 300), 0)) {
            nk_layout_row_dynamic(NuklearGUI, 0, 1);
            nk_label_wrap(NuklearGUI, "Welcome to the BlueDragonEngine Example. The code for this should demonstrate typical usage of the engine.");
            nk_label(NuklearGUI, "This is a 2nd label.", NK_TEXT_LEFT);
            nk_layout_row_dynamic(NuklearGUI, 140, 1);
            if (nk_group_begin(NuklearGUI, "Test Group", NK_WINDOW_BORDER | NK_WINDOW_TITLE)) {
                nk_layout_row_dynamic(NuklearGUI, 0, 3);
                nk_label(NuklearGUI, "0,0", NK_TEXT_CENTERED); nk_label(NuklearGUI, "1,0", NK_TEXT_CENTERED); nk_label(NuklearGUI, "2,0", NK_TEXT_CENTERED);
                nk_label(NuklearGUI, "0,1", NK_TEXT_CENTERED); nk_label(NuklearGUI, "1,1", NK_TEXT_CENTERED); nk_label(NuklearGUI, "2,1", NK_TEXT_CENTERED);
                nk_label(NuklearGUI, "0,2", NK_TEXT_CENTERED); nk_label(NuklearGUI, "1,2", NK_TEXT_CENTERED); nk_label(NuklearGUI, "2,2", NK_TEXT_CENTERED);
                nk_group_end(NuklearGUI);
            }
        }
        nk_end(NuklearGUI);
    }

    virtual void OnRender() override {
        auto result = onRender();
        if (!result.valid()) {
            sol::error err = result;
            TraceLog(LOG_ERROR, std::format("Call failed because: {}", err.what()).c_str());
            assert(false);
        }
    }
};

int main(int argc, char * argv[]) {
    return ExampleEngine()(argc, argv).HandleError();
}
