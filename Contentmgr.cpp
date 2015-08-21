#include "Contentmgr.h"

Contentmgr::Contentmgr(SDL_Renderer* renderer)
{
  textureload(renderer);
}

Contentmgr::~Contentmgr()
{
  unloadAll();
}

void Contentmgr::unloadAll()
{
  for(int e = 0; e < loadedTextures.size(); e++)
  {
    SDL_DestroyTexture(loadedTextures[e]);
  }
  loadedTextures.clear();
}

void Contentmgr::textureload(SDL_Renderer* renderer)
{
  SDL_Texture* texture = IMG_LoadTexture(renderer, "cityTiles_089.png");
  loadedTextures.push_back(texture);
}

SDL_Texture* Contentmgr::getTexture(int index)
{
  return loadedTextures[index];
}
