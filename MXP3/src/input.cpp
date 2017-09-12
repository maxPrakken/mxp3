#include "..\include\input.h"

Input* Input::instance = NULL;

Input * Input::getInstance()
{
	if (instance == NULL)
	{
		instance = new Input();
	}
	return instance;
}

void Input::Update()
{
	Input::getInstance()->_update();
}

bool Input::MustQuit()
{
	return Input::getInstance()->mustQuit;
}

void Input::_update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			mustQuit = true;
			break;
		default:
			break;
		}
	}
}

Input::Input()
{
	mustQuit = false;
}

Input::~Input()
{
}
