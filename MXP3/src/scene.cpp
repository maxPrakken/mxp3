#include "../include/scene.h"


Scene::Scene(SDL_Renderer * renderer) : Entity(renderer)
{
	pic = new Entity(Renderer::getInstance()->getRenderer());

	pic2 = new Entity(Renderer::getInstance()->getRenderer());
	pic2->myTex = new Texture(Renderer::getInstance()->getRenderer(), "assets/INA.tga");
	this->addchild(pic2);
	pic2->scale = new Vector2(100, 100);
	pic2->pos = new Vector2(400, 0);

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
	//checks if entity is colliding with other entity
	if (pic->isColliding(pic2)) {
		std::cout << "colliding" << std::endl;
	}

	//player movement, to be taken out soon
	//============================================
	if (Input::getInstance()->getKey(SDLK_w)) {
		(*pic->pos) -= Vector2(0, 100) * deltatime; 
	}
	if (Input::getInstance()->getKey(SDLK_a)) {
		(*pic->pos) -= Vector2(100, 0) * deltatime;
	}
	if (Input::getInstance()->getKey(SDLK_s)) {
		(*pic->pos) += Vector2(0, 100) * deltatime;
	}
	if (Input::getInstance()->getKey(SDLK_d)) {
		(*pic->pos) += Vector2(100, 0) * deltatime;
	}
	//============================================

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
