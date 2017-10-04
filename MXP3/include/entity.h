#pragma once

#include <iostream>

#include "texture.h"
#include "vector2.h"

#include <SDL2/SDL.h>
#include <vector>

class Renderer;

class __declspec(dllexport) Entity {
public:

	//default constructor en deconstructor
	Entity(SDL_Renderer* renderer);
	virtual ~Entity();

	//update function that updates every frame
	virtual void update(double deltatime);

	//texture of the entity
	Texture* myTex;

	//position and scale of the entity
	Vector2* pos;
	Vector2* scale;

	//addchild function. add it to the window and parent
	void addchild(Entity* child);
	//removechild function, removes it from the window and parent
	void removechild(Entity* child);
	//addtexture function, add the myTex texture to the entity
	//void addTexture(std::string path);

	//vector with chilren of current entity
	std::vector<Entity*>childrenVec;
private:
	//parent entity
	Entity* _parent;

	//current and next entity in list
	int _guid; 
	static int _nextGuid;
};