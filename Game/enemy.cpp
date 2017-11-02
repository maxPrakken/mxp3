#include "enemy.h"

Enemy::Enemy() : Entity()
{
	spitesheetPath = "assets/testSheet.tga";

	animator.rows = Vector2(4, 1);
	animator.animateFromTo = Vector2(0, 3);

	health = 2;

	dead = false;
	canWalk = true;

	direction = Vector2(0, 0);

	sword = new Entity();
	sword->spitesheetPath = "assets/swordAnim.tga";
	sword->animator.rows = Vector2(4, 1);
	sword->animator.paused = true;
	sword->animator.cur = 0;
	sword->animator.animateFromTo = Vector2(0, 3);
	sword->animator.switchAfter = 0.1f;
	addchild(sword);
	sword->pos = direction;
	
	swordAnimCount = 0;
	swordAnimCan = false;
}

Enemy::~Enemy()
{
	
}

void Enemy::update(double deltatime)
{
	Entity::update(deltatime);

	sword->pos = direction *= 15;

	die(deltatime);
	animationController();
}

void Enemy::animationController()
{
	if (swordAnimCan) {
		sword->animator.paused = false;
		if (sword->animator.cur >= 3) {
			swordAnimCan = false;
			sword->animator.paused = true;
			sword->animator.cur = 0;
		}
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
