#include "Isorenderer.h"

Isorenderer::Isorenderer()
{
}

Isorenderer::~Isorenderer()
{
}

Vec2D Isorenderer::conToIso(Vec2D kartvec)
{
	Vec2D isovec(0, 0);
	isovec.x = kartvec.x - kartvec.y;
	isovec.y = (kartvec.x + kartvec.y) / 2;
	return isovec;
}

Vec2D Isorenderer::conToKart(Vec2D isovec)
{
	Vec2D kartvec(0, 0);
	kartvec.x = (2 * isovec.y + isovec.x) / 2;
	kartvec.y = (2 * isovec.y - isovec.x) / 2;
	return kartvec;
}

SDL_Texture* Isorenderer::textureDraw(SDL_Renderer* renderer) //(int[][] &map, int x, int y)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, "cityTiles_089.png");
	return texture;
}

void Isorenderer::rendering(SDL_Renderer* renderer) //(SDL_Renderer* renderer, int * map))
{
	SDL_Rect target;
	target.h = 100;
	target.w = 100;
	target.x = 0;
	target.y = 0;
	Vec2D loc_iso;
	SDL_Texture* texture = textureDraw(renderer);
	for(int x = 0; x < 10; x++)
	{
		for(int y = 0; y < 10; y++)
		{
			loc_iso.x = x*-100;
			loc_iso.y = y*40;
			Vec2D loc_kart = conToKart(loc_iso);
			target.x = loc_kart.x + 500;
			target.y = loc_kart.y;
			SDL_RenderCopy(renderer, texture, NULL, &target);
		}
	}
	//sichtbaren teil der map bestimmen
	//durchgehen:
	//textureDraw aufrufen mit koordinate
	//blite surface von textureDraw an passende koordinate
}

/*
rendering prozess:
1. sichtbaren teil der map bestimmen
2. tile für tile durchgehen:
2.1 lesen was ist in dem tile?
2.2 textur öffnen und auf surface schreiben
2.3 surface auf main window bliten
3. einheiten/objekte
4. UI

gesamter prozess: rendering();
2.1 und 2.2 texture draw
2.3 in main render funktion
*/
