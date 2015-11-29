#include "SDL.h"
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* argv[])
{
	SDL_Window *window;
	window = SDL_CreateWindow(
		"Cube",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_FULLSCREEN_DESKTOP
		);
	if (window == NULL)
	{
		printf("Couldn't create window: %s\n", SDL_GetError());
		SDL_Delay(5000);
		return 1;
	}

	SDL_Surface *bmp;
	bmp = SDL_LoadBMP("new_image.bmp");
	if (bmp == NULL)
	{
		printf("Unable to load bmp: %s\n", SDL_GetError());
		SDL_Delay(5000);
		return 1;
	}

	SDL_BlitSurface(bmp, NULL, SDL_GetWindowSurface(window), NULL);
	SDL_UpdateWindowSurface(window);

	SDL_Delay(5000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}