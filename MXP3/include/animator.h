#pragma once

#include "texture.h"
#include <iostream>

#include <SDL2\SDL.h>

class Renderer;
class Texture;

class __declspec(dllexport) Animator {
public:
	Animator();
	Animator(Vector2 rows);
	virtual ~Animator();
	virtual void update(double deltatime);

	Vector2 rows;

	int getCurrentChunk();

	int playAnimation(int start, int* current, int end);
	int start;
	int cur;
	bool paused;
	
	Vector2 animateFromTo;
	SDL_Rect getChuck(Vector2 position, Vector2 resolution);

private:
	int i;
	
};