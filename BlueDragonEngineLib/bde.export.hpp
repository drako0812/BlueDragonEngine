#pragma once

#if defined(_WIN32) && defined(BLUEDRAGONENGINELIB_DLL)
#ifdef BLUEDRAGONENGINELIB_EXPORTS
#define BDE_API __declspec(dllexport)
#else
#define BDE_API __declspec(dllimport)
#endif
#else
#define BDE_API
#endif
