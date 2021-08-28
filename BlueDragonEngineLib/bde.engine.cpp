module;
#include <raylib.h>
#include "raylib-nuklear.h"
#include <toml++/toml.h>
module bde.engine;

import bde.base;
import bde.object;
import bde.config;
import <string>;
import <string_view>;
import <iostream>;
import <vector>;
import <filesystem>;
import <fstream>;

namespace bde {
    Result::operator int() const { return static_cast<int>(Type); }

    int Result::HandleError(std::ostream & out) {
        if (Type != ResultType::Success) {
            out << Message << std::endl;
            out.flush();
        }
        return *this;
    }

    Result::operator bool() const { return !static_cast<bool>(Type); }

    Engine::~Engine() {
        TraceLog(LOG_INFO, "Shutting Down Engine");
    }

    Result Engine::operator()(int argc, char * argv[]) {
    #ifdef _DEBUG
        SetTraceLogLevel(LOG_DEBUG);
    #else
        SetTraceLogLevel(LOG_WARNING);
    #endif

        TraceLog(LOG_INFO, "Starting engine");

        if (std::filesystem::exists("bde_config.toml")) {
            TraceLog(LOG_INFO, "    Loading \"bde_config.toml\"");
            Config = toml::parse_file("bde_config.toml");
        } else {
            TraceLog(LOG_INFO, "    Creating default configuration");
            using namespace std::string_view_literals;
            static constexpr std::string_view Config_default = R"([display]
width = 800
height = 600
framerate = 60
default_bg_color = [245, 245, 245, 255]
)"sv;
            Config = toml::parse(Config_default);
        }
        TraceLog(LOG_INFO, "    Configuration loaded\n");

        TraceLog(LOG_INFO, "    Calling OnStartup");
        if (auto r = OnStartup(convertArguments(argc, argv)); !r) {
            return r;
        }

        Color default_bg_color = {
            Config["display"]["default_bg_color"][0].value<std::uint8_t>().value(),
            Config["display"]["default_bg_color"][1].value<std::uint8_t>().value(),
            Config["display"]["default_bg_color"][2].value<std::uint8_t>().value(),
            Config["display"]["default_bg_color"][3].value<std::uint8_t>().value()
        };

        TraceLog(LOG_INFO, "    Creating window");
        InitWindow(Config["display"]["width"].value<int>().value(), Config["display"]["height"].value<int>().value(), "BlueDragonEngine");
        SetTargetFPS(Config["display"]["framerate"].value<int>().value());

        int fontSize = 10;
        NuklearGUI = InitNuklear(fontSize);

        OnLoad();

        while (!WindowShouldClose()) {
            // Update
            UpdateNuklear(NuklearGUI);
            OnUpdate();

            // Draw
            BeginDrawing();
            ClearBackground(default_bg_color);
            OnRender();
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            DrawNuklear(NuklearGUI);
            EndDrawing();
        }

        OnShutdown();
        UnloadNuklear(NuklearGUI);
        CloseWindow();
        TraceLog(LOG_INFO, "    Window closed");

        {
            TraceLog(LOG_INFO, "    Opening \"bde_config.toml\"");
            std::ofstream outf("bde_config.toml", std::ios::out | std::ios::trunc);
            if (outf) {
                outf << Config << "\n";
                outf.close();
                TraceLog(LOG_INFO, "    Configuration saved");
            } else {
                TraceLog(LOG_WARNING, "    Failed to save configuration");
            }
        }

        TraceLog(LOG_INFO, "Engine shutdown");
        return { .Type = ResultType::Success };
    }

    Result Engine::OnStartup(std::vector<std::string> const & args) {
        std::cout << "Arguments:\n";
        for (auto const & arg : args) {
            std::cout << "    " << arg << std::endl;
        }
        std::cout << std::endl;

        return { .Type = ResultType::Success };
    }

    void Engine::OnLoad() { }
    void Engine::OnUpdate() { }
    void Engine::OnRender() { }
    void Engine::OnShutdown() { }

    std::vector<std::string> Engine::convertArguments(int argc, char * argv[]) {
        std::vector<std::string> args;
        args.resize(argc);
        for (int i = 0; i < argc; i++) {
            args.at(i) = argv[i];
        }
        return args;
    }
}
