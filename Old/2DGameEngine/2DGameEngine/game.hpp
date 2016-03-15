#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <windows.h>
#include <GL/gl.h>
#include <stdio.h>

#include <fstream>
#include <sstream>

#include "graphics.hpp"
#include "rectangle.hpp"

using namespace engine;

LRESULT CALLBACK WwdProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class Game
{
public:
	graphics::KX_ScreenRect ScreenRect;
	graphics::KX_ScreenRect WorldRect;

	Game();
	~Game();
};

#endif // __GAME_HPP__