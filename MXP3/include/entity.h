#pragma once

#include <iostream>

#include "vector2.h"

#include <vector>

class Renderer;

class __declspec(dllexport) Entity {
public:

	//default constructor en deconstructor
	Entity();
	virtual ~Entity();

	//update function that updates every frame
	virtual void update(double deltatime);

	//texture of the entity
	std::string texturePath;

	//position and scale of the entity
	Vector2* pos;
	Vector2* scale;

	//addchild function. add it to the window and parent
	void addchild(Entity* child);
	//removechild function, removes it from the window and parent
	void removechild(Entity* child);

	//checks if the entity is colliding with another entity
	bool isColliding(Entity* other);

	//vector with chilren of current entity
	std::vector<Entity*>childrenVec;
private:
	//parent entity
	Entity* _parent;

	//current and next entity in list
	int _guid; 
	static int _nextGuid;
};