#include "ext_include.h"
#include "Isorenderer.h"

int resX = 1024;
int resY = 768;

std::mt19937 random_gen;

int map[50][50];
int visible[16][12];
int camposX = 0;
int camposY = 0;

void renderScreen(SDL_Renderer* renderer)
{
	for(int y = 0; y < 12; y++)
	{
		for(int x = 0; x < 16; x++)
		{
			SDL_Rect rect;
			rect.h = 64;
			rect.w = 64;
			rect.x = x * 64;
			rect.y = y * 64;
			SDL_SetRenderDrawColor(renderer, 255, visible[x][y], 0, SDL_ALPHA_OPAQUE);
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}

void getVisibleScreen(int ScreenposX, int ScreenposY)
{
	for(int y = 0; y < 12; y++)
	{
		for(int x = 0; x < 16; x++)
		{
			visible[x][y] = map[ScreenposX + x][ScreenposY + y];
		}
	}
}

void scrolling()
{
	const Uint8 *keystate = SDL_GetKeyboardState(nullptr);
	if(keystate[SDL_SCANCODE_RIGHT] && camposX < 50 - 16)
		camposX++;
	if(keystate[SDL_SCANCODE_LEFT] && camposX > 0)
		camposX--;
	if(keystate[SDL_SCANCODE_UP] && camposY > 0)
		camposY--;
	if(keystate[SDL_SCANCODE_DOWN] && camposY < 50 - 12)
		camposY++;
}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("2DEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resX, resY, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	bool running = true;
	std::clock_t oldtime = std::clock();
	for(int x = 0; x < 50; x++)
	{
		for(int y = 0; y < 50; y++)
		{
			map[x][y] = std::uniform_int_distribution<int>(1, 255)(random_gen);
		}
	}

	Isorenderer iso;

	while(running)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_WINDOWEVENT:
				switch(event.window.event)
				{
				case SDL_WINDOWEVENT_CLOSE:
					running = false;
					break;
				}
				break;
			}
		}
		std::clock_t time = std::clock();
		if((double)time - (double)oldtime >= 100)
		{
			scrolling();
			oldtime = time;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		iso.rendering(renderer);
		SDL_RenderCopy(renderer, iso.maintexture, NULL, NULL);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return 0;
}
