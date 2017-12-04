#pragma once

#include "../MXP3/include/entity.h"

class EnemyGun : public Entity {

public:

	//default constructor
	EnemyGun();
	//default deconstructor
	virtual ~EnemyGun();
	//update function
	virtual void update(double deltatime);

	void shoot();

	int health;

	Vector2 direction;

private:

	std::vector<Entity*>bullets;
};