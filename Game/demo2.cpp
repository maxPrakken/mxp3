#include "demo2.h"

Demo2::Demo2()
{
	background = new Background();
	addchild(background);

	player = new Player();
	player->pos = Vector2(200, 100);
	addchild(player);

	buildPlatform(200, 200, 2, 1);
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

void Demo2::buildPlatform(int posx, int posy, int gridx, int gridy)
{
	Background* platform = new Background(Vector2(gridx, gridy), "assets/stoneGrey.tga");
	platformVector.push_back(platform);
	platform->pos = Vector2(posx, posy);
	addchild(platform);
}
