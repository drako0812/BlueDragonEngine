module;
#include "raylib.h"
export module bde.engine;

import bde.base;
import bde.object;
import bde.config;
import <string>;
import <iostream>;
import <vector>;

namespace bde {

    /// @brief Represents success or failure of an operation
    export enum class ResultType {
        Success,
        Failure,
    };

    /// @brief The result of some operation that can report an error.
    export struct Result {
        ResultType Type;

        /// @brief The error from the ran operation.
        error Message;

        inline operator int() { return static_cast<int>(Type); }

        /// @brief If there was an error, output error message. Return result regardless.
        /// @param out The std::ostream to output the error message to.
        /// @return the result.
        inline int HandleError(std::ostream & out = std::cerr) {
            if (Type != ResultType::Success) {
                out << Message << std::endl;
                out.flush();
            }
            return *this;
        }

        inline operator bool() { return !static_cast<bool>(Type); }
    };

    /// @brief Parent class of the BlueDragonEngine
    export class Engine {
    public:
        Configuration Config;

        virtual ~Engine();

        /// @brief Run the Engine with the given command-line arguments
        /// @param argc Argument count (argc from main)
        /// @param argv Argumen values (argv from main)
        /// @return a Result indicating success or failure in running the Engine.
        Result operator() (int argc, char * argv[]);

        virtual Result OnStartup(std::vector<std::string> const & args);

    protected:

        std::vector<std::string> convertArguments(int argc, char * argv[]);
    };

    Engine::~Engine() {
        std::cout << "Shutting Down Engine\n";
    }

    Result Engine::operator()(int argc, char * argv[]) {
        std::cout << "Starting Engine\n";

        if (auto r = OnStartup(convertArguments(argc, argv)); !r) {
            return r;
        }

        Config.CreateCategory("display").
            SetInt("display", "width", 800).
            SetInt("display", "height", 450).
            SetInt("display", "framerate", 60).
            SetList("display", "default_bg_color", ConfigList{ 245ll,245ll,245ll,255ll });

        Color default_bg_color;
        {
            auto v = Config.GetList("display", "default_bg_color").value();
            default_bg_color = Color{
                static_cast<unsigned char>(std::any_cast<ConfigInt>(v[0])),
                static_cast<unsigned char>(std::any_cast<ConfigInt>(v[1])),
                static_cast<unsigned char>(std::any_cast<ConfigInt>(v[2])),
                static_cast<unsigned char>(std::any_cast<ConfigInt>(v[3]))
            };
        }

        InitWindow(Config.GetInt("display", "width").value(), Config.GetInt("display", "height").value(), "raylib [core] example - basic window");
        SetTargetFPS(Config.GetInt("display", "framerate").value());

        while (!WindowShouldClose()) {
            // Update

            // Draw
            BeginDrawing();
            ClearBackground(default_bg_color);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            EndDrawing();
        }

        CloseWindow();

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

    std::vector<std::string> Engine::convertArguments(int argc, char * argv[]) {
        std::vector<std::string> args;
        args.resize(argc);
        for (int i = 0; i < argc; i++) {
            args.at(i) = argv[i];
        }
        return args;
    }

}
