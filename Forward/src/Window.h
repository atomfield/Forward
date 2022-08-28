#pragma once

#include "Platform.h"

#include <Windows.h>

typedef struct tagWINDOW* WINDOW;

typedef struct tagWINDOWCONFIG
{
	STRING Title;

	uint32_t Width;

	uint32_t Height;
} WINDOWCONFIG;

typedef void (*ONWINDOWRESIZE)(WINDOW Window, int Width, int Height);

int NewWindow(WINDOWCONFIG* Config, WINDOW* Window);

void MakeCurrent(WINDOW Window);

void SetWindowResizeCallback(WINDOW Window, ONWINDOWRESIZE Callback);

BOOL Closed(WINDOW Window);

void Present(WINDOW Window);

void PollEvents();

void DeleteWindow(WINDOW Window);
