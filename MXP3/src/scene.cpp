#include "../include/scene.h"


Scene::Scene() : Entity()
{
	texturePath = "";
}

Scene::~Scene()
{
	
}

void Scene::update(double deltatime)
{
	updateChildren(deltatime);
}

Vector2* Scene::placeCenter(Entity* entity)
{
	return new Vector2((Renderer::getInstance()->getResolution().x / 2) - (entity->scale->x / 2), (Renderer::getInstance()->getResolution().y / 2) - (entity->scale->x / 2));
}

void Scene::updateChildren(float deltatime)
{
	std::vector<Entity*>::iterator it = childrenVec.begin();
	while (it != childrenVec.end())
	{
		(*it)->update(deltatime);
		it++;
	}
}
