/*
	SincroB GameWindow
*/

#ifndef __GRAPHICS_HPP__
#define __GRAPHICS_HPP__

#include <windows.h>
#include <iostream>
#include <math.h>
#include <GL\gl.h>

#include "maths.hpp"

namespace engine { using namespace maths; namespace graphics {

	#define NUM_VIDEOMODES 4

	struct WM_VideoMode
	{
		int width, height, bpp;

		WM_VideoMode() {};
		WM_VideoMode(int width, int height, int bpp) {this->width=width; this->height=height; this->bpp=bpp;};
		~WM_VideoMode() {};
	};

	class WM_Window
	{
	public:
		WM_Window();
		~WM_Window();

		void init_window();
		void init_context(int bits);

		void destroy_window();
		void destroy_context();

		BOOL create_window(char *title, WNDPROC wndproc);
		void create_window(bool toggle_fullscreen);

	public:
		int getCurrentWidth()
		{
			RECT rect_client;
			GetClientRect(hwnd, &rect_client);
			return (rect_client.right - rect_client.left);
		}

		int getCurrentHeight()
		{
			RECT rect_client;
			GetClientRect(hwnd, &rect_client);
			return (rect_client.bottom - rect_client.top);
		}

		int getCurrentMode()
		{
			return inFullscreen ? fullscreen_mode : windowed_mode;
		}

	public:
		HDC hdc;
		HGLRC hrc;
		HWND hwnd;
		HINSTANCE hinstance;
		DEVMODE native;

		WM_VideoMode video_modes[NUM_VIDEOMODES];
		WM_VideoMode virtual_modes[NUM_VIDEOMODES];

		int border_width;
		int border_height;

		int windowed_mode;
		int fullscreen_mode;

		int scale_mode;
		float scale_value;
		void write_scale();

		bool inFullscreen;
		bool inActive;

		vec2 window_position;
	};
} }

#endif // __GRAPHICS_HPP__