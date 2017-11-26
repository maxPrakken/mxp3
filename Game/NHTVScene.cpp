#include "NHTVScene.h"

NHTVScene::NHTVScene() : Scene()
{
	background = new Background(Vector2(3, 2), "assets/stoneGrey.png", Vector2(100, 100));
	addchild(background);


}

NHTVScene::~NHTVScene()
{

}

void NHTVScene::update(double deltatime)
{
	Scene::update(deltatime);
}
