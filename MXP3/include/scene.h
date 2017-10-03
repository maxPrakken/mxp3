#pragma once

#include "entity.h"
#include "renderer.h"

class __declspec(dllexport) Scene : public Entity {
public:
	Scene(SDL_Renderer* renderer);
	virtual ~Scene();

	void update(float deltatime);

	Entity* pic;

private:
	void updateChildren(float deltatime);
};