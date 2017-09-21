#pragma once

#include <iostream>
#include "renderer.h"
#include "texture.h"

class __declspec(dllexport) Entity {
public:
	Entity();
	virtual ~Entity();

	Texture* myTex = new Texture("assets/INA.tga");

	void addchild();
private:

};