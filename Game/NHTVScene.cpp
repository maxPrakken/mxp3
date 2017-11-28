#include "NHTVScene.h"

NHTVScene::NHTVScene() : Scene()
{
	
	background = new Background(Vector2(2, 2), "assets/test.png", Vector2(200, 200));
	background->pos = Vector2(0, 0);
	addchild(background);


}

NHTVScene::~NHTVScene()
{

}

void NHTVScene::update(double deltatime)
{
	Scene::update(deltatime);
}
