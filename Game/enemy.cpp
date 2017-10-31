#include "enemy.h"

Enemy::Enemy() : Entity()
{
	spitesheetPath = "assets/testSheet.tga";

	animator.rows = Vector2(4, 1);
	animator.animateFromTo = Vector2(0, 3);

	health = 2;
}

Enemy::~Enemy()
{
	
}

void Enemy::update(double deltatime)
{
	
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
