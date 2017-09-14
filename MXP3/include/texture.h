#pragma once

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "../include/renderer.h"
#include <string>

class __declspec(dllexport) Texture
{
public:
	Texture();
	Texture(std::string string);
	virtual ~Texture();
	static SDL_Texture* loadTexture(std::string path);
	SDL_Texture* tex;
protected:
};