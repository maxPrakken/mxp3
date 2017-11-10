#pragma once

#include "../MXP3/include/scene.h"
#include "background.h"
#include "player.h"

class Demo2 : public Scene {
public:
	Demo2();
	virtual ~Demo2();

	virtual void update(double deltatime);


private:
	void buildPlatform(int posx, int posy, int gridx, int gridy);

	std::vector<Background*>platformVector;

	Player* player;

	Background* background;

	Entity* wallLeft;
	Entity* wallRight;
	Entity* wallTop;
	Entity* wallDown;
};