#include <SDL2/SDL.h>

int main (void)
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n",
		       SDL_GetError());
		return (1);
	}

	/* Create a new window instance */
	window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED,
				  SDL_WINDOWPOS_CENTERED, 1260, 720, 0);
	if (window == NULL)
	{
		fprintf(stderr, "SDL_Createwindow Error: %s\n",
		       SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* crea a new renderer instance linked to the Window */
	renderer = SDL_CreateRenderer(window, -1,
				      SDL_RENDERER_ACCELERATED |
				      SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n",
		       SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}
