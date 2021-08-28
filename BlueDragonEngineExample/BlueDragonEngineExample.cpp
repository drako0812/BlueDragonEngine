#include "raylib-nuklear.h"
#include <toml++/toml.h>
#include "bde.export.hpp"
import bde.base;
import bde.errors;
import bde.engine;
import <string>;
import <vector>;
import <iostream>;

class ExampleEngine : public bde::Engine {
public:
    Font nuklearFont;

    virtual void OnLoad() override {
        UnloadNuklear(NuklearGUI);
        nuklearFont = LoadFont("resources/7x5.ttf"); int font_size = 8;
        //nuklearFont = LoadFont("resources/Monotype_Gerhilt.ttf"); int font_size = 9; // IMPERFECT PIXEL ALIGNMENT
        //nuklearFont = LoadFont("resources/ProggySquareSZ.ttf"); int font_size = 11; // IMPERFECT HORIZONTAL PIXEL ALIGNMENT
        NuklearGUI = InitNuklearEx(nuklearFont, font_size);
    }

    virtual void OnUpdate() override {
        if (nk_begin(NuklearGUI, "BlueDragonEngine Example", nk_rect(10, 10, 500, 480),
                     NK_WINDOW_BORDER | NK_WINDOW_TITLE)) {
            nk_layout_row_dynamic(NuklearGUI, 60, 1);
            nk_label_wrap(NuklearGUI, "Welcome to the BlueDragonEngine Example. The code for this should demonstrate typical usage of the engine.");
            nk_label(NuklearGUI, "This is a 2nd label.", NK_TEXT_LEFT);

        }
        nk_end(NuklearGUI);
    }
};

int main(int argc, char * argv[]) {
    return ExampleEngine()(argc, argv).HandleError();
}
