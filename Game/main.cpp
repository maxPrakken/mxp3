#include <renderer.h>
#include <texture.h>
#include <SDL2\SDL.h>
#include <input.h>

#include "../MXP3/include/entity.h"

Input* Input::instance = NULL;

#undef main
int main(int argc, char *argv[])
{
	Entity* myEntity = new Entity();
	myEntity->myTex = new Texture("assets/INA.tga");
	while (!Input::MustQuit())
	{
		Input::Update();
		myEntity->addchild();
		Renderer::getInstance()->update();
	}
	return 0;
}