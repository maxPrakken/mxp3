#include "..\include\entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::addchild()
{
	Renderer::getInstance()->showTexture(myTex->tex);
}
