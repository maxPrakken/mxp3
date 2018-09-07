#include "demo1.h"

Demo1::Demo1() : Scene()
{
	std::cout << "===DEMO1===" << std::endl;
	//default value 
	texturePath = "";

	//background needs to be divined up top
	background = new Grid(Vector2(8, 8), "assets/cobblestone.png", Vector2(100, 100));
	addchild(background);
	background->pos = Vector2(100, 0);
	background->tileTexture = "assets/cobblestone.png";

	spawnEnemy(Vector2(600, 600));
	spawnEnemy(Vector2(500, 500));

	player = new Player();
	addchild(player);
	player->rot = 0;

	//spawns hearts that resemble your health
	hearts = new Entity();
	hearts->pos = Vector2(100, 100);
	hearts->size = Vector2(100, 400);
	hearts->spitesheetPath = "assets/hearts.png";
	hearts->animator.rows = Vector2(4, 1);
	hearts->animator.paused = true;
	hearts->animator.cur = 0;
	addchild(hearts);

	finishDoor = new Entity();
	finishDoor->texturePath = "assets/INA.png";
	finishDoor->size = Vector2(50, 100);
	finishDoor->pos = Vector2(-200, -200);
	addchild(finishDoor);

	spawnWalls();

	enemyHitTimer = 0;
	enemyHitTimerCheck = false;
	hitAfter = 2.0f;

	enemiesAlive = enemyList.size();
	
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

	if (!player->dead) {

		if (player->getChildren() == NULL) {
			player->addchild(player->sword);
		}

		if (enemyHitTimerCheck) { enemyHitTimer += deltatime; }
		AI(deltatime);
		hitEnemy();
		enemyDie();
		audioController();
		heartController();
		goToNextLevel();
		wallCollisionCheck();
		if(!player->dead) { player->demo1MovementController(deltatime); }
	}
	else {
		
	}
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
					enemiesAlive--;
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

void Demo1::heartController()
{
	if (player->health == 5) {
		hearts->animator.cur = 0;
	}
	else if (player->health == 4) {
		hearts->animator.cur = 1;
	}
	else if (player->health == 3) {
		hearts->animator.cur = 2;
	}
	else if (player->health == 2 || player->health == 1) {
		hearts->animator.cur = 3;
	}
	else if(player->health <= 0) {
		hearts->animator.cur = 4;
	}
}

void Demo1::goToNextLevel()
{
	if (enemiesAlive <= 0) {
		finishDoor->pos = Vector2(800, 200);
		if (player->isColliding(finishDoor)) {
			std::cout << "you won!" << std::endl;
		}
	}
}

void Demo1::spawnWalls()
{
		wallLeft = new Entity();
		wallRight = new Entity();
		wallTop = new Entity();
		wallDown = new Entity();

		wallLeft->size = Vector2(2, 800);
		wallRight->size = Vector2(2, 800);
		wallTop->size = Vector2(800, 2);
		wallDown->size = Vector2(800, 2);

		wallLeft->pos = Vector2(180, 400);
		wallRight->pos = Vector2(975, 400);
		wallTop->pos = Vector2(600, -20);
		wallDown->pos = Vector2(600, 775);

		addchild(wallLeft);
		addchild(wallRight);
		addchild(wallTop);
		addchild(wallDown);

		wallVector.push_back(wallLeft);
		wallVector.push_back(wallRight);
		wallVector.push_back(wallTop);
		wallVector.push_back(wallDown);
}

void Demo1::wallCollisionCheck()
{
	if (player->isColliding(wallLeft)) {
		player->canLeft = false;
	}else { player->canLeft = true; }

	if (player->isColliding(wallRight)) {
		player->canRight = false;
	}else { player->canRight = true; }

	if (player->isColliding(wallTop)) {
		player->canUp = false;
	}else { player->canUp = true; }

	if (player->isColliding(wallDown)) {
		player->canDown = false;
	}else { player->canDown = true; }
}
