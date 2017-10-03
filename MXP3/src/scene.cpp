#include "..\include\scene.h"


Scene::Scene(SDL_Renderer * renderer) : Entity(renderer)
{
	pic = new Entity(Renderer::getInstance()->getRenderer());
	pic->myTex = new Texture(Renderer::getInstance()->getRenderer(), "assets/INA.tga");

	this->addchild(pic);
	pic->pos = new Vector2(200, 300);
}

Scene::~Scene()
{
}

void Scene::update(double deltatime)
{
	if (Input::getInstance()->getKey(SDLK_w)) {
		(*pic->pos) -= Vector2(0, 100) * deltatime; 
	}

	updateChildren(deltatime);
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
