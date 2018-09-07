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

	//movement controller demo1
	void demo1MovementController(double deltatime);
	//movement controller demo2
	void demo2MovementController(double deltatime);

	//return hasSlashed bool
	bool getHasSlashed() { return hasSlashed; }

	Vector2 getVelocity() { return velocity; }

	Vector2 getGravity() { return gravity; }

	int health;

	bool dead;

	bool canUp;
	bool canDown;
	bool canRight;
	bool canLeft;

	bool grounded;

	Entity* sword;
	Vector2 velocity;

private:
	//animation controller
	void animationController();

	//slash enemies
	void slash();

	//player dies
	int die(double deltatime);

	int swordAnimCount;
	bool swordAnimCan;

	bool hasSlashed;

	float speed;
	
	Vector2 gravity;

	double swordTimer;
};
