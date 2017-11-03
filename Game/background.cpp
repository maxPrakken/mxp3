#include "background.h"

Background::Background() : Entity()
{
	grid = Vector2(8, 8);
	spawnPos = Vector2(200, 0);
	startX = spawnPos.x;

	buildBackground();
}

Background::~Background()
{

}

void Background::update(double deltatime)
{
	Entity::update(deltatime);

}

void Background::buildBackground()
{
	for (int i = 0; i < grid.x * grid.y; i++) {
		spawnTile();
	}
}

void Background::spawnTile()
{
	Entity* tile = new Entity();
	tile->texturePath = "assets/cobblestone.tga";
	tile->size = Vector2(100, 100);
	addchild(tile);
	tileVector.push_back(tile);
	tile->pos = spawnPos;
	if (spawnPos.x <= grid.x * tile->size.x) {
		spawnPos += Vector2(tile->size.x, 0);
		std::cout << spawnPos.x << " " << spawnPos.y << std::endl;

	}
	else if(spawnPos.x > grid.x * tile->size.x) {
		//HIER 
		spawnPos.x = startX;
		spawnPos.y += tile->size.y;
		std::cout << spawnPos.x << " " << spawnPos.y << std::endl;
	}
	
	
}
