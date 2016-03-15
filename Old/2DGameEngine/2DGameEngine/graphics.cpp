#include "graphics.hpp"
#pragma warning(disable:4244)

namespace engine { using namespace maths; namespace graphics {

	WM_Window::WM_Window()
	{
		hdc = NULL;
		hrc = NULL;
		hwnd = NULL;
	}

	WM_Window::~WM_Window()
	{
		destroy_window();
	}

	void WM_Window::init_window()
	{
		inActive = true;
		inFullscreen = false;

		windowed_mode = 1;
		fullscreen_mode = 0;
		scale_mode = 1;

		EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &native);

		video_modes[0] = WM_VideoMode(4*native.dmPelsWidth, 4*native.dmPelsHeight, 32);
		video_modes[1] = WM_VideoMode(3*native.dmPelsWidth, 3*native.dmPelsHeight, 32);
		video_modes[2] = WM_VideoMode(2*native.dmPelsWidth, 2*native.dmPelsHeight, 32);
		video_modes[3] = WM_VideoMode(1*native.dmPelsWidth, 1*native.dmPelsHeight, 32);

		virtual_modes[0] = WM_VideoMode(1920, 1080, 32);
		virtual_modes[0] = WM_VideoMode(1440,  810, 32);
		virtual_modes[0] = WM_VideoMode( 960,  540, 32);
		virtual_modes[0] = WM_VideoMode( 480,  270, 32);

		for (int idx=0; idx<NUM_VIDEOMODES; idx++)
		{
			if (video_modes[idx].height % 2 != 0)
				video_modes[idx].height = video_modes[idx].height - 1;
		}
	}

	void WM_Window::init_context(int bits)
	{
		unsigned int pixel_format;
		static PIXELFORMATDESCRIPTOR pixel_format_decriptor;

		ZeroMemory(&pixel_format_decriptor, sizeof(pixel_format_decriptor));

		pixel_format_decriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pixel_format_decriptor.nVersion = 1;
		pixel_format_decriptor.dwFlags = PFD_DRAW_TO_BITMAP | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pixel_format_decriptor.iPixelType = PFD_TYPE_RGBA;
		pixel_format_decriptor.cColorBits = bits;
		pixel_format_decriptor.cDepthBits = 16;
		pixel_format_decriptor.iLayerType = PFD_MAIN_PLANE;

		hdc = GetDC(hwnd);
		pixel_format = ChoosePixelFormat(hdc, &pixel_format_decriptor);
		SetPixelFormat(hdc, pixel_format, &pixel_format_decriptor);
		hrc = wglCreateContext(hdc);
		wglMakeCurrent(hdc, hrc);
	}

	// Scale;
	void WM_Window::write_scale()
	{
		float bit_scale = 16.0f;

		scale_value = 16.0f;
		scale_mode = 3;

		float width = (float) getCurrentWidth();
		float height = (float) getCurrentHeight();

		if ((width / height) < (16.0f / 9.0f))
		{
			if (width >= 1920)
			{
				scale_value = bit_scale * 4;
				scale_mode = 0;

			} else if (width >= 1440)
			{
				scale_value = bit_scale * 3;
				scale_mode = 1;

			} else if (width >= 960)
			{
				scale_value = bit_scale * 2;
				scale_mode = 2;

			}

		} else
		{
			if (height >= 1080)
			{
				scale_value = bit_scale * 4;
				scale_mode = 0;

			} else if (height >= 810)
			{
				scale_value = bit_scale * 3;
				scale_mode = 1;

			} else if (height >= 540)
			{
				scale_value = bit_scale * 2;
				scale_mode = 2;

			}
		}
	}

