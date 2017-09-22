#pragma once

#include <iostream>
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>

#include "entity.h"

class __declspec(dllexport) Renderer
{
public:
	static Renderer* getInstance();

	void showTexture(SDL_Texture * tex);

	void update();
	void renderEntity(Entity * entity);
	SDL_Renderer* getRenderer() {
		return renderer;
	};
private:
	int resX, resY;

	static Renderer* instance;

	Renderer();
	Renderer(int rX, int rY);
	virtual ~Renderer();

	SDL_Window* window;
	SDL_Renderer* renderer;
};
