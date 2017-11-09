#include "demo2.h"

Demo2::Demo2()
{
	background = new Background();
	addchild(background);
}

Demo2::~Demo2()
{
	delete background;
}

void Demo2::update(double deltatime)
{
}
