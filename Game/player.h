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

	//animation controller
	void animationController();

	//slash enemies
	void slash();

	//return hasSlashed bool
	bool getHasSlashed() { return hasSlashed; }

	int health;

	int swordAnimCount;
	bool swordAnimCan;

	Entity* sword;

private:
	bool hasSlashed;

	float speed;
};
