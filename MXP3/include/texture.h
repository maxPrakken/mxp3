#pragma once

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <string>
#include <iostream>

class __declspec(dllexport) Texture
{
public:
	//default constructor
	Texture();
	//constructor overloader that takes path to texture
	Texture(SDL_Renderer* renderer, std::string string);
	//deconstructor
	virtual ~Texture();
	//loadtexture function. draws the texture on the window
	static SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);
	//instance of sdl texture to pass to the renderer
	SDL_Texture* tex;
protected:
};