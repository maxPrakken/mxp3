#pragma once

#include "entity.h"
#include "renderer.h"
#include "input.h"

class __declspec(dllexport) Scene : public Entity {
public:
	//default constuctor
	Scene(SDL_Renderer* renderer);
	//deconstructor
	virtual ~Scene();

	//update function. updates every frame
	void update(double deltatime);
	
	//places entity in the absolute middle of the window
	Vector2* placeCenter(Entity* entity);

	Entity* pic;
	Entity* pic2;

private:
	//update the children of the scene
	void updateChildren(float deltatime);
};