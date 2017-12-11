#include "NHTVPlayer.h"

NHTVPlayer::NHTVPlayer()
{
	texturePath = "assets/INA.png";

	grounded = false;

	speed = 100;

	velocity = Vector2(0, 0);
	gravity = Vector2(0, 100);
}

NHTVPlayer::~NHTVPlayer()
{

}

void NHTVPlayer::update(double deltatime)
{
	Entity::update(deltatime); 

	movement(deltatime);
	bulletRotDir();	
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
	Bullet* bullet = new Bullet();
	bullet->texturePath = "asssets/INA.png";
	//direction and rotations stuff here

	bullets.push_back(bullet);
	//addchild bullets to scene through bullets vector
}

void NHTVPlayer::deflect()
{

}

void NHTVPlayer::bulletRotDir()
{
	//do bullet rotation and direction here
}
