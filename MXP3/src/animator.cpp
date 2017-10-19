#include "..\include\animator.h"

Animator::Animator()
{
	rows = Vector2();
	textureToAnimate = NULL;
}

Animator::Animator(Texture* texture)
{
	textureToAnimate = texture;
	rows = Vector2(0, 0);
}

Animator::Animator(Texture* texture, Vector2 rows)
{
	textureToAnimate = texture;
	this->rows = rows;
}

Animator::~Animator()
{
}

SDL_Rect * Animator::getChuck(Vector2 position)
{
	Vector2 res = textureToAnimate->Resolution();
	float xPos = res.x / rows.x;
	float yPos = res.y / rows.y;

	SDL_Rect r;
	r.h = yPos;
	r.w = xPos;
	r.x = xPos * position.x;
	r.y = yPos * position.y;
	return nullptr;
}
