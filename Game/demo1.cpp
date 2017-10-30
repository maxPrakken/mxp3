#include "demo1.h"

Demo1::Demo1() : Scene()
{
	std::cout << "===NEW SCENE===" << std::endl;

	//default value 
	texturePath = "";

	pic = new Entity();
	pic2 = new Entity();

	test = new Enemy();
	addchild(test);

	player = new Player();
	addchild(player);
	 
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
	
}

Demo1::~Demo1()
{
	delete pic;
	delete pic2;
	delete test;
}

void Demo1::update(double deltatime)
{
	Scene::update(deltatime);

	//movement(deltatime);
	//audioController();
}

void Demo1::movement(double deltatime)
{

}

void Demo1::audioController()
{

}
