#pragma once

#include <iostream>
#include <SDL2\SDL.h>

class __declspec(dllexport) Renderer
{
public:
	Renderer();
	Renderer(int rX,int rY);
	virtual ~Renderer();

	void update();

private:
	int resX, resY;


	SDL_Window* window;
	SDL_Renderer* renderer;
};
