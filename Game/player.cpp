#include "player.h"

Player::Player() : Entity()
{
	spitesheetPath = "assets/playerAnim.tga";

	animator.rows = Vector2(15, 1);
	animator.animateFromTo = Vector2(5, 6);
	pos = Vector2(200, 100);
	size = Vector2(50, 100);
	velocity = Vector2(0, 0);

	gravity = Vector2(0, 500);

	velocity += gravity;

	grounded = false;

	speed = 150;

	flip = SDL_FLIP_NONE;	/* example (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);*/

	sword = new Entity();
	sword->size = Vector2(100, 100);
	sword->spitesheetPath = "assets/swordAnim.tga";
	sword->animator.rows = Vector2(6, 1);
	sword->animator.paused = true;
	sword->animator.animateFromTo = Vector2(0, 5);
	sword->animator.switchAfter = 0.1f;
	addchild(sword);
	sword->pos = Vector2(25, -50);

	swordAnimCount = 0;
	swordAnimCan = false;

	swordTimer = 0;

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
		swordTimer += deltatime;
	}
	else { die(deltatime); }
}

void Player::demo1MovementController(double deltatime)
{
	animationController();
	slash();

	if (canUp) {
		if (Input::getInstance()->getKey(SDLK_w)) {
			pos -= Vector2(0, speed) * deltatime;
			animator.cur = 0;
			animator.animateFromTo = Vector2(0, 4);

			sword->flip = SDL_FLIP_NONE;
			sword->pos = Vector2(0, -75);
		}
	}

	if (canLeft) {
		if (Input::getInstance()->getKey(SDLK_a)) {
			pos -= Vector2(speed, 0) * deltatime;
			flip = SDL_FLIP_HORIZONTAL;
			animator.animateFromTo = Vector2(10, 14);

			sword->flip = SDL_FLIP_HORIZONTAL;
			sword->pos = Vector2(-75, -25);
		}
	}

	if (canDown) {
		if (Input::getInstance()->getKey(SDLK_s)) {
			pos += Vector2(0, speed) * deltatime;
			animator.cur = 5;
			animator.animateFromTo = Vector2(5, 9);

			sword->flip = SDL_FLIP_VERTICAL;
			sword->pos = Vector2(0, 25);
		}
	}

	if (canRight) {
		if (Input::getInstance()->getKey(SDLK_d)) {
			pos += Vector2(speed, 0) * deltatime;
			flip = SDL_FLIP_NONE;
			animator.animateFromTo = Vector2(10, 14);

			sword->flip = SDL_FLIP_NONE;
			sword->pos = Vector2(25, -25);
		}
	}
}

void Player::demo2MovementController(double deltatime)
{
	if (velocity.y < 500 && !grounded) {
		velocity += gravity * deltatime;
	}

	if (Input::getInstance()->getKey(SDLK_a)) {
		pos -= Vector2(speed, 0) * deltatime;
		flip = SDL_FLIP_HORIZONTAL;
		animator.animateFromTo = Vector2(10, 14);
	}

	if (Input::getInstance()->getKey(SDLK_d)) {
		pos += Vector2(speed, 0) * deltatime;
		flip = SDL_FLIP_NONE;
		animator.animateFromTo = Vector2(10, 14);
	}

	if (Input::getInstance()->getKeyDown(SDLK_SPACE) && grounded) {
		velocity = Vector2(0, -500);
	}

	pos += velocity * deltatime;
}

void Player::animationController()
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

void Player::slash()
{

	if (Input::getInstance()->getKeyDown(SDLK_SPACE) && swordTimer >= 1.0) {
		hasSlashed = true;
		Audio::getInstance()->playAudio("sword.wav");
		swordAnimCan = true;
		swordTimer = 0;
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
