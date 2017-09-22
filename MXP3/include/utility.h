#pragma once

#include "vector2.h"
#include <SDL2\SDL.h>
namespace util
{
	SDL_Rect vector2ToSDL_Rect(Vector2 pos, Vector2 size)
	{
		SDL_Rect r;
		if (&pos != NULL) {
			r.x = pos.x;
			r.y = pos.y;
		}
		if (&size != NULL) {
			r.h = size.y;
			r.w = size.x;
		}
		return r;
	}
}