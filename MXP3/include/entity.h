#pragma once

#include <iostream>
#include "texture.h"
#include "vector2.h"
#include <SDL2\SDL.h>
#include <vector>

class __declspec(dllexport) Entity {
public:
	Entity(SDL_Renderer* renderer);
	virtual ~Entity();

	virtual void update(float deltatime);

	Texture* myTex;

	Vector2* pos;
	Vector2* scale;

	void addchild(Entity* child);
	void removechild(Entity* child);

	std::vector<Entity*>childrenVec;
private:
	Entity* _parent;

	int _guid; 
	static int _nextGuid;
};