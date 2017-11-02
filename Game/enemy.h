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

	int die(double deltatime);

	int health;

	bool dead;
	bool canWalk;

	int swordAnimCount;
	bool swordAnimCan;

	bool getHasSlashed() { return hasSlashed; }
	

	Vector2 direction;

	Entity* sword;

private:
	bool hasSlashed;
};