	BOOL WM_Window::create_window(char *title, WNDPROC wndproc)
	{
		WNDCLASS window_class;
		DWORD dw_ex_style;
		DWORD dw_style;
		RECT window_rect;

		int width = inFullscreen ? video_modes[fullscreen_mode].width : video_modes[windowed_mode].width;
		int height = inFullscreen ? video_modes[fullscreen_mode].height : video_modes[windowed_mode].height;
		int bits = inFullscreen ? video_modes[fullscreen_mode].bpp : video_modes[windowed_mode].bpp;

		window_position = vec2(native.dmPelsWidth/2 - width/2, native.dmPelsHeight/2 - height/2);

		int	x = inFullscreen ? 0 : window_position.x;
		int	y = inFullscreen ? 0 : window_position.y;

		window_rect.left = (long) x;
		window_rect.right = (long) x + width;
		window_rect.top = (long) y;
		window_rect.bottom = (long) + y;

		hinstance = GetModuleHandle(NULL);

		window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		window_class.lpfnWndProc = (WNDPROC) wndproc;
		window_class.cbClsExtra	= 0;
		window_class.cbWndExtra	= 0;
		window_class.hInstance = hinstance;
		window_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
		window_class.hbrBackground = NULL;	
		window_class.lpszMenuName = NULL;	
		window_class.lpszClassName = __TEXT("OGL");

		RegisterClass(&window_class);

		if (inFullscreen)
		{
			DEVMODE dev_mode;

			memset(&dev_mode, 0, sizeof(dev_mode));
			dev_mode.dmSize=sizeof(dev_mode);
			dev_mode.dmPelsWidth = width;
			dev_mode.dmPelsHeight = height;
			dev_mode.dmBitsPerPel = bits;	
			dev_mode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

			ChangeDisplaySettings(&dev_mode, CDS_FULLSCREEN);		
			dw_ex_style = WS_EX_APPWINDOW;
			dw_style = WS_POPUP;

			ShowCursor(false);
		} else
		{
			dw_ex_style = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

			if(windowed_mode == 0)
				dw_style = WS_OVERLAPPED | WS_MINIMIZEBOX | WS_CAPTION | WS_SYSMENU;

			else
				dw_style = WS_OVERLAPPEDWINDOW | WS_MINIMIZEBOX | WS_CAPTION | WS_SYSMENU;
		}

		AdjustWindowRectEx(&window_rect, dw_style, false, dw_ex_style);

		hwnd = CreateWindowEx(dw_ex_style, __TEXT("OGL"), title, dw_style | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, window_rect.left, window_rect.top, window_rect.right - window_rect.left, window_rect.bottom - window_rect.top, NULL, NULL, hinstance, NULL);	

		RECT rect_client, rect_wind;

		GetClientRect(hwnd, &rect_client); 
		GetWindowRect(hwnd, &rect_wind);

		border_width = 2*((rect_wind.right - rect_wind.left) - rect_client.right)/2; 
		border_height = 2*((rect_wind.bottom - rect_wind.top) - rect_client.bottom)/2; 

		// Inicializa o Contexto em OpenGL;
		init_context(bits);

		SetForegroundWindow(hwnd);
		SetFocus(hwnd);

		return true;
	}

	void WM_Window::create_window(bool toggle_fullscreen)
	{
		if (toggle_fullscreen)
		{
			inFullscreen = !inFullscreen;
			destroy_context();
		}

		RECT window_rect;

		int	width = inFullscreen ? video_modes[fullscreen_mode].width : video_modes[windowed_mode].width;
		int	height = inFullscreen ? video_modes[fullscreen_mode].height : video_modes[windowed_mode].height;
		int	bits = inFullscreen ? video_modes[fullscreen_mode].bpp : video_modes[windowed_mode].bpp;

		window_position = vec2(native.dmPelsWidth/2 - width/2, native.dmPelsHeight/2 - height/2);

		int	x = inFullscreen ? 0 : window_position.x;
		int	y = inFullscreen ? 0 : window_position.y;

		// Janela proporcoes;
		window_rect.left = (long) x;
		window_rect.right = (long) x + width;
		window_rect.top = (long) y;	
		window_rect.bottom = (long) y + height;

		if(inFullscreen) 
		{
			SetWindowLongPtr(hwnd, GWL_EXSTYLE, WS_EX_APPWINDOW );
			SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE);

			SetWindowPos(hwnd,HWND_TOP, 0, 0, width, height, SWP_SHOWWINDOW);

			DEVMODE dev_mode;
			dev_mode.dmSize = sizeof(DEVMODE);
			dev_mode.dmPelsWidth = width;
			dev_mode.dmPelsHeight = height;
			dev_mode.dmBitsPerPel = bits;
			dev_mode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;

			ChangeDisplaySettings(&dev_mode, CDS_FULLSCREEN);

			ShowCursor(false);
		} else
		{
			DWORD dw_style;
			DWORD dw_ex_style = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;	

			if(windowed_mode == 0)
				dw_style = WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU;

			else
				dw_style = WS_OVERLAPPEDWINDOW | WS_MINIMIZEBOX | WS_CAPTION | WS_SYSMENU;

			SetWindowLongPtr(hwnd, GWL_EXSTYLE,  dw_ex_style);
			SetWindowLongPtr(hwnd, GWL_STYLE, dw_style);

			AdjustWindowRectEx(&window_rect, dw_style, false, dw_ex_style);

			SetWindowPos(hwnd,HWND_TOP, window_rect.left, window_rect.top, window_rect.right-window_rect.left, window_rect.bottom-window_rect.top, SWP_SHOWWINDOW);

			if(toggle_fullscreen)
				ChangeDisplaySettings(NULL, 0);
		}

		if(toggle_fullscreen)
			init_context(bits);
	}

	void WM_Window::destroy_window()
	{
		destroy_context();

		if (hdc)
		{
			ReleaseDC(hwnd, hdc);
			hdc = NULL;
		}

		if (hwnd)
		{
			DestroyWindow(hwnd);
			hwnd = NULL;
		}

		UnregisterClass(__TEXT("OGL"), hinstance);
		hinstance = NULL;
	}

	void WM_Window::destroy_context()
	{
		if (inFullscreen)
		{
			ChangeDisplaySettings(NULL, 0);
			ShowCursor(true);
		}

		if (hdc)
		{
			wglMakeCurrent(NULL, NULL);
			wglDeleteContext(hrc);
			hrc = NULL;
		}
	}
} }