#include "demo1.h"

Demo1::Demo1() : Scene()
{
	std::cout << "===NEW SCENE===" << std::endl;

	//default value 
	texturePath = "";

	//spawnEnemy(Vector2(300, 300));
	spawnEnemy(Vector2(500, 500));

	player = new Player();
	addchild(player);
	player->rot = 0;
}

Demo1::~Demo1()
{
	for (unsigned int i = 0; i < enemyList.size(); i++) {
		removechild(enemyList[i]);
		delete enemyList[i];
	}
	enemyList.clear();

	delete player;

}

void Demo1::update(double deltatime)
{
	Scene::update(deltatime);

	hitEnemy(deltatime);
	AI(deltatime);
	enemyDie();
}

void Demo1::audioController()
{

}

void Demo1::hitEnemy(double deltatime)
{
	if (player->getHasSlashed()) {
		std::vector<Enemy*>::iterator it = enemyList.begin();
		while (it != enemyList.end()) {
			if (player->sword->isColliding((*it))) {
				(*it)->health--;
				if ((*it)->health <= 0) {
					(*it)->dead = true;
					
					
				}
			}
			it++;
		}
	}
}

void Demo1::enemyDie()
{
	std::vector<Enemy*>::iterator it = enemyList.begin();
	while (it != enemyList.end()) {
		if ((*it)->rot <= -90 && (*it)->dead == true) {

			removechild((*it));
		}
		it++;
	}
}

void Demo1::AI(double deltatime)
{
	//movement towards the player

	std::vector<Enemy*>::iterator it = enemyList.begin();
	while (it != enemyList.end()) {
		if ((*it)->canWalk) {
			Vector2 direction;
			direction = player->pos - (*it)->pos;
			direction.normalize();
			direction *= 100.0f * deltatime;
			if ((*it)->distanceTo(player) < 400.0f) {
				(*it)->pos += direction;
			}
			//std::cout << (*it)->distanceTo(player) << std::endl;
		}
		it++;
	}
}


void Demo1::spawnEnemy(Vector2 position)
{
	Enemy* enemy = new Enemy();
	enemyList.push_back(enemy);
	addchild(enemy);
	enemy->pos = position;
}

