#include "ExampleScene.h"

ExampleScene::ExampleScene() : Scene()
{
	//default value 
	texturePath = "";

	/*
	//just a idle entity
	pic->texturePath = "assets/INA.tga";
	this->addchild(pic);
	pic->size = Vector2(100, 100);
	pic->pos = placeCenter(pic);

	//entity with animations
	pic2->spitesheetPath = "assets/testSheet.tga";
	pic->addchild(pic2);
	pic2->size = Vector2(100, 100);
	pic2->pos = Vector2(128, 0);
	pic2->animator.rows = Vector2(4, 1);
	pic2->animator.animateFromTo = Vector2(0, 3);
	//pic2->animator.paused = true;
	*/
}

ExampleScene::~ExampleScene()
{

}

void ExampleScene::update(double deltatime)
{

}

