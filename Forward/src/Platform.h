
#pragma once

#include <stdint.h>

#include <stddef.h>

#include <Windows.h>

#include "WindowsGL.h"

#include "GL.h"

#ifdef _UNICODE
#define Entry wWinMain
typedef LPWSTR STRING;
#else
#define Entry WinMain
typedef LPSTR STRING;
#endif

#define GAME_NAME "Forward"
