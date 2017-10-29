#pragma once

#include "../MXP3/include/scene.h"

class Demo1 : public Scene{

public:
	//constructor 
	Demo1();
	//deconstructor
	virtual ~Demo1();
	//update function
	virtual void update(double deltatime);

	Entity* pic;
	Entity* pic2;

	void movement(double deltatime);
	void audioController();

private:

};