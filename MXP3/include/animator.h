#pragma once

#include "texture.h"
#include <iostream>

#include <SDL2\SDL.h>

class Renderer;
class Texture;

class __declspec(dllexport) Animator {
public:
	//default constuctor
	Animator();
	//constructor that takes rows
	Animator(Vector2 rows);
	//deconstructor
	virtual ~Animator();
	//update function
	virtual void update(double deltatime);

	bool getStart();

	//vector 2 rows, determens in how many pieces a spritesheet is sliced
	Vector2 rows;

	//gets current chunk according to rows
	int getCurrentChunk();

	//start position of the animation
	int start;
	//current position of the animation
	int cur;
	//bool to check if the animation is paused
	bool paused;

	//timer to time when to switch chunk
	double timer;
	//deadline for timer, at this float time the timer will reset. 
	//this determenates how fast/slow the animation will play
	double switchAfter;

	//playanimtion function plays the actual animation
	int playAnimation(int start, int* current, int end);

	//vector 2 to set start and end of the animation
	Vector2 animateFromTo;
	//getchunk function for the renderer
	SDL_Rect getChuck(Vector2 position, Vector2 resolution);

private:
	//private int i to stay globaly scoped
	int i;
	
};