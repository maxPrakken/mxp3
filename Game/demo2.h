#pragma once

#include "../MXP3/include/scene.h"
#include "background.h"

class Demo2 : public Scene {
public:
	Demo2();
	virtual ~Demo2();

	virtual void update(double deltatime);


private:
	Background* background;
};