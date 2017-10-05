#pragma once

#include "../MXP3/include/scene.h"

class MyScene : public Scene{
public:
	MyScene();
	virtual ~MyScene();
	virtual void update(double deltatime);

	Entity* pic;
	Entity* pic2;

private:

};