#pragma once

#include "../MXP3/include/scene.h"

#include "enemy.h"
#include "player.h"
#include "background.h"

class Demo1 : public Scene{

public:
	//constructor 
	Demo1();
	//deconstructor
	virtual ~Demo1();
	//update function
	virtual void update(double deltatime);

	Player* player;

	Entity* hearts;

	Background* background;

	void audioController();

	void hitEnemy();

	void enemyDie();

	void AI(double deltatime);

	void spawnEnemy(Vector2 position);

	void heartController();

	double enemyHitTimer;
	bool enemyHitTimerCheck;
	float hitAfter;

	std::vector<Enemy*>enemyList;

private:
	
};
