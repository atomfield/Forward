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

int NewWindow(WINDOWCONFIG* Config, WINDOW* Window);

void MakeCurrent(WINDOW Window);

BOOL Closed(WINDOW Window);

void Present(WINDOW Window);

void PollEvents();

void DeleteWindow(WINDOW Window);
