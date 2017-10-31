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
	void animationController();

	//movement controller
	void movementController();

	//function for hitting the player
	void hit();

	int health;

private:

};