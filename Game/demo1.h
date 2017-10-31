#pragma once

#include "../MXP3/include/scene.h"

#include "enemy.h"
#include "player.h"

class Demo1 : public Scene{

public:
	//constructor 
	Demo1();
	//deconstructor
	virtual ~Demo1();
	//update function
	virtual void update(double deltatime);

	Player* player;

	void audioController();

	void hitEnemy();

	void AI(double deltatime);

	void spawnEnemy(Vector2 position);

	std::vector<Enemy*>enemyList;

private:
	
};
