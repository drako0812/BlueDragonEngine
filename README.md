# BlueDragonEngine

**BlueDragonEngine** is a programmer-first game engine. It uses brand new C++20 language features and uses several other open source libraries to achieve its goals.

[Downloading](#downloading) | [Building](#building) | [Usage](#usage) | [Dependencies](#dependencies)

## Downloading

Currently (until there are [releases][releases]), the only useful way to download the engine is by using Git.

```bat
cd <where-ever you want to dowload to>
git clone --recurse-submodules https://github.com/drako0812/BlueDragonEngine
cd BlueDragonEngine
```

## Building

Currently, I only have build instructions for Visual Studio 2019 on Windows 10.

### Vcpkg

This engine uses [Vcpkg][vcpkg] to handle most of its dependencies, the others are git submodules and should have been aquired automatically in the [Downloading](#downloading) step.

So make sure you install Vcpkg using their instructions before proceeding.

### Using Visual Studio 2019 IDE

1. Open `BlueDragonEngine.sln` in the root folder to open the VS Solution for the engine.
2. Select the Solution Configuration (either Debug or Release).
3. Select `Build->Build Solution` to build the engine.
4. Wait.
5. Profit 😜
   
   There should be a `BlueDragonEngineLib.lib` file in `<project root>/x64/<Debug or Release>/`. Currently, the Debug version of the engine is over 100 MiB and the Release version is over 70 MiB. I will investigate if there are ways to shrink that down.

### Using Visual Studio 2019 Command Line

> ***COMING SOON***

## Usage

### Setting up a Visual Studio 2019 Project

I think the easiest way currently to get set up is to just add a project to the engine's Solution (`<root>/BlueDragonEngine.sln`).

Since this engine uses very cutting-edge C++20 features (namely, modules) and it doesn't hide away all of its dependencies through abstraction layers yet, there is a bit of configuration to making a project work with the engine.

> **NOTE:** Hopefully this process will become simpler as the project (as well as the compilers) mature.

1. First, make a new project (I'd go with a C++ Windows Console project for easiest integration).
2. Open up the property pages for the new project. Ensure that `Configuration` is set to `All Configurations` and `Platform` is set to `All Platforms`.
3. Go to `General`
   1. Change `C++ Language Standard` to `/std:c++latest`
   2. Change `C Language Standard` to `/std:c17` (This might not be neccessary)
4. Go to `vcpkg`
   1. Make sure `Use Vcpkg`, `Use Vcpkg Manifest`, `Install Vcpkg Dependencies`, and `Use AutoLink` are all set to `Yes`.
5. Go to `C/C++ -> General`
   1. Set `Additional Include Directories` is `$(SolutionDir)extern\raylib-nuklear\include;%(AdditionalIncludeDirectories)`
   2. Set `Scan Sources for Module Dependencies` to `Yes`
6. Go to `C/C++ -> Preprocessor`
   1. Add `SOL_ALL_SAFETIES_ON=1` and `SOL_USING_CXX_LUA=1` to `Preprocessor Definitions`
7. Go to `C/C++ -> Language`
   1. Set `Enable Experimental C++ Standard Library Modules` to `Yes`
8. Save the changes to the properties and close the window.
9. Add the file `vcpkg.json` to your project
10. Fill in at least the following contents into that JSON file:
    
    ```.json
    {
        "$schema": "https://raw.githubusercontent.com/microsoft/vcpkg/master/scripts/vcpkg.schema.json",
        "name": "name-of-project",
        "version": "0.1.0",
        "dependencies": [
            {
                "name": "raylib",
                "features": [ "use-audio" ]
            },
            "tomlplusplus",
            "nuklear",
            {
                "name": "lua",
                "features": [ "cpp" ]
            },
            "sol2"
        ]
    }
    ```

    Be sure to change `name` to whatever your project will be called. And change `version` to whatever the version of your project is. Be aware that there are rules to how to name your project in a `vcpkg.json` manifest. Consult the Vcpkg documentation for those rules.
11. Right click on your project in the Solution Explorer then  select `Add -> Reference...`
12. In `Projects -> Solution` select `BlueDragonEngineLib` (check the checkbox) and click `OK`.
13. You're basically ready to go, now. But to get you started here's a couple bare-bones examples for your program:
    1.  ```cpp
        #include "raylib-nuklear.h"
        #include <toml++/toml.h>
        #include <sol/sol.hpp>
        #include "bde.export.hpp"
        import bde.base;
        import bde.errors;
        import bde.engine;
        import <string>;
        import <vector>;
        import <iostream>;

        int main(int argc, char * argv[]) {
            return bde::Engine()(argc, argv).HandleError();
        }
        ```
        This doesn't do really anything than open an empty window.
    2. ```cpp
       #include "raylib-nuklear.h"
       #include <toml++/toml.h>
       #include <sol/sol.hpp>
       #include "bde.export.hpp"
       import bde.base;
       import bde.errors;
       import bde.engine;
       import <string>;
       import <vector>;
       import <iostream>;
   
       class ExampleEngine : public bde::Engine {
       public:
           virtual ~ExampleEngine() override {
               // Put any cleanup code here.
           }

           virtual bde::Result OnStartup(std::vector<std::string> const & args) override {
               // This is called before the Engine is entirely online
               // Process the command-line arguments in `args` here.

               return { .Type = bde::ResultType::Success };
           }

           virtual void OnLoad() override {
               // Add code to perform when loading the Engine here.
           }

           virtual void OnUpdate() override {
               if (nk_begin(NuklearGUI, "BlueDragonEngine Example", nk_rect(256, 256, 400, 300), 0)) {
                   nk_layout_row_dynamic(NuklearGUI, 0, 3);
                   nk_label(NuklearGUI, "Hello World!", NK_TEXT_LEFT);
                   if (nk_button_label(NuklearGUI, "Okay")) {
                       TraceLog(LOG_INFO, "Pressed Okay!");
                   }
                   if (nk_button_label(NuklearGUI, "Cancel")) {
                       TraceLog(LOG_INFO, "Pressed Cancel!");
                   }
               }
               nk_end(NuklearGUI);
               // Add code to update game state every frame here.
           }

           virtual void OnRender() override {
               DrawCircle(128, 128, 128, YELLOW);
               // Add code to render game visuals every frame here.
           }

           virtual void OnShutdown() override {
               // Add code that should be ran when shutting down the game but still needs the Engine active.
           }
       };

       int main(int argc, char * argv[]) {
           return ExampleEngine()(argc, argv).HandleError();
       }
       ```

       This demonstrates some usage of the [Nuklear][nuklear] immediate-mode GUI library as well as [Raylib][raylib]. It also shows all the *current* customization points to the engine.

## Dependencies

Once again, all the dependencies should be acquired automatically either through the `git clone` command or when building utilizing Vcpkg.

1. [Raylib][raylib] is the backbone of this engine. It's used for everything from managing the window to displaying graphics and handling audio.
2. [Nuklear][nuklear] is used for GUI purposes in the engine.
3. [raylib-nuklear][raylib-nuklear] is used as the glue between Raylib and Nuklear.
4. [toml++][tomlplusplus] is used for working with TOML configuration files.
5. [Lua][lua] is used for scripting-language purposes.
6. [Sol][sol] is used for glueing together the engine and Lua.

[releases]: https://github.com/drako0812/BlueDragonEngine/releases
[vcpkg]: https://github.com/microsoft/vcpkg
[raylib]: https://raylib.com
[nuklear]: https://github.com/Immediate-Mode-UI/Nuklear
[raylib-nuklear]: https://github.com/RobLoach/raylib-nuklear
[tomlplusplus]: https://marzer.github.io/tomlplusplus/
[lua]: https://www.lua.org/
[sol]: https://github.com/ThePhD/sol2
