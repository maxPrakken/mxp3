#include "..\include\entity.h"

int Entity::_nextGuid = 0;

Entity::Entity()
{
	_guid = _nextGuid;
	_nextGuid++;
	_parent = NULL;
	texturePath = "";
	spitesheetPath = "";

	animator = Animator();
	pos = Vector2(0, 0);
	size = Vector2(100, 100);
}

Entity::~Entity()
{
	delete _parent;
}

void Entity::update(double deltatime)
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

Vector2 Entity::getParentPosition()
{
	if (_parent == NULL) {
		return pos;
	}
	else {
		return pos + _parent->pos;
	}
}

bool Entity::isColliding(Entity* other) {
	float dx = this->pos.x - other->pos.x;
	float dy = this->pos.y - other->pos.y;

	if ((abs(dx) * 2.0f < (size.x + other->size.x)) &&
		(abs(dy) * 2.0f < (size.y + other->size.y)))
	{
		return true;
	}
	return false;	
}

