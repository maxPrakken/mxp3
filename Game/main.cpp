#include <renderer.h>
#include <texture.h>
#include <SDL2\SDL.h>
#include <input.h>
#include "demo1.h"
#include "demo2.h"
#include "demo3.h"

#include "../MXP3/include/entity.h"
#include <sceneManager.h>

Input* Input::instance = NULL;

#undef main
int main(int argc, char *argv[])
{

	Audio::getInstance();

	SceneManager::getInstance()->addScene("FirstDemo", new Demo1());
	SceneManager::getInstance()->addScene("SecondDemo", new Demo2());
	SceneManager::getInstance()->addScene("ThirdDemo", new Demo3());

	while (!Input::getInstance()->getMustQuit())
	{
		Input::getInstance()->update();
		SceneManager::getInstance()->currentScene->update(Renderer::getInstance()->getDeltatime());
		Renderer::getInstance()->renderScene(SceneManager::getInstance()->currentScene);

		if (Input::getInstance()->getKeyDown(SDLK_RIGHTBRACKET) && SceneManager::getInstance()->currentScene == SceneManager::getInstance()->getScene("FirstDemo"))
		{
			SceneManager::getInstance()->setCurrentScene("SecondDemo");
		}
		else if (Input::getInstance()->getKeyDown(SDLK_RIGHTBRACKET) && SceneManager::getInstance()->currentScene == SceneManager::getInstance()->getScene("SecondDemo"))
		{
			SceneManager::getInstance()->setCurrentScene("ThirdDemo");
		}
		else if (Input::getInstance()->getKeyDown(SDLK_RIGHTBRACKET) && SceneManager::getInstance()->currentScene == SceneManager::getInstance()->getScene("ThirdDemo"))
		{
			SceneManager::getInstance()->setCurrentScene("FirstDemo");
		}

		Renderer::getInstance()->update();
	}
	return 0;
}
