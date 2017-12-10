#include "NHTVPlayer.h"

NHTVPlayer::NHTVPlayer()
{
	texturePath = "assets/INA.png";

	grounded = false;

	speed = 100;

	velocity = Vector2(0, 0);
	gravity = Vector2(0, 300);
}

NHTVPlayer::~NHTVPlayer()
{

}

void NHTVPlayer::update(double deltatime)
{
	Entity::update(deltatime); 

	movement(deltatime);
}

void NHTVPlayer::movement(double deltatime)
{
	if (velocity.y < 500 && !grounded) {
		velocity += gravity * deltatime;
	}

	if (Input::getInstance()->getKey(SDLK_a)) {
		pos -= Vector2(speed, 0) * deltatime;
	}

	if (Input::getInstance()->getKey(SDLK_d)) {
		pos += Vector2(speed, 0) * deltatime;
	}

	if (Input::getInstance()->getKeyDown(SDLK_SPACE) && grounded) {
		velocity = Vector2(0, -500);
	}

	pos += velocity * deltatime;
}

void NHTVPlayer::shoot()
{

}

void NHTVPlayer::deflect()
{

}
