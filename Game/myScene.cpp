#include "myScene.h"

MyScene::MyScene() : Scene()
{
	std::cout << "===NEW SCENE===" << std::endl;

	texturePath = "";

	pic = new Entity();
	pic2 = new Entity();

	pic->texturePath = "assets/INA.tga";
	this->addchild(pic);
	pic->size = Vector2(100, 100);
	pic->pos = placeCenter(pic);

	pic2->spitesheetPath = "assets/testSheet.tga";
	pic->addchild(pic2);
	pic2->size = Vector2(100, 100);
	pic2->pos = Vector2(128, 0);
	pic2->animator.rows = Vector2(4, 1);
	pic2->animator.animateFromTo = Vector2(2, 4);
	//pic2->animator.paused = true;
}

MyScene::~MyScene()
{
	delete pic;
	delete pic2;
}

void MyScene::update(double deltatime)
{
	//checks if entity is colliding with other entity
	if (pic->isColliding(pic2)) {
		std::cout << "colliding" << std::endl;
	}

	movement(deltatime);
	audioController();
}

void MyScene::movement(double deltatime)
{
	//player movement, to be taken out soon
	//============================================
	if (Input::getInstance()->getKey(SDLK_w)) {
		pic->pos -= Vector2(0, 100) * deltatime;
	}
	if (Input::getInstance()->getKey(SDLK_a)) {
		pic->pos -= Vector2(100, 0) * deltatime;
	}
	if (Input::getInstance()->getKey(SDLK_s)) {
		pic->pos += Vector2(0, 100) * deltatime;
	}
	if (Input::getInstance()->getKey(SDLK_d)) {
		pic->pos += Vector2(100, 0) * deltatime;
	}
	//============================================
}

void MyScene::audioController()
{
	//===========================================
	//sound testing

	//play audio
	if (Input::getInstance()->getKeyDown(SDLK_o))
	{
		Audio::getInstance()->playAudio("test3.wav");
	}

	//pause audio
	if (Input::getInstance()->getKeyDown(SDLK_p))
	{
		Audio::getInstance()->pauseAudio();
		//Audio::getInstance()->pauseAudio(0);
	}
	//resume audio
	if (Input::getInstance()->getKeyDown(SDLK_l))
	{
		Audio::getInstance()->resumeAudio();
	}
	//============================================
}
