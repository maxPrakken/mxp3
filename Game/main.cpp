#include <renderer.h>
#include <texture.h>
#include <SDL2\SDL.h>
#include <input.h>
#include "myScene.h"

#include "../MXP3/include/entity.h"

Input* Input::instance = NULL;

#undef main
int main(int argc, char *argv[])
{
	Audio::getInstance();
	MyScene* scene = new MyScene();
	while (!Input::getInstance()->getMustQuit())
	{
		Input::getInstance()->update();
		scene->update(Renderer::getInstance()->getDeltatime());
		Renderer::getInstance()->renderScene(scene);
		Renderer::getInstance()->update();
	}
	return 0;
}
