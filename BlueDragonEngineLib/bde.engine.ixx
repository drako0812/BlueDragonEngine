module;
#include "bde.export.hpp"
//#include "raylib.h"
//#include "raylib-nuklear.h"
#include <nuklear.h>
#include <toml++/toml.h>
#include <sol/sol.hpp>
export module bde.engine;

import bde.base;
//import bde.object;
//import bde.config;
//import <cstdint>;
//import <string>;
//import <string_view>;
import <iostream>;
import <vector>;
//import <filesystem>;
//import <fstream>;

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

        BDE_API operator int() const;

        /// @brief If there was an error, output error message. Return result regardless.
        /// @param out The std::ostream to output the error message to.
        /// @return the result.
        BDE_API int HandleError(std::ostream & out = std::cerr);

        BDE_API operator bool() const;
    };

    /// @brief Parent class of the BlueDragonEngine
    export class Engine {
    public:
        toml::table Config;
        nk_context * NuklearGUI;
        sol::state Lua;

        BDE_API virtual ~Engine();

        /// @brief Run the Engine with the given command-line arguments
        /// @param argc Argument count (argc from main)
        /// @param argv Argumen values (argv from main)
        /// @return a Result indicating success or failure in running the Engine.
        BDE_API Result operator() (int argc, char * argv[]);

        BDE_API virtual Result OnStartup(std::vector<std::string> const & args);
        BDE_API virtual void OnLoad();
        BDE_API virtual void OnUpdate();
        BDE_API virtual void OnRender();
        BDE_API virtual void OnShutdown();

    protected:

        BDE_API std::vector<std::string> convertArguments(int argc, char * argv[]);

    private:

        void loadEngineLuaAPI();
        void loadRaylibLuaAPI();
        void loadNuklearLuaAPI();
    };

}
