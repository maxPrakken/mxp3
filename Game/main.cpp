#include <renderer.h>
#include <input.h>
Input* Input::instance = NULL;

#undef main
int main(int argc, char *argv[])
{
	Renderer* r = new Renderer();

	while (!Input::MustQuit())
	{
		Input::Update();
		r->update();
	}

	delete r;
	return 0;
}