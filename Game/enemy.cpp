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

void Enemy::animationController()
{

}

void Enemy::movementController()
{

}

void Enemy::hit()
{
}
