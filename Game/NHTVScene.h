#pragma once 

#include "../MXP3/include/scene.h"

#include "enemy.h"
#include "player.h"
#include "background.h"

class NHTVScene : public Scene {
public:

	//constuctor
	NHTVScene();
	//deconstructor
	virtual ~NHTVScene();
	//update function
	virtual void update(double deltatime);

private:

};