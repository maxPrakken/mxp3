#include "enemy.h"

Enemy::Enemy() : Entity()
{
	spitesheetPath = "assets/enemyAnim.png";

	size = Vector2(50, 50);

	animator.rows = Vector2(15, 1);
	animator.animateFromTo = Vector2(5, 6);

	health = 3;

	dead = false;
	canWalk = true;

	direction = Vector2(0, 0);

	sword = new Entity();
	sword->spitesheetPath = "assets/swordAnim.png";
	sword->size = Vector2(100, 100);
	sword->animator.rows = Vector2(6, 1);
	sword->animator.paused = true;
	sword->animator.cur = 0;
	sword->animator.animateFromTo = Vector2(0, 5);
	sword->animator.switchAfter = 0.1f;
	addchild(sword);
	sword->pos = direction;
	
	swordAnimCount = 0;
	swordAnimCan = false;
}

Enemy::~Enemy()
{
	delete sword;
}

void Enemy::update(double deltatime)
{
	Entity::update(deltatime);

	sword->pos = direction *= 7;

	die(deltatime);
	animationController();
}

void Enemy::animationController()
{
	if (swordAnimCan) {
		sword->animator.paused = false;
		if (sword->animator.cur >= 5) {
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
