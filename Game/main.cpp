#include <renderer.h>
#include <texture.h>
#include <SDL2\SDL.h>
#include <input.h>
Input* Input::instance = NULL;

#undef main
int main(int argc, char *argv[])
{
	Texture* texture = new Texture("assets/pepe.png");
	while (!Input::MustQuit())
	{
		Input::Update();
		Renderer::getInstance()->showTexture(texture->tex);
		Renderer::getInstance()->update();
	}
	return 0;
}