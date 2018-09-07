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
	
	int health;

	bool dead;
	bool canWalk;

	bool getHasSlashed() { return hasSlashed; }
	
	bool swordAnimCan;

	Entity* sword;
	Vector2 direction;

private:
	//animation controller
	void animationController();

	int die(double deltatime);

	int swordAnimCount;

	bool hasSlashed;


};