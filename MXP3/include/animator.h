#pragma once

#include "texture.h"
#include <iostream>

#include <SDL2\SDL.h>

class Renderer;

class __declspec(dllexport) Animator {
public:
	Animator();
	Animator(Texture* texture);
	Animator(Texture* texture, Vector2 rows);
	virtual ~Animator();
	Vector2 rows;

	SDL_Rect* getChuck(Vector2 position);

private:
	Texture* textureToAnimate;

};