#include "..\include\scene.h"


Scene::Scene(SDL_Renderer * renderer) : Entity(renderer)
{
}

Scene::~Scene()
{
}

void Scene::update(float deltatime)
{
	std::vector<Entity*>::iterator it = childrenVec.begin();
	while (it != childrenVec.end())
	{
		(*it)->update(deltatime);
	}
}
