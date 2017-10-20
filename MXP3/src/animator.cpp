#include "..\include\animator.h"

Animator::Animator()
{
	rows = Vector2();
	i = 0;
	cur = 1;
	paused = false;

	animateFromTo = Vector2(0, 0);
	start = animateFromTo.x;

	timer = 0;
	switchAfter = 0.5;
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
	timer += deltatime;
	getCurrentChunk();
}

int Animator::getCurrentChunk()
{
	if (i != rows.x && !paused) {
		i++;
	}
	else if (i == rows.x && !paused) {
		i = 0;
	}
	else if (paused) {
		return i;
	}
	return i;
}

int Animator::playAnimation(int start, int* current, int end)
{
	if (timer > switchAfter) {
		timer = fmod(timer, switchAfter);
		if ((*current) != end && !paused) {
			(*current)++;
		}
		else if ((*current) == end && !paused) {
			(*current) = start;
		}
		else if (paused) {
			return (*current);
		}
		return (*current);
	}
	return (*current);
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
