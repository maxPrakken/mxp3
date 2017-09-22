#pragma once

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <string>
#include <iostream>

class __declspec(dllexport) Texture
{
public:
	Texture();
	Texture(SDL_Renderer* renderer, std::string string);
	virtual ~Texture();
	static SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);
	SDL_Texture* tex;
protected:
};