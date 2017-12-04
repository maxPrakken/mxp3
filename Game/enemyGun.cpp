#include "enemyGun.h"

EnemyGun::EnemyGun()
{
	health = 3;
	direction = Vector2(0, 0);

}

EnemyGun::~EnemyGun()
{

}

void EnemyGun::update(double deltatime)
{
	Entity::update(deltatime);


}

void EnemyGun::shoot()
{
	Entity* bullet = new Entity();
	bullet->texturePath = "assets/INA.tga";
	bullet->size = Vector2(50, 25);

}
