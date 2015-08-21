#ifndef _ISORENDERER_H_
#define _ISORENDERER_H_

#include "ext_include.h"
#include "Vec2D.h"
#include "Contentmgr.h"

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
	void rendering(SDL_Renderer* renderer, Contentmgr manager); //(SDL_Renderer* renderer, int * map);
};

#endif
