
#include "Window.h"

#include <Windows.h>

#include "WindowsGL.h"

#define GET_WINDOW_VIEW(hWnd) (WINDOW)GetWindowLongPtr(hWnd, GWLP_USERDATA)

struct tagWINDOW
{
	HWND Window;

	HDC DeviceContext;

	HGLRC RenderingContext;

	BOOL Closed;

	ONWINDOWRESIZE OnResize;
};

static HGLRC SetupRenderingContext(_In_ HDC DeviceContext)
{
	HGLRC RenderingContext = NULL;

	int PixelFormat = 0;

	UINT NumberOfPixelFormats = 0;

	static const int PixelAttributes[] =
	{
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
		WGL_COLOR_BITS_ARB, 32,
		WGL_DEPTH_BITS_ARB, 24,
		WGL_STENCIL_BITS_ARB, 8,
		0,
	};

	static const int ContextAttributes[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
		WGL_CONTEXT_MINOR_VERSION_ARB, 6,
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		0,
	};

	wglChoosePixelFormatARB(DeviceContext, PixelAttributes, NULL, 1, &PixelFormat, &NumberOfPixelFormats);

	SetPixelFormat(DeviceContext, PixelFormat, &PixelFormatDescriptor);

	RenderingContext = wglCreateContextAttribsARB(DeviceContext, NULL, ContextAttributes);

	return(RenderingContext);
}

static LRESULT __stdcall WindowCallback(_In_ HWND Window, _In_ UINT Message, _In_ WPARAM WParam, _In_ LPARAM LParam)
{
	if (Message == WM_CREATE)
	{
		CREATESTRUCT* CreateInfo = (CREATESTRUCT*)LParam;

		WINDOW View = CreateInfo->lpCreateParams;

		View->Window = Window;

		View->DeviceContext = GetDC(Window);

		View->RenderingContext = SetupRenderingContext(View->DeviceContext);

		View->Closed = FALSE;

		SetWindowLongPtr(Window, GWLP_USERDATA, (LONG_PTR)View);

		return(0);
	}

	else if (Message == WM_CLOSE)
	{
		WINDOW View = GET_WINDOW_VIEW(Window);

		View->Closed = TRUE;

		return(0);
	}

	else if (Message == WM_SIZE)
	{
		WINDOW View = GET_WINDOW_VIEW(Window);
		
		if (View->OnResize)
		{
			RECT WindowRect;

			GetClientRect(View->Window, &WindowRect);

			int Width = WindowRect.right - WindowRect.left;

			int Height = WindowRect.bottom - WindowRect.top;

			View->OnResize(View, Width, Height);
		}

		return(0);
	}

	else if (Message == WM_DESTROY)
	{
		WINDOW View = GET_WINDOW_VIEW(Window);

		if (wglGetCurrentContext() == View->RenderingContext)
		{
			wglMakeCurrent(NULL, NULL);
		}

		wglDeleteContext(View->RenderingContext);

		ReleaseDC(View->Window, View->DeviceContext);

		return(0);
	}

	return(DefWindowProc(Window, Message, WParam, LParam));
}

int NewWindow(WINDOWCONFIG* Config, WINDOW* Window)
{
	int ErrorCode = ERROR_SUCCESS;

	*Window = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(**Window));

	WINDOW View = *Window;

	WNDCLASS WindowClass = { 0 };

	LoadWGL();

	WindowClass.hInstance = GetModuleHandle(NULL);

	WindowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);

	WindowClass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;

	WindowClass.lpfnWndProc = WindowCallback;

	WindowClass.lpszClassName = Config->Title;

	if (RegisterClass(&WindowClass) == 0)
	{
		ErrorCode = GetLastError();

		goto Error;
	}

	if (CreateWindow(WindowClass.lpszClassName, Config->Title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, Config->Width, Config->Height, NULL, NULL, GetModuleHandle(NULL), View) == NULL)
	{
		ErrorCode = GetLastError();

		goto Error;
	}

	return(0);

Error:

	HeapFree(GetProcessHeap(), 0, Window);

	return(ErrorCode);
}

void MakeCurrent(WINDOW Window)
{
	wglMakeCurrent(Window->DeviceContext, Window->RenderingContext);
}

void SetWindowResizeCallback(WINDOW Window, ONWINDOWRESIZE Callback)
{
	Window->OnResize = Callback;

	RECT WindowRect;

	GetClientRect(Window->Window, &WindowRect);

	int Width = WindowRect.right - WindowRect.left;

	int Height = WindowRect.bottom - WindowRect.top;

	Window->OnResize(Window, Width, Height);
}

BOOL Closed(WINDOW Window)
{
	if (Window)
	{
		return Window->Closed;
	}
	else
	{
		return TRUE;
	}
}

void Present(WINDOW Window)
{
	if (Window)
	{
		SwapBuffers(Window->DeviceContext);
	}
}

void PollEvents()
{
	MSG Message = { 0 };
	
	while (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
	{
		DispatchMessage(&Message);
	}
}

void DeleteWindow(WINDOW Window)
{
	if (Window)
	{
		DestroyWindow(Window->Window);

		HeapFree(GetProcessHeap(), 0, Window);
	}
}
