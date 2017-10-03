#pragma once

#include "entity.h"
#include "renderer.h"
#include "input.h"

class __declspec(dllexport) Scene : public Entity {
public:
	Scene(SDL_Renderer* renderer);
	virtual ~Scene();

	void update(double deltatime);

	Entity* pic;

private:
	void updateChildren(float deltatime);
};