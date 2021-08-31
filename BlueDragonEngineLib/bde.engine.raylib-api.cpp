module;
#include <raylib.h>
#include <sol/sol.hpp>
#include <toml++/toml.h>
module bde.engine;

import bde.base;
import bde.object;
import bde.config;

namespace bde {

    void Engine::loadRaylibLuaAPI() {
        auto rl = Lua["rl"].get_or_create<sol::table>();
        rl["PI"] = PI;
        rl["DEG2RAD"] = DEG2RAD;
        rl["RAD2DEG"] = RAD2DEG;

        rl.new_usertype<Vector2>("Vector2");
        rl.new_usertype<Vector3>("Vector3");
        rl.new_usertype<Vector4>("Vector4");
        rl.new_usertype<Quaternion>("Quaternion");
        rl.new_usertype<Matrix>("Matrix");
        rl.new_usertype<Color>("Color");
        rl.new_usertype<Rectangle>("Rectangle");
        rl.new_usertype<Image>("Image");
        rl.new_usertype<Texture>("Texture");
        rl.new_usertype<RenderTexture>("RenderTexture");
        rl.new_usertype<NPatchInfo>("NPatchInfo");
        rl.new_usertype<CharInfo>("CharInfo");
        rl.new_usertype<Font>("Font");
        rl.new_usertype<Camera3D>("Camera3D");
        rl.new_usertype<Camera2D>("Camera2D");
        rl.new_usertype<Mesh>("Mesh");
        rl.new_usertype<Shader>("Shader");
        rl.new_usertype<MaterialMap>("MaterialMap");
        rl.new_usertype<Material>("Material");
        rl.new_usertype<Transform>("Transform");
        rl.new_usertype<BoneInfo>("BoneInfo");
        rl.new_usertype<Model>("Model");
        rl.new_usertype<ModelAnimation>("ModelAnimation");
        rl.new_usertype<Ray>("Ray");
        rl.new_usertype<RayHitInfo>("RayHitInfo");
        rl.new_usertype<BoundingBox>("BoundingBox");
        rl.new_usertype<Wave>("Wave");
        //rl.new_usertype<rAudioBuffer>("rAudioBuffer"); // TODO: Does this actually need to be exported?
        rl.new_usertype<AudioStream>("AudioStream");
        rl.new_usertype<Sound>("Sound");
        rl.new_usertype<Music>("Music");
        rl.new_usertype<VrDeviceInfo>("VrDeviceInfo");
        rl.new_usertype<VrStereoConfig>("VrStereoConfig");

        // Basic Colors
        rl["LIGHTGRAY"] = LIGHTGRAY;
        rl["GRAY"] = GRAY;
        rl["DARKGRAY"] = DARKGRAY;
        rl["YELLOW"] = YELLOW;
        rl["GOLD"] = GOLD;
        rl["ORANGE"] = ORANGE;
        rl["PINK"] = PINK;
        rl["RED"] = RED;
        rl["MAROON"] = MAROON;
        rl["GREEN"] = GREEN;
        rl["LIME"] = LIME;
        rl["DARKGREEN"] = DARKGREEN;
        rl["SKYBLUE"] = SKYBLUE;
        rl["BLUE"] = BLUE;
        rl["DARKBLUE"] = DARKBLUE;
        rl["PURPLE"] = PURPLE;
        rl["VIOLET"] = VIOLET;
        rl["DARKPURPLE"] = DARKPURPLE;
        rl["BEIGE"] = BEIGE;
        rl["BROWN"] = BROWN;
        rl["DARKBROWN"] = DARKBROWN;
        rl["WHITE"] = WHITE;
        rl["BLACK"] = BLACK;
        rl["BLANK"] = BLANK;
        rl["MAGENTA"] = MAGENTA;
        rl["RAYWHITE"] = RAYWHITE;

        // ConfigFlags
        rl["FLAG_VSYNC_HINT"] = FLAG_VSYNC_HINT;
        rl["FLAG_FULLSCREEN_MODE"] = FLAG_FULLSCREEN_MODE;
        rl["FLAG_WINDOW_RESIZABLE"] = FLAG_WINDOW_RESIZABLE;
        rl["FLAG_WINDOW_UNDECORATED"] = FLAG_WINDOW_UNDECORATED;
        rl["FLAG_WINDOW_MINIMIZED"] = FLAG_WINDOW_MINIMIZED;
        rl["FLAG_WINDOW_MAXIMIZED"] = FLAG_WINDOW_MAXIMIZED;
        rl["FLAG_WINDOW_UNFOCUSED"] = FLAG_WINDOW_UNFOCUSED;
        rl["FLAG_WINDOW_TOPMOST"] = FLAG_WINDOW_TOPMOST;
        rl["FLAG_WINDOW_ALWAYS_RUN"] = FLAG_WINDOW_ALWAYS_RUN;
        rl["FLAG_WINDOW_TRANSPARENT"] = FLAG_WINDOW_TRANSPARENT;
        rl["FLAG_WINDOW_HIGHDPI"] = FLAG_WINDOW_HIGHDPI;
        rl["FLAG_MSAA_4X_HINT"] = FLAG_MSAA_4X_HINT;
        rl["FLAG_INTERLACED_HINT"] = FLAG_INTERLACED_HINT;

        // TraceLogLevel
        rl["LOG_ALL"] = LOG_ALL;
        rl["LOG_TRACE"] = LOG_TRACE;
        rl["LOG_DEBUG"] = LOG_DEBUG;
        rl["LOG_INFO"] = LOG_INFO;
        rl["LOG_WARNING"] = LOG_WARNING;
        rl["LOG_ERROR"] = LOG_ERROR;
        rl["LOG_FATAL"] = LOG_FATAL;
        rl["LOG_NONE"] = LOG_NONE;

        // KeyboardKey
        rl["KEY_NULL"] = KEY_NULL;
        // Alphanumeric keys
        rl["KEY_APOSTROPHE"] = KEY_APOSTROPHE;
        rl["KEY_COMMA"] = KEY_COMMA;
        rl["KEY_MINUS"] = KEY_MINUS;
        rl["KEY_PERIOD"] = KEY_PERIOD;
        rl["KEY_SLASH"] = KEY_SLASH;
        rl["KEY_ZERO"] = KEY_ZERO;
        rl["KEY_ONE"] = KEY_ONE;
        rl["KEY_TWO"] = KEY_TWO;
        rl["KEY_THREE"] = KEY_THREE;
        rl["KEY_FOUR"] = KEY_FOUR;
        rl["KEY_FIVE"] = KEY_FIVE;
        rl["KEY_SIX"] = KEY_SIX;
        rl["KEY_SEVEN"] = KEY_SEVEN;
        rl["KEY_EIGHT"] = KEY_EIGHT;
        rl["KEY_NINE"] = KEY_NINE;
        rl["KEY_SEMICOLON"] = KEY_SEMICOLON;
        rl["KEY_EQUAL"] = KEY_EQUAL;
        rl["KEY_A"] = KEY_A;
        rl["KEY_B"] = KEY_B;
        rl["KEY_C"] = KEY_C;
        rl["KEY_D"] = KEY_D;
        rl["KEY_E"] = KEY_E;
        rl["KEY_F"] = KEY_F;
        rl["KEY_G"] = KEY_G;
        rl["KEY_H"] = KEY_H;
        rl["KEY_I"] = KEY_I;
        rl["KEY_J"] = KEY_J;
        rl["KEY_K"] = KEY_K;
        rl["KEY_L"] = KEY_L;
        rl["KEY_M"] = KEY_M;
        rl["KEY_N"] = KEY_N;
        rl["KEY_O"] = KEY_O;
        rl["KEY_P"] = KEY_P;
        rl["KEY_Q"] = KEY_Q;
        rl["KEY_R"] = KEY_R;
        rl["KEY_S"] = KEY_S;
        rl["KEY_T"] = KEY_T;
        rl["KEY_U"] = KEY_U;
        rl["KEY_V"] = KEY_V;
        rl["KEY_W"] = KEY_W;
        rl["KEY_X"] = KEY_X;
        rl["KEY_Y"] = KEY_Y;
        rl["KEY_Z"] = KEY_Z;
        // Function keys
        rl["KEY_SPACE"] = KEY_SPACE;
        rl["KEY_ESCAPE"] = KEY_ESCAPE;
        rl["KEY_ENTER"] = KEY_ENTER;
        rl["KEY_TAB"] = KEY_TAB;
        rl["KEY_BACKSPACE"] = KEY_BACKSPACE;
        rl["KEY_INSERT"] = KEY_INSERT;
        rl["KEY_DELETE"] = KEY_DELETE;
        rl["KEY_RIGHT"] = KEY_RIGHT;
        rl["KEY_LEFT"] = KEY_LEFT;
        rl["KEY_DOWN"] = KEY_DOWN;
        rl["KEY_UP"] = KEY_UP;
        rl["KEY_PAGE_UP"] = KEY_PAGE_UP;
        rl["KEY_PAGE_DOWN"] = KEY_PAGE_DOWN;
        rl["KEY_HOME"] = KEY_HOME;
        rl["KEY_END"] = KEY_END;
        rl["KEY_CAPS_LOCK"] = KEY_CAPS_LOCK;
        rl["KEY_SCROLL_LOCK"] = KEY_SCROLL_LOCK;
        rl["KEY_NUM_LOCK"] = KEY_NUM_LOCK;
        rl["KEY_PRINT_SCREEN"] = KEY_PRINT_SCREEN;
        rl["KEY_PAUSE"] = KEY_PAUSE;
        rl["KEY_F1"] = KEY_F1;
        rl["KEY_F2"] = KEY_F2;
        rl["KEY_F3"] = KEY_F3;
        rl["KEY_F4"] = KEY_F4;
        rl["KEY_F5"] = KEY_F5;
        rl["KEY_F6"] = KEY_F6;
        rl["KEY_F7"] = KEY_F7;
        rl["KEY_F8"] = KEY_F8;
        rl["KEY_F9"] = KEY_F9;
        rl["KEY_F10"] = KEY_F10;
        rl["KEY_F11"] = KEY_F11;
        rl["KEY_F12"] = KEY_F12;
        rl["KEY_LEFT_SHIFT"] = KEY_LEFT_SHIFT;
        rl["KEY_LEFT_CONTROL"] = KEY_LEFT_CONTROL;
        rl["KEY_LEFT_ALT"] = KEY_LEFT_ALT;
        rl["KEY_LEFT_SUPER"] = KEY_LEFT_SUPER;
        rl["KEY_RIGHT_SHIFT"] = KEY_RIGHT_SHIFT;
        rl["KEY_RIGHT_CONTROL"] = KEY_RIGHT_CONTROL;
        rl["KEY_RIGHT_ALT"] = KEY_RIGHT_ALT;
        rl["KEY_RIGHT_SUPER"] = KEY_RIGHT_SUPER;
        rl["KEY_KB_MENU"] = KEY_KB_MENU;
        rl["KEY_LEFT_BRACKET"] = KEY_LEFT_BRACKET;
        rl["KEY_BACKSLASH"] = KEY_BACKSLASH;
        rl["KEY_RIGHT_BRACKET"] = KEY_RIGHT_BRACKET;
        rl["KEY_GRAVE"] = KEY_GRAVE;
        // Keypad keys
        rl["KEY_KP_0"] = KEY_KP_0;
        rl["KEY_KP_1"] = KEY_KP_1;
        rl["KEY_KP_2"] = KEY_KP_2;
        rl["KEY_KP_3"] = KEY_KP_3;
        rl["KEY_KP_4"] = KEY_KP_4;
        rl["KEY_KP_5"] = KEY_KP_5;
        rl["KEY_KP_6"] = KEY_KP_6;
        rl["KEY_KP_7"] = KEY_KP_7;
        rl["KEY_KP_8"] = KEY_KP_8;
        rl["KEY_KP_9"] = KEY_KP_9;
        rl["KEY_KP_DECIMAL"] = KEY_KP_DECIMAL;
        rl["KEY_KP_DIVIDE"] = KEY_KP_DIVIDE;
        rl["KEY_KP_MULTIPLY"] = KEY_KP_MULTIPLY;
        rl["KEY_KP_SUBTRACT"] = KEY_KP_SUBTRACT;
        rl["KEY_KP_ADD"] = KEY_KP_ADD;
        rl["KEY_KP_ENTER"] = KEY_KP_ENTER;
        rl["KEY_KP_EQUAL"] = KEY_KP_EQUAL;
        // Android key buttons
        rl["KEY_BACK"] = KEY_BACK;
        rl["KEY_MENU"] = KEY_MENU;
        rl["KEY_VOLUME_UP"] = KEY_VOLUME_UP;
        rl["KEY_VOLUME_DOWN"] = KEY_VOLUME_DOWN;

        // MouseButton
        rl["MOUSE_LEFT_BUTTON"] = MOUSE_LEFT_BUTTON;
        rl["MOUSE_RIGHT_BUTTON"] = MOUSE_RIGHT_BUTTON;
        rl["MOUSE_MIDDLE_BUTTON"] = MOUSE_MIDDLE_BUTTON;

        // MouseCursor
        rl["MOUSE_CURSOR_DEFAULT"] = MOUSE_CURSOR_DEFAULT;
        rl["MOUSE_CURSOR_ARROW"] = MOUSE_CURSOR_ARROW;
        rl["MOUSE_CURSOR_IBEAM"] = MOUSE_CURSOR_IBEAM;
        rl["MOUSE_CURSOR_CROSSHAIR"] = MOUSE_CURSOR_CROSSHAIR;
        rl["MOUSE_CURSOR_POINTING_HAND"] = MOUSE_CURSOR_POINTING_HAND;
        rl["MOUSE_CURSOR_RESIZE_EW"] = MOUSE_CURSOR_RESIZE_EW;     // The horizontal resize/move arrow shape
        rl["MOUSE_CURSOR_RESIZE_NS"] = MOUSE_CURSOR_RESIZE_NS;     // The vertical resize/move arrow shape
        rl["MOUSE_CURSOR_RESIZE_NWSE"] = MOUSE_CURSOR_RESIZE_NWSE;     // The top-left to bottom-right diagonal resize/move arrow shape
        rl["MOUSE_CURSOR_RESIZE_NESW"] = MOUSE_CURSOR_RESIZE_NESW;     // The top-right to bottom-left diagonal resize/move arrow shape
        rl["MOUSE_CURSOR_RESIZE_ALL"] = MOUSE_CURSOR_RESIZE_ALL;     // The omni-directional resize/move cursor shape
        rl["MOUSE_CURSOR_NOT_ALLOWED"] = MOUSE_CURSOR_NOT_ALLOWED;     // The operation-not-allowed shape

        // GamepadButton
        // This is here just for error checking
        rl["GAMEPAD_BUTTON_UNKNOWN"] = GAMEPAD_BUTTON_UNKNOWN;
        // This is normally a DPAD
        rl["GAMEPAD_BUTTON_LEFT_FACE_UP"] = GAMEPAD_BUTTON_LEFT_FACE_UP;
        rl["GAMEPAD_BUTTON_LEFT_FACE_RIGHT"] = GAMEPAD_BUTTON_LEFT_FACE_RIGHT;
        rl["GAMEPAD_BUTTON_LEFT_FACE_DOWN"] = GAMEPAD_BUTTON_LEFT_FACE_DOWN;
        rl["GAMEPAD_BUTTON_LEFT_FACE_LEFT"] = GAMEPAD_BUTTON_LEFT_FACE_LEFT;
        // This normally corresponds with PlayStation and Xbox controllers
        // XBOX: [Y,X,A,B]
        // PS3: [Triangle,Square,Cross,Circle]
        // No support for 6 button controllers though..
        rl["GAMEPAD_BUTTON_RIGHT_FACE_UP"] = GAMEPAD_BUTTON_RIGHT_FACE_UP;
        rl["GAMEPAD_BUTTON_RIGHT_FACE_RIGHT"] = GAMEPAD_BUTTON_RIGHT_FACE_RIGHT;
        rl["GAMEPAD_BUTTON_RIGHT_FACE_DOWN"] = GAMEPAD_BUTTON_RIGHT_FACE_DOWN;
        rl["GAMEPAD_BUTTON_RIGHT_FACE_LEFT"] = GAMEPAD_BUTTON_RIGHT_FACE_LEFT;
        // Triggers
        rl["GAMEPAD_BUTTON_LEFT_TRIGGER_1"] = GAMEPAD_BUTTON_LEFT_TRIGGER_1;
        rl["GAMEPAD_BUTTON_LEFT_TRIGGER_2"] = GAMEPAD_BUTTON_LEFT_TRIGGER_2;
        rl["GAMEPAD_BUTTON_RIGHT_TRIGGER_1"] = GAMEPAD_BUTTON_RIGHT_TRIGGER_1;
        rl["GAMEPAD_BUTTON_RIGHT_TRIGGER_2"] = GAMEPAD_BUTTON_RIGHT_TRIGGER_2;
        // These are buttons in the center of the gamepad
        rl["GAMEPAD_BUTTON_MIDDLE_LEFT"] = GAMEPAD_BUTTON_MIDDLE_LEFT;     // PS3 Select
        rl["GAMEPAD_BUTTON_MIDDLE"] = GAMEPAD_BUTTON_MIDDLE;          // PS Button/XBOX Button
        rl["GAMEPAD_BUTTON_MIDDLE_RIGHT"] = GAMEPAD_BUTTON_MIDDLE_RIGHT;    // PS3 Start
        // These are the joystick press in buttons
        rl["GAMEPAD_BUTTON_LEFT_THUMB"] = GAMEPAD_BUTTON_LEFT_THUMB;
        rl["GAMEPAD_BUTTON_RIGHT_THUMB"] = GAMEPAD_BUTTON_RIGHT_THUMB;

        // GampadAxis
        // Left stick
        rl["GAMEPAD_AXIS_LEFT_X"] = GAMEPAD_AXIS_LEFT_X;
        rl["GAMEPAD_AXIS_LEFT_Y"] = GAMEPAD_AXIS_LEFT_Y;
        // Right stick
        rl["GAMEPAD_AXIS_RIGHT_X"] = GAMEPAD_AXIS_RIGHT_X;
        rl["GAMEPAD_AXIS_RIGHT_Y"] = GAMEPAD_AXIS_RIGHT_Y;
        // Pressure levels for the back triggers
        rl["GAMEPAD_AXIS_LEFT_TRIGGER"] = GAMEPAD_AXIS_LEFT_TRIGGER;      // [1..-1] (pressure-level)
        rl["GAMEPAD_AXIS_RIGHT_TRIGGER"] = GAMEPAD_AXIS_RIGHT_TRIGGER;      // [1..-1] (pressure-level)

        // MaterialMapIndex
        rl["MATERIAL_MAP_ALBEDO"] = MATERIAL_MAP_ALBEDO;       // MATERIAL_MAP_DIFFUSE
        rl["MATERIAL_MAP_METALNESS"] = MATERIAL_MAP_METALNESS;       // MATERIAL_MAP_SPECULAR
        rl["MATERIAL_MAP_NORMAL"] = MATERIAL_MAP_NORMAL;
        rl["MATERIAL_MAP_ROUGHNESS"] = MATERIAL_MAP_ROUGHNESS;
        rl["MATERIAL_MAP_OCCLUSION"] = MATERIAL_MAP_OCCLUSION;
        rl["MATERIAL_MAP_EMISSION"] = MATERIAL_MAP_EMISSION;
        rl["MATERIAL_MAP_HEIGHT"] = MATERIAL_MAP_HEIGHT;
        rl["MATERIAL_MAP_BRDG"] = MATERIAL_MAP_BRDG;
        rl["MATERIAL_MAP_CUBEMAP"] = MATERIAL_MAP_CUBEMAP;             // NOTE: Uses GL_TEXTURE_CUBE_MAP
        rl["MATERIAL_MAP_IRRADIANCE"] = MATERIAL_MAP_IRRADIANCE;          // NOTE: Uses GL_TEXTURE_CUBE_MAP
        rl["MATERIAL_MAP_PREFILTER"] = MATERIAL_MAP_PREFILTER;            // NOTE: Uses GL_TEXTURE_CUBE_MAP
        rl["MATERIAL_MAP_DIFFUSE"] = MATERIAL_MAP_DIFFUSE;
        rl["MATERIAL_MAP_SPECULAR"] = MATERIAL_MAP_SPECULAR;

        // ShaderLocationIndex
        rl["SHADER_LOC_VERTEX_POSITION"] = SHADER_LOC_VERTEX_POSITION;
        rl["SHADER_LOC_VERTEX_TEXCOORD01"] = SHADER_LOC_VERTEX_TEXCOORD01;
        rl["SHADER_LOC_VERTEX_TEXCOORD02"] = SHADER_LOC_VERTEX_TEXCOORD02;
        rl["SHADER_LOC_VERTEX_NORMAL"] = SHADER_LOC_VERTEX_NORMAL;
        rl["SHADER_LOC_VERTEX_TANGENT"] = SHADER_LOC_VERTEX_TANGENT;
        rl["SHADER_LOC_VERTEX_COLOR"] = SHADER_LOC_VERTEX_COLOR;
        rl["SHADER_LOC_MATRIX_MVP"] = SHADER_LOC_MATRIX_MVP;
        rl["SHADER_LOC_MATRIX_VIEW"] = SHADER_LOC_MATRIX_VIEW;
        rl["SHADER_LOC_MATRIX_PROJECTION"] = SHADER_LOC_MATRIX_PROJECTION;
        rl["SHADER_LOC_MATRIX_MODEL"] = SHADER_LOC_MATRIX_MODEL;
        rl["SHADER_LOC_MATRIX_NORMAL"] = SHADER_LOC_MATRIX_NORMAL;
        rl["SHADER_LOC_VECTOR_VIEW"] = SHADER_LOC_VECTOR_VIEW;
        rl["SHADER_LOC_COLOR_DIFFUSE"] = SHADER_LOC_COLOR_DIFFUSE;
        rl["SHADER_LOC_COLOR_SPECULAR"] = SHADER_LOC_COLOR_SPECULAR;
        rl["SHADER_LOC_COLOR_AMBIENT"] = SHADER_LOC_COLOR_AMBIENT;
        rl["SHADER_LOC_MAP_ALBEDO"] = SHADER_LOC_MAP_ALBEDO;          // SHADER_LOC_MAP_DIFFUSE
        rl["SHADER_LOC_MAP_METALNESS"] = SHADER_LOC_MAP_METALNESS;       // SHADER_LOC_MAP_SPECULAR
        rl["SHADER_LOC_MAP_NORMAL"] = SHADER_LOC_MAP_NORMAL;
        rl["SHADER_LOC_MAP_ROUGHNESS"] = SHADER_LOC_MAP_ROUGHNESS;
        rl["SHADER_LOC_MAP_OCCLUSION"] = SHADER_LOC_MAP_OCCLUSION;
        rl["SHADER_LOC_MAP_EMISSION"] = SHADER_LOC_MAP_EMISSION;
        rl["SHADER_LOC_MAP_HEIGHT"] = SHADER_LOC_MAP_HEIGHT;
        rl["SHADER_LOC_MAP_CUBEMAP"] = SHADER_LOC_MAP_CUBEMAP;
        rl["SHADER_LOC_MAP_IRRADIANCE"] = SHADER_LOC_MAP_IRRADIANCE;
        rl["SHADER_LOC_MAP_PREFILTER"] = SHADER_LOC_MAP_PREFILTER;
        rl["SHADER_LOC_MAP_DIFFUSE"] = SHADER_LOC_MAP_DIFFUSE;
        rl["SHADER_LOC_MAP_SPECULAR"] = SHADER_LOC_MAP_SPECULAR;

        // ShaderUniformDataType
        rl["SHADER_UNIFORM_FLOAT"] = SHADER_UNIFORM_FLOAT;
        rl["SHADER_UNIFORM_VEC2"] = SHADER_UNIFORM_VEC2;
        rl["SHADER_UNIFORM_VEC3"] = SHADER_UNIFORM_VEC3;
        rl["SHADER_UNIFORM_VEC4"] = SHADER_UNIFORM_VEC4;
        rl["SHADER_UNIFORM_INT"] = SHADER_UNIFORM_INT;
        rl["SHADER_UNIFORM_IVEC2"] = SHADER_UNIFORM_IVEC2;
        rl["SHADER_UNIFORM_IVEC3"] = SHADER_UNIFORM_IVEC3;
        rl["SHADER_UNIFORM_IVEC4"] = SHADER_UNIFORM_IVEC4;
        rl["SHADER_UNIFORM_SAMPLER2D"] = SHADER_UNIFORM_SAMPLER2D;

        // PixelFormat
        rl["PIXELFORMAT_UNCOMPRESSED_GRAYSCALE"] = PIXELFORMAT_UNCOMPRESSED_GRAYSCALE;     // 8 bit per pixel (no alpha)
        rl["PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA"] = PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA;        // 8*2 bpp (2 channels)
        rl["PIXELFORMAT_UNCOMPRESSED_R5G6B5"] = PIXELFORMAT_UNCOMPRESSED_R5G6B5;            // 16 bpp
        rl["PIXELFORMAT_UNCOMPRESSED_R8G8B8"] = PIXELFORMAT_UNCOMPRESSED_R8G8B8;            // 24 bpp
        rl["PIXELFORMAT_UNCOMPRESSED_R5G5B5A1"] = PIXELFORMAT_UNCOMPRESSED_R5G5B5A1;          // 16 bpp (1 bit alpha)
        rl["PIXELFORMAT_UNCOMPRESSED_R4G4B4A4"] = PIXELFORMAT_UNCOMPRESSED_R4G4B4A4;          // 16 bpp (4 bit alpha)
        rl["PIXELFORMAT_UNCOMPRESSED_R8G8B8A8"] = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;          // 32 bpp
        rl["PIXELFORMAT_UNCOMPRESSED_R32"] = PIXELFORMAT_UNCOMPRESSED_R32;               // 32 bpp (1 channel - float)
        rl["PIXELFORMAT_UNCOMPRESSED_R32G32B32"] = PIXELFORMAT_UNCOMPRESSED_R32G32B32;         // 32*3 bpp (3 channels - float)
        rl["PIXELFORMAT_UNCOMPRESSED_R32G32B32A32"] = PIXELFORMAT_UNCOMPRESSED_R32G32B32A32;      // 32*4 bpp (4 channels - float)
        rl["PIXELFORMAT_COMPRESSED_DXT1_RGB"] = PIXELFORMAT_COMPRESSED_DXT1_RGB;            // 4 bpp (no alpha)
        rl["PIXELFORMAT_COMPRESSED_DXT1_RGBA"] = PIXELFORMAT_COMPRESSED_DXT1_RGBA;           // 4 bpp (1 bit alpha)
        rl["PIXELFORMAT_COMPRESSED_DXT3_RGBA"] = PIXELFORMAT_COMPRESSED_DXT3_RGBA;           // 8 bpp
        rl["PIXELFORMAT_COMPRESSED_DXT5_RGBA"] = PIXELFORMAT_COMPRESSED_DXT5_RGBA;           // 8 bpp
        rl["PIXELFORMAT_COMPRESSED_ETC1_RGB"] = PIXELFORMAT_COMPRESSED_ETC1_RGB;            // 4 bpp
        rl["PIXELFORMAT_COMPRESSED_ETC2_RGB"] = PIXELFORMAT_COMPRESSED_ETC2_RGB;            // 4 bpp
        rl["PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA"] = PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA;       // 8 bpp
        rl["PIXELFORMAT_COMPRESSED_PVRT_RGB"] = PIXELFORMAT_COMPRESSED_PVRT_RGB;            // 4 bpp
        rl["PIXELFORMAT_COMPRESSED_PVRT_RGBA"] = PIXELFORMAT_COMPRESSED_PVRT_RGBA;           // 4 bpp
        rl["PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA"] = PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA;       // 8 bpp
        rl["PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA"] = PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA;        // 2 bpp

        // TextureFilter
        rl["TEXTURE_FILTER_POINT"] = TEXTURE_FILTER_POINT;               // No filter, just pixel aproximation
        rl["TEXTURE_FILTER_BILINEAR"] = TEXTURE_FILTER_BILINEAR;                // Linear filtering
        rl["TEXTURE_FILTER_TRILINEAR"] = TEXTURE_FILTER_TRILINEAR;               // Trilinear filtering (linear with mipmaps)
        rl["TEXTURE_FILTER_ANISOTROPIC_4X"] = TEXTURE_FILTER_ANISOTROPIC_4X;          // Anisotropic filtering 4x
        rl["TEXTURE_FILTER_ANISOTROPIC_8X"] = TEXTURE_FILTER_ANISOTROPIC_8X;          // Anisotropic filtering 8x
        rl["TEXTURE_FILTER_ANISOTROPIC_16X"] = TEXTURE_FILTER_ANISOTROPIC_16X;         // Anisotropic filtering 16x

        // TextureWrap
        rl["TEXTURE_WRAP_REPEAT"] = TEXTURE_WRAP_REPEAT;        // Repeats texture in tiled mode
        rl["TEXTURE_WRAP_CLAMP"] = TEXTURE_WRAP_CLAMP;             // Clamps texture to edge pixel in tiled mode
        rl["TEXTURE_WRAP_MIRROR_REPEAT"] = TEXTURE_WRAP_MIRROR_REPEAT;     // Mirrors and repeats the texture in tiled mode
        rl["TEXTURE_WRAP_MIRROR_CLAMP"] = TEXTURE_WRAP_MIRROR_CLAMP;       // Mirrors and clamps to border the texture in tiled mode

        // CubemapLayout
        rl["CUBEMAP_LAYOUT_AUTO_DETECT"] = CUBEMAP_LAYOUT_AUTO_DETECT;        // Automatically detect layout type
        rl["CUBEMAP_LAYOUT_LINE_VERTICAL"] = CUBEMAP_LAYOUT_LINE_VERTICAL;          // Layout is defined by a vertical line with faces
        rl["CUBEMAP_LAYOUT_LINE_HORIZONTAL"] = CUBEMAP_LAYOUT_LINE_HORIZONTAL;        // Layout is defined by an horizontal line with faces
        rl["CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR"] = CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR;    // Layout is defined by a 3x4 cross with cubemap faces
        rl["CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE"] = CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE;    // Layout is defined by a 4x3 cross with cubemap faces
        rl["CUBEMAP_LAYOUT_PANORAMA"] = CUBEMAP_LAYOUT_PANORAMA;                // Layout is defined by a panorama image (equirectangular map)

        // FontType
        rl["FONT_DEFAULT"] = FONT_DEFAULT;
        rl["FONT_BITMAP"] = FONT_BITMAP;
        rl["FONT_SDF"] = FONT_SDF;

        // BlendMode
        rl["BLEND_ALPHA"] = BLEND_ALPHA;        // Blend textures considering alpha (default)
        rl["BLEND_ADDITIVE"] = BLEND_ADDITIVE;         // Blend textures adding colors
        rl["BLEND_MULTIPLIED"] = BLEND_MULTIPLIED;       // Blend textures multiplying colors
        rl["BLEND_ADD_COLORS"] = BLEND_ADD_COLORS;       // Blend textures adding colors (alternative)
        rl["BLEND_SUBTRACT_COLORS"] = BLEND_SUBTRACT_COLORS;  // Blend textures subtracting colors (alternative)
        rl["BLEND_CUSTOM"] = BLEND_CUSTOM;            // Belnd textures using custom src/dst factors (use rlSetBlendMode())

        // Gestures
        rl["GESTURE_NONE"] = GESTURE_NONE;
        rl["GESTURE_TAP"] = GESTURE_TAP;
        rl["GESTURE_DOUBLETAP"] = GESTURE_DOUBLETAP;
        rl["GESTURE_HOLD"] = GESTURE_HOLD;
        rl["GESTURE_DRAG"] = GESTURE_DRAG;
        rl["GESTURE_SWIPE_RIGHT"] = GESTURE_SWIPE_RIGHT;
        rl["GESTURE_SWIPE_LEFT"] = GESTURE_SWIPE_LEFT;
        rl["GESTURE_SWIPE_UP"] = GESTURE_SWIPE_UP;
        rl["GESTURE_SWIPE_DOWN"] = GESTURE_SWIPE_DOWN;
        rl["GESTURE_PINCH_IN"] = GESTURE_PINCH_IN;
        rl["GESTURE_PINCH_OUT"] = GESTURE_PINCH_OUT;

        // CameraMode
        rl["CAMERA_CUSTOM"] = CAMERA_CUSTOM;
        rl["CAMERA_FREE"] = CAMERA_FREE;
        rl["CAMERA_ORBITAL"] = CAMERA_ORBITAL;
        rl["CAMERA_FIRST_PERSON"] = CAMERA_FIRST_PERSON;
        rl["CAMERA_THIRD_PERSON"] = CAMERA_THIRD_PERSON;

        // CameraProjection
        rl["CAMERA_PERSPECTIVE"] = CAMERA_PERSPECTIVE;
        rl["CAMERA_ORTHOGRAPHIC"] = CAMERA_ORTHOGRAPHIC;

        // NPatchLayout
        rl["NPATCH_NINE_PATCH"] = NPATCH_NINE_PATCH;
        rl["NPATCH_THREE_PATCH_VERTICAL"] = NPATCH_THREE_PATCH_VERTICAL;
        rl["NPATCH_THREE_PATCH_HORIZONTAL"] = NPATCH_THREE_PATCH_HORIZONTAL;

        //------------------------------------------------------------------------------------
// Window and Graphics Device Functions (Module: core)
//------------------------------------------------------------------------------------

// Window-related functions
        rl.set_function("InitWindow", &InitWindow);
        rl.set_function("WindowShouldClose", &WindowShouldClose);
        rl.set_function("CloseWindow", &CloseWindow);
        rl.set_function("IsWindowReady", &IsWindowReady);
        rl.set_function("IsWindowFullscreen", &IsWindowFullscreen);
        rl.set_function("IsWindowHidden", &IsWindowHidden);
        rl.set_function("IsWindowMinimized", &IsWindowMinimized);
        rl.set_function("IsWindowMaximized", &IsWindowMaximized);
        rl.set_function("IsWindowFocused", &IsWindowFocused);
        rl.set_function("IsWindowResized", &IsWindowResized);
        rl.set_function("IsWindowState", &IsWindowState);
        rl.set_function("SetWindowState", &SetWindowState);
        rl.set_function("ClearWindowState", &ClearWindowState);
        rl.set_function("ToggleFullscreen", &ToggleFullscreen);
        rl.set_function("MaximizeWindow", &MaximizeWindow);
        rl.set_function("MinimizeWindow", &MinimizeWindow);
        rl.set_function("RestoreWindow", &RestoreWindow);
        rl.set_function("SetWindowIcon", &SetWindowIcon);
        rl.set_function("SetWindowTitle", &SetWindowTitle);
        rl.set_function("SetWindowPosition", &SetWindowPosition);
        rl.set_function("SetWindowMonitor", &SetWindowMonitor);
        rl.set_function("SetWindowMinSize", &SetWindowMinSize);
        rl.set_function("SetWindowSize", &SetWindowSize);
        rl.set_function("GetWindowHandle", &GetWindowHandle);
        rl.set_function("GetScreenWidth", &GetScreenWidth);
        rl.set_function("GetScreenHeight", &GetScreenHeight);
        rl.set_function("GetMonitorCount", &GetMonitorCount);
        rl.set_function("GetCurrentMonitor", &GetCurrentMonitor);
        rl.set_function("GetMonitorPosition", &GetMonitorPosition);
        rl.set_function("GetMonitorWidth", &GetMonitorWidth);
        rl.set_function("GetMonitorHeight", &GetMonitorHeight);
        rl.set_function("GetMonitorPhysicalWidth", &GetMonitorPhysicalWidth);
        rl.set_function("GetMonitorPhysicalHeight", &GetMonitorPhysicalHeight);
        rl.set_function("GetMonitorRefreshRate", &GetMonitorRefreshRate);
        rl.set_function("GetWindowPosition", &GetWindowPosition);
        rl.set_function("GetWindowScaleDPI", &GetWindowScaleDPI);
        rl.set_function("GetMonitorName", &GetMonitorName);
        rl.set_function("SetClipboardText", &SetClipboardText);
        rl.set_function("GetClipboardText", &GetClipboardText);

        // Cursor-related functions
        rl.set_function("ShowCursor", &ShowCursor);
        rl.set_function("HideCursor", &HideCursor);
        rl.set_function("IsCursorHidden", &IsCursorHidden);
        rl.set_function("EnableCursor", &EnableCursor);
        rl.set_function("DisableCursor", &DisableCursor);
        rl.set_function("IsCursorOnScreen", &IsCursorOnScreen);

        // Drawing-related functions
        rl.set_function("ClearBackground", &ClearBackground);
        rl.set_function("BeginDrawing", &BeginDrawing);
        rl.set_function("EndDrawing", &EndDrawing);
        rl.set_function("BeginMode2D", &BeginMode2D);                          // Initialize 2D mode with custom camera (2D)
        rl.set_function("EndMode2D", &EndMode2D);                                       // Ends 2D mode with custom camera
        rl.set_function("BeginMode3D", &BeginMode3D);                          // Initializes 3D mode with custom camera (3D)
        rl.set_function("EndMode3D", &EndMode3D);                                       // Ends 3D mode and returns to default 2D orthographic mode
        rl.set_function("BeginTextureMode", &BeginTextureMode);
        rl.set_function("EndTextureMode", &EndTextureMode);
        rl.set_function("BeginShaderMode", &BeginShaderMode);
        rl.set_function("EndShaderMode", &EndShaderMode);
        rl.set_function("BeginBlendMode", &BeginBlendMode);
        rl.set_function("EndBlendMode", &EndBlendMode);
        rl.set_function("BeginScissorMode", &BeginScissorMode);
        rl.set_function("EndScissorMode", &EndScissorMode);
        rl.set_function("BeginVrStereoMode", &BeginVrStereoMode);
        rl.set_function("EndVrStereoMode", &EndVrStereoMode);

        // VR stereo config functions for VR simulator
        rl.set_function("LoadVrStereoConfig", &LoadVrStereoConfig);
        rl.set_function("UnloadVrStereoConfig", &UnloadVrStereoConfig);

        // Shader management functions
        // NOTE: Shader functionality is not available on OpenGL 1.1
        rl.set_function("LoadShader", &LoadShader);
        rl.set_function("LoadShaderFromMemory", &LoadShaderFromMemory);
        rl.set_function("GetShaderLocation", &GetShaderLocation);
        rl.set_function("GetShaderLocationAttrib", &GetShaderLocationAttrib);
        rl.set_function("SetShaderValue", &SetShaderValue);
        rl.set_function("SetShaderValueV", &SetShaderValueV);
        rl.set_function("SetShaderValueMatrix", &SetShaderValueMatrix);
        rl.set_function("SetShaderValueTexture", &SetShaderValueTexture);
        rl.set_function("UnloadShader", &UnloadShader);

        // Screen-space-related functions
        rl.set_function("GetMouseRay", &GetMouseRay);
        rl.set_function("GetCameraMatrix", &GetCameraMatrix);
        rl.set_function("GetCameraMatrix2D", &GetCameraMatrix2D);                  // Returns camera 2d transform matrix
        rl.set_function("GetWorldToScreen", &GetWorldToScreen);
        rl.set_function("GetWorldToScreenEx", &GetWorldToScreenEx);
        rl.set_function("GetWorldToScreen2D", &GetWorldToScreen2D); // Returns the screen space position for a 2d camera world space position
        rl.set_function("GetScreenToWorld2D", &GetScreenToWorld2D); // Returns the world space position for a 2d camera screen space position

        // Timing-related functions
        rl.set_function("SetTargetFPS", &SetTargetFPS);
        rl.set_function("GetFPS", &GetFPS);
        rl.set_function("GetFrameTime", &GetFrameTime);
        rl.set_function("GetTime", &GetTime);

        // Misc. functions
        rl.set_function("GetRandomValue", &GetRandomValue);
        rl.set_function("TakeScreenshot", &TakeScreenshot);
        rl.set_function("SetConfigFlags", &SetConfigFlags);

        rl.set_function("TraceLog", &TraceLog);
        rl.set_function("SetTraceLogLevel", &SetTraceLogLevel);
        rl.set_function("MemAlloc", &MemAlloc);
        rl.set_function("MemRealloc", &MemRealloc);
        rl.set_function("MemFree", &MemFree);

        // Set custom callbacks
        // WARNING: Callbacks setup is intended for advance users
        rl.set_function("SetTraceLogCallback", &SetTraceLogCallback);
        rl.set_function("SetLoadFileDataCallback", &SetLoadFileDataCallback);
        rl.set_function("SetSaveFileDataCallback", &SetSaveFileDataCallback);
        rl.set_function("SetLoadFileTextCallback", &SetLoadFileTextCallback);
        rl.set_function("SetSaveFileTextCallback", &SetSaveFileTextCallback);

        // Files management functions
        rl.set_function("LoadFileData", &LoadFileData);
        rl.set_function("UnloadFileData", &UnloadFileData);
        rl.set_function("SaveFileData", &SaveFileData);
        rl.set_function("LoadFileText", &LoadFileText);
        rl.set_function("UnloadFileText", &UnloadFileText);
        rl.set_function("SaveFileText", &SaveFileText);
        rl.set_function("FileExists", &FileExists);
        rl.set_function("DirectoryExists", &DirectoryExists);
        rl.set_function("IsFileExtension", &IsFileExtension);
        rl.set_function("GetFileExtension", &GetFileExtension);
        rl.set_function("GetFileName", &GetFileName);
        rl.set_function("GetFileNameWithoutExt", &GetFileNameWithoutExt);
        rl.set_function("GetDirectoryPath", &GetDirectoryPath);
        rl.set_function("GetPrevDirectoryPath", &GetPrevDirectoryPath);
        rl.set_function("GetWorkingDirectory", &GetWorkingDirectory);
        rl.set_function("GetDirectoryFiles", &GetDirectoryFiles);
        rl.set_function("ClearDirectoryFiles", &ClearDirectoryFiles);
        rl.set_function("ChangeDirectory", &ChangeDirectory);
        rl.set_function("IsFileDropped", &IsFileDropped);
        rl.set_function("GetDroppedFiles", &GetDroppedFiles);
        rl.set_function("ClearDroppedFiles", &ClearDroppedFiles);
        rl.set_function("GetFileModTime", &GetFileModTime);

        rl.set_function("CompressData", &CompressData);
        rl.set_function("DecompressData", &DecompressData);

        // Persistent storage management
        rl.set_function("SaveStorageValue", &SaveStorageValue);
        rl.set_function("LoadStorageValue", &LoadStorageValue);

        rl.set_function("OpenURL", &OpenURL);

        //------------------------------------------------------------------------------------
        // Input Handling Functions (Module: core)
        //------------------------------------------------------------------------------------

        // Input-related functions: keyboard
        rl.set_function("IsKeyPressed", &IsKeyPressed);
        rl.set_function("IsKeyDown", &IsKeyDown);
        rl.set_function("IsKeyReleased", &IsKeyReleased);
        rl.set_function("IsKeyUp", &IsKeyUp);
        rl.set_function("SetExitKey", &SetExitKey);
        rl.set_function("GetKeyPressed", &GetKeyPressed);
        rl.set_function("GetCharPressed", &GetCharPressed);

        // Input-related functions: gamepads
        rl.set_function("IsGamepadAvailable", &IsGamepadAvailable);
        rl.set_function("IsGamepadName", &IsGamepadName);
        rl.set_function("GetGamepadName", &GetGamepadName);
        rl.set_function("IsGamepadButtonPressed", &IsGamepadButtonPressed);
        rl.set_function("IsGamepadButtonDown", &IsGamepadButtonDown);
        rl.set_function("IsGamepadButtonReleased", &IsGamepadButtonReleased);
        rl.set_function("IsGamepadButtonUp", &IsGamepadButtonUp);
        rl.set_function("GetGamepadButtonPressed", &GetGamepadButtonPressed);
        rl.set_function("GetGamepadAxisCount", &GetGamepadAxisCount);
        rl.set_function("GetGamepadAxisMovement", &GetGamepadAxisMovement);
        rl.set_function("SetGamepadMappings", &SetGamepadMappings);

        // Input-related functions: mouse
        rl.set_function("IsMouseButtonPressed", &IsMouseButtonPressed);
        rl.set_function("IsMouseButtonDown", &IsMouseButtonDown);
        rl.set_function("IsMouseButtonReleased", &IsMouseButtonReleased);
        rl.set_function("IsMouseButtonUp", &IsMouseButtonUp);
        rl.set_function("GetMouseX", &GetMouseX);
        rl.set_function("GetMouseY", &GetMouseY);
        rl.set_function("GetMousePosition", &GetMousePosition);
        rl.set_function("SetMousePosition", &SetMousePosition);
        rl.set_function("SetMouseOffset", &SetMouseOffset);
        rl.set_function("SetMouseScale", &SetMouseScale);
        rl.set_function("GetMouseWheelMove", &GetMouseWheelMove);
        rl.set_function("SetMouseCursor", &SetMouseCursor);

        // Input-related functions: touch
        rl.set_function("GetTouchX", &GetTouchX);
        rl.set_function("GetTouchY", &GetTouchY);
        rl.set_function("GetTouchPosition", &GetTouchPosition);

        //------------------------------------------------------------------------------------
        // Gestures and Touch Handling Functions (Module: gestures)
        //------------------------------------------------------------------------------------
        rl.set_function("SetGesturesEnabled", &SetGesturesEnabled);
        rl.set_function("IsGestureDetected", &IsGestureDetected);
        rl.set_function("GetGestureDetected", &GetGestureDetected);
        rl.set_function("GetTouchPointsCount", &GetTouchPointsCount);
        rl.set_function("GetGestureHoldDuration", &GetGestureHoldDuration);
        rl.set_function("GetGestureDragVector", &GetGestureDragVector);
        rl.set_function("GetGestureDragAngle", &GetGestureDragAngle);
        rl.set_function("GetGesturePinchVector", &GetGesturePinchVector);
        rl.set_function("GetGesturePinchAngle", &GetGesturePinchAngle);

        //------------------------------------------------------------------------------------
        // Camera System Functions (Module: camera)
        //------------------------------------------------------------------------------------
        rl.set_function("SetCameraMode", &SetCameraMode);
        rl.set_function("UpdateCamera", &UpdateCamera);

        rl.set_function("SetCameraPanControl", &SetCameraPanControl);
        rl.set_function("SetCameraAltControl", &SetCameraAltControl);
        rl.set_function("SetCameraSmoothZoomControl", &SetCameraSmoothZoomControl);
        rl.set_function("SetCameraMoveControls", &SetCameraMoveControls);

        //------------------------------------------------------------------------------------
        // Basic Shapes Drawing Functions (Module: shapes)
        //------------------------------------------------------------------------------------
        // Set texture and rectangle to be used on shapes drawing
        // NOTE: It can be useful when using basic shapes and one single font,
        // defining a font char white rectangle would allow drawing everything in a single draw call
        rl.set_function("SetShapesTexture", &SetShapesTexture);

        // Basic shapes drawing functions
        rl.set_function("DrawPixel", &DrawPixel);
        rl.set_function("DrawPixelV", &DrawPixelV);
        rl.set_function("DrawLine", &DrawLine);
        rl.set_function("DrawLineV", &DrawLineV);
        rl.set_function("DrawLineEx", &DrawLineEx);
        rl.set_function("DrawLineBezier", &DrawLineBezier);
        rl.set_function("DrawLineBezierQuad", &DrawLineBezierQuad);
        rl.set_function("DrawLineStrip", &DrawLineStrip);
        rl.set_function("DrawCircle", &DrawCircle);
        //rl.set_function("DrawCircle", [](int centerX, int centerY, float radius, Color const & color) { DrawCircle(centerX, centerY, radius, color); });
        rl.set_function("DrawCircleSector", &DrawCircleSector);
        rl.set_function("DrawCircleSectorLines", &DrawCircleSectorLines);
        rl.set_function("DrawCircleGradient", &DrawCircleGradient);
        rl.set_function("DrawCircleV", &DrawCircleV);
        rl.set_function("DrawCircleLines", &DrawCircleLines);
        rl.set_function("DrawEllipse", &DrawEllipse);
        rl.set_function("DrawEllipseLines", &DrawEllipseLines);
        rl.set_function("DrawRing", &DrawRing);
        rl.set_function("DrawRingLines", &DrawRingLines);
        rl.set_function("DrawRectangle", &DrawRectangle);
        rl.set_function("DrawRectangleV", &DrawRectangleV);
        rl.set_function("DrawRectangleRec", &DrawRectangleRec);
        rl.set_function("DrawRectanglePro", &DrawRectanglePro);
        rl.set_function("DrawRectangleGradientV", &DrawRectangleGradientV);
        rl.set_function("DrawRectangleGradientH", &DrawRectangleGradientH);
        rl.set_function("DrawRectangleGradientEx", &DrawRectangleGradientEx);
        rl.set_function("DrawRectangleLines", &DrawRectangleLines);
        rl.set_function("DrawRectangleLinesEx", &DrawRectangleLinesEx);
        rl.set_function("DrawRectangleRounded", &DrawRectangleRounded);
        rl.set_function("DrawRectangleRoundedLines", &DrawRectangleRoundedLines);
        rl.set_function("DrawTriangle", &DrawTriangle);
        rl.set_function("DrawTriangleLines", &DrawTriangleLines);
        rl.set_function("DrawTriangleFan", &DrawTriangleFan);
        rl.set_function("DrawTriangleStrip", &DrawTriangleStrip);
        rl.set_function("DrawPoly", &DrawPoly);
        rl.set_function("DrawPolyLines", &DrawPolyLines);

        // Basic shapes collision detection functions
        rl.set_function("CheckCollisionRecs", &CheckCollisionRecs);
        rl.set_function("CheckCollisionCircles", &CheckCollisionCircles);
        rl.set_function("CheckCollisionCircleRec", &CheckCollisionCircleRec);
        rl.set_function("CheckCollisionPointRec", &CheckCollisionPointRec);
        rl.set_function("CheckCollisionPointCircle", &CheckCollisionPointCircle);
        rl.set_function("CheckCollisionPointTriangle", &CheckCollisionPointTriangle);
        rl.set_function("CheckCollisionLines", &CheckCollisionLines);
        rl.set_function("GetCollisionRec", &GetCollisionRec);

        //------------------------------------------------------------------------------------
        // Texture Loading and Drawing Functions (Module: textures)
        //------------------------------------------------------------------------------------

        // Image loading functions
        // NOTE: This functions do not require GPU access
        rl.set_function("LoadImage", &LoadImage);
        rl.set_function("LoadImageRaw", &LoadImageRaw);
        rl.set_function("LoadImageAnim", &LoadImageAnim);
        rl.set_function("LoadImageFromMemory", &LoadImageFromMemory);
        rl.set_function("UnloadImage", &UnloadImage);
        rl.set_function("ExportImage", &ExportImage);
        rl.set_function("ExportImageAsCode", &ExportImageAsCode);

        // Image generation functions
        rl.set_function("GenImageColor", &GenImageColor);
        rl.set_function("GenImageGradientV", &GenImageGradientV);
        rl.set_function("GenImageGradientH", &GenImageGradientH);
        rl.set_function("GenImageGradientRadial", &GenImageGradientRadial);
        rl.set_function("GenImageChecked", &GenImageChecked);
        rl.set_function("GenImageWhiteNoise", &GenImageWhiteNoise);
        rl.set_function("GenImagePerlinNoise", &GenImagePerlinNoise);
        rl.set_function("GenImageCellular", &GenImageCellular);

        // Image manipulation functions
        rl.set_function("ImageCopy", &ImageCopy);
        rl.set_function("ImageFromImage", &ImageFromImage);
        rl.set_function("ImageText", &ImageText);
        rl.set_function("ImageTextEx", &ImageTextEx);
        rl.set_function("ImageFormat", &ImageFormat);
        rl.set_function("ImageToPOT", &ImageToPOT);
        rl.set_function("ImageCrop", &ImageCrop);
        rl.set_function("ImageAlphaCrop", &ImageAlphaCrop);
        rl.set_function("ImageAlphaClear", &ImageAlphaClear);
        rl.set_function("ImageAlphaMask", &ImageAlphaMask);
        rl.set_function("ImageAlphaPremultiply", &ImageAlphaPremultiply);
        rl.set_function("ImageResize", &ImageResize);
        rl.set_function("ImageResizeNN", &ImageResizeNN);
        rl.set_function("ImageResizeCanvas", &ImageResizeCanvas);
        rl.set_function("ImageMipmaps", &ImageMipmaps);
        rl.set_function("ImageDither", &ImageDither);
        rl.set_function("ImageFlipVertical", &ImageFlipVertical);
        rl.set_function("ImageFlipHorizontal", &ImageFlipHorizontal);
        rl.set_function("ImageRotateCW", &ImageRotateCW);
        rl.set_function("ImageRotateCCW", &ImageRotateCCW);
        rl.set_function("ImageColorTint", &ImageColorTint);
        rl.set_function("ImageColorInvert", &ImageColorInvert);
        rl.set_function("ImageColorGrayscale", &ImageColorGrayscale);
        rl.set_function("ImageColorContrast", &ImageColorContrast);
        rl.set_function("ImageColorBrightness", &ImageColorBrightness);
        rl.set_function("ImageColorReplace", &ImageColorReplace);
        rl.set_function("LoadImageColors", &LoadImageColors);
        rl.set_function("LoadImagePalette", &LoadImagePalette);
        rl.set_function("UnloadImageColors", &UnloadImageColors);
        rl.set_function("UnloadImagePalette", &UnloadImagePalette);
        rl.set_function("GetImageAlphaBorder", &GetImageAlphaBorder);

        // Image drawing functions
        // NOTE: Image software-rendering functions (CPU)
        rl.set_function("ImageClearBackground", &ImageClearBackground);
        rl.set_function("ImageDrawPixel", &ImageDrawPixel);
        rl.set_function("ImageDrawPixelV", &ImageDrawPixelV);
        rl.set_function("ImageDrawLine", &ImageDrawLine);
        rl.set_function("ImageDrawLineV", &ImageDrawLineV);
        rl.set_function("ImageDrawCircle", &ImageDrawCircle);
        rl.set_function("ImageDrawCircleV", &ImageDrawCircleV);
        rl.set_function("ImageDrawRectangle", &ImageDrawRectangle);
        rl.set_function("ImageDrawRectangleV", &ImageDrawRectangleV);
        rl.set_function("ImageDrawRectangleRec", &ImageDrawRectangleRec);
        rl.set_function("ImageDrawRectangleLines", &ImageDrawRectangleLines);
        rl.set_function("ImageDraw", &ImageDraw);
        rl.set_function("ImageDrawText", &ImageDrawText);
        rl.set_function("ImageDrawTextEx", &ImageDrawTextEx);

        // Texture loading functions
        // NOTE: These functions require GPU access
        rl.set_function("LoadTexture", &LoadTexture);
        rl.set_function("LoadTextureFromImage", &LoadTextureFromImage);
        rl.set_function("LoadTextureCubemap", &LoadTextureCubemap);
        rl.set_function("LoadRenderTexture", &LoadRenderTexture);
        rl.set_function("UnloadTexture", &UnloadTexture);
        rl.set_function("UnloadRenderTexture", &UnloadRenderTexture);
        rl.set_function("UpdateTexture", &UpdateTexture);
        rl.set_function("UpdateTextureRec", &UpdateTextureRec);
        rl.set_function("GetTextureData", &GetTextureData);
        rl.set_function("GetScreenData", &GetScreenData);

        // Texture configuration functions
        rl.set_function("GenTextureMipmaps", &GenTextureMipmaps);
        rl.set_function("SetTextureFilter", &SetTextureFilter);
        rl.set_function("SetTextureWrap", &SetTextureWrap);

        // Texture drawing functions
        rl.set_function("DrawTexture", &DrawTexture);
        rl.set_function("DrawTextureV", &DrawTextureV);
        rl.set_function("DrawTextureEx", &DrawTextureEx);
        rl.set_function("DrawTextureRec", &DrawTextureRec);
        rl.set_function("DrawTextureQuad", &DrawTextureQuad);
        rl.set_function("DrawTextureTiled", &DrawTextureTiled);
        rl.set_function("DrawTexturePro", &DrawTexturePro);
        rl.set_function("DrawTextureNPatch", &DrawTextureNPatch);
        rl.set_function("DrawTexturePoly", &DrawTexturePoly);

        // Color/pixel related functions
        rl.set_function("Fade", &Fade);
        rl.set_function("ColorToInt", &ColorToInt);
        rl.set_function("ColorNormalize", &ColorNormalize);
        rl.set_function("ColorFromNormalized", &ColorFromNormalized);
        rl.set_function("ColorToHSV", &ColorToHSV);
        rl.set_function("ColorFromHSV", &ColorFromHSV);
        rl.set_function("ColorAlpha", &ColorAlpha);
        rl.set_function("ColorAlphaBlend", &ColorAlphaBlend);
        rl.set_function("GetColor", &GetColor);
        rl.set_function("GetPixelColor", &GetPixelColor);
        rl.set_function("SetPixelColor", &SetPixelColor);
        rl.set_function("GetPixelDataSize", &GetPixelDataSize);

        //------------------------------------------------------------------------------------
        // Font Loading and Text Drawing Functions (Module: text)
        //------------------------------------------------------------------------------------

        // Font loading/unloading functions
        rl.set_function("GetFontDefault", &GetFontDefault);
        rl.set_function("LoadFont", &LoadFont);
        rl.set_function("LoadFontEx", &LoadFontEx);
        rl.set_function("LoadFontFromImage", &LoadFontFromImage);
        rl.set_function("LoadFontFromMemory", &LoadFontFromMemory);
        rl.set_function("LoadFontData", &LoadFontData);
        rl.set_function("GenImageFontAtlas", &GenImageFontAtlas);
        rl.set_function("UnloadFontData", &UnloadFontData);
        rl.set_function("UnloadFont", &UnloadFont);

        // Text drawing functions
        rl.set_function("DrawFPS", &DrawFPS);
        rl.set_function("DrawText", &DrawText);
        rl.set_function("DrawTextEx", &DrawTextEx);
        rl.set_function("DrawTextRec", &DrawTextRec);
        rl.set_function("DrawTextRecEx", &DrawTextRecEx);
        rl.set_function("DrawTextCodepoint", &DrawTextCodepoint);

        // Text misc. functions
        rl.set_function("MeasureText", &MeasureText);
        rl.set_function("MeasureTextEx", &MeasureTextEx);
        rl.set_function("GetGlyphIndex", &GetGlyphIndex);

        // Text strings management functions (no utf8 strings, only byte chars)
        // NOTE: Some strings allocate memory internally for returned strings, just be careful!
        rl.set_function("TextCopy", &TextCopy);
        rl.set_function("TextIsEqual", &TextIsEqual);
        rl.set_function("TextLength", &TextLength);
        rl.set_function("TextFormat", &TextFormat);
        rl.set_function("TextSubtext", &TextSubtext);
        rl.set_function("TextReplace", &TextReplace);
        rl.set_function("TextInsert", &TextInsert);
        rl.set_function("TextJoin", &TextJoin);
        rl.set_function("TextSplit", &TextSplit);
        rl.set_function("TextAppend", &TextAppend);
        rl.set_function("TextFindIndex", &TextFindIndex);
        rl.set_function("TextToUpper", &TextToUpper);
        rl.set_function("TextToLower", &TextToLower);
        rl.set_function("TextToPascal", &TextToPascal);
        rl.set_function("TextToInteger", &TextToInteger);
        rl.set_function("TextToUtf8", &TextToUtf8);                  // Encode text codepoint into utf8 text (memory must be freed!)

        // UTF8 text strings management functions
        rl.set_function("GetCodepoints", &GetCodepoints);
        rl.set_function("GetCodepointsCount", &GetCodepointsCount);
        rl.set_function("GetNextCodepoint", &GetNextCodepoint);
        rl.set_function("CodepointToUtf8", &CodepointToUtf8);    // Encode codepoint into utf8 text (char array length returned as parameter)

        //------------------------------------------------------------------------------------
        // Basic 3d Shapes Drawing Functions (Module: models)
        //------------------------------------------------------------------------------------

        // Basic geometric 3D shapes drawing functions
        rl.set_function("DrawLine3D", &DrawLine3D);                                    // Draw a line in 3D world space
        rl.set_function("DrawPoint3D", &DrawPoint3D);                                                   // Draw a point in 3D space, actually a small line
        rl.set_function("DrawCircle3D", &DrawCircle3D); // Draw a circle in 3D world space
        rl.set_function("DrawTriangle3D", &DrawTriangle3D);                              // Draw a color-filled triangle (vertex in counter-clockwise order!)
        rl.set_function("DrawTriangleStrip3D", &DrawTriangleStrip3D);                           // Draw a triangle strip defined by points
        rl.set_function("DrawCube", &DrawCube);
        rl.set_function("DrawCubeV", &DrawCubeV);
        rl.set_function("DrawCubeWires", &DrawCubeWires);
        rl.set_function("DrawCubeWiresV", &DrawCubeWiresV);
        rl.set_function("DrawCubeTexture", &DrawCubeTexture);
        rl.set_function("DrawSphere", &DrawSphere);
        rl.set_function("DrawSphereEx", &DrawSphereEx);
        rl.set_function("DrawSphereWires", &DrawSphereWires);
        rl.set_function("DrawCylinder", &DrawCylinder);
        rl.set_function("DrawCylinderWires", &DrawCylinderWires);
        rl.set_function("DrawPlane", &DrawPlane);
        rl.set_function("DrawRay", &DrawRay);
        rl.set_function("DrawGrid", &DrawGrid);

        //------------------------------------------------------------------------------------
        // Model 3d Loading and Drawing Functions (Module: models)
        //------------------------------------------------------------------------------------

        // Model loading/unloading functions
        rl.set_function("LoadModel", &LoadModel);
        rl.set_function("LoadModelFromMesh", &LoadModelFromMesh);
        rl.set_function("UnloadModel", &UnloadModel);
        rl.set_function("UnloadModelKeepMeshes", &UnloadModelKeepMeshes);

        // Mesh loading/unloading functions
        rl.set_function("UploadMesh", &UploadMesh);
        rl.set_function("UpdateMeshBuffer", &UpdateMeshBuffer);
        rl.set_function("DrawMesh", &DrawMesh);
        rl.set_function("DrawMeshInstanced", &DrawMeshInstanced);
        rl.set_function("UnloadMesh", &UnloadMesh);
        rl.set_function("ExportMesh", &ExportMesh);

        // Material loading/unloading functions
        rl.set_function("LoadMaterials", &LoadMaterials);
        rl.set_function("LoadMaterialDefault", &LoadMaterialDefault);
        rl.set_function("UnloadMaterial", &UnloadMaterial);
        rl.set_function("SetMaterialTexture", &SetMaterialTexture);
        rl.set_function("SetModelMeshMaterial", &SetModelMeshMaterial);

        // Model animations loading/unloading functions
        rl.set_function("LoadModelAnimations", &LoadModelAnimations);
        rl.set_function("UpdateModelAnimation", &UpdateModelAnimation);
        rl.set_function("UnloadModelAnimation", &UnloadModelAnimation);
        rl.set_function("UnloadModelAnimations", &UnloadModelAnimations);
        rl.set_function("IsModelAnimationValid", &IsModelAnimationValid);

        // Mesh generation functions
        rl.set_function("GenMeshPoly", &GenMeshPoly);
        rl.set_function("GenMeshPlane", &GenMeshPlane);
        rl.set_function("GenMeshCube", &GenMeshCube);
        rl.set_function("GenMeshSphere", &GenMeshSphere);
        rl.set_function("GenMeshHemiSphere", &GenMeshHemiSphere);
        rl.set_function("GenMeshCylinder", &GenMeshCylinder);
        rl.set_function("GenMeshTorus", &GenMeshTorus);
        rl.set_function("GenMeshKnot", &GenMeshKnot);
        rl.set_function("GenMeshHeightmap", &GenMeshHeightmap);
        rl.set_function("GenMeshCubicmap", &GenMeshCubicmap);

        // Mesh manipulation functions
        rl.set_function("MeshBoundingBox", &MeshBoundingBox);
        rl.set_function("MeshTangents", &MeshTangents);
        rl.set_function("MeshBinormals", &MeshBinormals);

        // Model drawing functions
        rl.set_function("DrawModel", &DrawModel);
        rl.set_function("DrawModelEx", &DrawModelEx);
        rl.set_function("DrawModelWires", &DrawModelWires);
        rl.set_function("DrawModelWiresEx", &DrawModelWiresEx);
        rl.set_function("DrawBoundingBox", &DrawBoundingBox);
        rl.set_function("DrawBillboard", &DrawBillboard);
        rl.set_function("DrawBillboardRec", &DrawBillboardRec);

        // Collision detection functions
        rl.set_function("CheckCollisionSpheres", &CheckCollisionSpheres);
        rl.set_function("CheckCollisionBoxes", &CheckCollisionBoxes);
        rl.set_function("CheckCollisionBoxSphere", &CheckCollisionBoxSphere);
        rl.set_function("CheckCollisionRaySphere", &CheckCollisionRaySphere);
        rl.set_function("CheckCollisionRaySphereEx", &CheckCollisionRaySphereEx);
        rl.set_function("CheckCollisionRayBox", &CheckCollisionRayBox);
        rl.set_function("GetCollisionRayMesh", &GetCollisionRayMesh);
        rl.set_function("GetCollisionRayModel", &GetCollisionRayModel);
        rl.set_function("GetCollisionRayTriangle", &GetCollisionRayTriangle);
        rl.set_function("GetCollisionRayGround", &GetCollisionRayGround);

        //------------------------------------------------------------------------------------
        // Audio Loading and Playing Functions (Module: audio)
        //------------------------------------------------------------------------------------

        // Audio device management functions
        rl.set_function("InitAudioDevice", &InitAudioDevice);
        rl.set_function("CloseAudioDevice", &CloseAudioDevice);
        rl.set_function("IsAudioDeviceReady", &IsAudioDeviceReady);
        rl.set_function("SetMasterVolume", &SetMasterVolume);

        // Wave/Sound loading/unloading functions
        rl.set_function("LoadWave", &LoadWave);
        rl.set_function("LoadWaveFromMemory", &LoadWaveFromMemory);
        rl.set_function("LoadSound", &LoadSound);
        rl.set_function("LoadSoundFromWave", &LoadSoundFromWave);
        rl.set_function("UpdateSound", &UpdateSound);
        rl.set_function("UnloadWave", &UnloadWave);
        rl.set_function("UnloadSound", &UnloadSound);
        rl.set_function("ExportWave", &ExportWave);
        rl.set_function("ExportWaveAsCode", &ExportWaveAsCode);

        // Wave/Sound management functions
        rl.set_function("PlaySound", &PlaySound);
        rl.set_function("StopSound", &StopSound);
        rl.set_function("PauseSound", &PauseSound);
        rl.set_function("ResumeSound", &ResumeSound);
        rl.set_function("PlaySoundMulti", &PlaySoundMulti);
        rl.set_function("StopSoundMulti", &StopSoundMulti);
        rl.set_function("GetSoundsPlaying", &GetSoundsPlaying);
        rl.set_function("IsSoundPlaying", &IsSoundPlaying);
        rl.set_function("SetSoundVolume", &SetSoundVolume);
        rl.set_function("SetSoundPitch", &SetSoundPitch);
        rl.set_function("WaveFormat", &WaveFormat);
        rl.set_function("WaveCopy", &WaveCopy);
        rl.set_function("WaveCrop", &WaveCrop);
        rl.set_function("LoadWaveSamples", &LoadWaveSamples);
        rl.set_function("UnloadWaveSamples", &UnloadWaveSamples);

        // Music management functions
        rl.set_function("LoadMusicStream", &LoadMusicStream);
        rl.set_function("LoadMusicStreamFromMemory", &LoadMusicStreamFromMemory);
        rl.set_function("UnloadMusicStream", &UnloadMusicStream);
        rl.set_function("PlayMusicStream", &PlayMusicStream);
        rl.set_function("IsMusicPlaying", &IsMusicPlaying);
        rl.set_function("UpdateMusicStream", &UpdateMusicStream);
        rl.set_function("StopMusicStream", &StopMusicStream);
        rl.set_function("PauseMusicStream", &PauseMusicStream);
        rl.set_function("ResumeMusicStream", &ResumeMusicStream);
        rl.set_function("SetMusicVolume", &SetMusicVolume);
        rl.set_function("SetMusicPitch", &SetMusicPitch);
        rl.set_function("GetMusicTimeLength", &GetMusicTimeLength);
        rl.set_function("GetMusicTimePlayed", &GetMusicTimePlayed);

        // AudioStream management functions
        rl.set_function("InitAudioStream", &InitAudioStream);
        rl.set_function("UpdateAudioStream", &UpdateAudioStream);
        rl.set_function("CloseAudioStream", &CloseAudioStream);
        rl.set_function("IsAudioStreamProcessed", &IsAudioStreamProcessed);
        rl.set_function("PlayAudioStream", &PlayAudioStream);
        rl.set_function("PauseAudioStream", &PauseAudioStream);
        rl.set_function("ResumeAudioStream", &ResumeAudioStream);
        rl.set_function("IsAudioStreamPlaying", &IsAudioStreamPlaying);
        rl.set_function("StopAudioStream", &StopAudioStream);
        rl.set_function("SetAudioStreamVolume", &SetAudioStreamVolume);
        rl.set_function("SetAudioStreamPitch", &SetAudioStreamPitch);
        rl.set_function("SetAudioStreamBufferSizeDefault", &SetAudioStreamBufferSizeDefault);

    }

}
