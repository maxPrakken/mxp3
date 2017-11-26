#pragma once

#include "../MXP3/include/entity.h"

class Background : public Entity {
public:
	Background();
	Background(Vector2 gridSize, std::string tiletexture);
	Background(Vector2 gridSize, std::string tiletexture, Vector2 tilesize);
	virtual ~Background();
	virtual void update(double deltatime);

	std::vector<Entity*> getTileVector() {return tileVector;}

	std::string tileTexture;

	Vector2 grid;
	Vector2 spawnPos;

private:
	void buildBackground();
	void buildBackground(Vector2 tilesize);
	void spawnTile();
	void spawnTile(Vector2 tilesize);

	int startX;

	std::vector<Entity*>tileVector;
};