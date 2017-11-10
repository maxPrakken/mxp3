#include "demo2.h"

Demo2::Demo2()
{
	background = new Background();
	addchild(background);

	player = new Player();
	player->pos = Vector2(200, 100);
	addchild(player);
}

Demo2::~Demo2()
{
	delete background;
}

void Demo2::update(double deltatime)
{
	Scene::update(deltatime);

	if (player->getChildren() != NULL) {
		player->removechild(player->sword);
	}

	player->demo2MovementController(deltatime);
}

void Demo2::wallCollisionCheck()
{
	if (player->isColliding(wallLeft)) {
		player->canLeft = false;
	}
	else { player->canLeft = true; }

	if (player->isColliding(wallRight)) {
		player->canRight = false;
	}
	else { player->canRight = true; }

	if (player->isColliding(wallTop)) {
		player->canUp = false;
	}
	else { player->canUp = true; }

	if (player->isColliding(wallDown)) {
		player->canDown = false;
	}
	else { player->canDown = true; }
}
