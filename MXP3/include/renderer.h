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
	void renderScene(Entity* entity);
	void renderTexture(Texture* texture, SDL_Rect* rect);
	double getDeltatime() { return deltatime; }
	SDL_Renderer* getRenderer() {
		return renderer;
	};
private:
	int resX, resY;

	Uint64 LAST;
	double deltatime;

	static Renderer* instance;

	Renderer();
	Renderer(int rX, int rY);
	virtual ~Renderer();

	void calculateDeltatime();

	SDL_Window* window;
	SDL_Renderer* renderer;
};
