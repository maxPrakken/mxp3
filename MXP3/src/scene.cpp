#include "../include/scene.h"


Scene::Scene(SDL_Renderer * renderer) : Entity(renderer)
{
	pic = new Entity(Renderer::getInstance()->getRenderer());

	pic->myTex = new Texture(Renderer::getInstance()->getRenderer(), "assets/INA.tga");
	this->addchild(pic);
	pic->scale = new Vector2(100, 100);
	pic->pos = placeCenter(pic);
}

Scene::~Scene()
{
	delete pic;
}

void Scene::update(double deltatime)
{
	if (Input::getInstance()->getKey(SDLK_w)) {
		(*pic->pos) -= Vector2(0, 100) * deltatime; 
	}

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
