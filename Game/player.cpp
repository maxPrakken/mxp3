#include "player.h"

Player::Player() : Entity()
{
	spitesheetPath = "assets/testSheet.tga";

	animator.rows = Vector2(4, 1);
	animator.animateFromTo = Vector2(2, 3);
	pos = Vector2(200, 100);
	size = Vector2(50, 50);

	speed = 150;

	flip = SDL_FLIP_NONE;	/* example (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);*/

	sword = new Entity();
	sword->size = Vector2(50, 50);
	sword->spitesheetPath = "assets/swordAnim.tga";
	sword->animator.rows = Vector2(4, 1);
	sword->animator.paused = true;
	sword->animator.animateFromTo = Vector2(0, 3);
	sword->animator.switchAfter = 0.1f;
	addchild(sword);
	sword->pos = Vector2(25, 0);

	swordAnimCount = 0;
	swordAnimCan = false;

	hasSlashed = false;

	dead = false;
	health = 5;

	canUp = true;
	canDown = true;
	canRight = true;
	canLeft = true;
}

Player::~Player()
{
	delete sword;
}

void Player::update(double deltatime)
{
	Entity::update(deltatime);

	if (!dead) {
		movementController(deltatime);
		animationController();
		slash();
	}
	else { die(deltatime); }
}

void Player::movementController(double deltatime)
{
	if (canUp) {
		if (Input::getInstance()->getKey(SDLK_w)) {
			pos -= Vector2(0, speed) * deltatime;

			sword->flip = SDL_FLIP_NONE;
			sword->pos = Vector2(0, -25);
		}
	}

	if (canLeft) {
		if (Input::getInstance()->getKey(SDLK_a)) {
			pos -= Vector2(speed, 0) * deltatime;
			flip = SDL_FLIP_HORIZONTAL;

			sword->flip = SDL_FLIP_HORIZONTAL;
			sword->pos = Vector2(-25, 0);
		}
	}

	if (canDown) {
		if (Input::getInstance()->getKey(SDLK_s)) {
			pos += Vector2(0, speed) * deltatime;

			sword->flip = SDL_FLIP_NONE;
			sword->pos = Vector2(0, 25);
		}
	}

	if (canRight) {
		if (Input::getInstance()->getKey(SDLK_d)) {
			pos += Vector2(speed, 0) * deltatime;
			flip = SDL_FLIP_NONE;

			sword->flip = SDL_FLIP_NONE;
			sword->pos = Vector2(25, 0);
		}
	}
}

void Player::animationController()
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

void Player::slash()
{
	
	if (Input::getInstance()->getKeyDown(SDLK_SPACE)) {
		hasSlashed = true;
		Audio::getInstance()->playAudio("sword.wav");
		swordAnimCan = true;

	}
	else {
		hasSlashed = false;
	}	
}

int Player::die(double deltatime) {
	if (rot >= -90 && dead) {
		rot -= 200 * deltatime;
		return 1;
	}
	else {
		return 0;
	}
	return 2;
}
