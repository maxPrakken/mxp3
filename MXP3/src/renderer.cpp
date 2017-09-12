#include "../include/renderer.h"

Renderer::Renderer()
{
	resX = 800;
	resY = 600;
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
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

Renderer::Renderer(int rX,int rY)
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

void Renderer::update()
{
	SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}
