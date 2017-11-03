#pragma once

#include "../MXP3/include/entity.h"

class Background : public Entity {
public:
	Background();
	virtual ~Background();
	virtual void update(double deltatime);

	void buildBackground();
	void spawnTile();

	Vector2 grid;
	Vector2 spawnPos;
	int startX;

	std::vector<Entity*>tileVector;

private:

};