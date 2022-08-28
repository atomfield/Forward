
#include "WindowsGL.h"

static int SetupFakeContext();
static void TerminateFakeContext();

static BOOL WGLLoaded = FALSE;

int LoadWGL()
{
	int Error = ERROR_SUCCESS;

	if (WGLLoaded == TRUE)
	{
		goto Exit;
	}

	Error = SetupFakeContext();
	if (Error != ERROR_SUCCESS)
	{
		goto Exit;
	}

	__wglChoosePixelFormatARB =
		(PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");

	__wglCreateContextAttribsARB =
		(PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	
	__wglSwapIntervalEXT =
		(PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");

	TerminateFakeContext();

	WGLLoaded = TRUE;

Exit:

	return(Error);
}

static HWND FakeWindow = NULL;

static HDC FakeDeviceContext = NULL;

static HGLRC FakeRenderingContext = NULL;

static HDC LastDeviceContext = NULL;

static HGLRC LastRenderingContext = NULL;

static int SetupFakeContext()
{
	int Error = ERROR_SUCCESS;

	int PixelFormat = 0;

	WNDCLASS FakeWindowClass = { 0 };

	FakeWindowClass.lpfnWndProc = DefWindowProc;
	
	FakeWindowClass.lpszClassName = TEXT("FakeWindowClass");

	if (RegisterClass(&FakeWindowClass) == 0)
	{
		Error = GetLastError();

		goto Exit;
	}

	FakeWindow = CreateWindow(FakeWindowClass.lpszClassName, NULL, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL);

	if (FakeWindow == NULL)
	{
		Error = GetLastError();

		goto Exit;
	}

	FakeDeviceContext = GetDC(FakeWindow);

	PixelFormat = ChoosePixelFormat(FakeDeviceContext, &PixelFormatDescriptor);
	
	SetPixelFormat(FakeDeviceContext, PixelFormat, &PixelFormatDescriptor);

	LastDeviceContext = wglGetCurrentDC();

	LastRenderingContext = wglGetCurrentContext();

	FakeRenderingContext = wglCreateContext(FakeDeviceContext);
	
	wglMakeCurrent(FakeDeviceContext, FakeRenderingContext);

Exit:

	return(0);
}

static void TerminateFakeContext()
{
	wglMakeCurrent(LastDeviceContext, LastRenderingContext);

	wglDeleteContext(FakeRenderingContext);

	ReleaseDC(FakeWindow, FakeDeviceContext);

	DestroyWindow(FakeWindow);

	UnregisterClass(TEXT("FakeWindowClass"), NULL);
}

const PIXELFORMATDESCRIPTOR	PixelFormatDescriptor =
{
	sizeof(PIXELFORMATDESCRIPTOR),
	1,
	PFD_DOUBLEBUFFER | PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL,
	PFD_TYPE_RGBA,
	32,
	0, 0, 0, 0, 0, 0,
	0,
	0,
	0,
	0, 0, 0, 0,
	24,
	8,
	0,
	PFD_MAIN_PLANE,
	0,
	0, 0, 0
};

PFNWGLCHOOSEPIXELFORMATARBPROC		__wglChoosePixelFormatARB;
PFNWGLCREATECONTEXTATTRIBSARBPROC	__wglCreateContextAttribsARB;
PFNWGLSWAPINTERVALEXTPROC			__wglSwapIntervalEXT;
