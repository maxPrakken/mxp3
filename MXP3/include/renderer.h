#pragma once

#include <iostream>
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <map>
#include "entity.h"
#include "texture.h"

// singleton renderer
class __declspec(dllexport) Renderer
{
public:
	//getinstance, gets instance of renderer
	static Renderer* getInstance();

	//shows SDL texture on screen
	void showTexture(SDL_Texture * tex);

	//updates the renderer
	void update();
	//renders entity in window
	void renderEntity(Entity * entity);
	//renders scene in window
	void renderScene(Entity* entity);
	//renders texture in window
	void renderTexture(Texture* texture, SDL_Rect* rect);
	//renders spritesheet in scene
	void renderSpritesheet(Texture* texture, SDL_Rect chunk, SDL_Rect* rect);
	//gets resolution
	Vector2 getResolution() { return Vector2(resX, resY); }
	//gets deltatime
	double getDeltatime() { return deltatime; }
	//Get/Add an image to your imageBlob
	Texture *GetImage(std::string path);
	//Destroy an image that
	void destroyTexture(std::string path);
	//retrieves the instance of the renderer
	SDL_Renderer* getRenderer() {
		return renderer;
	};
private:
	//int resolution X and Y
	int resX, resY;

	//64bit int for calculating deltatime and double deltatime variable
	Uint64 LAST;
	double deltatime;

	//the instance of renderer
	static Renderer* instance;

	//default constructor
	Renderer();
	//constructor overloader and deconstructor
	Renderer(int rX, int rY);
	virtual ~Renderer();

	//calculate deltatime function.
	void calculateDeltatime();


	//Map holding all the images
	std::map<std::string, Texture*> imageBlob;

	//sdl window and renderer instances
	SDL_Window* window;
	SDL_Renderer* renderer;
};
