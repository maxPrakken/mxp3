#pragma once

#include "../MXP3/include/scene.h"

#include "enemy.h"
#include "player.h"

class Demo1 : public Scene{

public:
	//constructor 
	Demo1();
	//deconstructor
	virtual ~Demo1();
	//update function
	virtual void update(double deltatime);

	Entity* pic;
	Entity* pic2;

	Enemy* test;
	Player* player;

	void movement(double deltatime);
	void audioController();

private:

};