#include <renderer.h>
#include <texture.h>
#include <SDL2\SDL.h>
#include <input.h>

#include "../MXP3/include/entity.h"

Input* Input::instance = NULL;

#undef main
int main(int argc, char *argv[])
{
	Entity* scene = new Entity(Renderer::getInstance()->getRenderer());
	while (!Input::MustQuit())
	{
		Input::Update();
		//this->addchild(myEntity);
		Renderer::getInstance()->renderScene(scene);
		Renderer::getInstance()->update();

	}
	return 0;
}