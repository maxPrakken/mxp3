#pragma once

#include <SDL2/SDL.h>

#include "../MXP3/include/scene.h"

class MyScene : public Scene{
public:
	MyScene();
	virtual ~MyScene();
	virtual void update(double deltatime);

private:

};