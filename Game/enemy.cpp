#include "enemy.h"

Enemy::Enemy() : Entity()
{
	spitesheetPath = "assets/testSheet.tga";

	animator.rows = Vector2(4, 1);
	animator.animateFromTo = Vector2(0, 3);

	health = 2;

	dead = false;
	canWalk = true;
}

Enemy::~Enemy()
{
	
}

void Enemy::update(double deltatime)
{
	die(deltatime);
}

void Enemy::animationController(int i)
{
	switch (i) {
	
	//idle
	case 1:
		//animator.animateFromTo = Vector2(0, 0);
		break;
	
	//walking
	case 2:
		//animator.animateFromTo = Vector2(0, 0);
		break;

	//hitting
	case 3:
		//animator.animateFromTo = Vector2(0, 0);
		break;
	}
}

int Enemy::die(double deltatime)
{
	if (rot >= -90 && dead) {
		rot -= 200 * deltatime;
		canWalk = false;
		return 1;
	}
	else {
		canWalk = true;
		return 0;
	}
	return 2;
}
