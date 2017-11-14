#include "demo2.h"

Demo2::Demo2()
{
	background = new Background();
	addchild(background);

	buildPlatform(Vector2(300, 700));

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

	playerCheckGround();
	player->demo2MovementController(deltatime);
}

void Demo2::buildPlatform(Vector2 pos)
{
	Entity* platform = new Entity();
	platform->size = Vector2(100, 50);
	platform->pos = pos;
	platform->texturePath = "assets/stoneGrey.tga";
	addchild(platform);
	platformVector.push_back(platform);
}

void Demo2::playerCheckGround()
{
	std::vector<Entity*>::iterator it = platformVector.begin();
	while (it != platformVector.end()) {
		if ((*it)->isColliding(player)) {
			player->velocity = Vector2(0, 0);
			player->grounded = true;
		}
		else {
			player->grounded = false;
		}
		it++;
	}
}
