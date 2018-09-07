#pragma once

#include <entity.h>

class Grid : public Entity {
public:
	Grid();
	Grid(Vector2 gridSize, std::string tiletexture);
	Grid(Vector2 gridSize, std::string tiletexture, Vector2 tilesize);
	virtual ~Grid();
	virtual void update(double deltatime);

	std::vector<Entity*> getTileVector() {return tileVector;}

	std::string tileTexture;

	Vector2 grid;
	Vector2 spawnPos;
	Vector2 spawnPos2;

private:
	void buildgrid();
	void buildgrid(Vector2 tilesize);
	void spawnTile();
	void spawnTile(Vector2 tilesize);

	int startX;
	int startX2;

	bool firstTile;

	std::vector<Entity*>tileVector;
};