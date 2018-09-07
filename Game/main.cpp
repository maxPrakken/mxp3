#include <renderer.h>
#include <texture.h>
#include <SDL2\SDL.h>
#include <input.h>
#include "Demo/demo1.h"

#include "../MXP3/include/entity.h"
#include <sceneManager.h>

Input* Input::instance = NULL;

#undef main
int main(int argc, char *argv[])
{
	int curscene = 0;

	Audio::getInstance();

	//use this to create a scene
	SceneManager::getInstance()->addScene("Demo1", new Demo1());


	while (!Input::getInstance()->getMustQuit())
	{
		Input::getInstance()->update();
		SceneManager::getInstance()->currentScene->update(Renderer::getInstance()->getDeltatime());
		Renderer::getInstance()->renderScene(SceneManager::getInstance()->currentScene);

		//set the start scene here
		SceneManager::getInstance()->setCurrentScene("Demo1");

		Renderer::getInstance()->update();
	}
	return 0;
}
