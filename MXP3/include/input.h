#pragma once

#include <SDL2\SDL.h>

class __declspec(dllexport) Input {
public:
	static Input* getInstance();
	static void Update();
	static void Destroy() { delete instance; }
	static bool MustQuit();
private:
	static Input* instance;
	//functions
	void _update();

	//variables
	bool mustQuit;
	Input();
	~Input();
};