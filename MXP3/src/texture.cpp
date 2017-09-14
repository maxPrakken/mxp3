#include "..\include\texture.h"

Texture::Texture()
{
}

Texture::Texture(std::string string)
{
	tex = loadTexture(string);
}

Texture::~Texture()
{
	SDL_DestroyTexture(tex);
}

SDL_Texture * Texture::loadTexture(std::string path)
{
	SDL_Surface* surf = IMG_Load(path.c_str());
	if (surf == NULL)
	{
		std::cout << "Could not load image: " << IMG_GetError() << std::endl;
		return NULL;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Renderer::getInstance()->getRenderer(),surf);
	SDL_FreeSurface(surf);
	std::cout << "Image loaded: " << path << std::endl;
	return tex;
}
