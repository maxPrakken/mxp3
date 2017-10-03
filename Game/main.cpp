#include <renderer.h>
#include <texture.h>
#include <SDL2\SDL.h>
#include <input.h>
#include <scene.h>

#include "../MXP3/include/entity.h"

Input* Input::instance = NULL;

#undef main
int main(int argc, char *argv[])
{
	Scene* scene = new Scene(Renderer::getInstance()->getRenderer());

	while (!Input::MustQuit())
	{
		Input::Update();
		//this->addchild(myEntity);
		scene->update(Renderer::getInstance()->getDeltatime());
		Renderer::getInstance()->renderScene(scene);
		Renderer::getInstance()->update();

	}
	return 0;
}