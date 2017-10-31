#include <renderer.h>
#include <texture.h>
#include <SDL2\SDL.h>
#include <input.h>
#include "demo1.h"

#include "../MXP3/include/entity.h"

Input* Input::instance = NULL;

#undef main
int main(int argc, char *argv[])
{
	Audio::getInstance();
	Demo1* demo1 = new Demo1();
	while (!Input::getInstance()->getMustQuit())
	{
		Input::getInstance()->update();
		demo1->update(Renderer::getInstance()->getDeltatime());
		Renderer::getInstance()->renderScene(demo1);
		Renderer::getInstance()->update();
	}
	return 0;
}
