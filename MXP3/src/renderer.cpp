#include "../include/renderer.h"

Renderer* Renderer::instance = NULL;

Renderer::Renderer()
{
	LAST = 0;
	deltatime = 0;

	resX = 800;
	resY = 600;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "failed to initialize SDL2: " << SDL_GetError() << std::endl;
		exit(-1);
	}
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		std::cout << "Could not initiate SDL2_IMG: " << IMG_GetError() << std::endl;
		SDL_Quit();
		exit(-1);
	}

	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resX, resY, NULL);
	if (window == NULL)
	{
		std::cout << "failed to create window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(-2);
	}

	renderer = SDL_CreateRenderer(window, -1, NULL);
	if (renderer == NULL) {
		std::cout << "failed to create renderer: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-3);
	}

	std::cout << "Renderer Created" << std::endl;
}

Renderer::Renderer(int rX, int rY)
{
	resX = rX;
	resY = rY;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "failed to initialize SDL2: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resX, resY, NULL);
	if (window == NULL)
	{
		std::cout << "failed to create window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(-2);
	}

	renderer = SDL_CreateRenderer(window, -1, NULL);
	if (renderer == NULL) {
		std::cout << "failed to create renderer: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-3);
	}

	std::cout << "Renderer Created" << std::endl;
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

Renderer * Renderer::getInstance()
{
	if (instance == NULL) {
		instance = new Renderer();
	}
	return instance;
}

void Renderer::showTexture(SDL_Texture* tex) {
	SDL_Rect srect;
	srect.x = 0;
	srect.y = 0;
	srect.h = 512;
	srect.w = 512;
	SDL_Rect drect;
	SDL_RenderCopy(renderer, tex, NULL, &srect);
}

void Renderer::update()
{
	SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);

	calculateDeltatime();
}

void Renderer::renderEntity(Entity* entity)
{
	Texture* texture = entity->myTex;

	if (texture != NULL) {
		SDL_Rect r;
		if (entity->pos != NULL) {
			r.x = entity->pos->x;
			r.y = entity->pos->y;
		}
		if (entity->scale != NULL) {
			r.h = entity->scale->y;
			r.w = entity->scale->x;
		}
		renderTexture(texture, &r);
	}
	std::vector<Entity*>::iterator it = entity->childrenVec.begin();
	while (it != entity->childrenVec.end())
	{
		renderEntity((*it));
		it++;
	}
}

void Renderer::renderScene(Entity * entity)
{
	SDL_RenderClear(this->renderer);

	renderEntity(entity);


	SDL_RenderPresent(this->renderer);
}

void Renderer::renderTexture(Texture* texture, SDL_Rect* rect)
{
	if (texture->tex != NULL){
		SDL_RenderCopyEx(renderer, texture->tex, NULL, rect, 0, 0, SDL_FLIP_NONE);
	}
}

void Renderer::calculateDeltatime()
{
	Uint64 NOW = SDL_GetTicks();
	deltatime = NOW - LAST;
	deltatime /= 1000;
}

