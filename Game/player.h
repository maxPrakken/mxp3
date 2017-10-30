#pragma once

#include "../MXP3/include/entity.h"
#include "../MXP3/include/input.h"

class Player : public Entity {
public:
	//constructor
	Player();
	//deconstructor
	virtual ~Player();
	//update function
	virtual void update(double deltatime);

	//movement controller
	void movementController(double deltatime);

	//slash enemies
	void slash();
private:

	float speed;
};