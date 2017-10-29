#include "myScene.h"

MyScene::MyScene() : Scene()
{
	std::cout << "===NEW SCENE===" << std::endl;

	//default value 
	texturePath = "";


	/*
	pic->texturePath = "assets/INA.tga";
	this->addchild(pic);
	pic->size = Vector2(100, 100);
	pic->pos = placeCenter(pic);

	pic2->spitesheetPath = "assets/testSheet.tga";
	pic->addchild(pic2);
	pic2->size = Vector2(100, 100);
	pic2->pos = Vector2(128, 0);
	pic2->animator.rows = Vector2(4, 1);
	pic2->animator.animateFromTo = Vector2(0, 3);
	//pic2->animator.paused = true;
	*/
}

MyScene::~MyScene()
{

}

void MyScene::update(double deltatime)
{
	Scene::update(deltatime);

	movement(deltatime);
	audioController();
}

void MyScene::movement(double deltatime)
{

}

void MyScene::audioController()
{
	
}
