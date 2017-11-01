#pragma once

#include "../MXP3/include/entity.h"

class Enemy : public Entity {
public:
	//constructor
	Enemy();
	//deconstructor
	virtual ~Enemy();
	//update function
	virtual void update(double deltatime);
	
	//animation controller
	void animationController(int i);

	int die(double deltatime);

	int health;

	bool dead;
	bool canWalk;

private:

};