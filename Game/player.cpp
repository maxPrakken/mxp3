#include "player.h"

Player::Player() : Entity()
{
	spitesheetPath = "assets/testSheet.tga";

	animator.rows = Vector2(4, 1);
	animator.animateFromTo = Vector2(2, 3);
	pos = Vector2(100, 100);

	speed = 150;

	flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
}

Player::~Player()
{

}

void Player::update(double deltatime)
{
	movementController(deltatime);
	slash();
}

void Player::movementController(double deltatime)
{
	if (Input::getInstance()->getKey(SDLK_w)) {
		pos -= Vector2(0, speed) * deltatime;
	}
	if (Input::getInstance()->getKey(SDLK_a)) {
		pos -= Vector2(speed, 0) * deltatime;
	}
	if (Input::getInstance()->getKey(SDLK_s)) {
		pos += Vector2(0, speed) * deltatime;
	}
	if (Input::getInstance()->getKey(SDLK_d)) {
		pos += Vector2(speed, 0) * deltatime;
	}
}

void Player::slash()
{
	if (Input::getInstance()->getKeyDown(SDLK_SPACE)) {
		
	}
}
