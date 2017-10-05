#include "myScene.h"

MyScene::MyScene() : Scene()
{
	std::cout << "===NEW SCENE===" << std::endl;

	texturePath = "";
	pic = new Entity();

	pic2 = new Entity();
	pic2->texturePath = "assets/INA.tga";
	this->addchild(pic2);
	pic2->scale = new Vector2(100, 100);
	pic2->pos = new Vector2(400, 0);

	pic->texturePath = "assets/INA.tga";
	this->addchild(pic);
	pic->scale = new Vector2(100, 100);
	pic->pos = placeCenter(pic);
}

MyScene::~MyScene()
{
	delete pic;
}

void MyScene::update(double deltatime)
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
}
