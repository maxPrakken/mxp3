#pragma once

#include "../MXP3/include/scene.h"

class ExampleScene : public Scene{

public:
	//constructor 
	ExampleScene();
	//deconstructor
	virtual ~ExampleScene();
	//update function
	virtual void update(double deltatime);

private:

};