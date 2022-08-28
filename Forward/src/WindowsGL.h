#pragma once

#include <Windows.h>

#include "wgl.h"

int LoadWGL();

extern const PIXELFORMATDESCRIPTOR			PixelFormatDescriptor;

extern PFNWGLCHOOSEPIXELFORMATARBPROC		__wglChoosePixelFormatARB;
extern PFNWGLCREATECONTEXTATTRIBSARBPROC	__wglCreateContextAttribsARB;
extern PFNWGLSWAPINTERVALEXTPROC			__wglSwapIntervalEXT;

#define wglChoosePixelFormatARB				__wglChoosePixelFormatARB
#define wglCreateContextAttribsARB			__wglCreateContextAttribsARB
#define wglSwapIntervalEXT					__wglSwapIntervalEXT
