#pragma once 

#include "../MXP3/include/scene.h"

#include "enemy.h"
#include "player.h"
#include "grid.h"
#include "NHTVPlayer.h"

class NHTVScene : public Scene {
public:

	//constuctor
	NHTVScene();
	//deconstructor
	virtual ~NHTVScene();
	//update function
	virtual void update(double deltatime);

private:

	Grid* background;
	NHTVPlayer* player;
};