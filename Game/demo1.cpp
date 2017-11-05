#include "demo1.h"

Demo1::Demo1() : Scene()
{
	//test comment (remove)

	std::cout << "===NEW SCENE===" << std::endl;

	//default value 
	texturePath = "";

	//background needs to be divined up top
	background = new Background();
	//background->texturePath = "assets/INA.tga";
	std::cout << background->size.x << " " << background->size.y << std::endl;
	addchild(background);
	background->pos = Vector2(0, 0);

	//spawnEnemy(Vector2(300, 300));
	spawnEnemy(Vector2(500, 500));

	player = new Player();
	addchild(player);
	player->rot = 0;

	enemyHitTimer = 0;
	enemyHitTimerCheck = false;
	hitAfter = 2.0f;
	
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

	if(enemyHitTimerCheck){ enemyHitTimer += deltatime; }

	hitEnemy();
	AI(deltatime);
	enemyDie();
	audioController();
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
	std::vector<Enemy*>::iterator it = enemyList.begin();
	while (it != enemyList.end()) {

		//movement towards the player

		if ((*it)->canWalk) {
			(*it)->direction = player->pos - (*it)->pos;
			(*it)->direction.normalize();
			(*it)->direction *= 100.0f * deltatime;
			//std::cout << (*it)->direction.x << " " << (*it)->direction.y << std::endl;
			if ((*it)->distanceTo(player) < 400.0f) {
				(*it)->pos += (*it)->direction;
			}
		}


		//enemy hit controller
		if ((*it)->sword->isColliding(player)) {

			enemyHitTimerCheck = true;

			if (enemyHitTimer > hitAfter) {
				enemyHitTimer = fmod(enemyHitTimer, hitAfter);

				(*it)->swordAnimCan = true;
				player->health--;

				Audio::getInstance()->playAudio("sword.wav");

				std::cout << player->health << std::endl;

				if (player->health <= 0) {
					player->dead = true;
				}
			}
		}
		else { enemyHitTimerCheck = false; }
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

