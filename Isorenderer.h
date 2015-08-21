#ifndef _Isorenderer_h_
#define _Isorenderer_h_

#include "ext_include.h"
#include "Vec2D.h"

class Isorenderer
{
private:
public:
	SDL_Texture* maintexture;

	Isorenderer();
	~Isorenderer();

	Vec2D conToIso(Vec2D kartvec);
	Vec2D conToKart(Vec2D isovec);
	SDL_Texture* textureDraw(SDL_Renderer* renderer); //(int[][] &map, int x, int y);
	void rendering(SDL_Renderer*); //(SDL_Renderer* renderer, int * map);
};

#endif
