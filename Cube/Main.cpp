#include "SDL.h"
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

uint32_t getPixel(SDL_Surface *surface, int x, int y)
{
	uint32_t *pixels = (uint32_t *)surface->pixels;
	return pixels[(y * surface->w) + x];
}

void putPixel(SDL_Surface *surface, int x, int y, uint32_t pixel)
{
	uint32_t *pixels = (uint32_t *)surface->pixels;
	pixels[(y * surface->w) + x] = pixel;
}

int main(int argc, char* argv[])
{
	SDL_Window *window;
	window = SDL_CreateWindow(
		"Cube",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_OPENGL
		);
	if (window == NULL)
	{
		printf("Couldn't create window: %s\n", SDL_GetError());
		SDL_Delay(5000);
		return 1;
	}

	const int radius = 50;

	SDL_Surface *createdBMP = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
	for (int x = 0; x < createdBMP->w; x++)
	{
		for (int y = 0; y < createdBMP->h; y++)
		{
			const bool isInside = (((createdBMP->w / 2 - x)*(createdBMP->w / 2 - x) + (createdBMP->h / 2 - y)*(createdBMP->h / 2 - y)) <= radius*radius);
			if (isInside)
			{
				putPixel(createdBMP, x, y, 0x00ff0000);
			}
			else
			{
				putPixel(createdBMP, x, y, 0);
			}
		}
	}

	SDL_BlitSurface(createdBMP, NULL, SDL_GetWindowSurface(window), NULL);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(5000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}