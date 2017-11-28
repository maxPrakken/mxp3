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
	Vector2 spawnPos2;

private:
	void buildBackground();
	void buildBackground(Vector2 tilesize);
	void spawnTile();
	void spawnTile(Vector2 tilesize);

	int startX;
	int startX2;

	std::vector<Entity*>tileVector;
};