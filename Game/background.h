#pragma once

#include "../MXP3/include/entity.h"

class Background : public Entity {
public:
	Background();
	virtual ~Background();
	virtual void update(double deltatime);

	Vector2 grid;
	Vector2 spawnPos;

private:
	void buildBackground();
	void spawnTile();

	int startX;

	std::vector<Entity*>tileVector;
};