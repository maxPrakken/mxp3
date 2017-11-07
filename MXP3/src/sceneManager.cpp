#include "..\include\sceneManager.h"

SceneManager* SceneManager::instance = NULL;

SceneManager * SceneManager::getInstance()
{
	if (instance == NULL) {
		instance = new SceneManager();
	}
	return instance;
}

void SceneManager::update(double deltatime)
{

}

void SceneManager::addScene(std::string name, Scene * scene)
{
	if (sceneVector.find(name) == sceneVector.end())
	{
		sceneVector.emplace(name, scene);
		if (currentScene == NULL)
		{
			currentScene = scene;
		}
	}
}

Scene * SceneManager::getScene(std::string name)
{
	return sceneVector[name];
}

void SceneManager::DeleteScene(std::string name)
{
	if (sceneVector.find(name) != sceneVector.end())
	{
		Scene* scene = sceneVector[name];
		sceneVector.erase(name);
		delete scene;
		return;
	}
}

void SceneManager::setCurrentScene(std::string name)
{
	if (sceneVector.find(name) != sceneVector.end())
	{
		currentScene = sceneVector[name];
		return;
	}
	else
	{
		std::cout << "Scene Does not exist" << std::endl;
	}
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	std::map<std::string, Scene*>::iterator it = sceneVector.begin();
	while (it != sceneVector.end())
	{
		delete (*it).second;
		it++;
	}
	sceneVector.clear();
}
