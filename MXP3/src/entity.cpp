#include "..\include\entity.h"

int Entity::_nextGuid = 0;

Entity::Entity(SDL_Renderer* renderer)
{
	_guid = _nextGuid;
	_nextGuid++;
	this->_parent = NULL;
	myTex = new Texture();
}

Entity::~Entity()
{
	delete myTex;
}

void Entity::update(float deltatime)
{

}

void Entity::addchild(Entity* child)
{
	if (child->_parent != NULL) {
		child->_parent->removechild(child);
	} 
	if (child->_parent == this) {
		return;
	}
	child->_parent = this;
	this->childrenVec.push_back(child);
	//Renderer::getInstance()->showTexture(myTex->tex);
}

void Entity::removechild(Entity * child)
{
	std::vector< Entity* >::iterator it = childrenVec.begin();
	while (it != childrenVec.end()) {
		if ((*it)->_guid == child->_guid) {
			it = childrenVec.erase(it);
			return;
		}
		else {
			++it;
		}
	}
}
