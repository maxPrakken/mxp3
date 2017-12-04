#include "NHTVScene.h"

NHTVScene::NHTVScene() : Scene()
{
	
	background = new Grid(Vector2(12, 8), "assets/test.png", Vector2(100, 100));
	background->pos = Vector2(-100, 0);
	addchild(background);

	player = new NHTVPlayer();
}

NHTVScene::~NHTVScene()
{

}

void NHTVScene::update(double deltatime)
{
	Scene::update(deltatime);
}
