#include "demo1.h"

Demo1::Demo1() : Scene()
{
	std::cout << "===NEW SCENE===" << std::endl;

	//default value 
	texturePath = "";

	spawnEnemy(Vector2(300, 300));
	spawnEnemy(Vector2(500, 500));

	player = new Player();
	addchild(player);
	player->rot = 0;

	/*
	pic2->spitesheetPath = "assets/testSheet.tga";
	pic->addchild(pic2);
	pic2->size = Vector2(100, 100);
	pic2->pos = Vector2(128, 0);
	pic2->animator.rows = Vector2(4, 1);
	pic2->animator.animateFromTo = Vector2(0, 3);
	*/
}

Demo1::~Demo1()
{
	for (unsigned int i = 0; i < enemyList.size(); i++) {
		removechild(enemyList[i]);
		delete enemyList[i];
	}
	enemyList.clear();
}

void Demo1::update(double deltatime)
{
	Scene::update(deltatime);

	hitEnemy();
	std::cout << player->rot << std::endl;
}

void Demo1::audioController()
{

}

void Demo1::hitEnemy()
{
	if (player->getHasSlashed()) {
		std::vector<Enemy*>::iterator it = enemyList.begin();
		while (it != enemyList.end()) {
			if (player->sword->isColliding((*it))) {
				(*it)->health--;
				if ((*it)->health == 0) {
					removechild((*it));
				}
			}
			it++;
		}
	}
}

void Demo1::enemyHitPlayer()
{

}

void Demo1::spawnEnemy(Vector2 position)
{
	Enemy* enemy = new Enemy();
	enemyList.push_back(enemy);
	addchild(enemy);
	enemy->pos = position;
}

