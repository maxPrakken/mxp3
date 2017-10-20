#include "..\include\animator.h"

Animator::Animator()
{
	rows = Vector2();
	i = 0;
	paused = false;
}


Animator::Animator(Vector2 rows)
{
	this->rows;
}

Animator::~Animator()
{
}

void Animator::update(double deltatime)
{
	getCurrentChunk();
}

int Animator::getCurrentChunk()
{
	if (i != rows.x && !paused) {
		i++;
	}
	else if(i = rows.x && !paused) {
		i = 0;
	}
	else if (paused) {
		return i;
	}
	return i;
}

SDL_Rect Animator::getChuck(Vector2 position, Vector2 resolution)
{
	Vector2 res = resolution;
	float xPos = res.x / rows.x;
	float yPos = res.y / rows.y;

	SDL_Rect r;
	r.h = yPos;
	r.w = xPos;
	r.x = xPos * position.x;
	r.y = yPos * position.y;
	return r;
}
